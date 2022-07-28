#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}


void Output::Printlabel(string msg , int x , int y) const
{
	
	
	int MsgX = x;
	int MsgY = y;
	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.DrawColor); 
	pWind->DrawString(MsgX, MsgY, msg);
}


//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearToolbarArea() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight );
	
}
void Output::Draw_rectangle_label(int x , int y , int size) const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle( x, y, x+12*size , y+28 );
	
}

void Output::Draw_rectangle_delete(GraphicsInfo r_gfxinfo) const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle( r_gfxinfo.x1-2 , r_gfxinfo.y1-2 ,r_gfxinfo.x2+2 ,r_gfxinfo.y2+2  );
	
}

void Output::flushmouse() const {
	pWind->FlushMouseQueue();
}

void Output::flushkey() const {
	pWind->FlushKeyQueue();
}


////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::ClearDrawingArea() const

{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
void Output::CreateDesignToolBar() const
{
	ClearToolbarArea();
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_ADD] = "images\\Menu\\add.jpg";
	MenuItemImages[ITM_select] = "images\\Menu\\Select.jpg";
	
	
	MenuItemImages[ITM_DLT] = "images\\Menu\\delete.jpg";
	MenuItemImages[ITM_SVE] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_LAD] = "images\\Menu\\load.jpg";
	MenuItemImages[ITM_CPY] = "images\\Menu\\copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\cut.jpg";
	MenuItemImages[ITM_PST] = "images\\Menu\\paste.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\undo.jpg";
	MenuItemImages[ITM_Editconnection] = "images\\Menu\\editConnection.jpg";
	MenuItemImages[ITM_SIMULATE] = "images\\Menu\\simulate.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT	; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}


void Output::CreateDesignToolBar2() const
{
	ClearToolbarArea();
	UI.AppMode = DESIGN2;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_ADD_NO];
	MenuItemImages[ITM_ADDgate] = "images\\Menu\\addgate.jpg";
	MenuItemImages[ITM_SWITCH]  = "images\\Menu\\switch.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\led.jpg";
	MenuItemImages[ITM_CON] = "images\\Menu\\connect.jpg";
	MenuItemImages[ITM_LBL] = "images\\Menu\\label.jpg";
	//TODO: Prepare image for each menu item and add it to the list
	MenuItemImages[ITM_BACK] = "images\\Menu\\back.jpg";
	


	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_ADD_NO; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}



void Output::CreateDesignToolBar3() const
{
	ClearToolbarArea();
	UI.AppMode = DESIGN3;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_GATE_NO];
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_OR2]  = "images\\Menu\\Menu_OR2.jpg";
	
	//TODO: Prepare image for each menu item and add it to the list
	MenuItemImages[ITM_Buff] = "images\\Menu\\Menu_Buff.jpg";
	MenuItemImages[ITM_INV] = "images\\Menu\\Menu_INV.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Menu_NAND2.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Menu_NOR2.jpg";
	MenuItemImages[ITM_XOR] = "images\\Menu\\Menu_XOR.jpg";
	MenuItemImages[ITM_XNOR] = "images\\Menu\\Menu_XNOR.jpg";

	MenuItemImages[ITM_NOR3] = "images\\Menu\\Menu_NOR3.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\Menu_AND3.jpg"; 
	MenuItemImages[ITM_XOR3] = "images\\Menu\\Menu_XOR3.jpg"; 
	MenuItemImages[ITM_BACK2] = "images\\Menu\\back2.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_GATE_NO; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(BLUE,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	ClearToolbarArea();
	UI.AppMode = SIMULATION;	//Simulation Mode
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_SwitchOnorOff]  = "images\\Menu\\SwitchOnorOff.jpg";
	MenuItemImages[ITM_Operate]  = "images\\Menu\\operate.jpg";
	MenuItemImages[ITM_TRUTH]  = "images\\Menu\\table.jpg";
	MenuItemImages[ITM_PROB] = "images\\Menu\\prob.jpg";
    MenuItemImages[ITM_DES] = "images\\Menu\\design.jpg";
    MenuItemImages[ITM_EXITSIM] = "images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ITM_UNDO2] = "images\\Menu\\undo.jpg";


	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);
	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)

	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_AND2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

//TODO: Add similar functions to draw all components

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_NAND2_Hi.jpg";
	else  
		GateImage="Images\\Gates\\Gate_NAND2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}

void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_OR2_Hi.jpg";
	else  
		GateImage="Images\\Gates\\Gate_OR2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_NOR2_Hi.jpg";
	else  
		GateImage="Images\\Gates\\Gate_NOR2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR2_Width, UI.NOR2_Height);
}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_XOR2_Hi.jpg";
	else  
		GateImage="Images\\Gates\\Gate_XOR2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_XNOR2_Hi.jpg";
	else  
		GateImage="Images\\Gates\\Gate_XNOR2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XNOR2_Width, UI.XNOR2_Height);
}

void Output::DrawNOT(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_INV_Hi.jpg";
	else  
		GateImage="Images\\Gates\\Gate_INV.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOT_Width, UI.NOT_Height);
}

void Output::DrawBuffer(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_Buffer_Hi.jpg";
	else  
		GateImage="Images\\Gates\\Gate_Buffer.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Buffer_Width, UI.Buffer_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_AND3_Hi.jpg";
	else  
		GateImage="Images\\Gates\\Gate_AND3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND3_Width, UI.AND3_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_NOR3_Hi.jpg";
	else  
		GateImage="Images\\Gates\\Gate_NOR3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR3_Width, UI.NOR3_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_XOR3_Hi.jpg";
	else  
		GateImage="Images\\Gates\\Gate_XOR3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR3_Width, UI.XOR3_Height);
}

void Output::DrawSwitch(GraphicsInfo r_GfxInfo, bool selected , bool onoroff) const
{
	
	string GateImage;
	if(onoroff){
		if(selected)
		GateImage="Images\\Switch\\SwitchOn_selected.jpg";
		else
        GateImage="Images\\Switch\\SwitchOn.jpg";
	}
	else{
	if(selected)
		GateImage="Images\\Switch\\SwitchOff_selected.jpg";
	else  
		GateImage="Images\\Switch\\SwitchOff.jpg";
	
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Switch_Width, UI.Switch_Height);
}

void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected , bool LEDOnorOff) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\LED\\Led_selected.jpg";
	else { 
		if(LEDOnorOff){
		GateImage="Images\\LED\\LEDOn.jpg";
		}
		else{
		GateImage="Images\\LED\\LEDOff.jpg";
		}
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}

void Output::DrwLine(GraphicsInfo r_GfxInfo){
	pWind->SetPen(WHITE);
if (r_GfxInfo.x1==r_GfxInfo.x2 || r_GfxInfo.y1==r_GfxInfo.y2)
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
	else pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, ((r_GfxInfo.x1+ r_GfxInfo.x2)/2), r_GfxInfo.y1);
	     pWind->DrawLine(((r_GfxInfo.x1+ r_GfxInfo.x2)/2), r_GfxInfo.y1, ((r_GfxInfo.x1+ r_GfxInfo.x2)/2), r_GfxInfo.y2);
		 pWind->DrawLine(((r_GfxInfo.x1+ r_GfxInfo.x2)/2), r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);

}

void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection
	if (selected)

		
	{
		pWind->SetPen(RED);
	if (r_GfxInfo.x1==r_GfxInfo.x2 || r_GfxInfo.y1==r_GfxInfo.y2)
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
	else pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, ((r_GfxInfo.x1+ r_GfxInfo.x2)/2), r_GfxInfo.y1);
	     pWind->DrawLine(((r_GfxInfo.x1+ r_GfxInfo.x2)/2), r_GfxInfo.y1, ((r_GfxInfo.x1+ r_GfxInfo.x2)/2), r_GfxInfo.y2);
		 pWind->DrawLine(((r_GfxInfo.x1+ r_GfxInfo.x2)/2), r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
	}
	else if (!selected)
	{
		pWind->SetPen(BLUE);
	if (r_GfxInfo.x1==r_GfxInfo.x2 || r_GfxInfo.y1==r_GfxInfo.y2)
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
	else pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, ((r_GfxInfo.x1+ r_GfxInfo.x2)/2), r_GfxInfo.y1);
	     pWind->DrawLine(((r_GfxInfo.x1+ r_GfxInfo.x2)/2), r_GfxInfo.y1, ((r_GfxInfo.x1+ r_GfxInfo.x2)/2), r_GfxInfo.y2);
		 pWind->DrawLine(((r_GfxInfo.x1+ r_GfxInfo.x2)/2), r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
	}
}


Output::~Output()
{
	delete pWind;
}
