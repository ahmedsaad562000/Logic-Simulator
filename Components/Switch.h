#ifndef _SWITCH_H
#define _SWITCH_H
#include "component.h"
#include "OutputPin.h"

class Switch : public Component
{
	bool silly;
	bool onoroff;
	STATUS s;
	OutputPin m_outpin;
public:
	
   ~Switch();
   Switch(const GraphicsInfo &r_GfxInfo , int r_FanOut);
	void Operate();	// set the status to high or low
	virtual void select(Output* pout);
	virtual void unselect(Output* pout);
	void switchOnorOff();
	void Draw(Output* pOut);	//Draws 2-input gate
	virtual OutputPin* getoutputpinlocation(int&x , int&y);
	int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual InputPin* getinputpin(int&x , int&y , int n);
	virtual void deletecmpn(Output *pOut , ApplicationManager* pApp);
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s);
	


};
#endif

