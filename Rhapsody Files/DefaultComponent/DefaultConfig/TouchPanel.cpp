/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TouchPanel
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\TouchPanel.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "TouchPanel.h"
//#[ ignore
#define Default_TouchPanel_TouchPanel_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class TouchPanel
TouchPanel::TouchPanel(void) {
    NOTIFY_CONSTRUCTOR(TouchPanel, TouchPanel(), 0, Default_TouchPanel_TouchPanel_SERIALIZE);
}

TouchPanel::~TouchPanel(void) {
    NOTIFY_DESTRUCTOR(~TouchPanel, true);
}

#ifdef _OMINSTRUMENT
IMPLEMENT_META_P(TouchPanel, Default, Default, false, OMAnimatedTouchPanel)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\TouchPanel.cpp
*********************************************************************/
