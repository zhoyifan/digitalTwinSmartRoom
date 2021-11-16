/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: EnvironMent
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\EnvironMent.h
*********************************************************************/

#ifndef EnvironMent_H
#define EnvironMent_H

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
//## classInstance itsExternalLighting
#include "ExternalLighting.h"
//## classInstance itsTemperature
#include "Temperature.h"
//## classInstance itsWeather
#include "Weather.h"
//## link itsDTSR
class DTSR;

//## package Default

//## class EnvironMent
class EnvironMent {
#ifdef _OMINSTRUMENT
    OM_DECLARE_COMPOSITE_OFFSET
#endif // _OMINSTRUMENT

    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedEnvironMent;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    EnvironMent(void);
    
    //## auto_generated
    ~EnvironMent(void);
    
    ////    Additional operations    ////
    
    //## auto_generated
    const DTSR* getItsDTSR(void) const;
    
    //## auto_generated
    void setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    const ExternalLighting* getItsExternalLighting(void) const;
    
    //## auto_generated
    const Temperature* getItsTemperature(void) const;
    
    //## auto_generated
    const Weather* getItsWeather(void) const;

protected :

    //## auto_generated
    void cleanUpRelations(void);
    
    ////    Relations and components    ////

private :

    DTSR* itsDTSR;		//## link itsDTSR
    
    ExternalLighting itsExternalLighting;		//## classInstance itsExternalLighting
    
    Temperature itsTemperature;		//## classInstance itsTemperature
    
    Weather itsWeather;		//## classInstance itsWeather
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    void _setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    void _clearItsDTSR(void);
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedEnvironMent : virtual public AOMInstance {
    DECLARE_META(EnvironMent, OMAnimatedEnvironMent)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: component_3\DefaultConfig\EnvironMent.h
*********************************************************************/
