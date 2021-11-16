/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: FireAlarm
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\FireAlarm.h
*********************************************************************/

#ifndef FireAlarm_H
#define FireAlarm_H

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

//## link itsFireSensor
class FireSensor;

//## link itsHVAC
class HVAC;

//## link itsVentilation
class Ventilation;

//#[ ignore
#define OMAnim_Default_FireAlarm_FireNow_ARGS_DECLARATION

#define OMAnim_Default_FireAlarm_FireStop_ARGS_DECLARATION

#define OMAnim_Default_FireAlarm_callMain_ARGS_DECLARATION

#define OMAnim_Default_FireAlarm_getFirealarm_bool_ARGS_DECLARATION

#define OMAnim_Default_FireAlarm_setFire_bool_bool_ARGS_DECLARATION bool p_fire_bool;

#define OMAnim_Default_FireAlarm_setFirealarm_bool_bool_ARGS_DECLARATION bool p_firealarm_bool;
//#]

//## package Default

//## class FireAlarm
class FireAlarm : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedFireAlarm;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    explicit FireAlarm(IOxfActive* const theActiveContext = NULL);
    
    //## auto_generated
    virtual ~FireAlarm(void);
    
    ////    Operations    ////
    
    //## operation FireNow()
    virtual void FireNow(void);
    
    //## operation FireStop()
    virtual void FireStop(void);
    
    //## operation callMain()
    virtual int callMain(void);
    
    //## operation getFirealarm_bool()
    virtual bool getFirealarm_bool(void);
    
    ////    Additional operations    ////
    
    //## auto_generated
    const SOCKADDR_IN getAddress_fire(void) const;
    
    //## auto_generated
    void setAddress_fire(const SOCKADDR_IN p_address_fire);
    
    //## auto_generated
    const SOCKADDR_IN getAddress_firealarm(void) const;
    
    //## auto_generated
    void setAddress_firealarm(const SOCKADDR_IN p_address_firealarm);
    
    //## auto_generated
    const float getFire(void) const;
    
    //## auto_generated
    void setFire(const float p_fire);
    
    //## auto_generated
    const bool getFire_bool(void) const;
    
    //## auto_generated
    void setFire_bool(const bool p_fire_bool);
    
    //## auto_generated
    const float getFirealarm(void) const;
    
    //## auto_generated
    void setFirealarm(const float p_firealarm);
    
    //## auto_generated
    void setFirealarm_bool(const bool p_firealarm_bool);
    
    //## auto_generated
    const int getIResultFire(void) const;
    
    //## auto_generated
    void setIResultFire(const int p_iResultFire);
    
    //## auto_generated
    const int getIResultFirealarm(void) const;
    
    //## auto_generated
    void setIResultFirealarm(const int p_iResultFirealarm);
    
    //## auto_generated
    const int getISendResultFire(void) const;
    
    //## auto_generated
    void setISendResultFire(const int p_iSendResultFire);
    
    //## auto_generated
    const int getISendResultFirealarm(void) const;
    
    //## auto_generated
    void setISendResultFirealarm(const int p_iSendResultFirealarm);
    
    //## auto_generated
    const SOCKET getListenSocketForFire(void) const;
    
    //## auto_generated
    void setListenSocketForFire(const SOCKET p_listenSocketForFire);
    
    //## auto_generated
    const SOCKET getListenSocketForFirealarm(void) const;
    
    //## auto_generated
    void setListenSocketForFirealarm(const SOCKET p_listenSocketForFirealarm);
    
    //## auto_generated
    const int getPortFire(void) const;
    
    //## auto_generated
    void setPortFire(const int p_portFire);
    
    //## auto_generated
    const int getPortFirealarm(void) const;
    
    //## auto_generated
    void setPortFirealarm(const int p_portFirealarm);
    
    //## auto_generated
    const char getRecvbuf(const Rhp_int32_t iterI1) const;
    
    //## auto_generated
    void setRecvbuf(const Rhp_int32_t iterI1, const char p_recvbuf);
    
    //## auto_generated
    const int getRecvbuflen(void) const;
    
    //## auto_generated
    void setRecvbuflen(const int p_recvbuflen);
    
    //## auto_generated
    const char* getServerName(void) const;
    
    //## auto_generated
    void setServerName(char* const p_serverName);
    
    //## auto_generated
    const WSADATA getWs(void) const;
    
    //## auto_generated
    void setWs(const WSADATA p_ws);
    
    //## auto_generated
    const DTSR* getItsDTSR(void) const;
    
    //## auto_generated
    void setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    const FireSensor* getItsFireSensor(void) const;
    
    //## auto_generated
    void setItsFireSensor(FireSensor* const p_FireSensor);
    
    //## auto_generated
    const HVAC* getItsHVAC(void) const;
    
    //## auto_generated
    void setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    const Ventilation* getItsVentilation(void) const;
    
    //## auto_generated
    void setItsVentilation(Ventilation* const p_Ventilation);
    
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

    SOCKADDR_IN address_fire;		//## attribute address_fire
    
    SOCKADDR_IN address_firealarm;		//## attribute address_firealarm
    
    float fire;		//## attribute fire
    
    bool fire_bool;		//## attribute fire_bool
    
    float firealarm;		//## attribute firealarm
    
    bool firealarm_bool;		//## attribute firealarm_bool
    
    int iResultFire;		//## attribute iResultFire
    
    int iResultFirealarm;		//## attribute iResultFirealarm
    
    int iSendResultFire;		//## attribute iSendResultFire
    
    int iSendResultFirealarm;		//## attribute iSendResultFirealarm
    
    SOCKET listenSocketForFire;		//## attribute listenSocketForFire
    
    SOCKET listenSocketForFirealarm;		//## attribute listenSocketForFirealarm
    
    int portFire;		//## attribute portFire
    
    int portFirealarm;		//## attribute portFirealarm
    
    char recvbuf[DEFAULT_BUFLEN];		//## attribute recvbuf
    
    int recvbuflen;		//## attribute recvbuflen
    
    char* serverName;		//## attribute serverName
    
    WSADATA ws;		//## attribute ws
    
    ////    Relations and components    ////
    
    DTSR* itsDTSR;		//## link itsDTSR
    
    FireSensor* itsFireSensor;		//## link itsFireSensor
    
    HVAC* itsHVAC;		//## link itsHVAC
    
    Ventilation* itsVentilation;		//## link itsVentilation
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    void _setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    void _clearItsDTSR(void);
    
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
    void __setItsVentilation(Ventilation* const p_Ventilation);
    
    //## auto_generated
    void _setItsVentilation(Ventilation* const p_Ventilation);
    
    //## auto_generated
    void _clearItsVentilation(void);
    
    // rootState:
    //## statechart_method
    inline RhpBoolean rootState_IN(void) const;
    
    // state_0:
    //## statechart_method
    inline RhpBoolean state_0_IN(void) const;
    
    //## statechart_method
    void state_0_entDef(void);
    
    //## statechart_method
    void state_0_exit(void);
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_0_processEvent(void);
    
    // state_2:
    //## statechart_method
    inline RhpBoolean state_2_IN(void) const;
    
    //## statechart_method
    void state_2_entDef(void);
    
    //## statechart_method
    void state_2_exit(void);
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_2_processEvent(void);
    
    // SendAndRecieve:
    //## statechart_method
    inline RhpBoolean SendAndRecieve_IN(void) const;
    
    // state_1:
    //## statechart_method
    inline RhpBoolean state_1_IN(void) const;
    
    //## statechart_method
    void state_1_entDef(void);
    
    //## statechart_method
    void state_1_exit(void);
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_1_processEvent(void);
    
    // Normal:
    //## statechart_method
    inline RhpBoolean Normal_IN(void) const;
    
    // Alarm:
    //## statechart_method
    inline RhpBoolean Alarm_IN(void) const;
    
    // accepttimeevent_9:
    //## statechart_method
    inline RhpBoolean accepttimeevent_9_IN(void) const;
    
    // accepttimeevent_8:
    //## statechart_method
    inline RhpBoolean accepttimeevent_8_IN(void) const;
    
    // accepttimeevent_6:
    //## statechart_method
    inline RhpBoolean accepttimeevent_6_IN(void) const;
    
    // accepttimeevent_5:
    //## statechart_method
    inline RhpBoolean accepttimeevent_5_IN(void) const;

protected :

    //## statechart_method
    virtual void rootState_entDef(void);
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent(void);
    
    ////    Framework    ////
    
//#[ ignore
    enum FireAlarm_Enum {
        OMNonState = 0,
        state_0 = 1,
        state_2 = 2,
        SendAndRecieve = 3,
        state_1 = 4,
        Normal = 5,
        Alarm = 6,
        accepttimeevent_9 = 7,
        accepttimeevent_8 = 8,
        accepttimeevent_6 = 9,
        accepttimeevent_5 = 10
    };
//#]

private :

//#[ ignore
    FireAlarm_Enum rootState_subState;
    
    FireAlarm_Enum rootState_active;
    
    FireAlarm_Enum state_2_subState;
    
    FireAlarm_Enum state_2_active;
    
    IOxfTimeout* state_2_timeout;
    
    FireAlarm_Enum state_1_subState;
    
    FireAlarm_Enum state_1_active;
    
    IOxfTimeout* state_1_timeout;
//#]
};

#ifdef _OMINSTRUMENT
DECLARE_OPERATION_CLASS(Default_FireAlarm_FireNow)

DECLARE_OPERATION_CLASS(Default_FireAlarm_FireStop)

DECLARE_OPERATION_CLASS(Default_FireAlarm_callMain)

DECLARE_OPERATION_CLASS(Default_FireAlarm_getFirealarm_bool)

DECLARE_OPERATION_CLASS(Default_FireAlarm_setFire_bool_bool)

DECLARE_OPERATION_CLASS(Default_FireAlarm_setFirealarm_bool_bool)

//#[ ignore
class OMAnimatedFireAlarm : virtual public AOMInstance {
    DECLARE_REACTIVE_META(FireAlarm, OMAnimatedFireAlarm)
    
    DECLARE_META_OP(Default_FireAlarm_FireNow)
    
    DECLARE_META_OP(Default_FireAlarm_FireStop)
    
    DECLARE_META_OP(Default_FireAlarm_callMain)
    
    DECLARE_META_OP(Default_FireAlarm_getFirealarm_bool)
    
    DECLARE_META_OP(Default_FireAlarm_setFire_bool_bool)
    
    DECLARE_META_OP(Default_FireAlarm_setFirealarm_bool_bool)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_0_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_2_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void SendAndRecieve_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_1_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Normal_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Alarm_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_9_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_8_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_6_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_5_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline RhpBoolean FireAlarm::rootState_IN(void) const {
    return true;
}

inline RhpBoolean FireAlarm::state_0_IN(void) const {
    return rootState_subState == state_0;
}

inline RhpBoolean FireAlarm::state_2_IN(void) const {
    return state_0_IN();
}

inline RhpBoolean FireAlarm::SendAndRecieve_IN(void) const {
    return state_2_subState == SendAndRecieve;
}

inline RhpBoolean FireAlarm::state_1_IN(void) const {
    return state_0_IN();
}

inline RhpBoolean FireAlarm::Normal_IN(void) const {
    return state_1_subState == Normal;
}

inline RhpBoolean FireAlarm::Alarm_IN(void) const {
    return state_1_subState == Alarm;
}

inline RhpBoolean FireAlarm::accepttimeevent_9_IN(void) const {
    return state_1_subState == accepttimeevent_9;
}

inline RhpBoolean FireAlarm::accepttimeevent_8_IN(void) const {
    return state_1_subState == accepttimeevent_8;
}

inline RhpBoolean FireAlarm::accepttimeevent_6_IN(void) const {
    return state_1_subState == accepttimeevent_6;
}

inline RhpBoolean FireAlarm::accepttimeevent_5_IN(void) const {
    return state_1_subState == accepttimeevent_5;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FireAlarm.h
*********************************************************************/
