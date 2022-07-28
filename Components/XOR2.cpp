#include "XOR2.h"

XOR2::XOR2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	type = GATE;
	Component::setselected(false);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR2::Operate()
{
	//caclulate the output status as the NORing of the two input pins
	if (m_InputPins[0].getStatus()!=m_InputPins[1].getStatus())
		m_OutputPin.setStatus(HIGH);
	else m_OutputPin.setStatus(LOW);
	//Add you code here
	m_OutputPin.operate();
}


// Function Draw
// Draws 2-input AND gate
void XOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR2(m_GfxInfo, Component::isselected());
}


//returns status of outputpin
int XOR2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

InputPin* XOR2::getinputpin(int &x, int &y, int n)
{  x=m_GfxInfo.x1;
   if (n==1)
   { y=m_GfxInfo.y1+20;
   return &m_InputPins[0];}
   else if (n==2)
   { y=m_GfxInfo.y2-20;
   return &m_InputPins[1];}
   else{ return NULL;}
}
//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
