/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: GUI
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\GUI.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "GUI.h"
//#[ ignore
#define Default_GUI_GUI_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class GUI
GUI::GUI(void) {
    NOTIFY_CONSTRUCTOR(GUI, GUI(), 0, Default_GUI_GUI_SERIALIZE);
}

GUI::~GUI(void) {
    NOTIFY_DESTRUCTOR(~GUI, true);
}

#ifdef _OMINSTRUMENT
IMPLEMENT_META_P(GUI, Default, Default, false, OMAnimatedGUI)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\GUI.cpp
*********************************************************************/
