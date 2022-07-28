#include "AND2.h"

AND2::AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	type = GATE;
	selected = false;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND2::Operate()
{
	if(m_InputPins[0].getStatus()==HIGH&&m_InputPins[1].getStatus()==HIGH)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);

	m_OutputPin.operate();
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND2(m_GfxInfo , selected);
}

//returns status of outputpin
int AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}
 InputPin* AND2::getinputpin(int&x , int&y , int n){
	 x = m_GfxInfo.x1;
	 
	 if (n == 1){
		 y = m_GfxInfo.y1+20;
		 return &m_InputPins[0];}
	 else  {
		 y = m_GfxInfo.y2-20;
		 return &m_InputPins[1];}
	 



 }


//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
