/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: DTSR
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\DTSR.h
*********************************************************************/

#ifndef DTSR_H
#define DTSR_H

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
//## auto_generated
#include "omcollec.h"
//## classInstance itsUCDynamicLightingBlk
#include "UCDynamicLightingBlk.h"
//## classInstance itsUCFireBlk
#include "UCFireBlk.h"
//## classInstance itsUCHVACBlk
#include "UCHVACBlk.h"
//## link itsAVSystem
class AVSystem;

//## link itsCO2Sensor
class CO2Sensor;

//## link itsEnvironMent
class EnvironMent;

//## link itsFireAlarm
class FireAlarm;

//## link itsFireSensor
class FireSensor;

//## link itsHVAC
class HVAC;

//## link itsIntelligentLamp
class IntelligentLamp;

//## link itsInteraction
class Interaction;

//## link itsInterconnection
class Interconnection;

//## link itsMovementDetectionSensor
class MovementDetectionSensor;

//## link itsOccupancySensor
class OccupancySensor;

//## link itsSASystem
class SASystem;

//## link itsSoftwareController
class SoftwareController;

//## link itsTemperatureSensor
class TemperatureSensor;

//## link itsUser
class User;

//## link itsVisualEntity
class VisualEntity;

//## package Default

//## class DTSR
class DTSR {
#ifdef _OMINSTRUMENT
    OM_DECLARE_COMPOSITE_OFFSET
#endif // _OMINSTRUMENT

    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedDTSR;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    DTSR(void);
    
    //## auto_generated
    ~DTSR(void);
    
    ////    Additional operations    ////
    
    //## auto_generated
    const AVSystem* getItsAVSystem(void) const;
    
    //## auto_generated
    void setItsAVSystem(AVSystem* const p_AVSystem);
    
    //## auto_generated
    const CO2Sensor* getItsCO2Sensor(void) const;
    
    //## auto_generated
    void setItsCO2Sensor(CO2Sensor* const p_CO2Sensor);
    
    //## auto_generated
    const EnvironMent* getItsEnvironMent(void) const;
    
    //## auto_generated
    void setItsEnvironMent(EnvironMent* const p_EnvironMent);
    
    //## auto_generated
    const FireAlarm* getItsFireAlarm(void) const;
    
    //## auto_generated
    void setItsFireAlarm(FireAlarm* const p_FireAlarm);
    
    //## auto_generated
    const FireSensor* getItsFireSensor(void) const;
    
    //## auto_generated
    void setItsFireSensor(FireSensor* const p_FireSensor);
    
    //## auto_generated
    const HVAC* getItsHVAC(void) const;
    
    //## auto_generated
    void setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    OMIterator<IntelligentLamp*> getItsIntelligentLamp(void) const;
    
    //## auto_generated
    void addItsIntelligentLamp(IntelligentLamp* const p_IntelligentLamp);
    
    //## auto_generated
    void removeItsIntelligentLamp(IntelligentLamp* p_IntelligentLamp);
    
    //## auto_generated
    void clearItsIntelligentLamp(void);
    
    //## auto_generated
    const Interaction* getItsInteraction(void) const;
    
    //## auto_generated
    void setItsInteraction(Interaction* const p_Interaction);
    
    //## auto_generated
    const Interconnection* getItsInterconnection(void) const;
    
    //## auto_generated
    void setItsInterconnection(Interconnection* const p_Interconnection);
    
    //## auto_generated
    const MovementDetectionSensor* getItsMovementDetectionSensor(void) const;
    
    //## auto_generated
    void setItsMovementDetectionSensor(MovementDetectionSensor* const p_MovementDetectionSensor);
    
    //## auto_generated
    const OccupancySensor* getItsOccupancySensor(void) const;
    
    //## auto_generated
    void setItsOccupancySensor(OccupancySensor* const p_OccupancySensor);
    
    //## auto_generated
    const SASystem* getItsSASystem(void) const;
    
    //## auto_generated
    void setItsSASystem(SASystem* const p_SASystem);
    
    //## auto_generated
    const SoftwareController* getItsSoftwareController(void) const;
    
    //## auto_generated
    void setItsSoftwareController(SoftwareController* const p_SoftwareController);
    
    //## auto_generated
    const TemperatureSensor* getItsTemperatureSensor(void) const;
    
    //## auto_generated
    void setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor);
    
    //## auto_generated
    const UCDynamicLightingBlk* getItsUCDynamicLightingBlk(void) const;
    
    //## auto_generated
    const UCFireBlk* getItsUCFireBlk(void) const;
    
    //## auto_generated
    const UCHVACBlk* getItsUCHVACBlk(void) const;
    
    //## auto_generated
    const User* getItsUser(void) const;
    
    //## auto_generated
    void setItsUser(User* const p_User);
    
    //## auto_generated
    const VisualEntity* getItsVisualEntity(void) const;
    
    //## auto_generated
    void setItsVisualEntity(VisualEntity* const p_VisualEntity);

protected :

    //## auto_generated
    void cleanUpRelations(void);
    
    ////    Relations and components    ////

private :

    AVSystem* itsAVSystem;		//## link itsAVSystem
    
    CO2Sensor* itsCO2Sensor;		//## link itsCO2Sensor
    
    EnvironMent* itsEnvironMent;		//## link itsEnvironMent
    
    FireAlarm* itsFireAlarm;		//## link itsFireAlarm
    
    FireSensor* itsFireSensor;		//## link itsFireSensor
    
    HVAC* itsHVAC;		//## link itsHVAC
    
    OMCollection<IntelligentLamp*> itsIntelligentLamp;		//## link itsIntelligentLamp
    
    Interaction* itsInteraction;		//## link itsInteraction
    
    Interconnection* itsInterconnection;		//## link itsInterconnection
    
    MovementDetectionSensor* itsMovementDetectionSensor;		//## link itsMovementDetectionSensor
    
    OccupancySensor* itsOccupancySensor;		//## link itsOccupancySensor
    
    SASystem* itsSASystem;		//## link itsSASystem
    
    SoftwareController* itsSoftwareController;		//## link itsSoftwareController
    
    TemperatureSensor* itsTemperatureSensor;		//## link itsTemperatureSensor
    
    UCDynamicLightingBlk itsUCDynamicLightingBlk;		//## classInstance itsUCDynamicLightingBlk
    
    UCFireBlk itsUCFireBlk;		//## classInstance itsUCFireBlk
    
    UCHVACBlk itsUCHVACBlk;		//## classInstance itsUCHVACBlk
    
    User* itsUser;		//## link itsUser
    
    VisualEntity* itsVisualEntity;		//## link itsVisualEntity
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsAVSystem(AVSystem* const p_AVSystem);
    
    //## auto_generated
    void _setItsAVSystem(AVSystem* const p_AVSystem);
    
    //## auto_generated
    void _clearItsAVSystem(void);
    
    //## auto_generated
    void __setItsCO2Sensor(CO2Sensor* const p_CO2Sensor);
    
    //## auto_generated
    void _setItsCO2Sensor(CO2Sensor* const p_CO2Sensor);
    
    //## auto_generated
    void _clearItsCO2Sensor(void);
    
    //## auto_generated
    void __setItsEnvironMent(EnvironMent* const p_EnvironMent);
    
    //## auto_generated
    void _setItsEnvironMent(EnvironMent* const p_EnvironMent);
    
    //## auto_generated
    void _clearItsEnvironMent(void);
    
    //## auto_generated
    void __setItsFireAlarm(FireAlarm* const p_FireAlarm);
    
    //## auto_generated
    void _setItsFireAlarm(FireAlarm* const p_FireAlarm);
    
    //## auto_generated
    void _clearItsFireAlarm(void);
    
    //## auto_generated
    void __setItsFireSensor(FireSensor* const p_FireSensor);
    
    //## auto_generated
    void _setItsFireSensor(FireSensor* const p_FireSensor);
    
    //## auto_generated
    void _clearItsFireSensor(void);
    
    //## auto_generated
    void __setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    void _setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    void _clearItsHVAC(void);
    
    //## auto_generated
    void _addItsIntelligentLamp(IntelligentLamp* const p_IntelligentLamp);
    
    //## auto_generated
    void _removeItsIntelligentLamp(IntelligentLamp* const p_IntelligentLamp);
    
    //## auto_generated
    void _clearItsIntelligentLamp(void);
    
    //## auto_generated
    void __setItsInteraction(Interaction* const p_Interaction);
    
    //## auto_generated
    void _setItsInteraction(Interaction* const p_Interaction);
    
    //## auto_generated
    void _clearItsInteraction(void);
    
    //## auto_generated
    void __setItsInterconnection(Interconnection* const p_Interconnection);
    
    //## auto_generated
    void _setItsInterconnection(Interconnection* const p_Interconnection);
    
    //## auto_generated
    void _clearItsInterconnection(void);
    
    //## auto_generated
    void __setItsMovementDetectionSensor(MovementDetectionSensor* const p_MovementDetectionSensor);
    
    //## auto_generated
    void _setItsMovementDetectionSensor(MovementDetectionSensor* const p_MovementDetectionSensor);
    
    //## auto_generated
    void _clearItsMovementDetectionSensor(void);
    
    //## auto_generated
    void __setItsOccupancySensor(OccupancySensor* const p_OccupancySensor);
    
    //## auto_generated
    void _setItsOccupancySensor(OccupancySensor* const p_OccupancySensor);
    
    //## auto_generated
    void _clearItsOccupancySensor(void);
    
    //## auto_generated
    void __setItsSASystem(SASystem* const p_SASystem);
    
    //## auto_generated
    void _setItsSASystem(SASystem* const p_SASystem);
    
    //## auto_generated
    void _clearItsSASystem(void);
    
    //## auto_generated
    void __setItsSoftwareController(SoftwareController* const p_SoftwareController);
    
    //## auto_generated
    void _setItsSoftwareController(SoftwareController* const p_SoftwareController);
    
    //## auto_generated
    void _clearItsSoftwareController(void);
    
    //## auto_generated
    void __setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor);
    
    //## auto_generated
    void _setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor);
    
    //## auto_generated
    void _clearItsTemperatureSensor(void);
    
    //## auto_generated
    void __setItsUser(User* const p_User);
    
    //## auto_generated
    void _setItsUser(User* const p_User);
    
    //## auto_generated
    void _clearItsUser(void);
    
    //## auto_generated
    void __setItsVisualEntity(VisualEntity* const p_VisualEntity);
    
    //## auto_generated
    void _setItsVisualEntity(VisualEntity* const p_VisualEntity);
    
    //## auto_generated
    void _clearItsVisualEntity(void);
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedDTSR : virtual public AOMInstance {
    DECLARE_META(DTSR, OMAnimatedDTSR)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: component_3\DefaultConfig\DTSR.h
*********************************************************************/
