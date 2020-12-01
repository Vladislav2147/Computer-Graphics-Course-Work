#include "StdAfx.h"
#include "Sphere.h"

CSphere::CSphere(void)
{
	current_pos=0;
	MV.RedimMatrix(4,4);
	MW.RedimMatrix(3,3);
}


CSphere::~CSphere(void)
{
}

void CSphere::MV_and_MW(double OX,double OY,CRect& RW,CMatrix& PView){
	MV=CreateViewCoord(PView(0),PView(1),PView(2));	//матрица пересчета из мировой в виддовую СК
	CRectD RV(-OX,OY,OX,-OY);
	MW=SpaceToWindow(RV,RW);						//матрица пересчета из видовой в оконную СК
}

void CSphere::DrawOXYZ(CDC& dc,double OX,double OY,double OZ,CMatrix& PView,COLORREF color1,COLORREF color2){
	CPen* pen=new CPen(PS_SOLID,1,color1);
	CPen* old_pen=dc.SelectObject(pen);
	CMatrix S0(4),SX(4),SY(4),SZ(4);	//в мировой СК
	CMatrix V0(4),VX(4),VY(4),VZ(4);	//в видовой СК
	CMatrix W0(3),WX(3),WY(3),WZ(3);	//в оконной СК
	S0(3)=1;
	SX(0)=OX;SX(3)=1;
	SY(1)=OY;SY(3)=1;
	SZ(2)=-OZ;SZ(3)=1;
	V0=MV*S0;VX=MV*SX;VY=MV*SY;VZ=MV*SZ;	//пересчет из мировой в видовую СК
	V0(2)=1;VX(2)=1;VY(2)=1;VZ(2)=1;
	W0=MW*V0.GetCol(0,0,2);					//пересчет из видовой в оконную СК
	WX=MW*VX.GetCol(0,0,2);
	WY=MW*VY.GetCol(0,0,2);
	WZ=MW*VZ.GetCol(0,0,2);	
	CPoint p0(W0(0),W0(1)),pX(WX(0),WX(1)),pY(WY(0),WY(1)),pZ(WZ(0),WZ(1));
	dc.MoveTo(p0);dc.LineTo(pX);			//прорисовка положительных направлений осей координат
	dc.MoveTo(p0);dc.LineTo(pY);
	dc.MoveTo(p0);dc.LineTo(pZ);
	pen=new CPen(PS_SOLID,1,color2);
	dc.SelectObject(pen);
	dc.MoveTo(p0);dc.LineTo(p0.x-(pX.x-p0.x),p0.y-(pX.y-p0.y));		//прорисовка отрицательных направлений осей координат
	dc.MoveTo(p0);dc.LineTo(p0.x-(pY.x-p0.x),p0.y-(pY.y-p0.y));
	dc.MoveTo(p0);dc.LineTo(p0.x-(pZ.x-p0.x),p0.y-(pZ.y-p0.y));
	dc.SelectObject(old_pen);
}

void CSphere::DrawTraector(CDC& dc,double Radius,double tr_A,double tr_F,double tr_f,double density, CMatrix& PView,COLORREF color, bool show_trajectory){
	CPen* pen=new CPen(PS_SOLID,1,color);
	CPen* old_pen = dc.SelectObject(pen);
	double step = pi/density;
	int trajectory_point_amount = 2*pi/(step*abs(tr_F));
	
	S.RedimMatrix(4,trajectory_point_amount);	//в мировой СК
	CMatrix V(4,trajectory_point_amount);	//в видовой СК
	CMatrix W(3,trajectory_point_amount);	//в оконной СК
	for(int i=0;i<trajectory_point_amount;i++) {
		S(0,i)=(Radius+tr_A*sin((double)i*tr_f))*sin(i*step*tr_F);
		S(1,i)=(Radius+tr_A*sin((double)i*tr_f))*cos(i*step*tr_F);
		S(2,i)=0;
		S(3,i)=1;
	}
	for(int i=0;i<trajectory_point_amount;i++){
		CMatrix m=MV*S.GetCol(i);		//пересчет из мировой в видовую СК
		for(int j=0;j<4;j++)
			V(j,i)=m(j);
		V(2,i)=1;
	}
	for(int i=0;i<trajectory_point_amount;i++){
		CMatrix m=MW*V.GetCol(i,0,2);	//пересчет из видовой в оконную СК
		for(int j=0;j<3;j++)
			W(j,i)=m(j);
	}
	if (show_trajectory) {
		CPoint p0(W(0, 0), W(1, 0));
		dc.MoveTo(p0);
		for (int i = 1; i < trajectory_point_amount; i++) {
			CPoint p(W(0, i), W(1, i));
			dc.LineTo(p);					//прорисовка линиями от точки к точке
		}
		dc.SelectObject(old_pen);
	}
}



void CSphere::DrawD(CDC& dc,double Radius,CMatrix& PView,CMatrix& PLight,COLORREF color){
	BYTE R=GetRValue(color),G=GetGValue(color),B=GetBValue(color);
	CMatrix VSphere(3),VSphereNorm(3),PV(4),VCart(3);
	COLORREF col=color;
	double df=(double)45/Radius/MW(0,0),
		dq=(double)-45/Radius/MW(1,1),kLight=0;
	double cos_PN=0,cos_RN=0;
	CMatrix m=(MV*S.GetCol(current_pos)).GetCol(0,0,2);	//положение центра шара в видовой СК
	m(2)=1;
	m=MW*m;						//переход к оконным координатам
	CMatrix m2(4);m2(3)=1;
	m2=(MV*m2);					//координаты начала мировых координат в видовой СК
	m2.RedimData(3);
	m2(2)=1;
	m2=MW*m2;					//переход к оконным координатам
	m=m-m2;						//смещение центра шара от начала мировых координат в оконной СК

	VSphere(0)=Radius;

	//получение декартовых координат наблюдателя и источника освещения
	CMatrix VR=SphereToCart(PView),VS=SphereToCart(PLight);

	//перенос начала координат в центр шара, находящийся в заданной точке траектории
	//т.е. перемещение наблюдателя и источника света
	VR.RedimData(4);VR(3)=1;
	/*VR=Translate3D(S(0,current_pos),S(1,current_pos),S(2,current_pos))*VR;*/
	VS.RedimData(4);VS(3)=1;
	VS=Translate3D(S(0,current_pos),S(1,current_pos),S(2,current_pos))*VS;
	for(double fi=0;fi<=180.0;fi+=df){		//обход точек поверхности шара
		for(double q=0;q<=180.0;q+=dq){
			//обход левой половины

			VSphere(1)=PView(1)+fi;
			VSphere(2)=q;
			VCart=SphereToCart(VSphere);	//переход от сферических к декартовым координатам точки на поверхности шара
			VSphereNorm=VCart;

			PV(0)=VCart(0);
			PV(1)=VCart(1);
			PV(2)=VCart(2);
			PV(3)=1;
			PV=MV*PV;			//переход от мировой к видовой системе координат
			VCart(0)=PV(0);
			VCart(1)=PV(1);
			VCart(2)=1;
			VCart=MW*VCart;		//переход от видовой к оконной СК
			cos_PN=cosViV2(VS,VSphereNorm);
			if(cos_PN<=0){
				//установка освещенности точки в зависимости от угла между 
				//нормалью к поверхности сферы и вектором к источнику освещения
				kLight=-cos_PN;	
			}
			else kLight=0;
			col=RGB(R*kLight,G*kLight,B*kLight);
			VCart=VCart+m;	//смещение в оконной СК относительно начала координат
			dc.SetPixel(VCart(0),VCart(1),col);		//закрашивание точки на поверхности шара

			//обход правой половины
			VSphere(1)=PView(1)-fi;
			VSphere(2)=q;
			VCart=SphereToCart(VSphere);	//переход от сферических к декартовым координатам точки на поверхности шара
			VSphereNorm=VCart;

			PV(0)=VCart(0);
			PV(1)=VCart(1);
			PV(2)=VCart(2);
			PV(3)=1;
			PV=MV*PV;			//переход от мировой к видовой системе координат
			VCart(0)=PV(0);
			VCart(1)=PV(1);
			VCart(2)=1;
			VCart=MW*VCart;		//переход от видовой к оконной СК
			cos_PN=cosViV2(VS,VSphereNorm);
			if(cos_PN<=0){
				//установка освещенности точки в зависимости от угла между 
				//нормалью к поверхности сферы и вектором к источнику освещения
				kLight=-cos_PN;	
			}
			else kLight=0;
			col=RGB(R*kLight,G*kLight,B*kLight);
			VCart=VCart+m;	//смещение в оконной СК относительно начала координат
			dc.SetPixel(VCart(0),VCart(1),col);		//закрашивание точки на поверхности шара

		}
	}
}

void CSphere::DrawZ(CDC& dc,double Radius,CMatrix& PView,CMatrix& PLight,COLORREF color){
	BYTE R=GetRValue(color),G=GetGValue(color),B=GetBValue(color);
	CMatrix VSphere(3),VSphereNorm(3),PV(4),VCart(3);
	COLORREF col=color;
	double df=(double)45/Radius/MW(0,0),dq=(double)-45/Radius/MW(1,1),kLight=0;
	double cos_RN,cos_PN,xx,cos_A;
	CMatrix m=(MV*S.GetCol(current_pos)).GetCol(0,0,2);	//положение центра шара в видовой СК
	m(2)=1;
	m=MW*m;						//переход к оконным координатам
	CMatrix m2(4);m2(3)=1;
	m2=(MV*m2);					//координаты начала мировых координат в видовой СК
	m2.RedimData(3);
	m2(2)=1;
	m2=MW*m2;					//переход к оконным координатам
	m=m-m2;						//смещение центра шара от начала мировых координат в оконной СК

	VSphere(0)=Radius;
	//получение декартовых координат наблюдателя и источника освещения
	CMatrix VR=SphereToCart(PView),VS=SphereToCart(PLight);

	//перенос начала координат в центр шара, находящийся в заданной точке траектории
	//т.е. перемещение наблюдателя и источника света
	VR.RedimData(4);VR(3)=1;
	VR=Translate3D(S(0,current_pos),S(1,current_pos),S(2,current_pos))*VR;
	VS.RedimData(4);VS(3)=1;
	VS=Translate3D(S(0,current_pos),S(1,current_pos),S(2,current_pos))*VS;
	for(double fi=0;fi<=180.0;fi+=df){		//обход точек сферы
		for(double q=0;q<=180.0;q+=dq){
			//левая половина
			VSphere(1)=PView(1)+fi;
			VSphere(2)=q;
			VCart=SphereToCart(VSphere);
			VSphereNorm=VCart;

			PV(0)=VCart(0);
			PV(1)=VCart(1);
			PV(2)=VCart(2);
			PV(3)=1;
			PV=MV*PV;			//переход от мировой к видовой системе координат
			VCart(0)=PV(0);
			VCart(1)=PV(1);
			VCart(2)=1;
			VCart=MW*VCart;		//переход от видовой к оконной системе координат
			cos_PN=cosViV2(VS,VSphereNorm);
			if(cos_PN<0){
				xx=2*VS.Abs()*cos_PN/VSphereNorm.Abs();
				VS.RedimData(3);
				CMatrix RX=-VSphereNorm*xx+VS;
				cos_A=cosViV2(RX,VR);
				//установка освещенности точки в зависимости от угла между 
				//вектором к наблюдателю и вектором к источнику освещения
				if(cos_A<0)
					kLight=cos_A*cos_A;
				else kLight=0;
			}
			else kLight=0;
			col=RGB(R*kLight,G*kLight,B*kLight);
			VCart=VCart+m;		//смещение в оконной СК относительно начала координат
			dc.SetPixel(VCart(0),VCart(1),col);

			//правая половина
			VSphere(1)=PView(1)-fi;
			VSphere(2)=q;
			VCart=SphereToCart(VSphere);
			VSphereNorm=VCart;

			PV(0)=VCart(0);
			PV(1)=VCart(1);
			PV(2)=VCart(2);
			PV(3)=1;
			PV=MV*PV;			//переход от мировой к видовой системе координат
			VCart(0)=PV(0);
			VCart(1)=PV(1);
			VCart(2)=1;
			VCart=MW*VCart;		//переход от видовой к оконной системе координат
			cos_PN=cosViV2(VS,VSphereNorm);
			if(cos_PN<0){
				xx=2*VS.Abs()*cos_PN/VSphereNorm.Abs();
				VS.RedimData(3);
				CMatrix RX=-VSphereNorm*xx+VS;
				cos_A=cosViV2(RX,VR);
				//установка освещенности точки в зависимости от угла между 
				//вектором к наблюдателю и вектором к источнику освещения
				if(cos_A<0)
					kLight=cos_A*cos_A;
				else kLight=0;
			}
			else kLight=0;
			col=RGB(R*kLight,G*kLight,B*kLight);
			VCart=VCart+m;		//смещение в оконной СК относительно начала координат
			dc.SetPixel(VCart(0),VCart(1),col);

		}
	}
}

void CSphere::SetPos(int pos){
	current_pos=pos;
}
int CSphere::GetPos(){
	return current_pos;
}