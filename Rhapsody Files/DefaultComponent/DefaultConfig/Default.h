/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Default
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\Default.h
*********************************************************************/

#ifndef Default_H
#define Default_H

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
#include <event.h>
//## auto_generated
class AVSystem;

//## classInstance itsAirConditioner
class AirConditioner;

//## classInstance itsCO2Sensor
class CO2Sensor;

//## auto_generated
class DTSR;

//## auto_generated
class EnvironMent;

//## auto_generated
class ExternalLighting;

//## classInstance itsFireAlarm
class FireAlarm;

//## classInstance itsFireSensor
class FireSensor;

//## auto_generated
class GUI;

//## classInstance itsHVAC
class HVAC;

//## classInstance itsIntelligentLamp
class IntelligentLamp;

//## auto_generated
class Interaction;

//## auto_generated
class Interconnection;

//## auto_generated
class MovementDetectionSensor;

//## classInstance itsOccupancySensor
class OccupancySensor;

//## auto_generated
class SASystem;

//## auto_generated
class SoftwareController;

//## auto_generated
class Temperature;

//## classInstance itsTemperatureSensor
class TemperatureSensor;

//## auto_generated
class TouchPanel;

//## auto_generated
class UCDynamicLightingBlk;

//## auto_generated
class UCFireBlk;

//## auto_generated
class UCHVACBlk;

//## classInstance itsVentilation
class Ventilation;

//## auto_generated
class VisualEntity;

//## auto_generated
class Weather;

//## auto_generated
class a;

//## package Default


//#[ type DEFAULT_BUFLEN
#define DEFAULT_BUFLEN 1024
//#]

//## classInstance itsAirConditioner
extern AirConditioner itsAirConditioner;

//## classInstance itsCO2Sensor
extern CO2Sensor itsCO2Sensor;

//## classInstance itsFireAlarm
extern FireAlarm itsFireAlarm;

//## classInstance itsFireSensor
extern FireSensor itsFireSensor;

//## classInstance itsHVAC
extern HVAC itsHVAC;

//## classInstance itsIntelligentLamp
extern IntelligentLamp itsIntelligentLamp;

//## classInstance itsOccupancySensor
extern OccupancySensor itsOccupancySensor;

//## classInstance itsTemperatureSensor
extern TemperatureSensor itsTemperatureSensor;

//## classInstance itsVentilation
extern Ventilation itsVentilation;

//## auto_generated
void Default_initRelations(void);

//## auto_generated
bool Default_startBehavior(void);

//#[ ignore
class Default_OMInitializer {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    Default_OMInitializer(void);
    
    //## auto_generated
    ~Default_OMInitializer(void);
};
//#]

//## event event_54()
class event_54 : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevent_54;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    event_54(void);
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevent_54 : virtual public AOMEvent {
    DECLARE_META_EVENT(event_54)
};
//#]
#endif // _OMINSTRUMENT

//#[ ignore
extern const IOxfEvent::ID event_54_Default_id;
//#]

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Default.h
*********************************************************************/
