#ifndef _NOT_H
#define _NOT_H



#include "Gate.h"

class NOT :public Gate
{
public:
	NOT(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the NOT gate
	virtual void Draw(Output* pOut);	//Draws NOT gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual InputPin* getinputpin(int& x, int& y, int n);

};

#endif
