/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: HVAC
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\HVAC.h
*********************************************************************/

#ifndef HVAC_H
#define HVAC_H

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
//## link itsAirConditioner
class AirConditioner;

//## link itsCO2Sensor
class CO2Sensor;

//## link itsDTSR
class DTSR;

//## link itsFireAlarm
class FireAlarm;

//## link itsFireSensor
class FireSensor;

//## link itsTemperatureSensor
class TemperatureSensor;

//## link itsVentilation
class Ventilation;

//#[ ignore
#define OMAnim_Default_HVAC_setMode_int_ARGS_DECLARATION int p_mode;
//#]

//## package Default

//## class HVAC
class HVAC : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedHVAC;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    explicit HVAC(IOxfActive* const theActiveContext = NULL);
    
    //## auto_generated
    virtual ~HVAC(void);
    
    ////    Operations    ////
    
    //## operation callMain()
    virtual int callMain(void);
    
    //## operation getHvac()
    virtual float getHvac(void);
    
    //## operation getMode()
    virtual int getMode(void);
    
    //## operation setHvac(float)
    virtual void setHvac(float newValue);
    
    ////    Additional operations    ////
    
    //## auto_generated
    const SOCKADDR_IN getAddress_hvac(void) const;
    
    //## auto_generated
    void setAddress_hvac(const SOCKADDR_IN p_address_hvac);
    
    //## auto_generated
    const int getIResultHvac(void) const;
    
    //## auto_generated
    void setIResultHvac(const int p_iResultHvac);
    
    //## auto_generated
    const int getISendResultHvac(void) const;
    
    //## auto_generated
    void setISendResultHvac(const int p_iSendResultHvac);
    
    //## auto_generated
    const SOCKET getListenSocketForHvac(void) const;
    
    //## auto_generated
    void setListenSocketForHvac(const SOCKET p_listenSocketForHvac);
    
    //## auto_generated
    void setMode(const int p_mode);
    
    //## auto_generated
    const int getPortHvac(void) const;
    
    //## auto_generated
    void setPortHvac(const int p_portHvac);
    
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
    const AirConditioner* getItsAirConditioner(void) const;
    
    //## auto_generated
    void setItsAirConditioner(AirConditioner* const p_AirConditioner);
    
    //## auto_generated
    const CO2Sensor* getItsCO2Sensor(void) const;
    
    //## auto_generated
    void setItsCO2Sensor(CO2Sensor* const p_CO2Sensor);
    
    //## auto_generated
    const DTSR* getItsDTSR(void) const;
    
    //## auto_generated
    void setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    const FireAlarm* getItsFireAlarm(void) const;
    
    //## auto_generated
    void setItsFireAlarm(FireAlarm* const p_FireAlarm);
    
    //## auto_generated
    const FireSensor* getItsFireSensor(void) const;
    
    //## auto_generated
    void setItsFireSensor(FireSensor* const p_FireSensor);
    
    //## auto_generated
    const TemperatureSensor* getItsTemperatureSensor(void) const;
    
    //## auto_generated
    void setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor);
    
    //## auto_generated
    const Ventilation* getItsVentilation(void) const;
    
    //## auto_generated
    void setItsVentilation(Ventilation* const p_Ventilation);
    
    //## auto_generated
    const Ventilation* getItsVentilation_1(void) const;
    
    //## auto_generated
    void setItsVentilation_1(Ventilation* const p_Ventilation);
    
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

    SOCKADDR_IN address_hvac;		//## attribute address_hvac
    
    float hvac;		//## attribute hvac
    
    int iResultHvac;		//## attribute iResultHvac
    
    int iSendResultHvac;		//## attribute iSendResultHvac
    
    SOCKET listenSocketForHvac;		//## attribute listenSocketForHvac
    
    int mode;		//## attribute mode
    
    int portHvac;		//## attribute portHvac
    
    char recvbuf[DEFAULT_BUFLEN];		//## attribute recvbuf
    
    int recvbuflen;		//## attribute recvbuflen
    
    char* serverName;		//## attribute serverName
    
    WSADATA ws;		//## attribute ws
    
    ////    Relations and components    ////
    
    AirConditioner* itsAirConditioner;		//## link itsAirConditioner
    
    CO2Sensor* itsCO2Sensor;		//## link itsCO2Sensor
    
    DTSR* itsDTSR;		//## link itsDTSR
    
    FireAlarm* itsFireAlarm;		//## link itsFireAlarm
    
    FireSensor* itsFireSensor;		//## link itsFireSensor
    
    TemperatureSensor* itsTemperatureSensor;		//## link itsTemperatureSensor
    
    Ventilation* itsVentilation;		//## link itsVentilation
    
    Ventilation* itsVentilation_1;		//## link itsVentilation_1
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsAirConditioner(AirConditioner* const p_AirConditioner);
    
    //## auto_generated
    void _setItsAirConditioner(AirConditioner* const p_AirConditioner);
    
    //## auto_generated
    void _clearItsAirConditioner(void);
    
    //## auto_generated
    void __setItsCO2Sensor(CO2Sensor* const p_CO2Sensor);
    
    //## auto_generated
    void _setItsCO2Sensor(CO2Sensor* const p_CO2Sensor);
    
    //## auto_generated
    void _clearItsCO2Sensor(void);
    
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
    void __setItsFireSensor(FireSensor* const p_FireSensor);
    
    //## auto_generated
    void _setItsFireSensor(FireSensor* const p_FireSensor);
    
    //## auto_generated
    void _clearItsFireSensor(void);
    
    //## auto_generated
    void __setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor);
    
    //## auto_generated
    void _setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor);
    
    //## auto_generated
    void _clearItsTemperatureSensor(void);
    
    //## auto_generated
    void __setItsVentilation(Ventilation* const p_Ventilation);
    
    //## auto_generated
    void _setItsVentilation(Ventilation* const p_Ventilation);
    
    //## auto_generated
    void _clearItsVentilation(void);
    
    //## auto_generated
    void __setItsVentilation_1(Ventilation* const p_Ventilation);
    
    //## auto_generated
    void _setItsVentilation_1(Ventilation* const p_Ventilation);
    
    //## auto_generated
    void _clearItsVentilation_1(void);
    
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
    
    // Ventilation_:
    //## statechart_method
    inline RhpBoolean Ventilation__IN(void) const;
    
    // Off:
    //## statechart_method
    inline RhpBoolean Off_IN(void) const;
    
    // AirConditioner_:
    //## statechart_method
    inline RhpBoolean AirConditioner__IN(void) const;
    
    // accepttimeevent_21:
    //## statechart_method
    inline RhpBoolean accepttimeevent_21_IN(void) const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus accepttimeevent_21_handleEvent(void);
    
    // accepttimeevent_20:
    //## statechart_method
    inline RhpBoolean accepttimeevent_20_IN(void) const;
    
    // accepttimeevent_19:
    //## statechart_method
    inline RhpBoolean accepttimeevent_19_IN(void) const;
    
    // accepttimeevent_18:
    //## statechart_method
    inline RhpBoolean accepttimeevent_18_IN(void) const;

protected :

    //## statechart_method
    virtual void rootState_entDef(void);
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent(void);
    
    ////    Framework    ////
    
//#[ ignore
    enum HVAC_Enum {
        OMNonState = 0,
        state_0 = 1,
        state_2 = 2,
        SendAndRecieve = 3,
        state_1 = 4,
        Ventilation_ = 5,
        Off = 6,
        AirConditioner_ = 7,
        accepttimeevent_21 = 8,
        accepttimeevent_20 = 9,
        accepttimeevent_19 = 10,
        accepttimeevent_18 = 11
    };
//#]

private :

//#[ ignore
    HVAC_Enum rootState_subState;
    
    HVAC_Enum rootState_active;
    
    HVAC_Enum state_2_subState;
    
    HVAC_Enum state_2_active;
    
    IOxfTimeout* state_2_timeout;
    
    HVAC_Enum state_1_subState;
    
    HVAC_Enum state_1_active;
    
    IOxfTimeout* state_1_timeout;
//#]
};

#ifdef _OMINSTRUMENT
DECLARE_OPERATION_CLASS(Default_HVAC_setMode_int)

//#[ ignore
class OMAnimatedHVAC : virtual public AOMInstance {
    DECLARE_REACTIVE_META(HVAC, OMAnimatedHVAC)
    
    DECLARE_META_OP(Default_HVAC_setMode_int)
    
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
    void Ventilation__serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Off_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void AirConditioner__serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_21_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_20_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_19_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void accepttimeevent_18_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline RhpBoolean HVAC::rootState_IN(void) const {
    return true;
}

inline RhpBoolean HVAC::state_0_IN(void) const {
    return rootState_subState == state_0;
}

inline RhpBoolean HVAC::state_2_IN(void) const {
    return state_0_IN();
}

inline RhpBoolean HVAC::SendAndRecieve_IN(void) const {
    return state_2_subState == SendAndRecieve;
}

inline RhpBoolean HVAC::state_1_IN(void) const {
    return state_0_IN();
}

inline RhpBoolean HVAC::Ventilation__IN(void) const {
    return state_1_subState == Ventilation_;
}

inline RhpBoolean HVAC::Off_IN(void) const {
    return state_1_subState == Off;
}

inline RhpBoolean HVAC::AirConditioner__IN(void) const {
    return state_1_subState == AirConditioner_;
}

inline RhpBoolean HVAC::accepttimeevent_21_IN(void) const {
    return state_1_subState == accepttimeevent_21;
}

inline RhpBoolean HVAC::accepttimeevent_20_IN(void) const {
    return state_1_subState == accepttimeevent_20;
}

inline RhpBoolean HVAC::accepttimeevent_19_IN(void) const {
    return state_1_subState == accepttimeevent_19;
}

inline RhpBoolean HVAC::accepttimeevent_18_IN(void) const {
    return state_1_subState == accepttimeevent_18;
}

#endif
/*********************************************************************
	File Path	: component_3\DefaultConfig\HVAC.h
*********************************************************************/
