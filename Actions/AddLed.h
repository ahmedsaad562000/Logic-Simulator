
#ifndef _ADD_LED_H
#define _ADD_LED_H

#include "action.h"
#include "..\Components\LED.h"

class AddLed :
	public Action
{
	int Cx, Cy;	//Center point of the led
	int x1, y1, x2, y2;	//Two corners of the rectangluar area

public:
		AddLed(ApplicationManager *pApp);
	virtual ~AddLed();

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif

