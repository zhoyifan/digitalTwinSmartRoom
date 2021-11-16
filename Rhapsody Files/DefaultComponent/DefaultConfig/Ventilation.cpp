/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Ventilation
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\Ventilation.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "Ventilation.h"
//## link itsCO2Sensor
#include "CO2Sensor.h"
//## link itsFireAlarm
#include "FireAlarm.h"
//## link itsHVAC
#include "HVAC.h"
//#[ ignore
#define Default_Ventilation_Ventilation_SERIALIZE OM_NO_OP

#define Default_Ventilation_getCo2highgoal_SERIALIZE OM_NO_OP

#define OMAnim_Default_Ventilation_getCo2highgoal_UNSERIALIZE_ARGS

#define OMAnim_Default_Ventilation_getCo2highgoal_SERIALIZE_RET_VAL OP_SET_RET_VAL(animRetVal)

#define Default_Ventilation_getCo2lowgoal_SERIALIZE OM_NO_OP

#define OMAnim_Default_Ventilation_getCo2lowgoal_UNSERIALIZE_ARGS

#define OMAnim_Default_Ventilation_getCo2lowgoal_SERIALIZE_RET_VAL OP_SET_RET_VAL(animRetVal)

#define Default_Ventilation_getSpeed_SERIALIZE OM_NO_OP

#define OMAnim_Default_Ventilation_getSpeed_UNSERIALIZE_ARGS

#define OMAnim_Default_Ventilation_getSpeed_SERIALIZE_RET_VAL OP_SET_RET_VAL(animRetVal)

#define Default_Ventilation_settingVentilation1_SERIALIZE OM_NO_OP

#define OMAnim_Default_Ventilation_settingVentilation1_UNSERIALIZE_ARGS

#define OMAnim_Default_Ventilation_settingVentilation1_SERIALIZE_RET_VAL

#define Default_Ventilation_settingVentilation2_SERIALIZE OM_NO_OP

#define OMAnim_Default_Ventilation_settingVentilation2_UNSERIALIZE_ARGS

#define OMAnim_Default_Ventilation_settingVentilation2_SERIALIZE_RET_VAL OP_SET_RET_VAL(animRetVal)

#define Default_Ventilation_settingVentilation3_SERIALIZE OM_NO_OP

#define OMAnim_Default_Ventilation_settingVentilation3_UNSERIALIZE_ARGS

#define OMAnim_Default_Ventilation_settingVentilation3_SERIALIZE_RET_VAL

#define Default_Ventilation_settingVentilation4_SERIALIZE OM_NO_OP

#define OMAnim_Default_Ventilation_settingVentilation4_UNSERIALIZE_ARGS

#define OMAnim_Default_Ventilation_settingVentilation4_SERIALIZE_RET_VAL OP_SET_RET_VAL(animRetVal)

#define OMAnim_Default_Ventilation_setCo2currentgoal_float_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_co2currentgoal)

#define OMAnim_Default_Ventilation_setCo2currentgoal_float_SERIALIZE_RET_VAL

#define OMAnim_Default_Ventilation_setCo2densityroom_float_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_co2densityroom)

#define OMAnim_Default_Ventilation_setCo2densityroom_float_SERIALIZE_RET_VAL
//#]

//## package Default

//## class Ventilation
Ventilation::Ventilation(IOxfActive* const theActiveContext) : OMReactive(), co2currentgoal(10), co2density(10), co2highgoal(500), co2lowgoal(500), firealarm_bool(0), mode(0), itsCO2Sensor(NULL), itsFireAlarm(NULL), itsHVAC(NULL), itsHVAC_1(NULL), hvac(0), speed(100), status(0) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Ventilation, Ventilation(), 0, Default_Ventilation_Ventilation_SERIALIZE);
    setActiveContext(theActiveContext, false);
    initStatechart();
}

Ventilation::~Ventilation(void) {
    NOTIFY_DESTRUCTOR(~Ventilation, true);
    cleanUpRelations();
    cancelTimeouts();
}

float Ventilation::getCo2highgoal(void) {
    NOTIFY_OPERATION(getCo2highgoal, getCo2highgoal(), 0, Default_Ventilation_getCo2highgoal_SERIALIZE);
    //#[ operation getCo2highgoal()
    return co2highgoal;
    //#]
}

float Ventilation::getCo2lowgoal(void) {
    NOTIFY_OPERATION(getCo2lowgoal, getCo2lowgoal(), 0, Default_Ventilation_getCo2lowgoal_SERIALIZE);
    //#[ operation getCo2lowgoal()
    return co2lowgoal;
    //#]
}

void Ventilation::settingVentilation1(void) {
    NOTIFY_OPERATION(settingVentilation1, settingVentilation1(), 0, Default_Ventilation_settingVentilation1_SERIALIZE);
    //#[ operation settingVentilation1()
    firealarm_bool=itsFireAlarm->getFirealarm_bool();
    //#]
}

int Ventilation::settingVentilation2(void) {
    NOTIFY_OPERATION(settingVentilation2, settingVentilation2(), 0, Default_Ventilation_settingVentilation2_SERIALIZE);
    //#[ operation settingVentilation2()
    float co2densityfromsensor=itsCO2Sensor->getCo2density();
    if(co2densityfromsensor>90000){
    	return 0;
    }
    co2density=co2densityfromsensor;
    return 0;
    
    //#]
}

void Ventilation::settingVentilation3(void) {
    NOTIFY_OPERATION(settingVentilation3, settingVentilation3(), 0, Default_Ventilation_settingVentilation3_SERIALIZE);
    //#[ operation settingVentilation3()
    if(itsHVAC->getHvac()==3){
    	co2currentgoal=co2lowgoal;
    }else{
    	co2currentgoal=co2highgoal;
    }
    //#]
}

const float Ventilation::getCo2currentgoal(void) const {
    return co2currentgoal;
}

void Ventilation::setCo2currentgoal(const float p_co2currentgoal) {
    co2currentgoal = p_co2currentgoal;
    NOTIFY_SET_OPERATION;
}

const float Ventilation::getCo2density(void) const {
    return co2density;
}

void Ventilation::setCo2density(const float p_co2density) {
    co2density = p_co2density;
}

const bool Ventilation::getFirealarm_bool(void) const {
    return firealarm_bool;
}

void Ventilation::setFirealarm_bool(const bool p_firealarm_bool) {
    firealarm_bool = p_firealarm_bool;
}

const int Ventilation::getMode(void) const {
    return mode;
}

void Ventilation::setMode(const int p_mode) {
    mode = p_mode;
}

const CO2Sensor* Ventilation::getItsCO2Sensor(void) const {
    return itsCO2Sensor;
}

void Ventilation::setItsCO2Sensor(CO2Sensor* const p_CO2Sensor) {
    if(p_CO2Sensor != NULL)
        {
            p_CO2Sensor->_setItsVentilation(this);
        }
    _setItsCO2Sensor(p_CO2Sensor);
}

const FireAlarm* Ventilation::getItsFireAlarm(void) const {
    return itsFireAlarm;
}

void Ventilation::setItsFireAlarm(FireAlarm* const p_FireAlarm) {
    if(p_FireAlarm != NULL)
        {
            p_FireAlarm->_setItsVentilation(this);
        }
    _setItsFireAlarm(p_FireAlarm);
}

const HVAC* Ventilation::getItsHVAC(void) const {
    return itsHVAC;
}

void Ventilation::setItsHVAC(HVAC* const p_HVAC) {
    if(p_HVAC != NULL)
        {
            p_HVAC->_setItsVentilation(this);
        }
    _setItsHVAC(p_HVAC);
}

const HVAC* Ventilation::getItsHVAC_1(void) const {
    return itsHVAC_1;
}

void Ventilation::setItsHVAC_1(HVAC* const p_HVAC) {
    if(p_HVAC != NULL)
        {
            p_HVAC->_setItsVentilation_1(this);
        }
    _setItsHVAC_1(p_HVAC);
}

bool Ventilation::startBehavior(void) {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Ventilation::initStatechart(void) {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    rootState_timeout = NULL;
}

void Ventilation::cleanUpRelations(void) {
    if(itsCO2Sensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsCO2Sensor");
            const Ventilation* p_Ventilation = itsCO2Sensor->getItsVentilation();
            if(p_Ventilation != NULL)
                {
                    itsCO2Sensor->__setItsVentilation(NULL);
                }
            itsCO2Sensor = NULL;
        }
    if(itsFireAlarm != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsFireAlarm");
            const Ventilation* p_Ventilation = itsFireAlarm->getItsVentilation();
            if(p_Ventilation != NULL)
                {
                    itsFireAlarm->__setItsVentilation(NULL);
                }
            itsFireAlarm = NULL;
        }
    if(itsHVAC != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsHVAC");
            const Ventilation* p_Ventilation = itsHVAC->getItsVentilation();
            if(p_Ventilation != NULL)
                {
                    itsHVAC->__setItsVentilation(NULL);
                }
            itsHVAC = NULL;
        }
    if(itsHVAC_1 != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsHVAC_1");
            const Ventilation* p_Ventilation = itsHVAC_1->getItsVentilation_1();
            if(p_Ventilation != NULL)
                {
                    itsHVAC_1->__setItsVentilation_1(NULL);
                }
            itsHVAC_1 = NULL;
        }
}

void Ventilation::__setItsCO2Sensor(CO2Sensor* const p_CO2Sensor) {
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

void Ventilation::_setItsCO2Sensor(CO2Sensor* const p_CO2Sensor) {
    if(itsCO2Sensor != NULL)
        {
            itsCO2Sensor->__setItsVentilation(NULL);
        }
    __setItsCO2Sensor(p_CO2Sensor);
}

void Ventilation::_clearItsCO2Sensor(void) {
    NOTIFY_RELATION_CLEARED("itsCO2Sensor");
    itsCO2Sensor = NULL;
}

void Ventilation::__setItsFireAlarm(FireAlarm* const p_FireAlarm) {
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

void Ventilation::_setItsFireAlarm(FireAlarm* const p_FireAlarm) {
    if(itsFireAlarm != NULL)
        {
            itsFireAlarm->__setItsVentilation(NULL);
        }
    __setItsFireAlarm(p_FireAlarm);
}

void Ventilation::_clearItsFireAlarm(void) {
    NOTIFY_RELATION_CLEARED("itsFireAlarm");
    itsFireAlarm = NULL;
}

void Ventilation::__setItsHVAC(HVAC* const p_HVAC) {
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

void Ventilation::_setItsHVAC(HVAC* const p_HVAC) {
    if(itsHVAC != NULL)
        {
            itsHVAC->__setItsVentilation(NULL);
        }
    __setItsHVAC(p_HVAC);
}

void Ventilation::_clearItsHVAC(void) {
    NOTIFY_RELATION_CLEARED("itsHVAC");
    itsHVAC = NULL;
}

void Ventilation::__setItsHVAC_1(HVAC* const p_HVAC) {
    itsHVAC_1 = p_HVAC;
    if(p_HVAC != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsHVAC_1", p_HVAC, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsHVAC_1");
        }
}

void Ventilation::_setItsHVAC_1(HVAC* const p_HVAC) {
    if(itsHVAC_1 != NULL)
        {
            itsHVAC_1->__setItsVentilation_1(NULL);
        }
    __setItsHVAC_1(p_HVAC);
}

void Ventilation::_clearItsHVAC_1(void) {
    NOTIFY_RELATION_CLEARED("itsHVAC_1");
    itsHVAC_1 = NULL;
}

float Ventilation::getSpeed(void) {
    NOTIFY_OPERATION(getSpeed, getSpeed(), 0, Default_Ventilation_getSpeed_SERIALIZE);
    //#[ operation getSpeed()
    return speed;
    //#]
}

int Ventilation::settingVentilation4(void) {
    NOTIFY_OPERATION(settingVentilation4, settingVentilation4(), 0, Default_Ventilation_settingVentilation4_SERIALIZE);
    //#[ operation settingVentilation4()
    std::cout<<"executing"<<std::endl;
    //if(itsHVAC->getMode()!=2) return 0;
    std::cout<<"step one!"<<std::endl;
    //if(itsFireAlarm->getFirealarm_bool()==true){
    //	itsHVAC->setHvac(0);
    //	return 0;
    //}
    std::cout<<"step two!"<<std::endl;
    hvac=itsHVAC->getHvac();
    if(hvac>0&&hvac<3)return 0;
    
    co2densityroom=co2densityroom=itsCO2Sensor->getCo2density();
    if(co2densityroom>=100000){
    	itsHVAC->setHvac(0);
    	return 0;
    }
    std::cout<<"step three!"<<std::endl;
    settingVentilation3();
    std::cout<<"step four!"<<std::endl;
    if(co2densityroom<=co2currentgoal){
    	itsHVAC->setHvac(0);
    	return 0;
    }
    std::cout<<"step five!"<<std::endl;
    itsHVAC->setHvac(3);
    return 1;
    //#]
}

const float Ventilation::getCo2densityroom(void) const {
    return co2densityroom;
}

void Ventilation::setCo2densityroom(const float p_co2densityroom) {
    co2densityroom = p_co2densityroom;
    NOTIFY_SET_OPERATION;
}

const float Ventilation::getHvac(void) const {
    return hvac;
}

void Ventilation::setHvac(const float p_hvac) {
    hvac = p_hvac;
}

const int Ventilation::getStatus(void) const {
    return status;
}

void Ventilation::setStatus(const int p_status) {
    status = p_status;
}

bool Ventilation::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(rootState_timeout == arg)
        {
            rootState_timeout = NULL;
            res = true;
        }
    return res;
}

void Ventilation::cancelTimeouts(void) {
    cancel(rootState_timeout);
}

void Ventilation::rootState_entDef(void) {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.Off");
        rootState_subState = Off;
        rootState_active = Off;
        rootState_timeout = scheduleTimeout(1000, "ROOT.Off");
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus Ventilation::rootState_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        // State Off
        case Off:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == rootState_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("3");
                            cancel(rootState_timeout);
                            NOTIFY_STATE_EXITED("ROOT.Off");
                            NOTIFY_STATE_ENTERED("ROOT.accepttimeevent_4");
                            pushNullTransition();
                            rootState_subState = accepttimeevent_4;
                            rootState_active = accepttimeevent_4;
                            NOTIFY_TRANSITION_TERMINATED("3");
                            res = eventConsumed;
                        }
                }
            
        }
        break;
        // State Ventilating
        case Ventilating:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == rootState_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("5");
                            cancel(rootState_timeout);
                            NOTIFY_STATE_EXITED("ROOT.Ventilating");
                            NOTIFY_STATE_ENTERED("ROOT.accepttimeevent_5");
                            pushNullTransition();
                            rootState_subState = accepttimeevent_5;
                            rootState_active = accepttimeevent_5;
                            NOTIFY_TRANSITION_TERMINATED("5");
                            res = eventConsumed;
                        }
                }
            
        }
        break;
        case accepttimeevent_4:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    //## transition 1 
                    if(status==0)
                        {
                            NOTIFY_TRANSITION_STARTED("4");
                            NOTIFY_TRANSITION_STARTED("1");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.accepttimeevent_4");
                            //#[ transition 4 
                            status=settingVentilation4();
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.Off");
                            rootState_subState = Off;
                            rootState_active = Off;
                            rootState_timeout = scheduleTimeout(1000, "ROOT.Off");
                            NOTIFY_TRANSITION_TERMINATED("1");
                            NOTIFY_TRANSITION_TERMINATED("4");
                            res = eventConsumed;
                        }
                    else
                        {
                            NOTIFY_TRANSITION_STARTED("4");
                            NOTIFY_TRANSITION_STARTED("2");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.accepttimeevent_4");
                            //#[ transition 4 
                            status=settingVentilation4();
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.Ventilating");
                            rootState_subState = Ventilating;
                            rootState_active = Ventilating;
                            rootState_timeout = scheduleTimeout(1000, "ROOT.Ventilating");
                            NOTIFY_TRANSITION_TERMINATED("2");
                            NOTIFY_TRANSITION_TERMINATED("4");
                            res = eventConsumed;
                        }
                }
            
        }
        break;
        case accepttimeevent_5:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    //## transition 7 
                    if(status==0)
                        {
                            NOTIFY_TRANSITION_STARTED("6");
                            NOTIFY_TRANSITION_STARTED("7");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.accepttimeevent_5");
                            //#[ transition 6 
                            status=settingVentilation4();
                            //#]
                            //#[ transition 7 
                            itsHVAC->setHvac(0);
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.Off");
                            rootState_subState = Off;
                            rootState_active = Off;
                            rootState_timeout = scheduleTimeout(1000, "ROOT.Off");
                            NOTIFY_TRANSITION_TERMINATED("7");
                            NOTIFY_TRANSITION_TERMINATED("6");
                            res = eventConsumed;
                        }
                    else
                        {
                            NOTIFY_TRANSITION_STARTED("6");
                            NOTIFY_TRANSITION_STARTED("8");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.accepttimeevent_5");
                            //#[ transition 6 
                            status=settingVentilation4();
                            //#]
                            //#[ transition 8 
                            itsHVAC->setHvac(3);
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.Ventilating");
                            rootState_subState = Ventilating;
                            rootState_active = Ventilating;
                            rootState_timeout = scheduleTimeout(1000, "ROOT.Ventilating");
                            NOTIFY_TRANSITION_TERMINATED("8");
                            NOTIFY_TRANSITION_TERMINATED("6");
                            res = eventConsumed;
                        }
                }
            
        }
        break;
        default:
            break;
    }
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedVentilation::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("co2density", x2String(myReal->co2density));
    aomsAttributes->addAttribute("firealarm_bool", x2String(myReal->firealarm_bool));
    aomsAttributes->addAttribute("mode", x2String(myReal->mode));
    aomsAttributes->addAttribute("co2highgoal", x2String(myReal->co2highgoal));
    aomsAttributes->addAttribute("co2lowgoal", x2String(myReal->co2lowgoal));
    aomsAttributes->addAttribute("co2currentgoal", x2String(myReal->co2currentgoal));
    aomsAttributes->addAttribute("co2densityroom", x2String(myReal->co2densityroom));
    aomsAttributes->addAttribute("speed", x2String(myReal->speed));
    aomsAttributes->addAttribute("status", x2String(myReal->status));
    aomsAttributes->addAttribute("hvac", x2String(myReal->hvac));
}

void OMAnimatedVentilation::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsHVAC", false, true);
    if(myReal->itsHVAC)
        {
            aomsRelations->ADD_ITEM(myReal->itsHVAC);
        }
    aomsRelations->addRelation("itsFireAlarm", false, true);
    if(myReal->itsFireAlarm)
        {
            aomsRelations->ADD_ITEM(myReal->itsFireAlarm);
        }
    aomsRelations->addRelation("itsCO2Sensor", false, true);
    if(myReal->itsCO2Sensor)
        {
            aomsRelations->ADD_ITEM(myReal->itsCO2Sensor);
        }
    aomsRelations->addRelation("itsHVAC_1", false, true);
    if(myReal->itsHVAC_1)
        {
            aomsRelations->ADD_ITEM(myReal->itsHVAC_1);
        }
}

void OMAnimatedVentilation::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Ventilation::Off:
        {
            Off_serializeStates(aomsState);
        }
        break;
        case Ventilation::Ventilating:
        {
            Ventilating_serializeStates(aomsState);
        }
        break;
        case Ventilation::accepttimeevent_4:
        {
            accepttimeevent_4_serializeStates(aomsState);
        }
        break;
        case Ventilation::accepttimeevent_5:
        {
            accepttimeevent_5_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedVentilation::Ventilating_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Ventilating");
}

void OMAnimatedVentilation::Off_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Off");
}

void OMAnimatedVentilation::accepttimeevent_5_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.accepttimeevent_5");
}

void OMAnimatedVentilation::accepttimeevent_4_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.accepttimeevent_4");
}
//#]

IMPLEMENT_REACTIVE_META_P(Ventilation, Default, Default, false, OMAnimatedVentilation)

IMPLEMENT_META_OP(OMAnimatedVentilation, Default_Ventilation_getCo2highgoal, "getCo2highgoal", FALSE, "getCo2highgoal()", 0)

IMPLEMENT_OP_CALL(Default_Ventilation_getCo2highgoal, Ventilation, getCo2highgoal(), float animRetVal = )

IMPLEMENT_META_OP(OMAnimatedVentilation, Default_Ventilation_getCo2lowgoal, "getCo2lowgoal", FALSE, "getCo2lowgoal()", 0)

IMPLEMENT_OP_CALL(Default_Ventilation_getCo2lowgoal, Ventilation, getCo2lowgoal(), float animRetVal = )

IMPLEMENT_META_OP(OMAnimatedVentilation, Default_Ventilation_getSpeed, "getSpeed", FALSE, "getSpeed()", 0)

IMPLEMENT_OP_CALL(Default_Ventilation_getSpeed, Ventilation, getSpeed(), float animRetVal = )

IMPLEMENT_META_OP(OMAnimatedVentilation, Default_Ventilation_settingVentilation1, "settingVentilation1", FALSE, "settingVentilation1()", 0)

IMPLEMENT_OP_CALL(Default_Ventilation_settingVentilation1, Ventilation, settingVentilation1(), NO_OP())

IMPLEMENT_META_OP(OMAnimatedVentilation, Default_Ventilation_settingVentilation2, "settingVentilation2", FALSE, "settingVentilation2()", 0)

IMPLEMENT_OP_CALL(Default_Ventilation_settingVentilation2, Ventilation, settingVentilation2(), int animRetVal = )

IMPLEMENT_META_OP(OMAnimatedVentilation, Default_Ventilation_settingVentilation3, "settingVentilation3", FALSE, "settingVentilation3()", 0)

IMPLEMENT_OP_CALL(Default_Ventilation_settingVentilation3, Ventilation, settingVentilation3(), NO_OP())

IMPLEMENT_META_OP(OMAnimatedVentilation, Default_Ventilation_settingVentilation4, "settingVentilation4", FALSE, "settingVentilation4()", 0)

IMPLEMENT_OP_CALL(Default_Ventilation_settingVentilation4, Ventilation, settingVentilation4(), int animRetVal = )

IMPLEMENT_META_OP(OMAnimatedVentilation, Default_Ventilation_setCo2currentgoal_float, "setCo2currentgoal", FALSE, "setCo2currentgoal(float)", 1)

IMPLEMENT_OP_CALL(Default_Ventilation_setCo2currentgoal_float, Ventilation, setCo2currentgoal(p_co2currentgoal), NO_OP())

IMPLEMENT_META_OP(OMAnimatedVentilation, Default_Ventilation_setCo2densityroom_float, "setCo2densityroom", FALSE, "setCo2densityroom(float)", 1)

IMPLEMENT_OP_CALL(Default_Ventilation_setCo2densityroom_float, Ventilation, setCo2densityroom(p_co2densityroom), NO_OP())
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Ventilation.cpp
*********************************************************************/
