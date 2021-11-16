/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: Default
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\Default.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Default.h"
//## classInstance itsAirConditioner
#include "AirConditioner.h"
//## classInstance itsCO2Sensor
#include "CO2Sensor.h"
//## classInstance itsFireAlarm
#include "FireAlarm.h"
//## classInstance itsFireSensor
#include "FireSensor.h"
//## classInstance itsHVAC
#include "HVAC.h"
//## classInstance itsIntelligentLamp
#include "IntelligentLamp.h"
//## classInstance itsOccupancySensor
#include "OccupancySensor.h"
//## classInstance itsTemperatureSensor
#include "TemperatureSensor.h"
//## classInstance itsVentilation
#include "Ventilation.h"
//## auto_generated
#include "a.h"
//## auto_generated
#include "AVSystem.h"
//## auto_generated
#include "DTSR.h"
//## auto_generated
#include "EnvironMent.h"
//## auto_generated
#include "ExternalLighting.h"
//## auto_generated
#include "GUI.h"
//## auto_generated
#include "Interaction.h"
//## auto_generated
#include "Interconnection.h"
//## auto_generated
#include "MovementDetectionSensor.h"
//## auto_generated
#include "SASystem.h"
//## auto_generated
#include "SoftwareController.h"
//## auto_generated
#include "Temperature.h"
//## auto_generated
#include "TouchPanel.h"
//## auto_generated
#include "UCDynamicLightingBlk.h"
//## auto_generated
#include "UCFireBlk.h"
//## auto_generated
#include "UCHVACBlk.h"
//## auto_generated
#include "VisualEntity.h"
//## auto_generated
#include "Weather.h"
//#[ ignore
#define event_54_SERIALIZE OM_NO_OP

#define event_54_UNSERIALIZE OM_NO_OP

#define event_54_CONSTRUCTOR event_54()
//#]

//## package Default


//## classInstance itsAirConditioner
AirConditioner itsAirConditioner;

//## classInstance itsCO2Sensor
CO2Sensor itsCO2Sensor;

//## classInstance itsFireAlarm
FireAlarm itsFireAlarm;

//## classInstance itsFireSensor
FireSensor itsFireSensor;

//## classInstance itsHVAC
HVAC itsHVAC;

//## classInstance itsIntelligentLamp
IntelligentLamp itsIntelligentLamp;

//## classInstance itsOccupancySensor
OccupancySensor itsOccupancySensor;

//## classInstance itsTemperatureSensor
TemperatureSensor itsTemperatureSensor;

//## classInstance itsVentilation
Ventilation itsVentilation;

#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */);

static void RenameGlobalInstances(void);

IMPLEMENT_META_PACKAGE(Default, Default)
#endif // _OMINSTRUMENT

void Default_initRelations(void) {
    {
        {
            itsFireAlarm.setShouldDelete(false);
        }
        {
            itsFireSensor.setShouldDelete(false);
        }
        {
            itsHVAC.setShouldDelete(false);
        }
        {
            itsTemperatureSensor.setShouldDelete(false);
        }
        {
            itsCO2Sensor.setShouldDelete(false);
        }
        {
            itsAirConditioner.setShouldDelete(false);
        }
        {
            itsVentilation.setShouldDelete(false);
        }
        {
            itsIntelligentLamp.setShouldDelete(false);
        }
        {
            itsOccupancySensor.setShouldDelete(false);
        }
    }
    itsFireSensor.setItsFireAlarm(&itsFireAlarm);
    itsHVAC.setItsTemperatureSensor(&itsTemperatureSensor);
    itsCO2Sensor.setItsHVAC(&itsHVAC);
    itsHVAC.setItsFireSensor(&itsFireSensor);
    itsHVAC.setItsFireAlarm(&itsFireAlarm);
    itsHVAC.setItsAirConditioner(&itsAirConditioner);
    itsTemperatureSensor.setItsAirConditioner(&itsAirConditioner);
    itsHVAC.setItsVentilation(&itsVentilation);
    itsCO2Sensor.setItsVentilation(&itsVentilation);
    itsAirConditioner.setItsTemperatureSensor_1(&itsTemperatureSensor);
    itsVentilation.setItsHVAC_1(&itsHVAC);
    itsCO2Sensor.setItsOccupancySensor(&itsOccupancySensor);
    itsTemperatureSensor.setItsOccupancySensor(&itsOccupancySensor);
    
    #ifdef _OMINSTRUMENT
    RenameGlobalInstances();
    #endif // _OMINSTRUMENT
}

bool Default_startBehavior(void) {
    bool done = true;
    if(done == true)
        {
            done = itsAirConditioner.startBehavior();
        }
    if(done == true)
        {
            done = itsCO2Sensor.startBehavior();
        }
    if(done == true)
        {
            done = itsFireAlarm.startBehavior();
        }
    if(done == true)
        {
            done = itsFireSensor.startBehavior();
        }
    if(done == true)
        {
            done = itsHVAC.startBehavior();
        }
    if(done == true)
        {
            done = itsIntelligentLamp.startBehavior();
        }
    if(done == true)
        {
            done = itsOccupancySensor.startBehavior();
        }
    if(done == true)
        {
            done = itsTemperatureSensor.startBehavior();
        }
    if(done == true)
        {
            done = itsVentilation.startBehavior();
        }
    return done;
}

#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */) {
}

static void RenameGlobalInstances(void) {
    OM_SET_INSTANCE_NAME(&itsFireAlarm, FireAlarm, "itsFireAlarm", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&itsFireSensor, FireSensor, "itsFireSensor", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&itsHVAC, HVAC, "itsHVAC", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&itsTemperatureSensor, TemperatureSensor, "itsTemperatureSensor", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&itsCO2Sensor, CO2Sensor, "itsCO2Sensor", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&itsAirConditioner, AirConditioner, "itsAirConditioner", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&itsVentilation, Ventilation, "itsVentilation", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&itsIntelligentLamp, IntelligentLamp, "itsIntelligentLamp", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&itsOccupancySensor, OccupancySensor, "itsOccupancySensor", AOMNoMultiplicity);
}
#endif // _OMINSTRUMENT

//#[ ignore
Default_OMInitializer::Default_OMInitializer(void) {
    Default_initRelations();
    (void) Default_startBehavior();
}

Default_OMInitializer::~Default_OMInitializer(void) {
}
//#]

//## event event_54()
event_54::event_54(void) : OMEvent() {
    NOTIFY_EVENT_CONSTRUCTOR(event_54)
    setId(event_54_Default_id);
}

//#[ ignore
const IOxfEvent::ID event_54_Default_id(18601);
//#]

IMPLEMENT_META_EVENT_P(event_54, Default, Default, event_54())

/*********************************************************************
	File Path	: component_3\DefaultConfig\Default.cpp
*********************************************************************/
