#include "ChangeSwitch.h"
#include"..\ApplicationManager.h"

ChangeSwitch::ChangeSwitch(ApplicationManager *pApp):Action(pApp)
{
execute = true;	

}


ChangeSwitch::~ChangeSwitch()
{
}


void ChangeSwitch::ReadActionParameters(){
	
	

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Set Switch on or off , Select Switch");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
		if (!(Cy >= UI.ToolBarHeight && Cy < UI.height - UI.StatusBarHeight && Cx>0 && Cx < 1000))
	{
		pOut->PrintMsg("NOT IN the allowed DRAWING AREA! , NOTHING is ADDED! , click to advance");
		pIn->GetPointClicked(Cx, Cy);
		execute = false;
	}
		if(execute){
	Component* cmpn = pManager->getcomponent(Cx , Cy);
	if(cmpn){
	if(!(cmpn->gettype() == SWITCH)){
pOut->PrintMsg("No switch selected , click to advance");
execute = false;
	pIn->GetPointClicked(Cx, Cy);

	}
		}
	else{
	pOut->PrintMsg("No component selected , click to advance");
execute = false;
	pIn->GetPointClicked(Cx, Cy);
	}
	//Clear Status Bar
		pOut->ClearStatusBar();

		}
}
void ChangeSwitch::Execute(){
	ReadActionParameters();
	if(execute){	
	Switch* cmpn = (Switch*)pManager->getcomponent(Cx,Cy);
	


	if(!cmpn){
		pManager->GetOutput()->PrintMsg("No Component in this location.");

	}
	else{
		
		cmpn->switchOnorOff();
		
		}
	

	}
}

	//To undo this action (code depends on action type)
void ChangeSwitch::Undo(){}

	//To redo this action (code depends on action type)
 void ChangeSwitch::Redo(){
	
	}
