#ifndef _ADD_LABEL_H
#define _ADD_LABEL_H
#include "..\Components/Component.h"
#include "action.h"
class AddLabel :public Action
{
	int Cx, Cy;	//Center point of the label
	
public:
	AddLabel(ApplicationManager *pApp);
	~AddLabel();
	void ReadActionParameters();
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
};
#endif
