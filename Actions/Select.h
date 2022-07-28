#ifndef _SELECT_H
#define _SELECT_H
#include "action.h"

class Select :
	public Action
{
	bool indraw;
	int Cx , Cy;
public:
	Select(ApplicationManager *pApp);
	~Select();
	void ReadActionParameters();
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
};
#endif
