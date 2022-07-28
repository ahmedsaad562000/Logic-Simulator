#include "Select.h"
#include"..\ApplicationManager.h"

Select::Select(ApplicationManager *pApp):Action(pApp)
{
	execute = true;

}


Select::~Select()
{
}


void Select::ReadActionParameters(){
	
	

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Select , Select Component");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	if (!(Cy >= UI.ToolBarHeight  && Cy < UI.height - UI.StatusBarHeight && Cx>0 && Cx < 1000))
	{
		pOut->PrintMsg("NOT IN DRAWING AREA! , NOTHING is Selected! , click to advance");
		pIn->GetPointClicked(Cx, Cy);
		execute = false;
	}

	//Clear Status Bar
	pOut->ClearStatusBar();

	
}
void Select::Execute(){
	ReadActionParameters();
	if(execute){
	Component* cmpn = pManager->getcomponent(Cx,Cy);
	pManager->unselectall();


	if(!cmpn){
		pManager->GetOutput()->PrintMsg("No Component in this location. , Unselect ALL");

	}
	else{
		
		cmpn->select(pManager->GetOutput());
		
		}
	


}
}
	//To undo this action (code depends on action type)
void Select::Undo(){}

	//To redo this action (code depends on action type)
 void Select::Redo(){
	
	}