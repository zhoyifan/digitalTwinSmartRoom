/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: OccupancySensor
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\OccupancySensor.h
*********************************************************************/

#ifndef OccupancySensor_H
#define OccupancySensor_H

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
//## link itsCO2Sensor
class CO2Sensor;

//## link itsDTSR
class DTSR;

//## link itsTemperatureSensor
class TemperatureSensor;

//#[ ignore
#define OMAnim_Default_OccupancySensor_callMain_ARGS_DECLARATION

#define OMAnim_Default_OccupancySensor_setModifying_bool_bool_ARGS_DECLARATION bool p_modifying_bool;

#define OMAnim_Default_OccupancySensor_setOccupancy_bool_int_ARGS_DECLARATION int p_occupancy_bool;
//#]

//## package Default

//## class OccupancySensor
class OccupancySensor : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedOccupancySensor;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    explicit OccupancySensor(IOxfActive* const theActiveContext = NULL);
    
    //## auto_generated
    virtual ~OccupancySensor(void);
    
    ////    Operations    ////
    
    //## operation callMain()
    virtual int callMain(void);
    
    ////    Additional operations    ////
    
    //## auto_generated
    const SOCKADDR_IN getAddress_occupancy(void) const;
    
    //## auto_generated
    void setAddress_occupancy(const SOCKADDR_IN p_address_occupancy);
    
    //## auto_generated
    const int getIResultOccupancy(void) const;
    
    //## auto_generated
    void setIResultOccupancy(const int p_iResultOccupancy);
    
    //## auto_generated
    const int getISendResultOccupancy(void) const;
    
    //## auto_generated
    void setISendResultOccupancy(const int p_iSendResultOccupancy);
    
    //## auto_generated
    const SOCKET getListenSocketForOccupancy(void) const;
    
    //## auto_generated
    void setListenSocketForOccupancy(const SOCKET p_listenSocketForOccupancy);
    
    //## auto_generated
    const bool getModifying_bool(void) const;
    
    //## auto_generated
    void setModifying_bool(const bool p_modifying_bool);
    
    //## auto_generated
    const float getOccupancy(void) const;
    
    //## auto_generated
    void setOccupancy(const float p_occupancy);
    
    //## auto_generated
    const int getOccupancy_bool(void) const;
    
    //## auto_generated
    void setOccupancy_bool(const int p_occupancy_bool);
    
    //## auto_generated
    const int getPortOccupancy(void) const;
    
    //## auto_generated
    void setPortOccupancy(const int p_portOccupancy);
    
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
    const CO2Sensor* getItsCO2Sensor(void) const;
    
    //## auto_generated
    void setItsCO2Sensor(CO2Sensor* const p_CO2Sensor);
    
    //## auto_generated
    const DTSR* getItsDTSR(void) const;
    
    //## auto_generated
    void setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    const TemperatureSensor* getItsTemperatureSensor(void) const;
    
    //## auto_generated
    void setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor);
    
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

    SOCKADDR_IN address_occupancy;		//## attribute address_occupancy
    
    int iResultOccupancy;		//## attribute iResultOccupancy
    
    int iSendResultOccupancy;		//## attribute iSendResultOccupancy
    
    SOCKET listenSocketForOccupancy;		//## attribute listenSocketForOccupancy
    
    bool modifying_bool;		//## attribute modifying_bool
    
    float occupancy;		//## attribute occupancy
    
    int occupancy_bool;		//## attribute occupancy_bool
    
    int portOccupancy;		//## attribute portOccupancy
    
    char recvbuf[DEFAULT_BUFLEN];		//## attribute recvbuf
    
    int recvbuflen;		//## attribute recvbuflen
    
    char* serverName;		//## attribute serverName
    
    WSADATA ws;		//## attribute ws
    
    ////    Relations and components    ////
    
    CO2Sensor* itsCO2Sensor;		//## link itsCO2Sensor
    
    DTSR* itsDTSR;		//## link itsDTSR
    
    TemperatureSensor* itsTemperatureSensor;		//## link itsTemperatureSensor
    
    ////    Framework operations    ////

public :

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
    void __setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor);
    
    //## auto_generated
    void _setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor);
    
    //## auto_generated
    void _clearItsTemperatureSensor(void);
    
    // rootState:
    //## statechart_method
    inline RhpBoolean rootState_IN(void) const;
    
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
    enum OccupancySensor_Enum {
        OMNonState = 0,
        SendAndRecieve = 1
    };
//#]

private :

//#[ ignore
    OccupancySensor_Enum rootState_subState;
    
    OccupancySensor_Enum rootState_active;
    
    IOxfTimeout* rootState_timeout;
//#]
};

#ifdef _OMINSTRUMENT
DECLARE_OPERATION_CLASS(Default_OccupancySensor_callMain)

DECLARE_OPERATION_CLASS(Default_OccupancySensor_setModifying_bool_bool)

DECLARE_OPERATION_CLASS(Default_OccupancySensor_setOccupancy_bool_int)

//#[ ignore
class OMAnimatedOccupancySensor : virtual public AOMInstance {
    DECLARE_REACTIVE_META(OccupancySensor, OMAnimatedOccupancySensor)
    
    DECLARE_META_OP(Default_OccupancySensor_callMain)
    
    DECLARE_META_OP(Default_OccupancySensor_setModifying_bool_bool)
    
    DECLARE_META_OP(Default_OccupancySensor_setOccupancy_bool_int)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void SendAndRecieve_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline RhpBoolean OccupancySensor::rootState_IN(void) const {
    return true;
}

inline RhpBoolean OccupancySensor::SendAndRecieve_IN(void) const {
    return rootState_subState == SendAndRecieve;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\OccupancySensor.h
*********************************************************************/
