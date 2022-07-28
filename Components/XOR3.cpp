#include "XOR3.h"

XOR3::XOR3(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(3, r_FanOut)
{
	type = GATE;
	Component::setselected(false);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR3::Operate()
{
	//caclulate the output status as the NORing of the two input pins
	int a;
	int b;
	int c;
	int d;
	a=(m_InputPins[0].getStatus()==HIGH) ? 1 : 0;
	b=(m_InputPins[1].getStatus()==HIGH) ? 1 : 0;
	c=(m_InputPins[2].getStatus()==HIGH) ? 1 : 0;
	d=a+b+c;
	if (d%2!=0)
		m_OutputPin.setStatus(HIGH);
	else m_OutputPin.setStatus(LOW);

	m_OutputPin.operate();
	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void XOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	
	pOut->DrawXOR3(m_GfxInfo, Component::isselected());
}


//returns status of outputpin
int XOR3::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

InputPin* XOR3::getinputpin(int &x, int &y, int n)
{  x=m_GfxInfo.x1;
   if (n==1)
   { y=m_GfxInfo.y1+19;
   return &m_InputPins[0];}
   else if (n==2)
   { y=((m_GfxInfo.y2+m_GfxInfo.y1)/2)-2;
   return &m_InputPins[1];}
   else if (n==3)
   { y=m_GfxInfo.y2-20;
   return &m_InputPins[2];}
   else{ return NULL;}
}
//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

