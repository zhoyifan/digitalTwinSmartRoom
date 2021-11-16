/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: FireSensor
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\FireSensor.h
*********************************************************************/

#ifndef FireSensor_H
#define FireSensor_H

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
#include <omthread.h>
//## auto_generated
#include <omreactive.h>
//## auto_generated
#include <state.h>
//## auto_generated
#include <event.h>
//## link itsDTSR
class DTSR;

//## link itsFireAlarm
class FireAlarm;

//## link itsHVAC
class HVAC;

//#[ ignore
#define OMAnim_Default_FireSensor_setFire_bool_bool_ARGS_DECLARATION bool p_fire_bool;
//#]

//## package Default

//## class FireSensor
class FireSensor : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedFireSensor;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    explicit FireSensor(IOxfActive* const theActiveContext = NULL);
    
    //## auto_generated
    virtual ~FireSensor(void);
    
    ////    Operations    ////
    
    //## operation getFire_bool()
    virtual bool getFire_bool(void);
    
    ////    Additional operations    ////
    
    //## auto_generated
    void setFire_bool(const bool p_fire_bool);
    
    //## auto_generated
    const DTSR* getItsDTSR(void) const;
    
    //## auto_generated
    void setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    const FireAlarm* getItsFireAlarm(void) const;
    
    //## auto_generated
    void setItsFireAlarm(FireAlarm* const p_FireAlarm);
    
    //## auto_generated
    const HVAC* getItsHVAC(void) const;
    
    //## auto_generated
    void setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    virtual bool cancelTimeout(const IOxfTimeout* arg);
    
    //## auto_generated
    virtual bool startBehavior(void);

protected :

    //## auto_generated
    void initStatechart(void);
    
    //## auto_generated
    void cleanUpRelations(void);
    
    //## auto_generated
    void cancelTimeouts(void);
    
    ////    Attributes    ////

private :

    bool fire_bool;		//## attribute fire_bool
    
    ////    Relations and components    ////
    
    DTSR* itsDTSR;		//## link itsDTSR
    
    FireAlarm* itsFireAlarm;		//## link itsFireAlarm
    
    HVAC* itsHVAC;		//## link itsHVAC
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    void _setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    void _clearItsDTSR(void);
    
    //## auto_generated
    void __setItsFireAlarm(FireAlarm* const p_FireAlarm);
    
    //## auto_generated
    void _setItsFireAlarm(FireAlarm* const p_FireAlarm);
    
    //## auto_generated
    void _clearItsFireAlarm(void);
    
    //## auto_generated
    void __setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    void _setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    void _clearItsHVAC(void);
    
    // rootState:
    //## statechart_method
    inline RhpBoolean rootState_IN(void) const;
    
    // state_5:
    //## statechart_method
    inline RhpBoolean state_5_IN(void) const;
    
    //## statechart_method
    void state_5_entDef(void);
    
    //## statechart_method
    void state_5_exit(void);
    
    // NoFire:
    //## statechart_method
    inline RhpBoolean NoFire_IN(void) const;
    
    // Fire:
    //## statechart_method
    inline RhpBoolean Fire_IN(void) const;
    
    // accepttimeevent_12:
    //## statechart_method
    inline RhpBoolean accepttimeevent_12_IN(void) const;
    
    // accepttimeevent_11:
    //## statechart_method
    inline RhpBoolean accepttimeevent_11_IN(void) const;

protected :

    //## statechart_method
    virtual void rootState_entDef(void);
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent(void);
    
    ////    Framework    ////
    
//#[ ignore
    enum FireSensor_Enum {
        OMNonState = 0,
        state_5 = 1,
        NoFire = 2,
        Fire = 3,
        accepttimeevent_12 = 4,
        accepttimeevent_11 = 5
    };
//#]

private :

//#[ ignore
    FireSensor_Enum rootState_subState;
    
    FireSensor_Enum rootState_active;
    
    FireSensor_Enum state_5_subState;
    
    IOxfTimeout* state_5_timeout;
//#]
};

#ifdef _OMINSTRUMENT
DECLARE_OPERATION_CLASS(Default_FireSensor_setFire_bool_bool)

//#[ ignore
class OMAnimatedFireSensor : virtual public AOMInstance {
    DECLARE_REACTIVE_META(FireSensor, OMAnimatedFireSensor)
    
    DECLARE_META_OP(Default_FireSensor_setFire_bool_bool)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_5_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void NoFire_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Fire_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_12_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_11_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline RhpBoolean FireSensor::rootState_IN(void) const {
    return true;
}

inline RhpBoolean FireSensor::state_5_IN(void) const {
    return rootState_subState == state_5;
}

inline RhpBoolean FireSensor::NoFire_IN(void) const {
    return state_5_subState == NoFire;
}

inline RhpBoolean FireSensor::Fire_IN(void) const {
    return state_5_subState == Fire;
}

inline RhpBoolean FireSensor::accepttimeevent_12_IN(void) const {
    return state_5_subState == accepttimeevent_12;
}

inline RhpBoolean FireSensor::accepttimeevent_11_IN(void) const {
    return state_5_subState == accepttimeevent_11;
}

#endif
/*********************************************************************
	File Path	: component_3\DefaultConfig\FireSensor.h
*********************************************************************/
