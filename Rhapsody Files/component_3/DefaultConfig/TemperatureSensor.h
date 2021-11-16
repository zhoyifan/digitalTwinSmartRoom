/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: TemperatureSensor
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\TemperatureSensor.h
*********************************************************************/

#ifndef TemperatureSensor_H
#define TemperatureSensor_H

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

//## link itsOccupancySensor
class OccupancySensor;

//#[ ignore
#define OMAnim_Default_TemperatureSensor_setTemperatureroom_float_ARGS_DECLARATION float p_temperatureroom;
//#]

//## link itsAirConditioner
class AirConditioner;

//## link itsHVAC
class HVAC;

//## package Default

//## class TemperatureSensor
class TemperatureSensor : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedTemperatureSensor;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    explicit TemperatureSensor(IOxfActive* const theActiveContext = NULL);
    
    //## auto_generated
    virtual ~TemperatureSensor(void);
    
    ////    Operations    ////
    
    //## operation changeFromAirConditioner()
    virtual int changeFromAirConditioner(void);
    
    //## operation getTemperatureroom()
    virtual float getTemperatureroom(void);
    
    ////    Additional operations    ////
    
    //## auto_generated
    const bool getModifying_bool(void) const;
    
    //## auto_generated
    void setTemperatureroom(const float p_temperatureroom);
    
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
    
    ////    Relations and components    ////

private :

    HVAC* itsHVAC;		//## link itsHVAC
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    void _setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    void _clearItsHVAC(void);
    
    ////    Framework    ////
    
    //## operation callMain()
    virtual int callMain(void);
    
    //## auto_generated
    const SOCKADDR_IN getAddress_temperatureroom(void) const;
    
    //## auto_generated
    void setAddress_temperatureroom(const SOCKADDR_IN p_address_temperatureroom);
    
    //## auto_generated
    const int getIResultTemperatureroom(void) const;
    
    //## auto_generated
    void setIResultTemperatureroom(const int p_iResultTemperatureroom);
    
    //## auto_generated
    const int getISendResultTemperatureroom(void) const;
    
    //## auto_generated
    void setISendResultTemperatureroom(const int p_iSendResultTemperatureroom);
    
    //## auto_generated
    const SOCKET getListenSocketForTemperatureroom(void) const;
    
    //## auto_generated
    void setListenSocketForTemperatureroom(const SOCKET p_listenSocketForTemperatureroom);
    
    //## auto_generated
    const int getPortTemperatureroom(void) const;
    
    //## auto_generated
    void setPortTemperatureroom(const int p_portTemperatureroom);
    
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
    const float getSpeed(void) const;
    
    //## auto_generated
    void setSpeed(const float p_speed);
    
    //## auto_generated
    const WSADATA getWs(void) const;
    
    //## auto_generated
    void setWs(const WSADATA p_ws);
    
    //## auto_generated
    const AirConditioner* getItsAirConditioner(void) const;
    
    //## auto_generated
    void setItsAirConditioner(AirConditioner* const p_AirConditioner);
    
    //## auto_generated
    const AirConditioner* getItsAirConditioner_2(void) const;
    
    //## auto_generated
    void setItsAirConditioner_2(AirConditioner* const p_AirConditioner);

private :

    SOCKADDR_IN address_temperatureroom;		//## attribute address_temperatureroom
    
    int iResultTemperatureroom;		//## attribute iResultTemperatureroom
    
    int iSendResultTemperatureroom;		//## attribute iSendResultTemperatureroom
    
    SOCKET listenSocketForTemperatureroom;		//## attribute listenSocketForTemperatureroom
    
    bool modifying_bool;		//## attribute modifying_bool
    
    int portTemperatureroom;		//## attribute portTemperatureroom
    
    char recvbuf[DEFAULT_BUFLEN];		//## attribute recvbuf
    
    int recvbuflen;		//## attribute recvbuflen
    
    char* serverName;		//## attribute serverName
    
    float speed;		//## attribute speed
    
    float temperatureroom;		//## attribute temperatureroom
    
    WSADATA ws;		//## attribute ws
    
    AirConditioner* itsAirConditioner;		//## link itsAirConditioner
    
    AirConditioner* itsAirConditioner_2;		//## link itsAirConditioner_2

public :

    //## auto_generated
    void __setItsAirConditioner(AirConditioner* const p_AirConditioner);
    
    //## auto_generated
    void _setItsAirConditioner(AirConditioner* const p_AirConditioner);
    
    //## auto_generated
    void _clearItsAirConditioner(void);
    
    //## auto_generated
    void __setItsAirConditioner_2(AirConditioner* const p_AirConditioner);
    
    //## auto_generated
    void _setItsAirConditioner_2(AirConditioner* const p_AirConditioner);
    
    //## auto_generated
    void _clearItsAirConditioner_2(void);
    
    //## operation setModifying_bool(bool)
    virtual void setModifying_bool(bool newValue);
    
    //## auto_generated
    const DTSR* getItsDTSR(void) const;
    
    //## auto_generated
    void setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    const OccupancySensor* getItsOccupancySensor(void) const;
    
    //## auto_generated
    void setItsOccupancySensor(OccupancySensor* const p_OccupancySensor);

private :

    DTSR* itsDTSR;		//## link itsDTSR
    
    OccupancySensor* itsOccupancySensor;		//## link itsOccupancySensor

public :

    //## auto_generated
    void __setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    void _setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    void _clearItsDTSR(void);
    
    //## auto_generated
    void __setItsOccupancySensor(OccupancySensor* const p_OccupancySensor);
    
    //## auto_generated
    void _setItsOccupancySensor(OccupancySensor* const p_OccupancySensor);
    
    //## auto_generated
    void _clearItsOccupancySensor(void);
    
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
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_5_processEvent(void);
    
    // state_11:
    //## statechart_method
    inline RhpBoolean state_11_IN(void) const;
    
    //## statechart_method
    void state_11_entDef(void);
    
    //## statechart_method
    void state_11_exit(void);
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_11_processEvent(void);
    
    // SendAndRecieve:
    //## statechart_method
    inline RhpBoolean SendAndRecieve_IN(void) const;
    
    // state_10:
    //## statechart_method
    inline RhpBoolean state_10_IN(void) const;
    
    //## statechart_method
    void state_10_entDef(void);
    
    //## statechart_method
    void state_10_exit(void);
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_10_processEvent(void);
    
    // Normal:
    //## statechart_method
    inline RhpBoolean Normal_IN(void) const;
    
    // Modifying:
    //## statechart_method
    inline RhpBoolean Modifying_IN(void) const;
    
    // accepttimeevent_4:
    //## statechart_method
    inline RhpBoolean accepttimeevent_4_IN(void) const;
    
    // accepttimeevent_3:
    //## statechart_method
    inline RhpBoolean accepttimeevent_3_IN(void) const;

protected :

    //## statechart_method
    virtual void rootState_entDef(void);
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent(void);
    
//#[ ignore
    enum TemperatureSensor_Enum {
        OMNonState = 0,
        state_5 = 1,
        state_11 = 2,
        SendAndRecieve = 3,
        state_10 = 4,
        Normal = 5,
        Modifying = 6,
        accepttimeevent_4 = 7,
        accepttimeevent_3 = 8
    };
//#]

private :

//#[ ignore
    TemperatureSensor_Enum rootState_subState;
    
    TemperatureSensor_Enum rootState_active;
    
    TemperatureSensor_Enum state_11_subState;
    
    TemperatureSensor_Enum state_11_active;
    
    IOxfTimeout* state_11_timeout;
    
    TemperatureSensor_Enum state_10_subState;
    
    TemperatureSensor_Enum state_10_active;
    
    IOxfTimeout* state_10_timeout;
//#]
};

#ifdef _OMINSTRUMENT
DECLARE_OPERATION_CLASS(Default_TemperatureSensor_setTemperatureroom_float)

//#[ ignore
class OMAnimatedTemperatureSensor : virtual public AOMInstance {
    DECLARE_REACTIVE_META(TemperatureSensor, OMAnimatedTemperatureSensor)
    
    DECLARE_META_OP(Default_TemperatureSensor_setTemperatureroom_float)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_5_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_11_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void SendAndRecieve_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_10_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Normal_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Modifying_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_4_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_3_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline RhpBoolean TemperatureSensor::rootState_IN(void) const {
    return true;
}

inline RhpBoolean TemperatureSensor::state_5_IN(void) const {
    return rootState_subState == state_5;
}

inline RhpBoolean TemperatureSensor::state_11_IN(void) const {
    return state_5_IN();
}

inline RhpBoolean TemperatureSensor::SendAndRecieve_IN(void) const {
    return state_11_subState == SendAndRecieve;
}

inline RhpBoolean TemperatureSensor::state_10_IN(void) const {
    return state_5_IN();
}

inline RhpBoolean TemperatureSensor::Normal_IN(void) const {
    return state_10_subState == Normal;
}

inline RhpBoolean TemperatureSensor::Modifying_IN(void) const {
    return state_10_subState == Modifying;
}

inline RhpBoolean TemperatureSensor::accepttimeevent_4_IN(void) const {
    return state_10_subState == accepttimeevent_4;
}

inline RhpBoolean TemperatureSensor::accepttimeevent_3_IN(void) const {
    return state_10_subState == accepttimeevent_3;
}

#endif
/*********************************************************************
	File Path	: component_3\DefaultConfig\TemperatureSensor.h
*********************************************************************/
