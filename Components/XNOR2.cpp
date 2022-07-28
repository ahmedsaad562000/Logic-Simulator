#include "XNOR2.h"

XNOR2::XNOR2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	type = GATE;
	Component::setselected(false);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XNOR2::Operate()
{
	//caclulate the output status as the NORing of the two input pins
	if (m_InputPins[0].getStatus()!=m_InputPins[1].getStatus())
		m_OutputPin.setStatus(LOW);
	else m_OutputPin.setStatus(HIGH);
	//Add you code here
	m_OutputPin.operate();
}


// Function Draw
// Draws 2-input AND gate
void XNOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXNOR2(m_GfxInfo, Component::isselected());
}


//returns status of outputpin
int XNOR2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

InputPin* XNOR2::getinputpin(int &x, int &y, int n)
{  x=m_GfxInfo.x1;
   if (n==1)
   { y=m_GfxInfo.y1+21;
   return &m_InputPins[0];}
   else if (n==2)
   { y=m_GfxInfo.y2 - 19;
   return &m_InputPins[1];}
   else{ return NULL;}
}
//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
