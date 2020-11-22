#include "stdafx.h"
#include "imagelib.h"
#include "math.h"
#include <fstream>
using namespace std;

int showBitMap(HWND hwnd, HANDLE hBit, int x, int y)
{
	BITMAP BitMap;
	GetObject(hBit, sizeof(BITMAP), &BitMap);

	int height = BitMap.bmHeight;
	int width = BitMap.bmWidth;
	HDC hdc = GetDC(hwnd);
	HDC hdcMem = CreateCompatibleDC(hdc);
	HBITMAP oldBitMap = (HBITMAP)SelectObject(hdcMem, hBit);

	BitBlt(hdc, x, y, width, height, hdcMem, 0, 0, SRCCOPY);

	SelectObject(hdcMem, oldBitMap);
	ReleaseDC(hwnd, hdc);
	DeleteDC(hdcMem);
	return 0;
}
int ClientToBmp(HWND hWnd,char *Name)  //Сохранение рабочей области окна в файле Name.bmp
{
	BITMAPFILEHEADER    bmfHdr;
	BITMAPINFOHEADER bi;
	RECT r;
	int BitToPixel=24;			 
	GetClientRect(hWnd,&r);	
	HDC hdc = GetDC(hWnd);
	HDC hdcMem=CreateCompatibleDC(hdc); 
	HBITMAP BitMap = CreateCompatibleBitmap(hdc, r.right,r.bottom); 
	HBITMAP OldBitmap = (HBITMAP)SelectObject(hdcMem, BitMap);
	BitBlt(hdcMem, 0, 0, r.right, r.bottom, hdc, 0, 0, SRCCOPY);
	BitMap = (HBITMAP)SelectObject(hdcMem,OldBitmap);
	ZeroMemory(&bi,sizeof(BITMAPINFOHEADER));	
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = r.right;
	bi.biHeight = r.bottom;
	bi.biPlanes = 1;
	bi.biBitCount = BitToPixel; 
	bi.biSizeImage = (r.right * BitToPixel+31)/32*4 * r.bottom;
	DWORD dwWritten; 
	HANDLE fh = CreateFile(Name, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (fh == INVALID_HANDLE_VALUE)     return 2;

	bmfHdr.bfType = ('M'<<8)|'B';  
	bmfHdr.bfSize = bi.biSizeImage + sizeof(bmfHdr)+bi.biSize; 
	bmfHdr.bfReserved1 = bmfHdr.bfReserved2 = 0;
	bmfHdr.bfOffBits = sizeof(bmfHdr) + bi.biSize;
	WriteFile(fh, (LPSTR)&bmfHdr, sizeof(bmfHdr), &dwWritten, NULL);
	WriteFile(fh, (LPSTR)&bi, sizeof(BITMAPINFOHEADER), &dwWritten, NULL);
	char *lp=(char *) GlobalAlloc(GMEM_FIXED, bi.biSizeImage);
	int err=GetDIBits(hdc, BitMap,0,(UINT)r.bottom, lp,(LPBITMAPINFO)&bi, DIB_RGB_COLORS); 		          
	WriteFile(fh, lp, bi.biSizeImage, &dwWritten, NULL);
	GlobalFree(GlobalHandle(lp));
	CloseHandle(fh);
	ReleaseDC(hWnd,hdc);
	DeleteDC(hdcMem);		
	if (dwWritten == 0)        return 2; 
	return 0;
}
int ClientRectToBmp(HWND hWnd, char* Name, RECT r)
{
	BITMAPFILEHEADER    bmfHdr;
	BITMAPINFOHEADER bi;
	int BitToPixel=24;			
	HDC hdc = GetDC(hWnd);
	HDC hdcMem=CreateCompatibleDC(hdc); 
	HBITMAP BitMap = CreateCompatibleBitmap(hdc, r.right,r.bottom);//Создалем битовую карту BitMap по размеру рабочей области окна
	HBITMAP OldBitmap = (HBITMAP)SelectObject(hdcMem, BitMap);
	BitBlt(hdcMem, 0, 0, r.right, r.bottom, hdc, 0, 0, SRCCOPY);
	BitMap = (HBITMAP)SelectObject(hdcMem,OldBitmap);
	ZeroMemory(&bi,sizeof(BITMAPINFOHEADER));	
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = r.right;
	bi.biHeight = r.bottom;
	bi.biPlanes = 1;
	bi.biBitCount = BitToPixel; 
	bi.biSizeImage = (r.right * BitToPixel+31)/32*4 * r.bottom;
	DWORD dwWritten; 
	HANDLE fh = CreateFile(Name, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (fh == INVALID_HANDLE_VALUE)     return 2;

	bmfHdr.bfType = ('M'<<8)|'B';  
	bmfHdr.bfSize = bi.biSizeImage + sizeof(bmfHdr)+bi.biSize;
	bmfHdr.bfReserved1 = bmfHdr.bfReserved2 = 0;
	bmfHdr.bfOffBits = sizeof(bmfHdr) + bi.biSize; 
	WriteFile(fh, (LPSTR)&bmfHdr, sizeof(bmfHdr), &dwWritten, NULL);
	WriteFile(fh, (LPSTR)&bi, sizeof(BITMAPINFOHEADER), &dwWritten, NULL);
	char *lp=(char *) GlobalAlloc(GMEM_FIXED, bi.biSizeImage);
	int err=GetDIBits(hdc, BitMap,0,(UINT)r.bottom, lp,(LPBITMAPINFO)&bi, DIB_RGB_COLORS);           
	WriteFile(fh, lp, bi.biSizeImage, &dwWritten, NULL);
	GlobalFree(GlobalHandle(lp));
	CloseHandle(fh);
	ReleaseDC(hWnd,hdc);
	DeleteDC(hdcMem);		
	if (dwWritten == 0)        return 2; 
	return 0;
}
