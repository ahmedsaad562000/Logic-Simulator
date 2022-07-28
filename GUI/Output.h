#pragma once
#include "..\Defs.h"
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output(); // Performs the Window Initialization
	Input* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;
	void DrwLine(GraphicsInfo r_GfxInfo);
	void CreateDesignToolBar() const;	//Tool bar of the design mode
	void CreateDesignToolBar2() const;
	void CreateDesignToolBar3() const;
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar
	void Draw_rectangle_label(int x , int y , int size) const;
void Draw_rectangle_delete(GraphicsInfo r_gfxinfo) const;
	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area
	void ClearToolbarArea() const;
	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window
	void flushmouse() const;
	void flushkey() const;
	
	// Draws 2-input AND gate
	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	///TODO: Make similar functions for drawing all other gates, switch, and LED, .. etc
	void DrawOR2(GraphicsInfo r_GfxInfo, bool selected ) const;
	void DrawNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawBuffer(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOT(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawSwitch(GraphicsInfo r_GfxInfo, bool selected = false , bool onoroff = false) const;
	void DrawLED(GraphicsInfo r_GfxInfo, bool selected = false , bool LedOnorOff = false) const;

	// Draws Connection
	void DrawConnection(GraphicsInfo r_GfxInfo, bool selected = true) const;
	
	void PrintMsg(string msg) const;
void Output::Printlabel(string msg , int x , int y) const;
	//Print a message on Status bar
	

	~Output();
};
