/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: FireSensor
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\FireSensor.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "FireSensor.h"
//## link itsDTSR
#include "DTSR.h"
//## link itsFireAlarm
#include "FireAlarm.h"
//## link itsHVAC
#include "HVAC.h"
//#[ ignore
#define Default_FireSensor_FireSensor_SERIALIZE OM_NO_OP

#define Default_FireSensor_getFire_bool_SERIALIZE OM_NO_OP

#define OMAnim_Default_FireSensor_setFire_bool_bool_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_fire_bool)

#define OMAnim_Default_FireSensor_setFire_bool_bool_SERIALIZE_RET_VAL
//#]

//## package Default

//## class FireSensor
FireSensor::FireSensor(IOxfActive* const theActiveContext) : OMReactive(), fire_bool(0), itsDTSR(NULL), itsFireAlarm(NULL), itsHVAC(NULL) {
    NOTIFY_REACTIVE_CONSTRUCTOR(FireSensor, FireSensor(), 0, Default_FireSensor_FireSensor_SERIALIZE);
    setActiveContext(theActiveContext, false);
    initStatechart();
}

FireSensor::~FireSensor(void) {
    NOTIFY_DESTRUCTOR(~FireSensor, true);
    cleanUpRelations();
    cancelTimeouts();
}

bool FireSensor::getFire_bool(void) {
    NOTIFY_OPERATION(getFire_bool, getFire_bool(), 0, Default_FireSensor_getFire_bool_SERIALIZE);
    //#[ operation getFire_bool()
    return fire_bool;
    //#]
}

void FireSensor::setFire_bool(const bool p_fire_bool) {
    fire_bool = p_fire_bool;
    NOTIFY_SET_OPERATION;
}

const DTSR* FireSensor::getItsDTSR(void) const {
    return itsDTSR;
}

void FireSensor::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_setItsFireSensor(this);
        }
    _setItsDTSR(p_DTSR);
}

const FireAlarm* FireSensor::getItsFireAlarm(void) const {
    return itsFireAlarm;
}

void FireSensor::setItsFireAlarm(FireAlarm* const p_FireAlarm) {
    if(p_FireAlarm != NULL)
        {
            p_FireAlarm->_setItsFireSensor(this);
        }
    _setItsFireAlarm(p_FireAlarm);
}

const HVAC* FireSensor::getItsHVAC(void) const {
    return itsHVAC;
}

void FireSensor::setItsHVAC(HVAC* const p_HVAC) {
    if(p_HVAC != NULL)
        {
            p_HVAC->_setItsFireSensor(this);
        }
    _setItsHVAC(p_HVAC);
}

bool FireSensor::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(state_5_timeout == arg)
        {
            state_5_timeout = NULL;
            res = true;
        }
    return res;
}

bool FireSensor::startBehavior(void) {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void FireSensor::initStatechart(void) {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    state_5_subState = OMNonState;
    state_5_timeout = NULL;
}

void FireSensor::cleanUpRelations(void) {
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            const FireSensor* p_FireSensor = itsDTSR->getItsFireSensor();
            if(p_FireSensor != NULL)
                {
                    itsDTSR->__setItsFireSensor(NULL);
                }
            itsDTSR = NULL;
        }
    if(itsFireAlarm != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsFireAlarm");
            const FireSensor* p_FireSensor = itsFireAlarm->getItsFireSensor();
            if(p_FireSensor != NULL)
                {
                    itsFireAlarm->__setItsFireSensor(NULL);
                }
            itsFireAlarm = NULL;
        }
    if(itsHVAC != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsHVAC");
            const FireSensor* p_FireSensor = itsHVAC->getItsFireSensor();
            if(p_FireSensor != NULL)
                {
                    itsHVAC->__setItsFireSensor(NULL);
                }
            itsHVAC = NULL;
        }
}

void FireSensor::cancelTimeouts(void) {
    cancel(state_5_timeout);
}

void FireSensor::__setItsDTSR(DTSR* const p_DTSR) {
    itsDTSR = p_DTSR;
    if(p_DTSR != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsDTSR", p_DTSR, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
        }
}

void FireSensor::_setItsDTSR(DTSR* const p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->__setItsFireSensor(NULL);
        }
    __setItsDTSR(p_DTSR);
}

void FireSensor::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

void FireSensor::__setItsFireAlarm(FireAlarm* const p_FireAlarm) {
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

void FireSensor::_setItsFireAlarm(FireAlarm* const p_FireAlarm) {
    if(itsFireAlarm != NULL)
        {
            itsFireAlarm->__setItsFireSensor(NULL);
        }
    __setItsFireAlarm(p_FireAlarm);
}

void FireSensor::_clearItsFireAlarm(void) {
    NOTIFY_RELATION_CLEARED("itsFireAlarm");
    itsFireAlarm = NULL;
}

void FireSensor::__setItsHVAC(HVAC* const p_HVAC) {
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

void FireSensor::_setItsHVAC(HVAC* const p_HVAC) {
    if(itsHVAC != NULL)
        {
            itsHVAC->__setItsFireSensor(NULL);
        }
    __setItsHVAC(p_HVAC);
}

void FireSensor::_clearItsHVAC(void) {
    NOTIFY_RELATION_CLEARED("itsHVAC");
    itsHVAC = NULL;
}

void FireSensor::state_5_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_5");
    rootState_subState = state_5;
    NOTIFY_TRANSITION_STARTED("ROOT.state_5.0");
    NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.NoFire");
    state_5_subState = NoFire;
    rootState_active = NoFire;
    state_5_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.NoFire");
    NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.0");
}

void FireSensor::state_5_exit(void) {
    switch (state_5_subState) {
        // State NoFire
        case NoFire:
        {
            cancel(state_5_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.NoFire");
        }
        break;
        // State Fire
        case Fire:
        {
            cancel(state_5_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.Fire");
        }
        break;
        case accepttimeevent_11:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.accepttimeevent_11");
        }
        break;
        case accepttimeevent_12:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.accepttimeevent_12");
        }
        break;
        default:
            break;
    }
    state_5_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_5");
}

void FireSensor::rootState_entDef(void) {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        state_5_entDef();
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus FireSensor::rootState_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        // State NoFire
        case NoFire:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_5_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.1");
                            cancel(state_5_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.NoFire");
                            NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.accepttimeevent_11");
                            pushNullTransition();
                            state_5_subState = accepttimeevent_11;
                            rootState_active = accepttimeevent_11;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.1");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        // State Fire
        case Fire:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_5_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.4");
                            cancel(state_5_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.Fire");
                            NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.accepttimeevent_12");
                            pushNullTransition();
                            state_5_subState = accepttimeevent_12;
                            rootState_active = accepttimeevent_12;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.4");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        case accepttimeevent_11:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    //## transition state_5.2 
                    if(fire_bool==false)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.7");
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.2");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.accepttimeevent_11");
                            NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.NoFire");
                            state_5_subState = NoFire;
                            rootState_active = NoFire;
                            state_5_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.NoFire");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.2");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.7");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition state_5.3 
                            if(fire_bool==true)
                                {
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_5.7");
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_5.3");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.accepttimeevent_11");
                                    NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.Fire");
                                    state_5_subState = Fire;
                                    rootState_active = Fire;
                                    state_5_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.Fire");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.3");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.7");
                                    res = eventConsumed;
                                }
                        }
                }
            
            
        }
        break;
        case accepttimeevent_12:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    //## transition state_5.5 
                    if(fire_bool==true)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.8");
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.5");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.accepttimeevent_12");
                            NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.Fire");
                            state_5_subState = Fire;
                            rootState_active = Fire;
                            state_5_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.Fire");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.5");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.8");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition state_5.6 
                            if(fire_bool==false)
                                {
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_5.8");
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_5.6");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.accepttimeevent_12");
                                    NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.NoFire");
                                    state_5_subState = NoFire;
                                    rootState_active = NoFire;
                                    state_5_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.NoFire");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.6");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.8");
                                    res = eventConsumed;
                                }
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
void OMAnimatedFireSensor::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("fire_bool", x2String(myReal->fire_bool));
}

void OMAnimatedFireSensor::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsFireAlarm", false, true);
    if(myReal->itsFireAlarm)
        {
            aomsRelations->ADD_ITEM(myReal->itsFireAlarm);
        }
    aomsRelations->addRelation("itsHVAC", false, true);
    if(myReal->itsHVAC)
        {
            aomsRelations->ADD_ITEM(myReal->itsHVAC);
        }
    aomsRelations->addRelation("itsDTSR", false, true);
    if(myReal->itsDTSR)
        {
            aomsRelations->ADD_ITEM(myReal->itsDTSR);
        }
}

void OMAnimatedFireSensor::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    if(myReal->rootState_subState == FireSensor::state_5)
        {
            state_5_serializeStates(aomsState);
        }
}

void OMAnimatedFireSensor::state_5_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5");
    switch (myReal->state_5_subState) {
        case FireSensor::NoFire:
        {
            NoFire_serializeStates(aomsState);
        }
        break;
        case FireSensor::Fire:
        {
            Fire_serializeStates(aomsState);
        }
        break;
        case FireSensor::accepttimeevent_11:
        {
            accepttimeevent_11_serializeStates(aomsState);
        }
        break;
        case FireSensor::accepttimeevent_12:
        {
            accepttimeevent_12_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedFireSensor::NoFire_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.NoFire");
}

void OMAnimatedFireSensor::Fire_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.Fire");
}

void OMAnimatedFireSensor::accepttimeevent_12_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.accepttimeevent_12");
}

void OMAnimatedFireSensor::accepttimeevent_11_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.accepttimeevent_11");
}
//#]

IMPLEMENT_REACTIVE_META_P(FireSensor, Default, Default, false, OMAnimatedFireSensor)

IMPLEMENT_META_OP(OMAnimatedFireSensor, Default_FireSensor_setFire_bool_bool, "setFire_bool", FALSE, "setFire_bool(bool)", 1)

IMPLEMENT_OP_CALL(Default_FireSensor_setFire_bool_bool, FireSensor, setFire_bool(p_fire_bool), NO_OP())
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: component_3\DefaultConfig\FireSensor.cpp
*********************************************************************/
