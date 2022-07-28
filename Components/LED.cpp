#include "LED.h"
#include "../ApplicationManager.h"

LED::LED(const GraphicsInfo &r_GfxInfo)
{
	sc = LOW;
	selected = false;
	type = Led;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


LED::~LED()
{

}

void LED::setInputPinStatus(int n, STATUS s){
	sc =s;
	m_inpin.setStatus(sc);
}

void LED::Operate()

{

	sc = m_inpin.getStatus();

}
void LED::select(Output* pout){
	

	
	if(selected){

	unselect(pout);	
	}
	else{
		selected = true;
	
	
	}
	

}
void LED::unselect(Output* pout){
	selected = false;


}



void LED::Draw(Output* pOut)
{
	if (sc == HIGH){
	pOut->DrawLED(m_GfxInfo , selected , true );
	return;
	}
	else{
pOut->DrawLED(m_GfxInfo , selected , false );
	return;
	}
}	
	
int LED::GetOutPinStatus(){
	return -1;
}
//returns status of outputpin if LED, return -1
int LED::GetInputPinStatus(int n){
return sc;
}

InputPin* LED::getinputpin(int&x , int&y , int n){
	x = m_GfxInfo.x1+14;
	y = m_GfxInfo.y2;
	return &m_inpin;
}
//returns status of Inputpin # n if SWITCH, return -1
	OutputPin* LED::getoutputpinlocation(int&x , int&y){
		
		return NULL;
	}
	void LED::deletecmpn(Output *pOut ,  ApplicationManager* pApp){
	
	pOut->Draw_rectangle_delete(m_GfxInfo);
	pOut->Draw_rectangle_label(m_GfxInfo.x1 , m_GfxInfo.y1-28 , Component::getlabel().size());
	m_inpin.deleteconnection(pOut , pApp);
	pApp->RemoveComponent((Component*)this);
	}