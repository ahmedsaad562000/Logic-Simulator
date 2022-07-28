#include "Component.h"
int Component::cmpnid =0;

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	cmpnid++;
	ID = cmpnid;
	
	m_GfxInfo = r_GfxInfo;	
}

int Component::getID(){return ID;}
CompnType Component::gettype(){ return type; }
void Component::setselected(bool selectrt){
	selected = selectrt;

}

bool Component::InArea(int x , int  y){
	
	int x1 = m_GfxInfo.x1;
	int x2 = m_GfxInfo.x2;
	int y1 = m_GfxInfo.y1;
	int y2 = m_GfxInfo.y2;
	int mid = (x1 + x2)/2;
	if(x1>x2){
	int temp = x1;
	x1 = x2;
	x2 = temp;
	}
	int yl = y2;
	int yu = y1;


	if(y1>y2){
	yl = y1;
	yu = y2;
	}

	if(this->type==CONNECTION){
		if((y<=y1+5 && y>=y1-5 &&  x>=x1  && x<=mid ) ||  ( x>=mid-5  && x<=mid+5 && y>=yu && y<=yl )   ||  (y<=y2+5 && y>=y2-5 &&  x<=x2  && x>=mid  ))
			return true;
		else
			return false;
	}
	
	
	else{
		if(x>= m_GfxInfo.x1 && x<=m_GfxInfo.x2 && y>= m_GfxInfo.y1 && y<=m_GfxInfo.y2 ){return true;}
	return false;
	}
}



bool Component::isselected(){
	return this->selected;
}



void Component::setlabel(string s){
	m_Label = s;

}
string Component::getlabel(){
	return m_Label;
}
void Component::getlabelplace(int &x , int  &y)
{
	if (this->type==CONNECTION)
	{
		x = (m_GfxInfo.x1 + m_GfxInfo.x2)/2;
		if(m_GfxInfo.y1<m_GfxInfo.y2){y =m_GfxInfo.y1-30;}
		else{y =m_GfxInfo.y2-30;}

	
	}
	else{
	x = m_GfxInfo.x1;
	y =m_GfxInfo.y1-30;
	}

}


Component::Component()
{
	cmpnid++;
	ID = cmpnid;
	
}

Component::~Component()
{}

