/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: AirConditioner
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\AirConditioner.h
*********************************************************************/

#ifndef AirConditioner_H
#define AirConditioner_H

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
//## link itsHVAC
class HVAC;

//## link itsTemperatureSensor
class TemperatureSensor;

//#[ ignore
#define OMAnim_Default_AirConditioner_setTemperaturegoal_float_ARGS_DECLARATION float p_temperaturegoal;
//#]

//## package Default

//## class AirConditioner
class AirConditioner : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedAirConditioner;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    explicit AirConditioner(IOxfActive* const theActiveContext = NULL);
    
    //## auto_generated
    virtual ~AirConditioner(void);
    
    ////    Operations    ////
    
    //## operation SettingAirConditioner()
    virtual int SettingAirConditioner(void);
    
    //## operation callMain()
    virtual int callMain(void);
    
    //## operation callMain_copy()
    virtual int callMain_copy(void);
    
    //## operation getSpeed()
    virtual float getSpeed(void);
    
    //## operation getTemperaturegoal()
    virtual float getTemperaturegoal(void);
    
    ////    Additional operations    ////
    
    //## auto_generated
    const SOCKADDR_IN getAddress_temperaturegoal(void) const;
    
    //## auto_generated
    void setAddress_temperaturegoal(const SOCKADDR_IN p_address_temperaturegoal);
    
    //## auto_generated
    const float getDif(void) const;
    
    //## auto_generated
    void setDif(const float p_dif);
    
    //## auto_generated
    const float getHvac(void) const;
    
    //## auto_generated
    void setHvac(const float p_hvac);
    
    //## auto_generated
    const int getIResultTemperaturegoal(void) const;
    
    //## auto_generated
    void setIResultTemperaturegoal(const int p_iResultTemperaturegoal);
    
    //## auto_generated
    const int getISendResultTemperaturegoal(void) const;
    
    //## auto_generated
    void setISendResultTemperaturegoal(const int p_iSendResultTemperaturegoal);
    
    //## auto_generated
    const SOCKET getListenSocketForTemperaturegoal(void) const;
    
    //## auto_generated
    void setListenSocketForTemperaturegoal(const SOCKET p_listenSocketForTemperaturegoal);
    
    //## auto_generated
    const int getMode(void) const;
    
    //## auto_generated
    void setMode(const int p_mode);
    
    //## auto_generated
    const int getPortTemperaturegoal(void) const;
    
    //## auto_generated
    void setPortTemperaturegoal(const int p_portTemperaturegoal);
    
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
    void setTemperaturegoal(const float p_temperaturegoal);
    
    //## auto_generated
    const float getTemperatureroom(void) const;
    
    //## auto_generated
    void setTemperatureroom(const float p_temperatureroom);
    
    //## auto_generated
    const WSADATA getWs(void) const;
    
    //## auto_generated
    void setWs(const WSADATA p_ws);
    
    //## auto_generated
    const HVAC* getItsHVAC(void) const;
    
    //## auto_generated
    void setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    const TemperatureSensor* getItsTemperatureSensor(void) const;
    
    //## auto_generated
    void setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor);
    
    //## auto_generated
    const TemperatureSensor* getItsTemperatureSensor_1(void) const;
    
    //## auto_generated
    void setItsTemperatureSensor_1(TemperatureSensor* const p_TemperatureSensor);
    
    //## auto_generated
    const TemperatureSensor* getItsTemperatureSensor_2(void) const;
    
    //## auto_generated
    void setItsTemperatureSensor_2(TemperatureSensor* const p_TemperatureSensor);
    
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

    SOCKADDR_IN address_temperaturegoal;		//## attribute address_temperaturegoal
    
    float dif;		//## attribute dif
    
    float hvac;		//## attribute hvac
    
    int iResultTemperaturegoal;		//## attribute iResultTemperaturegoal
    
    int iSendResultTemperaturegoal;		//## attribute iSendResultTemperaturegoal
    
    SOCKET listenSocketForTemperaturegoal;		//## attribute listenSocketForTemperaturegoal
    
    int mode;		//## attribute mode
    
    int portTemperaturegoal;		//## attribute portTemperaturegoal
    
    char recvbuf[DEFAULT_BUFLEN];		//## attribute recvbuf
    
    int recvbuflen;		//## attribute recvbuflen
    
    char* serverName;		//## attribute serverName
    
    const float speed;		//## attribute speed
    
    float temperaturegoal;		//## attribute temperaturegoal
    
    float temperatureroom;		//## attribute temperatureroom
    
    WSADATA ws;		//## attribute ws
    
    ////    Relations and components    ////
    
    HVAC* itsHVAC;		//## link itsHVAC
    
    TemperatureSensor* itsTemperatureSensor;		//## link itsTemperatureSensor
    
    TemperatureSensor* itsTemperatureSensor_1;		//## link itsTemperatureSensor_1
    
    TemperatureSensor* itsTemperatureSensor_2;		//## link itsTemperatureSensor_2
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    void _setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    void _clearItsHVAC(void);
    
    //## auto_generated
    void __setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor);
    
    //## auto_generated
    void _setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor);
    
    //## auto_generated
    void _clearItsTemperatureSensor(void);
    
    //## auto_generated
    void __setItsTemperatureSensor_2(TemperatureSensor* const p_TemperatureSensor);
    
    //## auto_generated
    void _setItsTemperatureSensor_2(TemperatureSensor* const p_TemperatureSensor);
    
    //## auto_generated
    void _clearItsTemperatureSensor_2(void);
    
    // rootState:
    //## statechart_method
    inline RhpBoolean rootState_IN(void) const;
    
    // state_8:
    //## statechart_method
    inline RhpBoolean state_8_IN(void) const;
    
    //## statechart_method
    void state_8_entDef(void);
    
    //## statechart_method
    void state_8_exit(void);
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_8_processEvent(void);
    
    // state_9:
    //## statechart_method
    inline RhpBoolean state_9_IN(void) const;
    
    //## statechart_method
    void state_9_entDef(void);
    
    //## statechart_method
    void state_9_exit(void);
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_9_processEvent(void);
    
    // Off:
    //## statechart_method
    inline RhpBoolean Off_IN(void) const;
    
    // Heating:
    //## statechart_method
    inline RhpBoolean Heating_IN(void) const;
    
    // Cooling:
    //## statechart_method
    inline RhpBoolean Cooling_IN(void) const;
    
    // accepttimeevent_6:
    //## statechart_method
    inline RhpBoolean accepttimeevent_6_IN(void) const;
    
    // accepttimeevent_5:
    //## statechart_method
    inline RhpBoolean accepttimeevent_5_IN(void) const;
    
    // accepttimeevent_4:
    //## statechart_method
    inline RhpBoolean accepttimeevent_4_IN(void) const;
    
    // accepttimeevent_13:
    //## statechart_method
    inline RhpBoolean accepttimeevent_13_IN(void) const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus accepttimeevent_13TakeNull(void);
    
    //## statechart_method
    IOxfReactive::TakeEventStatus accepttimeevent_13_handleEvent(void);
    
    // state_10:
    //## statechart_method
    inline RhpBoolean state_10_IN(void) const;
    
    //## statechart_method
    void state_10_entDef(void);
    
    //## statechart_method
    void state_10_exit(void);
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_10_processEvent(void);
    
    // SendAndRecieve:
    //## statechart_method
    inline RhpBoolean SendAndRecieve_IN(void) const;

protected :

    //## statechart_method
    virtual void rootState_entDef(void);
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent(void);
    
    ////    Framework    ////
    
//#[ ignore
    enum AirConditioner_Enum {
        OMNonState = 0,
        state_8 = 1,
        state_9 = 2,
        Off = 3,
        Heating = 4,
        Cooling = 5,
        accepttimeevent_6 = 6,
        accepttimeevent_5 = 7,
        accepttimeevent_4 = 8,
        accepttimeevent_13 = 9,
        state_10 = 10,
        SendAndRecieve = 11
    };
//#]

private :

//#[ ignore
    AirConditioner_Enum rootState_subState;
    
    AirConditioner_Enum rootState_active;
    
    AirConditioner_Enum state_9_subState;
    
    AirConditioner_Enum state_9_active;
    
    IOxfTimeout* state_9_timeout;
    
    AirConditioner_Enum state_10_subState;
    
    AirConditioner_Enum state_10_active;
    
    IOxfTimeout* state_10_timeout;
//#]
};

#ifdef _OMINSTRUMENT
DECLARE_OPERATION_CLASS(Default_AirConditioner_setTemperaturegoal_float)

//#[ ignore
class OMAnimatedAirConditioner : virtual public AOMInstance {
    DECLARE_REACTIVE_META(AirConditioner, OMAnimatedAirConditioner)
    
    DECLARE_META_OP(Default_AirConditioner_setTemperaturegoal_float)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_8_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_9_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Off_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Heating_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Cooling_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_6_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_5_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_4_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_13_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_10_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void SendAndRecieve_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline RhpBoolean AirConditioner::rootState_IN(void) const {
    return true;
}

inline RhpBoolean AirConditioner::state_8_IN(void) const {
    return rootState_subState == state_8;
}

inline RhpBoolean AirConditioner::state_9_IN(void) const {
    return state_8_IN();
}

inline RhpBoolean AirConditioner::Off_IN(void) const {
    return state_9_subState == Off;
}

inline RhpBoolean AirConditioner::Heating_IN(void) const {
    return state_9_subState == Heating;
}

inline RhpBoolean AirConditioner::Cooling_IN(void) const {
    return state_9_subState == Cooling;
}

inline RhpBoolean AirConditioner::accepttimeevent_6_IN(void) const {
    return state_9_subState == accepttimeevent_6;
}

inline RhpBoolean AirConditioner::accepttimeevent_5_IN(void) const {
    return state_9_subState == accepttimeevent_5;
}

inline RhpBoolean AirConditioner::accepttimeevent_4_IN(void) const {
    return state_9_subState == accepttimeevent_4;
}

inline RhpBoolean AirConditioner::accepttimeevent_13_IN(void) const {
    return state_9_subState == accepttimeevent_13;
}

inline RhpBoolean AirConditioner::state_10_IN(void) const {
    return state_8_IN();
}

inline RhpBoolean AirConditioner::SendAndRecieve_IN(void) const {
    return state_10_subState == SendAndRecieve;
}

#endif
/*********************************************************************
	File Path	: component_3\DefaultConfig\AirConditioner.h
*********************************************************************/
