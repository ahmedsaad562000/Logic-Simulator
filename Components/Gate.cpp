#include "Gate.h"
#include "../ApplicationManager.h"
//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{

	
	
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}

void Gate::deletecmpn(Output* pOut , ApplicationManager* pApp){
	pOut->Draw_rectangle_delete(m_GfxInfo);
	pOut->Draw_rectangle_label(m_GfxInfo.x1 , m_GfxInfo.y1-28 , Component::getlabel().size());
	m_OutputPin.deleteconnections(pOut , pApp);
	for (int i = 0; i < m_Inputs; i++)
	{
	
		m_InputPins[i].deleteconnection(pOut , pApp);
	}
	pApp->RemoveComponent((Component*)this);
}


void Gate::select(Output* pout)
{
	if (Component::isselected())
	{
	unselect(pout);
	}
	else
	{
		selected = true;
	
	}
}
void Gate::unselect(Output* pout)
{
	selected = false;
	
}



	OutputPin* Gate::getoutputpinlocation(int&x , int&y){
		x = m_GfxInfo.x2;
		y = (m_GfxInfo.y1 + m_GfxInfo.y2)/2;
		return &m_OutputPin;
	}