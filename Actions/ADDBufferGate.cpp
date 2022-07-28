#include "AddBufferGate.h"
#include "..\ApplicationManager.h"

AddBufferGate::AddBufferGate(ApplicationManager* pApp) :Action(pApp)
{
	execute = true;
}

AddBufferGate::~AddBufferGate(void)
{
}

void AddBufferGate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("BUFFER Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	if (!(Cy >= UI.ToolBarHeight + 40 && Cy < UI.height - 40 - UI.StatusBarHeight && Cx>40 && Cx < 960))
	{
		pOut->PrintMsg("NOT IN the allowed DRAWING AREA! , NOTHING is ADDED! , click to advance");
		pIn->GetPointClicked(Cx, Cy);
		execute = false;
	}
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddBufferGate::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	if(execute){
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	BUFFER* pA = new BUFFER(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}
}
void AddBufferGate::Undo()
{}

void AddBufferGate::Redo()
{}