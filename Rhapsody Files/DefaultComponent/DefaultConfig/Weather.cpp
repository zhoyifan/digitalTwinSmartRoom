/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Weather
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\Weather.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Weather.h"
//#[ ignore
#define Default_Weather_Weather_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Weather
Weather::Weather(void) {
    NOTIFY_CONSTRUCTOR(Weather, Weather(), 0, Default_Weather_Weather_SERIALIZE);
}

Weather::~Weather(void) {
    NOTIFY_DESTRUCTOR(~Weather, true);
}

#ifdef _OMINSTRUMENT
IMPLEMENT_META_P(Weather, Default, Default, false, OMAnimatedWeather)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Weather.cpp
*********************************************************************/
