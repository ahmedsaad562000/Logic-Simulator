#include "Connection.h"
#include "../ApplicationManager.h"
Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
	
{
	selected = false;
	type = CONNECTION;
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}

void Connection::select(Output* pout)
{
	if (selected)
	{
	unselect(pout);
	}
	else
	{
		selected = true;
	
	}
}
void Connection::unselect(Output* pout)
{
	selected = false;
	
}

InputPin* Connection::getinputpin(int&x , int&y , int n){return NULL;}
OutputPin* Connection::getoutputpinlocation(int&x , int&y){return NULL;}

void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
	(DstPin->getComponent())->Operate();
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo , selected);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

 void Connection::deletecmpn(Output *pOut ,  ApplicationManager* pApp){
	 
	 SrcPin->removeconnection(this);
	 DstPin->disconnect();
	 pOut->DrwLine(m_GfxInfo);
	 int y;
	 if(m_GfxInfo.y1>m_GfxInfo.y2){
		  y = m_GfxInfo.y2;
	 }
	 else{y = m_GfxInfo.y1;}
	 pOut->Draw_rectangle_label((m_GfxInfo.x1 + m_GfxInfo.x2)/2 , y-28 , Component::getlabel().size());
	 pApp->RemoveComponent((Component*)this);
}