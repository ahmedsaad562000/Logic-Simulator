#include "OR.h"

OR::OR(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	type = GATE;
	selected = false;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void OR::Operate()
{
	
	
	if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == LOW)
	{
		m_OutputPin.setStatus(LOW);
	}
	if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == LOW)
	{
		m_OutputPin.setStatus(HIGH);
	}
	if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == HIGH)
	{
		m_OutputPin.setStatus(HIGH);
	}
	if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH)
	{
		m_OutputPin.setStatus(HIGH);
	}
	m_OutputPin.operate();
}
InputPin* OR::getinputpin(int& x, int& y, int n)
{
	x = m_GfxInfo.x1;
	if (n == 1)
	{
		y = m_GfxInfo.y1 + 25;
		return &m_InputPins[0];
	}
	else if (n == 2)
	{
		y = m_GfxInfo.y2 - 22;
		return &m_InputPins[1];

	}
	else{ return NULL;}
}

// Function Draw
// Draws OR gate
void OR::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawOR2(m_GfxInfo,selected);
}

//returns status of outputpin
int OR::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}