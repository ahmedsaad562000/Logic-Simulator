#include "AND3.h"

AND3::AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	type = GATE;
	Component::setselected(false);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND3::Operate()
{
	
	//caclulate the output status as the ANDing of the two input pins
	if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == LOW && m_InputPins[2].getStatus() == LOW)
	{
		m_OutputPin.setStatus(LOW);
	}
	if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == LOW && m_InputPins[2].getStatus() == LOW)
	{
		m_OutputPin.setStatus(LOW);
	}
	if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == HIGH && m_InputPins[2].getStatus() == LOW)
	{
		m_OutputPin.setStatus(LOW);
	}
	if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == LOW && m_InputPins[2].getStatus() == HIGH)
	{
		m_OutputPin.setStatus(LOW);
	}
	if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH && m_InputPins[2].getStatus() == LOW)
	{
		m_OutputPin.setStatus(LOW);
	}
	if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == LOW && m_InputPins[2].getStatus() == HIGH)
	{
		m_OutputPin.setStatus(LOW);
	}
	if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == HIGH && m_InputPins[2].getStatus() == HIGH)
	{
		m_OutputPin.setStatus(LOW);
	}
	
	if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH && m_InputPins[2].getStatus() == HIGH)
	{
		m_OutputPin.setStatus(HIGH);
	}
	m_OutputPin.operate();
	//Add you code here
}

InputPin* AND3::getinputpin(int& x, int& y, int n)
{
	x = m_GfxInfo.x1;
	if (n == 1)
	{
		y = m_GfxInfo.y1 + 20;
		return &m_InputPins[0];
	}
	else if (n == 2)
	{
		y = (m_GfxInfo.y2+ m_GfxInfo.y1)/2;
		return &m_InputPins[1];

	}
	else if (n == 3)
	{
		y = m_GfxInfo.y2 - 20;
		return &m_InputPins[2];

	}
	else{ return NULL;}
}

// Function Draw
// Draws 3-input AND gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND3(m_GfxInfo,Component::isselected());
}

//returns status of outputpin
int AND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
