#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"

class InputPin;
class OutputPin;
class ApplicationManager;
//Base class for classes Gate, Switch, and LED.
class Component
{
	
		static int cmpnid;
private:
	string m_Label;
	int ID;
	
protected:
	CompnType type;
	bool selected;
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	bool InArea(int x , int y) ;
	int getID();
	void setlabel(string s);
	string getlabel();
	CompnType gettype();
	void getlabelplace(int &x , int &y);
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1
	bool isselected();
	void setselected(bool select);
	virtual void select(Output* pOut)=0;
	virtual void unselect(Output* pOut)=0;
	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual void deletecmpn(Output *pOut , ApplicationManager* pApp) = 0;
	bool getselected();
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
