#include "AddAND3gate.h"
#include "..\ApplicationManager.h"

AddAND3gate::AddAND3gate(ApplicationManager* pApp) :Action(pApp)
{
	execute = true;
}

AddAND3gate::~AddAND3gate(void)
{
}

  
void AddAND3gate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input AND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	if (!(Cy >= UI.ToolBarHeight + 40 && Cy < UI.height - 40 - UI.StatusBarHeight && Cx>40 && Cx < 960))
	{
		pOut->PrintMsg("NOT IN the allowed DRAWING AREA! , NOTHING is ADDED! , click to advance");
		pIn->GetPointClicked(Cx, Cy);
		execute = false;
	}
	
	pOut->ClearStatusBar();
}

void AddAND3gate::Execute()
{
	ReadActionParameters();
	if(execute){
	//Get Center point of the Gate
	

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	AND3* pA = new AND3(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}
	
}
void AddAND3gate::Undo()
{}

void AddAND3gate::Redo()
{}
