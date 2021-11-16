/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: CO2Sensor
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\CO2Sensor.h
*********************************************************************/

#ifndef CO2Sensor_H
#define CO2Sensor_H

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

//## link itsHVAC
class HVAC;

//## link itsOccupancySensor
class OccupancySensor;

//## link itsVentilation
class Ventilation;

//#[ ignore
#define OMAnim_Default_CO2Sensor_setCo2density_float_ARGS_DECLARATION float p_co2density;
//#]

//## package Default

//## class CO2Sensor
class CO2Sensor : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedCO2Sensor;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    explicit CO2Sensor(IOxfActive* const theActiveContext = NULL);
    
    //## auto_generated
    virtual ~CO2Sensor(void);
    
    ////    Operations    ////
    
    //## operation callMain()
    virtual int callMain(void);
    
    //## operation changeFromHVAC()
    virtual int changeFromHVAC(void);
    
    //## operation getCo2density()
    virtual float getCo2density(void);
    
    //## operation initilializeCo2sensor()
    virtual void initilializeCo2sensor(void);
    
    //## operation setModifying_bool(bool)
    virtual void setModifying_bool(bool newValue);
    
    ////    Additional operations    ////
    
    //## auto_generated
    const SOCKADDR_IN getAddress_co2density(void) const;
    
    //## auto_generated
    void setAddress_co2density(const SOCKADDR_IN p_address_co2density);
    
    //## auto_generated
    void setCo2density(const float p_co2density);
    
    //## auto_generated
    const float getCo2highgoal(void) const;
    
    //## auto_generated
    void setCo2highgoal(const float p_co2highgoal);
    
    //## auto_generated
    const float getCo2lowgoal(void) const;
    
    //## auto_generated
    void setCo2lowgoal(const float p_co2lowgoal);
    
    //## auto_generated
    const int getIResultCo2density(void) const;
    
    //## auto_generated
    void setIResultCo2density(const int p_iResultCo2density);
    
    //## auto_generated
    const int getISendResultCo2density(void) const;
    
    //## auto_generated
    void setISendResultCo2density(const int p_iSendResultCo2density);
    
    //## auto_generated
    const SOCKET getListenSocketForCo2density(void) const;
    
    //## auto_generated
    void setListenSocketForCo2density(const SOCKET p_listenSocketForCo2density);
    
    //## auto_generated
    const bool getModifying_bool(void) const;
    
    //## auto_generated
    const int getPortCo2density(void) const;
    
    //## auto_generated
    void setPortCo2density(const int p_portCo2density);
    
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
    const DTSR* getItsDTSR(void) const;
    
    //## auto_generated
    void setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    const HVAC* getItsHVAC(void) const;
    
    //## auto_generated
    void setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    const OccupancySensor* getItsOccupancySensor(void) const;
    
    //## auto_generated
    void setItsOccupancySensor(OccupancySensor* const p_OccupancySensor);
    
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

    SOCKADDR_IN address_co2density;		//## attribute address_co2density
    
    float co2density;		//## attribute co2density
    
    float co2highgoal;		//## attribute co2highgoal
    
    float co2lowgoal;		//## attribute co2lowgoal
    
    int iResultCo2density;		//## attribute iResultCo2density
    
    int iSendResultCo2density;		//## attribute iSendResultCo2density
    
    SOCKET listenSocketForCo2density;		//## attribute listenSocketForCo2density
    
    bool modifying_bool;		//## attribute modifying_bool
    
    int portCo2density;		//## attribute portCo2density
    
    char recvbuf[DEFAULT_BUFLEN];		//## attribute recvbuf
    
    int recvbuflen;		//## attribute recvbuflen
    
    char* serverName;		//## attribute serverName
    
    float speed;		//## attribute speed
    
    WSADATA ws;		//## attribute ws
    
    ////    Relations and components    ////
    
    DTSR* itsDTSR;		//## link itsDTSR
    
    HVAC* itsHVAC;		//## link itsHVAC
    
    OccupancySensor* itsOccupancySensor;		//## link itsOccupancySensor
    
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
    void __setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    void _setItsHVAC(HVAC* const p_HVAC);
    
    //## auto_generated
    void _clearItsHVAC(void);
    
    //## auto_generated
    void __setItsOccupancySensor(OccupancySensor* const p_OccupancySensor);
    
    //## auto_generated
    void _setItsOccupancySensor(OccupancySensor* const p_OccupancySensor);
    
    //## auto_generated
    void _clearItsOccupancySensor(void);
    
    //## auto_generated
    void __setItsVentilation(Ventilation* const p_Ventilation);
    
    //## auto_generated
    void _setItsVentilation(Ventilation* const p_Ventilation);
    
    //## auto_generated
    void _clearItsVentilation(void);
    
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
    
    // state_7:
    //## statechart_method
    inline RhpBoolean state_7_IN(void) const;
    
    //## statechart_method
    void state_7_entDef(void);
    
    //## statechart_method
    void state_7_exit(void);
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_7_processEvent(void);
    
    // SendAndRecieve:
    //## statechart_method
    inline RhpBoolean SendAndRecieve_IN(void) const;
    
    // state_6:
    //## statechart_method
    inline RhpBoolean state_6_IN(void) const;
    
    //## statechart_method
    void state_6_entDef(void);
    
    //## statechart_method
    void state_6_exit(void);
    
    //## statechart_method
    IOxfReactive::TakeEventStatus state_6_processEvent(void);
    
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
    
    ////    Framework    ////
    
//#[ ignore
    enum CO2Sensor_Enum {
        OMNonState = 0,
        state_5 = 1,
        state_7 = 2,
        SendAndRecieve = 3,
        state_6 = 4,
        Normal = 5,
        Modifying = 6,
        accepttimeevent_4 = 7,
        accepttimeevent_3 = 8
    };
//#]

private :

//#[ ignore
    CO2Sensor_Enum rootState_subState;
    
    CO2Sensor_Enum rootState_active;
    
    CO2Sensor_Enum state_7_subState;
    
    CO2Sensor_Enum state_7_active;
    
    IOxfTimeout* state_7_timeout;
    
    CO2Sensor_Enum state_6_subState;
    
    CO2Sensor_Enum state_6_active;
    
    IOxfTimeout* state_6_timeout;
//#]
};

#ifdef _OMINSTRUMENT
DECLARE_OPERATION_CLASS(Default_CO2Sensor_setCo2density_float)

//#[ ignore
class OMAnimatedCO2Sensor : virtual public AOMInstance {
    DECLARE_REACTIVE_META(CO2Sensor, OMAnimatedCO2Sensor)
    
    DECLARE_META_OP(Default_CO2Sensor_setCo2density_float)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_5_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_7_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void SendAndRecieve_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void state_6_serializeStates(AOMSState* aomsState) const;
    
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

inline RhpBoolean CO2Sensor::rootState_IN(void) const {
    return true;
}

inline RhpBoolean CO2Sensor::state_5_IN(void) const {
    return rootState_subState == state_5;
}

inline RhpBoolean CO2Sensor::state_7_IN(void) const {
    return state_5_IN();
}

inline RhpBoolean CO2Sensor::SendAndRecieve_IN(void) const {
    return state_7_subState == SendAndRecieve;
}

inline RhpBoolean CO2Sensor::state_6_IN(void) const {
    return state_5_IN();
}

inline RhpBoolean CO2Sensor::Normal_IN(void) const {
    return state_6_subState == Normal;
}

inline RhpBoolean CO2Sensor::Modifying_IN(void) const {
    return state_6_subState == Modifying;
}

inline RhpBoolean CO2Sensor::accepttimeevent_4_IN(void) const {
    return state_6_subState == accepttimeevent_4;
}

inline RhpBoolean CO2Sensor::accepttimeevent_3_IN(void) const {
    return state_6_subState == accepttimeevent_3;
}

#endif
/*********************************************************************
	File Path	: component_3\DefaultConfig\CO2Sensor.h
*********************************************************************/
