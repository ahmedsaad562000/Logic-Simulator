#include "NOR3.h"

NOR3::NOR3(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(3, r_FanOut)
{
	type = GATE;
	Component::setselected(false);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOR3::Operate()
{
	//caclulate the output status as the NORing of the two input pins
	if (m_InputPins[0].getStatus()==HIGH || m_InputPins[1].getStatus()==HIGH || m_InputPins[2].getStatus()==HIGH)
		m_OutputPin.setStatus(LOW);
	else m_OutputPin.setStatus(HIGH);
	m_OutputPin.operate();
	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void NOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	
	pOut->DrawNOR3(m_GfxInfo, Component::isselected());
}


//returns status of outputpin
int NOR3::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

InputPin* NOR3::getinputpin(int &x, int &y, int n)
{  x=m_GfxInfo.x1;
   if (n==1)
   { y=m_GfxInfo.y1+24;
   return &m_InputPins[0];}
   else if (n==2)
   { y=((m_GfxInfo.y2+m_GfxInfo.y1)/2)-2;
   return &m_InputPins[1];}
   else if (n==3)
   { y=m_GfxInfo.y2-27;
   return &m_InputPins[2];}
   else{ return NULL;}
}
//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

