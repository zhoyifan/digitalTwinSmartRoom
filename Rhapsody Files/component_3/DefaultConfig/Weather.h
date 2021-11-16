/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: Weather
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\Weather.h
*********************************************************************/

#ifndef Weather_H
#define Weather_H

//## auto_generated
#include <oxf.h>
//## auto_generated
#include <aom.h>
//## auto_generated
#include "winsock2.h"
//## auto_generated
#include "stdio.h"
//## auto_generated
#include "windows.h"
//## auto_generated
#include "iostream"
//## auto_generated
#include "Ws2tcpip.h"
//## auto_generated
#include "string.h"
//## auto_generated
#include "Default.h"
//## package Default

//## class Weather
class Weather {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedWeather;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Weather(void);
    
    //## auto_generated
    ~Weather(void);
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedWeather : virtual public AOMInstance {
    DECLARE_META(Weather, OMAnimatedWeather)
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: component_3\DefaultConfig\Weather.h
*********************************************************************/
