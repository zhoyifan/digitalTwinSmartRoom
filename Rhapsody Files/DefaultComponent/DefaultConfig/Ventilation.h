/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Ventilation
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\Ventilation.h
*********************************************************************/

#ifndef Ventilation_H
#define Ventilation_H

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
//#[ ignore
#define OMAnim_Default_Ventilation_getCo2highgoal_ARGS_DECLARATION

#define OMAnim_Default_Ventilation_getCo2lowgoal_ARGS_DECLARATION

#define OMAnim_Default_Ventilation_getSpeed_ARGS_DECLARATION

#define OMAnim_Default_Ventilation_settingVentilation1_ARGS_DECLARATION

#define OMAnim_Default_Ventilation_settingVentilation2_ARGS_DECLARATION

#define OMAnim_Default_Ventilation_settingVentilation3_ARGS_DECLARATION

#define OMAnim_Default_Ventilation_settingVentilation4_ARGS_DECLARATION

#define OMAnim_Default_Ventilation_setCo2currentgoal_float_ARGS_DECLARATION float p_co2currentgoal;

#define OMAnim_Default_Ventilation_setCo2densityroom_float_ARGS_DECLARATION float p_co2densityroom;
//#]

//## link itsCO2Sensor
class CO2Sensor;

//## link itsFireAlarm
class FireAlarm;

//## link itsHVAC
class HVAC;

//## package Default

//## class Ventilation
class Ventilation : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedVentilation;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    explicit Ventilation(IOxfActive* const theActiveContext = NULL);
    
    //## auto_generated
    virtual ~Ventilation(void);
    
    ////    Operations    ////
    
    //## operation getCo2highgoal()
    virtual float getCo2highgoal(void);
    
    //## operation getCo2lowgoal()
    virtual float getCo2lowgoal(void);
    
    //## operation settingVentilation1()
    virtual void settingVentilation1(void);
    
    //## operation settingVentilation2()
    virtual int settingVentilation2(void);
    
    //## operation settingVentilation3()
    virtual void settingVentilation3(void);
    
    ////    Additional operations    ////
    
    //## auto_generated
    const float getCo2currentgoal(void) const;
    
    //## auto_generated
    void setCo2currentgoal(const float p_co2currentgoal);
    
    //## auto_generated
    const float getCo2density(void) const;
    
    //## auto_generated
    void setCo2density(const float p_co2density);
    
    //## auto_generated
    const bool getFirealarm_bool(void) const;
    
    //## auto_generated
    void setFirealarm_bool(const bool p_firealarm_bool);
    
    //## auto_generated
    const int getMode(void) const;
    
    //## auto_generated
    void setMode(const int p_mode);
    
    //## auto_generated
    const CO2Sensor* getItsCO2Sensor(void) const;
    
    //## auto_generated
    void setItsCO2Sensor(CO2Sensor* const p_CO2Sensor);
    
    //## auto_generated
    const FireAlarm* getItsFireAlarm(void) const;
    
    //## auto_generated
    void setItsFireAlarm(FireAlarm* const p_FireAlarm);
    
    //## auto_generated
    const HVAC* getItsHVAC(void) const;
    
    //## auto_generated
    void setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    const HVAC* getItsHVAC_1(void) const;
    
    //## auto_generated
    void setItsHVAC_1(HVAC* const p_HVAC);
    
    //## auto_generated
    virtual bool startBehavior(void);

protected :

    //## auto_generated
    void initStatechart(void);
    
    //## auto_generated
    void cleanUpRelations(void);
    
    ////    Attributes    ////

private :

    float co2currentgoal;		//## attribute co2currentgoal
    
    float co2density;		//## attribute co2density
    
    float co2densityroom;		//## attribute co2densityroom
    
    const float co2highgoal;		//## attribute co2highgoal
    
    const float co2lowgoal;		//## attribute co2lowgoal
    
    bool firealarm_bool;		//## attribute firealarm_bool
    
    int mode;		//## attribute mode
    
    ////    Relations and components    ////
    
    CO2Sensor* itsCO2Sensor;		//## link itsCO2Sensor
    
    FireAlarm* itsFireAlarm;		//## link itsFireAlarm
    
    HVAC* itsHVAC;		//## link itsHVAC
    
    HVAC* itsHVAC_1;		//## link itsHVAC_1
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsCO2Sensor(CO2Sensor* const p_CO2Sensor);
    
    //## auto_generated
    void _setItsCO2Sensor(CO2Sensor* const p_CO2Sensor);
    
    //## auto_generated
    void _clearItsCO2Sensor(void);
    
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
    
    //## auto_generated
    void __setItsHVAC_1(HVAC* const p_HVAC);
    
    //## auto_generated
    void _setItsHVAC_1(HVAC* const p_HVAC);
    
    //## auto_generated
    void _clearItsHVAC_1(void);
    
    ////    Framework    ////
    
    //## operation getSpeed()
    virtual float getSpeed(void);
    
    //## operation settingVentilation4()
    virtual int settingVentilation4(void);
    
    //## auto_generated
    const float getCo2densityroom(void) const;
    
    //## auto_generated
    void setCo2densityroom(const float p_co2densityroom);
    
    //## auto_generated
    const float getHvac(void) const;
    
    //## auto_generated
    void setHvac(const float p_hvac);
    
    //## auto_generated
    const int getStatus(void) const;
    
    //## auto_generated
    void setStatus(const int p_status);
    
    //## auto_generated
    virtual bool cancelTimeout(const IOxfTimeout* arg);

protected :

    //## auto_generated
    void cancelTimeouts(void);

private :

    float hvac;		//## attribute hvac
    
    const float speed;		//## attribute speed
    
    int status;		//## attribute status

public :

    // rootState:
    //## statechart_method
    inline RhpBoolean rootState_IN(void) const;
    
    // Ventilating:
    //## statechart_method
    inline RhpBoolean Ventilating_IN(void) const;
    
    // Off:
    //## statechart_method
    inline RhpBoolean Off_IN(void) const;
    
    // accepttimeevent_5:
    //## statechart_method
    inline RhpBoolean accepttimeevent_5_IN(void) const;
    
    // accepttimeevent_4:
    //## statechart_method
    inline RhpBoolean accepttimeevent_4_IN(void) const;

protected :

    //## statechart_method
    virtual void rootState_entDef(void);
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent(void);
    
//#[ ignore
    enum Ventilation_Enum {
        OMNonState = 0,
        Ventilating = 1,
        Off = 2,
        accepttimeevent_5 = 3,
        accepttimeevent_4 = 4
    };
//#]

private :

//#[ ignore
    Ventilation_Enum rootState_subState;
    
    Ventilation_Enum rootState_active;
    
    IOxfTimeout* rootState_timeout;
//#]
};

#ifdef _OMINSTRUMENT
DECLARE_OPERATION_CLASS(Default_Ventilation_getCo2highgoal)

DECLARE_OPERATION_CLASS(Default_Ventilation_getCo2lowgoal)

DECLARE_OPERATION_CLASS(Default_Ventilation_getSpeed)

DECLARE_OPERATION_CLASS(Default_Ventilation_settingVentilation1)

DECLARE_OPERATION_CLASS(Default_Ventilation_settingVentilation2)

DECLARE_OPERATION_CLASS(Default_Ventilation_settingVentilation3)

DECLARE_OPERATION_CLASS(Default_Ventilation_settingVentilation4)

DECLARE_OPERATION_CLASS(Default_Ventilation_setCo2currentgoal_float)

DECLARE_OPERATION_CLASS(Default_Ventilation_setCo2densityroom_float)

//#[ ignore
class OMAnimatedVentilation : virtual public AOMInstance {
    DECLARE_REACTIVE_META(Ventilation, OMAnimatedVentilation)
    
    DECLARE_META_OP(Default_Ventilation_getCo2highgoal)
    
    DECLARE_META_OP(Default_Ventilation_getCo2lowgoal)
    
    DECLARE_META_OP(Default_Ventilation_getSpeed)
    
    DECLARE_META_OP(Default_Ventilation_settingVentilation1)
    
    DECLARE_META_OP(Default_Ventilation_settingVentilation2)
    
    DECLARE_META_OP(Default_Ventilation_settingVentilation3)
    
    DECLARE_META_OP(Default_Ventilation_settingVentilation4)
    
    DECLARE_META_OP(Default_Ventilation_setCo2currentgoal_float)
    
    DECLARE_META_OP(Default_Ventilation_setCo2densityroom_float)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Ventilating_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Off_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_5_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_4_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline RhpBoolean Ventilation::rootState_IN(void) const {
    return true;
}

inline RhpBoolean Ventilation::Ventilating_IN(void) const {
    return rootState_subState == Ventilating;
}

inline RhpBoolean Ventilation::Off_IN(void) const {
    return rootState_subState == Off;
}

inline RhpBoolean Ventilation::accepttimeevent_5_IN(void) const {
    return rootState_subState == accepttimeevent_5;
}

inline RhpBoolean Ventilation::accepttimeevent_4_IN(void) const {
    return rootState_subState == accepttimeevent_4;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Ventilation.h
*********************************************************************/
