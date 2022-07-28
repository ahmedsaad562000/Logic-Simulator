#include "Input.h"
#include "Output.h"
#include<conio.h>
#include<iostream>


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}


//
void Input::waitpress(char &c)
{
	pWind->WaitKeyPress(c);	//Wait for key click
}
string Input::GetSrting(Output *pOut){
	

	pOut->flushkey();

string inn = "";

int asciicode;
const int back = 8;
const int esc = 27;
int i =0;
while(true)
{
	char key;
	waitpress(key);
	pOut->ClearStatusBar();
	asciicode = int(key);
	
			if (asciicode == back){
				if(i==0){
				inn.erase(i,1);
				i= i-1;
				}
				if(i>0){
					inn.erase(i,2);
				i= i-2;
				}
				
				
			pOut->ClearStatusBar();
         	pOut->PrintMsg(inn);
			}
			else if (asciicode == esc){
				
				inn = "";
				pOut->ClearStatusBar();
         	
				break;
			}
			else if (asciicode == 13 || asciicode == 10){
                pOut->ClearStatusBar();
                       break;
			}
				
			else{

			inn.push_back(key);
			pOut->ClearStatusBar();
         	pOut->PrintMsg(inn);
			}
			i = i+1;
}

	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar
//

pOut->flushmouse();
	return inn;

}
//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_ADD: return ADD;
			case ITM_select: return Menuselect;
			case ITM_DLT: return DEL;
			case ITM_SVE: return SAVE;
			case ITM_LAD: return LOAD;
			case ITM_CPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PST: return PST;
			case ITM_UNDO: return UNDO;
			
			case ITM_Editconnection: return EDIT_CONNECTION;
			case ITM_SIMULATE: return SIM_MODE;
			case ITM_EXIT: return EXIT;	
			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar

			}
		
		}
	
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}	
	else if (UI.AppMode == DESIGN2 ){
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_ADDgate: return ADDgate;
			case ITM_CON: return ADD_CONNECTION;
			case ITM_SWITCH: return ADD_Switch;
			case ITM_LED: return ADD_LED;
				case ITM_LBL: return ADD_Label;
			case ITM_BACK: return BACK;
		
			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar

			}
		
		}
	
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;

	
	
	}

	else if(UI.AppMode == DESIGN3){
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_Buff : return ADD_Buff;
			case ITM_INV: return ADD_INV;
			case ITM_NAND2: return ADD_NAND_GATE_2;
			case ITM_NOR2: return ADD_NOR_GATE_2;
			case ITM_XOR: return ADD_XOR_GATE_2;
			case ITM_XNOR: return ADD_XNOR_GATE_2;
			
			case ITM_NOR3: return ADD_NOR_GATE_3;
			case ITM_AND3: return ADD_AND_GATE_3;
			case ITM_XOR3: return ADD_XOR_GATE_3;
			case ITM_BACK2: return BACK2;
			
			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar

			}
		
		}
	
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}	
	
	

	else if (UI.AppMode == SIMULATION)	//Application is in Simulation mode
	{
		if ( y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			
			case ITM_SwitchOnorOff: return Change_Switch;
				case ITM_Operate: return OPERATE;
			case ITM_TRUTH: return Create_TruthTable;
			case ITM_PROB: return PROB;
			case ITM_UNDO2: return UNDO;
			
			case ITM_DES: return DSN_MODE;
			case ITM_EXITSIM: return EXIT;
			default: return SIM_TOOL;//user want to select/unselect a component
			}
			
		}
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
		
	}
	

}


Input::~Input()
{
}
