/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: DTSR
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\DTSR.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "DTSR.h"
//## link itsAVSystem
#include "AVSystem.h"
//## link itsCO2Sensor
#include "CO2Sensor.h"
//## link itsEnvironMent
#include "EnvironMent.h"
//## link itsFireAlarm
#include "FireAlarm.h"
//## link itsFireSensor
#include "FireSensor.h"
//## link itsHVAC
#include "HVAC.h"
//## link itsIntelligentLamp
#include "IntelligentLamp.h"
//## link itsInteraction
#include "Interaction.h"
//## link itsInterconnection
#include "Interconnection.h"
//## link itsMovementDetectionSensor
#include "MovementDetectionSensor.h"
//## link itsOccupancySensor
#include "OccupancySensor.h"
//## link itsSASystem
#include "SASystem.h"
//## link itsSoftwareController
#include "SoftwareController.h"
//## link itsTemperatureSensor
#include "TemperatureSensor.h"
//## link itsUser
#include "User.h"
//## link itsVisualEntity
#include "VisualEntity.h"
//#[ ignore
#define Default_DTSR_DTSR_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class DTSR
DTSR::DTSR(void) : itsAVSystem(NULL), itsCO2Sensor(NULL), itsEnvironMent(NULL), itsFireAlarm(NULL), itsFireSensor(NULL), itsHVAC(NULL), itsInteraction(NULL), itsInterconnection(NULL), itsMovementDetectionSensor(NULL), itsOccupancySensor(NULL), itsSASystem(NULL), itsSoftwareController(NULL), itsTemperatureSensor(NULL), itsUser(NULL), itsVisualEntity(NULL) {
    NOTIFY_CONSTRUCTOR(DTSR, DTSR(), 0, Default_DTSR_DTSR_SERIALIZE);
}

DTSR::~DTSR(void) {
    NOTIFY_DESTRUCTOR(~DTSR, true);
    cleanUpRelations();
}

const AVSystem* DTSR::getItsAVSystem(void) const {
    return itsAVSystem;
}

void DTSR::setItsAVSystem(AVSystem* const p_AVSystem) {
    if(p_AVSystem != NULL)
        {
            p_AVSystem->_setItsDTSR(this);
        }
    _setItsAVSystem(p_AVSystem);
}

const CO2Sensor* DTSR::getItsCO2Sensor(void) const {
    return itsCO2Sensor;
}

void DTSR::setItsCO2Sensor(CO2Sensor* const p_CO2Sensor) {
    if(p_CO2Sensor != NULL)
        {
            p_CO2Sensor->_setItsDTSR(this);
        }
    _setItsCO2Sensor(p_CO2Sensor);
}

const EnvironMent* DTSR::getItsEnvironMent(void) const {
    return itsEnvironMent;
}

void DTSR::setItsEnvironMent(EnvironMent* const p_EnvironMent) {
    if(p_EnvironMent != NULL)
        {
            p_EnvironMent->_setItsDTSR(this);
        }
    _setItsEnvironMent(p_EnvironMent);
}

const FireAlarm* DTSR::getItsFireAlarm(void) const {
    return itsFireAlarm;
}

void DTSR::setItsFireAlarm(FireAlarm* const p_FireAlarm) {
    if(p_FireAlarm != NULL)
        {
            p_FireAlarm->_setItsDTSR(this);
        }
    _setItsFireAlarm(p_FireAlarm);
}

const FireSensor* DTSR::getItsFireSensor(void) const {
    return itsFireSensor;
}

void DTSR::setItsFireSensor(FireSensor* const p_FireSensor) {
    if(p_FireSensor != NULL)
        {
            p_FireSensor->_setItsDTSR(this);
        }
    _setItsFireSensor(p_FireSensor);
}

const HVAC* DTSR::getItsHVAC(void) const {
    return itsHVAC;
}

void DTSR::setItsHVAC(HVAC* const p_HVAC) {
    if(p_HVAC != NULL)
        {
            p_HVAC->_setItsDTSR(this);
        }
    _setItsHVAC(p_HVAC);
}

OMIterator<IntelligentLamp*> DTSR::getItsIntelligentLamp(void) const {
    OMIterator<IntelligentLamp*> iter(itsIntelligentLamp);
    return iter;
}

void DTSR::addItsIntelligentLamp(IntelligentLamp* const p_IntelligentLamp) {
    if(p_IntelligentLamp != NULL)
        {
            p_IntelligentLamp->_setItsDTSR(this);
        }
    _addItsIntelligentLamp(p_IntelligentLamp);
}

void DTSR::removeItsIntelligentLamp(IntelligentLamp* p_IntelligentLamp) {
    if(p_IntelligentLamp != NULL)
        {
            p_IntelligentLamp->__setItsDTSR(NULL);
        }
    _removeItsIntelligentLamp(p_IntelligentLamp);
}

void DTSR::clearItsIntelligentLamp(void) {
    OMIterator<IntelligentLamp*> iter(itsIntelligentLamp);
    while (*iter){
        (*iter)->_clearItsDTSR();
        iter++;
    }
    _clearItsIntelligentLamp();
}

const Interaction* DTSR::getItsInteraction(void) const {
    return itsInteraction;
}

void DTSR::setItsInteraction(Interaction* const p_Interaction) {
    if(p_Interaction != NULL)
        {
            p_Interaction->_setItsDTSR(this);
        }
    _setItsInteraction(p_Interaction);
}

const Interconnection* DTSR::getItsInterconnection(void) const {
    return itsInterconnection;
}

void DTSR::setItsInterconnection(Interconnection* const p_Interconnection) {
    if(p_Interconnection != NULL)
        {
            p_Interconnection->_setItsDTSR(this);
        }
    _setItsInterconnection(p_Interconnection);
}

const MovementDetectionSensor* DTSR::getItsMovementDetectionSensor(void) const {
    return itsMovementDetectionSensor;
}

void DTSR::setItsMovementDetectionSensor(MovementDetectionSensor* const p_MovementDetectionSensor) {
    if(p_MovementDetectionSensor != NULL)
        {
            p_MovementDetectionSensor->_setItsDTSR(this);
        }
    _setItsMovementDetectionSensor(p_MovementDetectionSensor);
}

const OccupancySensor* DTSR::getItsOccupancySensor(void) const {
    return itsOccupancySensor;
}

void DTSR::setItsOccupancySensor(OccupancySensor* const p_OccupancySensor) {
    if(p_OccupancySensor != NULL)
        {
            p_OccupancySensor->_setItsDTSR(this);
        }
    _setItsOccupancySensor(p_OccupancySensor);
}

const SASystem* DTSR::getItsSASystem(void) const {
    return itsSASystem;
}

void DTSR::setItsSASystem(SASystem* const p_SASystem) {
    if(p_SASystem != NULL)
        {
            p_SASystem->_setItsDTSR(this);
        }
    _setItsSASystem(p_SASystem);
}

const SoftwareController* DTSR::getItsSoftwareController(void) const {
    return itsSoftwareController;
}

void DTSR::setItsSoftwareController(SoftwareController* const p_SoftwareController) {
    if(p_SoftwareController != NULL)
        {
            p_SoftwareController->_setItsDTSR(this);
        }
    _setItsSoftwareController(p_SoftwareController);
}

const TemperatureSensor* DTSR::getItsTemperatureSensor(void) const {
    return itsTemperatureSensor;
}

void DTSR::setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor) {
    if(p_TemperatureSensor != NULL)
        {
            p_TemperatureSensor->_setItsDTSR(this);
        }
    _setItsTemperatureSensor(p_TemperatureSensor);
}

const UCDynamicLightingBlk* DTSR::getItsUCDynamicLightingBlk(void) const {
    return &itsUCDynamicLightingBlk;
}

const UCFireBlk* DTSR::getItsUCFireBlk(void) const {
    return &itsUCFireBlk;
}

const UCHVACBlk* DTSR::getItsUCHVACBlk(void) const {
    return &itsUCHVACBlk;
}

const User* DTSR::getItsUser(void) const {
    return itsUser;
}

void DTSR::setItsUser(User* const p_User) {
    if(p_User != NULL)
        {
            p_User->_setItsDTSR(this);
        }
    _setItsUser(p_User);
}

const VisualEntity* DTSR::getItsVisualEntity(void) const {
    return itsVisualEntity;
}

void DTSR::setItsVisualEntity(VisualEntity* const p_VisualEntity) {
    if(p_VisualEntity != NULL)
        {
            p_VisualEntity->_setItsDTSR(this);
        }
    _setItsVisualEntity(p_VisualEntity);
}

void DTSR::cleanUpRelations(void) {
    if(itsAVSystem != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsAVSystem");
            const DTSR* p_DTSR = itsAVSystem->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    itsAVSystem->__setItsDTSR(NULL);
                }
            itsAVSystem = NULL;
        }
    if(itsCO2Sensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsCO2Sensor");
            const DTSR* p_DTSR = itsCO2Sensor->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    itsCO2Sensor->__setItsDTSR(NULL);
                }
            itsCO2Sensor = NULL;
        }
    if(itsEnvironMent != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsEnvironMent");
            const DTSR* p_DTSR = itsEnvironMent->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    itsEnvironMent->__setItsDTSR(NULL);
                }
            itsEnvironMent = NULL;
        }
    if(itsFireAlarm != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsFireAlarm");
            const DTSR* p_DTSR = itsFireAlarm->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    itsFireAlarm->__setItsDTSR(NULL);
                }
            itsFireAlarm = NULL;
        }
    if(itsFireSensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsFireSensor");
            const DTSR* p_DTSR = itsFireSensor->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    itsFireSensor->__setItsDTSR(NULL);
                }
            itsFireSensor = NULL;
        }
    if(itsHVAC != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsHVAC");
            const DTSR* p_DTSR = itsHVAC->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    itsHVAC->__setItsDTSR(NULL);
                }
            itsHVAC = NULL;
        }
    {
        OMIterator<IntelligentLamp*> iter(itsIntelligentLamp);
        while (*iter){
            const DTSR* p_DTSR = (*iter)->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    (*iter)->__setItsDTSR(NULL);
                }
            iter++;
        }
        itsIntelligentLamp.removeAll();
    }
    if(itsInteraction != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsInteraction");
            const DTSR* p_DTSR = itsInteraction->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    itsInteraction->__setItsDTSR(NULL);
                }
            itsInteraction = NULL;
        }
    if(itsInterconnection != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsInterconnection");
            const DTSR* p_DTSR = itsInterconnection->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    itsInterconnection->__setItsDTSR(NULL);
                }
            itsInterconnection = NULL;
        }
    if(itsMovementDetectionSensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsMovementDetectionSensor");
            const DTSR* p_DTSR = itsMovementDetectionSensor->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    itsMovementDetectionSensor->__setItsDTSR(NULL);
                }
            itsMovementDetectionSensor = NULL;
        }
    if(itsOccupancySensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsOccupancySensor");
            const DTSR* p_DTSR = itsOccupancySensor->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    itsOccupancySensor->__setItsDTSR(NULL);
                }
            itsOccupancySensor = NULL;
        }
    if(itsSASystem != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsSASystem");
            const DTSR* p_DTSR = itsSASystem->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    itsSASystem->__setItsDTSR(NULL);
                }
            itsSASystem = NULL;
        }
    if(itsSoftwareController != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsSoftwareController");
            const DTSR* p_DTSR = itsSoftwareController->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    itsSoftwareController->__setItsDTSR(NULL);
                }
            itsSoftwareController = NULL;
        }
    if(itsTemperatureSensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsTemperatureSensor");
            const DTSR* p_DTSR = itsTemperatureSensor->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    itsTemperatureSensor->__setItsDTSR(NULL);
                }
            itsTemperatureSensor = NULL;
        }
    if(itsUser != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsUser");
            const DTSR* p_DTSR = itsUser->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    itsUser->__setItsDTSR(NULL);
                }
            itsUser = NULL;
        }
    if(itsVisualEntity != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsVisualEntity");
            const DTSR* p_DTSR = itsVisualEntity->getItsDTSR();
            if(p_DTSR != NULL)
                {
                    itsVisualEntity->__setItsDTSR(NULL);
                }
            itsVisualEntity = NULL;
        }
}

void DTSR::__setItsAVSystem(AVSystem* const p_AVSystem) {
    itsAVSystem = p_AVSystem;
    if(p_AVSystem != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsAVSystem", p_AVSystem, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsAVSystem");
        }
}

void DTSR::_setItsAVSystem(AVSystem* const p_AVSystem) {
    if(itsAVSystem != NULL)
        {
            itsAVSystem->__setItsDTSR(NULL);
        }
    __setItsAVSystem(p_AVSystem);
}

void DTSR::_clearItsAVSystem(void) {
    NOTIFY_RELATION_CLEARED("itsAVSystem");
    itsAVSystem = NULL;
}

void DTSR::__setItsCO2Sensor(CO2Sensor* const p_CO2Sensor) {
    itsCO2Sensor = p_CO2Sensor;
    if(p_CO2Sensor != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsCO2Sensor", p_CO2Sensor, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsCO2Sensor");
        }
}

void DTSR::_setItsCO2Sensor(CO2Sensor* const p_CO2Sensor) {
    if(itsCO2Sensor != NULL)
        {
            itsCO2Sensor->__setItsDTSR(NULL);
        }
    __setItsCO2Sensor(p_CO2Sensor);
}

void DTSR::_clearItsCO2Sensor(void) {
    NOTIFY_RELATION_CLEARED("itsCO2Sensor");
    itsCO2Sensor = NULL;
}

void DTSR::__setItsEnvironMent(EnvironMent* const p_EnvironMent) {
    itsEnvironMent = p_EnvironMent;
    if(p_EnvironMent != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsEnvironMent", p_EnvironMent, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsEnvironMent");
        }
}

void DTSR::_setItsEnvironMent(EnvironMent* const p_EnvironMent) {
    if(itsEnvironMent != NULL)
        {
            itsEnvironMent->__setItsDTSR(NULL);
        }
    __setItsEnvironMent(p_EnvironMent);
}

void DTSR::_clearItsEnvironMent(void) {
    NOTIFY_RELATION_CLEARED("itsEnvironMent");
    itsEnvironMent = NULL;
}

void DTSR::__setItsFireAlarm(FireAlarm* const p_FireAlarm) {
    itsFireAlarm = p_FireAlarm;
    if(p_FireAlarm != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsFireAlarm", p_FireAlarm, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsFireAlarm");
        }
}

void DTSR::_setItsFireAlarm(FireAlarm* const p_FireAlarm) {
    if(itsFireAlarm != NULL)
        {
            itsFireAlarm->__setItsDTSR(NULL);
        }
    __setItsFireAlarm(p_FireAlarm);
}

void DTSR::_clearItsFireAlarm(void) {
    NOTIFY_RELATION_CLEARED("itsFireAlarm");
    itsFireAlarm = NULL;
}

void DTSR::__setItsFireSensor(FireSensor* const p_FireSensor) {
    itsFireSensor = p_FireSensor;
    if(p_FireSensor != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsFireSensor", p_FireSensor, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsFireSensor");
        }
}

void DTSR::_setItsFireSensor(FireSensor* const p_FireSensor) {
    if(itsFireSensor != NULL)
        {
            itsFireSensor->__setItsDTSR(NULL);
        }
    __setItsFireSensor(p_FireSensor);
}

void DTSR::_clearItsFireSensor(void) {
    NOTIFY_RELATION_CLEARED("itsFireSensor");
    itsFireSensor = NULL;
}

void DTSR::__setItsHVAC(HVAC* const p_HVAC) {
    itsHVAC = p_HVAC;
    if(p_HVAC != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsHVAC", p_HVAC, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsHVAC");
        }
}

void DTSR::_setItsHVAC(HVAC* const p_HVAC) {
    if(itsHVAC != NULL)
        {
            itsHVAC->__setItsDTSR(NULL);
        }
    __setItsHVAC(p_HVAC);
}

void DTSR::_clearItsHVAC(void) {
    NOTIFY_RELATION_CLEARED("itsHVAC");
    itsHVAC = NULL;
}

void DTSR::_addItsIntelligentLamp(IntelligentLamp* const p_IntelligentLamp) {
    if(p_IntelligentLamp != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsIntelligentLamp", p_IntelligentLamp, false, false);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsIntelligentLamp");
        }
    itsIntelligentLamp.add(p_IntelligentLamp);
}

void DTSR::_removeItsIntelligentLamp(IntelligentLamp* const p_IntelligentLamp) {
    NOTIFY_RELATION_ITEM_REMOVED("itsIntelligentLamp", p_IntelligentLamp);
    itsIntelligentLamp.remove(p_IntelligentLamp);
}

void DTSR::_clearItsIntelligentLamp(void) {
    NOTIFY_RELATION_CLEARED("itsIntelligentLamp");
    itsIntelligentLamp.removeAll();
}

void DTSR::__setItsInteraction(Interaction* const p_Interaction) {
    itsInteraction = p_Interaction;
    if(p_Interaction != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsInteraction", p_Interaction, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsInteraction");
        }
}

void DTSR::_setItsInteraction(Interaction* const p_Interaction) {
    if(itsInteraction != NULL)
        {
            itsInteraction->__setItsDTSR(NULL);
        }
    __setItsInteraction(p_Interaction);
}

void DTSR::_clearItsInteraction(void) {
    NOTIFY_RELATION_CLEARED("itsInteraction");
    itsInteraction = NULL;
}

void DTSR::__setItsInterconnection(Interconnection* const p_Interconnection) {
    itsInterconnection = p_Interconnection;
    if(p_Interconnection != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsInterconnection", p_Interconnection, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsInterconnection");
        }
}

void DTSR::_setItsInterconnection(Interconnection* const p_Interconnection) {
    if(itsInterconnection != NULL)
        {
            itsInterconnection->__setItsDTSR(NULL);
        }
    __setItsInterconnection(p_Interconnection);
}

void DTSR::_clearItsInterconnection(void) {
    NOTIFY_RELATION_CLEARED("itsInterconnection");
    itsInterconnection = NULL;
}

void DTSR::__setItsMovementDetectionSensor(MovementDetectionSensor* const p_MovementDetectionSensor) {
    itsMovementDetectionSensor = p_MovementDetectionSensor;
    if(p_MovementDetectionSensor != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsMovementDetectionSensor", p_MovementDetectionSensor, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsMovementDetectionSensor");
        }
}

void DTSR::_setItsMovementDetectionSensor(MovementDetectionSensor* const p_MovementDetectionSensor) {
    if(itsMovementDetectionSensor != NULL)
        {
            itsMovementDetectionSensor->__setItsDTSR(NULL);
        }
    __setItsMovementDetectionSensor(p_MovementDetectionSensor);
}

void DTSR::_clearItsMovementDetectionSensor(void) {
    NOTIFY_RELATION_CLEARED("itsMovementDetectionSensor");
    itsMovementDetectionSensor = NULL;
}

void DTSR::__setItsOccupancySensor(OccupancySensor* const p_OccupancySensor) {
    itsOccupancySensor = p_OccupancySensor;
    if(p_OccupancySensor != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsOccupancySensor", p_OccupancySensor, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsOccupancySensor");
        }
}

void DTSR::_setItsOccupancySensor(OccupancySensor* const p_OccupancySensor) {
    if(itsOccupancySensor != NULL)
        {
            itsOccupancySensor->__setItsDTSR(NULL);
        }
    __setItsOccupancySensor(p_OccupancySensor);
}

void DTSR::_clearItsOccupancySensor(void) {
    NOTIFY_RELATION_CLEARED("itsOccupancySensor");
    itsOccupancySensor = NULL;
}

void DTSR::__setItsSASystem(SASystem* const p_SASystem) {
    itsSASystem = p_SASystem;
    if(p_SASystem != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsSASystem", p_SASystem, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsSASystem");
        }
}

void DTSR::_setItsSASystem(SASystem* const p_SASystem) {
    if(itsSASystem != NULL)
        {
            itsSASystem->__setItsDTSR(NULL);
        }
    __setItsSASystem(p_SASystem);
}

void DTSR::_clearItsSASystem(void) {
    NOTIFY_RELATION_CLEARED("itsSASystem");
    itsSASystem = NULL;
}

void DTSR::__setItsSoftwareController(SoftwareController* const p_SoftwareController) {
    itsSoftwareController = p_SoftwareController;
    if(p_SoftwareController != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsSoftwareController", p_SoftwareController, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsSoftwareController");
        }
}

void DTSR::_setItsSoftwareController(SoftwareController* const p_SoftwareController) {
    if(itsSoftwareController != NULL)
        {
            itsSoftwareController->__setItsDTSR(NULL);
        }
    __setItsSoftwareController(p_SoftwareController);
}

void DTSR::_clearItsSoftwareController(void) {
    NOTIFY_RELATION_CLEARED("itsSoftwareController");
    itsSoftwareController = NULL;
}

void DTSR::__setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor) {
    itsTemperatureSensor = p_TemperatureSensor;
    if(p_TemperatureSensor != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsTemperatureSensor", p_TemperatureSensor, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsTemperatureSensor");
        }
}

void DTSR::_setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor) {
    if(itsTemperatureSensor != NULL)
        {
            itsTemperatureSensor->__setItsDTSR(NULL);
        }
    __setItsTemperatureSensor(p_TemperatureSensor);
}

void DTSR::_clearItsTemperatureSensor(void) {
    NOTIFY_RELATION_CLEARED("itsTemperatureSensor");
    itsTemperatureSensor = NULL;
}

void DTSR::__setItsUser(User* const p_User) {
    itsUser = p_User;
    if(p_User != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsUser", p_User, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsUser");
        }
}

void DTSR::_setItsUser(User* const p_User) {
    if(itsUser != NULL)
        {
            itsUser->__setItsDTSR(NULL);
        }
    __setItsUser(p_User);
}

void DTSR::_clearItsUser(void) {
    NOTIFY_RELATION_CLEARED("itsUser");
    itsUser = NULL;
}

void DTSR::__setItsVisualEntity(VisualEntity* const p_VisualEntity) {
    itsVisualEntity = p_VisualEntity;
    if(p_VisualEntity != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsVisualEntity", p_VisualEntity, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsVisualEntity");
        }
}

void DTSR::_setItsVisualEntity(VisualEntity* const p_VisualEntity) {
    if(itsVisualEntity != NULL)
        {
            itsVisualEntity->__setItsDTSR(NULL);
        }
    __setItsVisualEntity(p_VisualEntity);
}

void DTSR::_clearItsVisualEntity(void) {
    NOTIFY_RELATION_CLEARED("itsVisualEntity");
    itsVisualEntity = NULL;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedDTSR::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsFireSensor", false, true);
    if(myReal->itsFireSensor)
        {
            aomsRelations->ADD_ITEM(myReal->itsFireSensor);
        }
    aomsRelations->addRelation("itsUser", false, true);
    if(myReal->itsUser)
        {
            aomsRelations->ADD_ITEM(myReal->itsUser);
        }
    aomsRelations->addRelation("itsIntelligentLamp", false, false);
    {
        OMIterator<IntelligentLamp*> iter(myReal->itsIntelligentLamp);
        while (*iter){
            aomsRelations->ADD_ITEM(*iter);
            iter++;
        }
    }
    aomsRelations->addRelation("itsEnvironMent", false, true);
    if(myReal->itsEnvironMent)
        {
            aomsRelations->ADD_ITEM(myReal->itsEnvironMent);
        }
    aomsRelations->addRelation("itsSASystem", false, true);
    if(myReal->itsSASystem)
        {
            aomsRelations->ADD_ITEM(myReal->itsSASystem);
        }
    aomsRelations->addRelation("itsTemperatureSensor", false, true);
    if(myReal->itsTemperatureSensor)
        {
            aomsRelations->ADD_ITEM(myReal->itsTemperatureSensor);
        }
    aomsRelations->addRelation("itsInteraction", false, true);
    if(myReal->itsInteraction)
        {
            aomsRelations->ADD_ITEM(myReal->itsInteraction);
        }
    aomsRelations->addRelation("itsInterconnection", false, true);
    if(myReal->itsInterconnection)
        {
            aomsRelations->ADD_ITEM(myReal->itsInterconnection);
        }
    aomsRelations->addRelation("itsCO2Sensor", false, true);
    if(myReal->itsCO2Sensor)
        {
            aomsRelations->ADD_ITEM(myReal->itsCO2Sensor);
        }
    aomsRelations->addRelation("itsHVAC", false, true);
    if(myReal->itsHVAC)
        {
            aomsRelations->ADD_ITEM(myReal->itsHVAC);
        }
    aomsRelations->addRelation("itsAVSystem", false, true);
    if(myReal->itsAVSystem)
        {
            aomsRelations->ADD_ITEM(myReal->itsAVSystem);
        }
    aomsRelations->addRelation("itsFireAlarm", false, true);
    if(myReal->itsFireAlarm)
        {
            aomsRelations->ADD_ITEM(myReal->itsFireAlarm);
        }
    aomsRelations->addRelation("itsMovementDetectionSensor", false, true);
    if(myReal->itsMovementDetectionSensor)
        {
            aomsRelations->ADD_ITEM(myReal->itsMovementDetectionSensor);
        }
    aomsRelations->addRelation("itsOccupancySensor", false, true);
    if(myReal->itsOccupancySensor)
        {
            aomsRelations->ADD_ITEM(myReal->itsOccupancySensor);
        }
    aomsRelations->addRelation("itsVisualEntity", false, true);
    if(myReal->itsVisualEntity)
        {
            aomsRelations->ADD_ITEM(myReal->itsVisualEntity);
        }
    aomsRelations->addRelation("itsUCFireBlk", true, true);
    aomsRelations->ADD_ITEM(&myReal->itsUCFireBlk);
    aomsRelations->addRelation("itsUCHVACBlk", true, true);
    aomsRelations->ADD_ITEM(&myReal->itsUCHVACBlk);
    aomsRelations->addRelation("itsUCDynamicLightingBlk", true, true);
    aomsRelations->ADD_ITEM(&myReal->itsUCDynamicLightingBlk);
    aomsRelations->addRelation("itsSoftwareController", false, true);
    if(myReal->itsSoftwareController)
        {
            aomsRelations->ADD_ITEM(myReal->itsSoftwareController);
        }
}
//#]

IMPLEMENT_META_P(DTSR, Default, Default, false, OMAnimatedDTSR)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: component_3\DefaultConfig\DTSR.cpp
*********************************************************************/
