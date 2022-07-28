#include "Switch.h"
#include "../ApplicationManager.h"

Switch::Switch(const GraphicsInfo &r_GfxInfo , int r_FanOut):Component(r_GfxInfo),m_outpin(r_FanOut)
{
	onoroff = false;
	selected = false;
	silly = false;
	s = LOW;
	type = SWITCH;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	
}


Switch::~Switch()
{
}

void Switch::setInputPinStatus(int n, STATUS s){
return;
}

void Switch::Operate()

{

	m_outpin.setStatus(s);
	m_outpin.operate();
	
}
void Switch::select(Output* pout){
	

	
	if(selected || silly ){
		silly = false;
		unselect(pout);
		}
	else{
		silly = true;
		selected = true;}
	

}
void Switch::unselect(Output* pout){
	silly = false;
	selected = false;
	

}

void Switch::switchOnorOff(){

	if(onoroff){
		s = LOW;
		onoroff = false;
	
	}
	else
	{
		s = HIGH;
		onoroff = true;
		
	}
}

void Switch::Draw(Output* pOut)
{
	pOut->DrawSwitch(m_GfxInfo , selected , onoroff);
}	
	
int Switch::GetOutPinStatus(){
	return m_outpin.getStatus();
}
//returns status of outputpin if LED, return -1
int Switch::GetInputPinStatus(int n){
return -1;
}
void Switch::deletecmpn(Output* pOut , ApplicationManager* pApp){
	pOut->Draw_rectangle_delete(m_GfxInfo);
	pOut->Draw_rectangle_label(m_GfxInfo.x1 , m_GfxInfo.y1-28 , Component::getlabel().size());
	m_outpin.deleteconnections(pOut , pApp);
	
	pApp->RemoveComponent((Component*)this);
}

InputPin* Switch::getinputpin(int&x , int&y , int n){return NULL;}
//returns status of Inputpin # n if SWITCH, return -1
	OutputPin* Switch::getoutputpinlocation(int&x , int&y){
		x = m_GfxInfo.x2;
		y = (m_GfxInfo.y2)-13;
		return &m_outpin;
	}