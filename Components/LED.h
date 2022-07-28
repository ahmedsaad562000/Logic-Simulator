#ifndef _LED_H
#define _LED_H
#include "component.h"
#include "InputPin.h"
class LED :public Component
{
	STATUS sc;
	InputPin m_inpin;
public:
	LED(const GraphicsInfo &r_GfxInfo);
	~LED();
	void Operate();	// set the status to high or low
	
	
	void Draw(Output* pOut);	//Draws 2-input gate
	virtual OutputPin* getoutputpinlocation(int&x , int&y);
	int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual InputPin* getinputpin(int&x , int&y , int n);

	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s);
	virtual void select(Output* pout);
	virtual void unselect(Output* pout);
	virtual void deletecmpn(Output *pOut , ApplicationManager* pApp);

};
#endif
