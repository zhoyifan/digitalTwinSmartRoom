/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: Temperature
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\Temperature.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Temperature.h"
//#[ ignore
#define Default_Temperature_Temperature_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Temperature
Temperature::Temperature(void) {
    NOTIFY_CONSTRUCTOR(Temperature, Temperature(), 0, Default_Temperature_Temperature_SERIALIZE);
}

Temperature::~Temperature(void) {
    NOTIFY_DESTRUCTOR(~Temperature, true);
}

#ifdef _OMINSTRUMENT
IMPLEMENT_META_P(Temperature, Default, Default, false, OMAnimatedTemperature)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: component_3\DefaultConfig\Temperature.cpp
*********************************************************************/
