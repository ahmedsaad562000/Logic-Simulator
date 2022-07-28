#pragma once

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate:public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
public:
	Gate(int r_Inputs, int r_FanOut);
		bool InArea(int x , int y);
	   virtual void select(Output* pOut);
	virtual void unselect(Output* pOut);
		virtual InputPin* getinputpin(int&x , int&y , int n) = 0;
		OutputPin* getoutputpinlocation(int&x , int&y);
		virtual void deletecmpn(Output *pOut , ApplicationManager* pApp);

	

};


