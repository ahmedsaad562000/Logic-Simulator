#pragma once
#include "action.h"
class ChangeSwitch :
	public Action
{
	int Cx , Cy;
public:
	ChangeSwitch(ApplicationManager *pApp);
	~ChangeSwitch();
	void ReadActionParameters();
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
};

