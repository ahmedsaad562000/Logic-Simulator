#include "BUFFER.h"

BUFFER::BUFFER(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	type = GATE1;
	selected = false;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void BUFFER::Operate()
{
	 
	if (m_InputPins[0].getStatus() == LOW)
	{
		m_OutputPin.setStatus(LOW);
	}
	if (m_InputPins[0].getStatus() == HIGH)
	{
		m_OutputPin.setStatus(HIGH);
	}
	m_OutputPin.operate();
}
InputPin* BUFFER::getinputpin(int& x, int& y, int n)
{
	x = m_GfxInfo.x1;

	
		y = (m_GfxInfo.y1 + m_GfxInfo.y2 )/2;
		return &m_InputPins[0];

}

// Function Draw
// Draws BUFFER gate
void BUFFER::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBuffer(m_GfxInfo,selected);
}

//returns status of outputpin
int BUFFER::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int BUFFER::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void BUFFER::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}