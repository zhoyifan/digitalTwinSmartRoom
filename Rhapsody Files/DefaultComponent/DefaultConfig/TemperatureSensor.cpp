/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TemperatureSensor
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\TemperatureSensor.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "TemperatureSensor.h"
//## link itsHVAC
#include "HVAC.h"
//## link itsAirConditioner
#include "AirConditioner.h"
//## link itsDTSR
#include "DTSR.h"
//## link itsOccupancySensor
#include "OccupancySensor.h"
//#[ ignore
#define Default_TemperatureSensor_TemperatureSensor_SERIALIZE OM_NO_OP

#define Default_TemperatureSensor_callMain_SERIALIZE OM_NO_OP

#define OMAnim_Default_TemperatureSensor_callMain_UNSERIALIZE_ARGS

#define OMAnim_Default_TemperatureSensor_callMain_SERIALIZE_RET_VAL OP_SET_RET_VAL(animRetVal)

#define Default_TemperatureSensor_changeFromAirConditioner_SERIALIZE OM_NO_OP

#define OMAnim_Default_TemperatureSensor_changeFromAirConditioner_UNSERIALIZE_ARGS

#define OMAnim_Default_TemperatureSensor_changeFromAirConditioner_SERIALIZE_RET_VAL OP_SET_RET_VAL(animRetVal)

#define Default_TemperatureSensor_getTemperatureroom_SERIALIZE OM_NO_OP

#define OMAnim_Default_TemperatureSensor_getTemperatureroom_UNSERIALIZE_ARGS

#define OMAnim_Default_TemperatureSensor_getTemperatureroom_SERIALIZE_RET_VAL OP_SET_RET_VAL(animRetVal)

#define Default_TemperatureSensor_setModifying_bool_SERIALIZE aomsmethod->addAttribute("newValue", x2String(newValue));

#define OMAnim_Default_TemperatureSensor_setModifying_bool_bool_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,newValue)

#define OMAnim_Default_TemperatureSensor_setModifying_bool_bool_SERIALIZE_RET_VAL

#define OMAnim_Default_TemperatureSensor_setTemperatureroom_float_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_temperatureroom)

#define OMAnim_Default_TemperatureSensor_setTemperatureroom_float_SERIALIZE_RET_VAL
//#]

//## package Default

//## class TemperatureSensor
TemperatureSensor::TemperatureSensor(IOxfActive* const theActiveContext) : OMReactive(), itsHVAC(NULL), listenSocketForTemperatureroom(INVALID_SOCKET), modifying_bool(0), portTemperatureroom(10008), recvbuflen(DEFAULT_BUFLEN), serverName("127.0.0.1"), temperatureroom(20), itsAirConditioner(NULL), itsAirConditioner_2(NULL), itsDTSR(NULL), itsOccupancySensor(NULL) {
    NOTIFY_REACTIVE_CONSTRUCTOR(TemperatureSensor, TemperatureSensor(), 0, Default_TemperatureSensor_TemperatureSensor_SERIALIZE);
    setActiveContext(theActiveContext, false);
    initStatechart();
}

TemperatureSensor::~TemperatureSensor(void) {
    NOTIFY_DESTRUCTOR(~TemperatureSensor, true);
    cleanUpRelations();
    cancelTimeouts();
}

int TemperatureSensor::changeFromAirConditioner(void) {
    NOTIFY_OPERATION(changeFromAirConditioner, changeFromAirConditioner(), 0, Default_TemperatureSensor_changeFromAirConditioner_SERIALIZE);
    //#[ operation changeFromAirConditioner()
    //std::cout<<"itsHVAC->getMode() : "<<itsHVAC->getMode()<<std::endl;
    float temperaturegoal=itsAirConditioner->getTemperaturegoal();
    float dif=temperaturegoal-temperatureroom;
    //if(dif<speed && dif>(-1)*speed){
    //	temperatureroom=temperaturegoal;
    //	return 0;
    //} 
    
    float hvac=itsHVAC->getHvac();
    if((dif>=speed)&&(hvac==1)){
    	temperatureroom+=speed;
    }else if((dif<=(-1)*speed)&&(hvac==2)){
    	temperatureroom-=speed;
    }else if((dif>0)&&(hvac==1)){
    	temperatureroom=temperaturegoal;
    }else if((dif<0)&&(hvac==2)){
    	temperatureroom=temperaturegoal;
    }
    return 0;
    
    //#]
}

float TemperatureSensor::getTemperatureroom(void) {
    NOTIFY_OPERATION(getTemperatureroom, getTemperatureroom(), 0, Default_TemperatureSensor_getTemperatureroom_SERIALIZE);
    //#[ operation getTemperatureroom()
    //if(modifying_bool){
    //	return 1000;
    //}else{
    //	return temperatureroom;
    //}
    return modifying_bool ? 1000 : temperatureroom;
    //#]
}

const bool TemperatureSensor::getModifying_bool(void) const {
    return modifying_bool;
}

void TemperatureSensor::setTemperatureroom(const float p_temperatureroom) {
    temperatureroom = p_temperatureroom;
    NOTIFY_SET_OPERATION;
}

const HVAC* TemperatureSensor::getItsHVAC(void) const {
    return itsHVAC;
}

void TemperatureSensor::setItsHVAC(HVAC* const p_HVAC) {
    if(p_HVAC != NULL)
        {
            p_HVAC->_setItsTemperatureSensor(this);
        }
    _setItsHVAC(p_HVAC);
}

bool TemperatureSensor::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(state_11_timeout == arg)
        {
            state_11_timeout = NULL;
            res = true;
        }
    if(state_10_timeout == arg)
        {
            state_10_timeout = NULL;
            res = true;
        }
    return res;
}

bool TemperatureSensor::startBehavior(void) {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void TemperatureSensor::initStatechart(void) {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    state_11_subState = OMNonState;
    state_11_active = OMNonState;
    state_11_timeout = NULL;
    state_10_subState = OMNonState;
    state_10_active = OMNonState;
    state_10_timeout = NULL;
}

void TemperatureSensor::cleanUpRelations(void) {
    if(itsAirConditioner != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsAirConditioner");
            const TemperatureSensor* p_TemperatureSensor = itsAirConditioner->getItsTemperatureSensor();
            if(p_TemperatureSensor != NULL)
                {
                    itsAirConditioner->__setItsTemperatureSensor(NULL);
                }
            itsAirConditioner = NULL;
        }
    if(itsAirConditioner_2 != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsAirConditioner_2");
            const TemperatureSensor* p_TemperatureSensor = itsAirConditioner_2->getItsTemperatureSensor_2();
            if(p_TemperatureSensor != NULL)
                {
                    itsAirConditioner_2->__setItsTemperatureSensor_2(NULL);
                }
            itsAirConditioner_2 = NULL;
        }
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            const TemperatureSensor* p_TemperatureSensor = itsDTSR->getItsTemperatureSensor();
            if(p_TemperatureSensor != NULL)
                {
                    itsDTSR->__setItsTemperatureSensor(NULL);
                }
            itsDTSR = NULL;
        }
    if(itsHVAC != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsHVAC");
            const TemperatureSensor* p_TemperatureSensor = itsHVAC->getItsTemperatureSensor();
            if(p_TemperatureSensor != NULL)
                {
                    itsHVAC->__setItsTemperatureSensor(NULL);
                }
            itsHVAC = NULL;
        }
    if(itsOccupancySensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsOccupancySensor");
            const TemperatureSensor* p_TemperatureSensor = itsOccupancySensor->getItsTemperatureSensor();
            if(p_TemperatureSensor != NULL)
                {
                    itsOccupancySensor->__setItsTemperatureSensor(NULL);
                }
            itsOccupancySensor = NULL;
        }
}

void TemperatureSensor::cancelTimeouts(void) {
    cancel(state_11_timeout);
    cancel(state_10_timeout);
}

void TemperatureSensor::__setItsHVAC(HVAC* const p_HVAC) {
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

void TemperatureSensor::_setItsHVAC(HVAC* const p_HVAC) {
    if(itsHVAC != NULL)
        {
            itsHVAC->__setItsTemperatureSensor(NULL);
        }
    __setItsHVAC(p_HVAC);
}

void TemperatureSensor::_clearItsHVAC(void) {
    NOTIFY_RELATION_CLEARED("itsHVAC");
    itsHVAC = NULL;
}

int TemperatureSensor::callMain(void) {
    NOTIFY_OPERATION(callMain, callMain(), 0, Default_TemperatureSensor_callMain_SERIALIZE);
    //#[ operation callMain()
    #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
    #define _WINSOCK_DEPRECATED_NO_WARNINGS
    #endif
    
    #include <stdlib.h>
    
    WSAStartup(0x0101,&ws);
    
    char out_string_for_temperatureroom [1024];
    
    //TEMPERATUREROOM
    ZeroMemory(&address_temperatureroom, sizeof(address_temperatureroom));
    address_temperatureroom.sin_family = AF_INET;
    address_temperatureroom.sin_port = htons(portTemperatureroom);
    address_temperatureroom.sin_addr.s_addr=inet_addr(serverName);
    
    //INITIALIZE ALL SOCKETS
    listenSocketForTemperatureroom = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    //CONNECT ALL THE SOCKETS
    iResultTemperatureroom = connect(listenSocketForTemperatureroom,(SOCKADDR*)&address_temperatureroom, sizeof(address_temperatureroom)); 
    
    
    
    //ASSIGN VALUES TO SEND 
    sprintf(out_string_for_temperatureroom, "%f", temperatureroom);
    
    
    
    //SEND VALUE
    iSendResultTemperatureroom = sendto(listenSocketForTemperatureroom, (char *)&out_string_for_temperatureroom ,sizeof(uint32_t), 0 ,(SOCKADDR *) & address_temperatureroom, sizeof (address_temperatureroom) );
    //SHOW SENT VALUES IN CONSOLE
    //printf("Temperatureroom value sent: %s \n",out_string_for_temperatureroom);
    
    //RECIEVED VALUE OF TEMPERATUREROOM
    iResultTemperatureroom = recv(listenSocketForTemperatureroom, recvbuf, recvbuflen, 0); 
    float temperatureroomtocheck = atof(recvbuf);
    printf("TEMPERATUREROOM value recieved: %f\n",atof(recvbuf));
    //CLOSE ALL THE SOCKETS
    closesocket(listenSocketForTemperatureroom);
    return 0;
    
    //#]
}

const SOCKADDR_IN TemperatureSensor::getAddress_temperatureroom(void) const {
    return address_temperatureroom;
}

void TemperatureSensor::setAddress_temperatureroom(const SOCKADDR_IN p_address_temperatureroom) {
    address_temperatureroom = p_address_temperatureroom;
}

const int TemperatureSensor::getIResultTemperatureroom(void) const {
    return iResultTemperatureroom;
}

void TemperatureSensor::setIResultTemperatureroom(const int p_iResultTemperatureroom) {
    iResultTemperatureroom = p_iResultTemperatureroom;
}

const int TemperatureSensor::getISendResultTemperatureroom(void) const {
    return iSendResultTemperatureroom;
}

void TemperatureSensor::setISendResultTemperatureroom(const int p_iSendResultTemperatureroom) {
    iSendResultTemperatureroom = p_iSendResultTemperatureroom;
}

const SOCKET TemperatureSensor::getListenSocketForTemperatureroom(void) const {
    return listenSocketForTemperatureroom;
}

void TemperatureSensor::setListenSocketForTemperatureroom(const SOCKET p_listenSocketForTemperatureroom) {
    listenSocketForTemperatureroom = p_listenSocketForTemperatureroom;
}

const int TemperatureSensor::getPortTemperatureroom(void) const {
    return portTemperatureroom;
}

void TemperatureSensor::setPortTemperatureroom(const int p_portTemperatureroom) {
    portTemperatureroom = p_portTemperatureroom;
}

const char TemperatureSensor::getRecvbuf(const Rhp_int32_t iterI1) const {
    return recvbuf[iterI1];
}

void TemperatureSensor::setRecvbuf(const Rhp_int32_t iterI1, const char p_recvbuf) {
    recvbuf[iterI1] = p_recvbuf;
}

const int TemperatureSensor::getRecvbuflen(void) const {
    return recvbuflen;
}

void TemperatureSensor::setRecvbuflen(const int p_recvbuflen) {
    recvbuflen = p_recvbuflen;
}

const char* TemperatureSensor::getServerName(void) const {
    return serverName;
}

void TemperatureSensor::setServerName(char* const p_serverName) {
    serverName = p_serverName;
}

const float TemperatureSensor::getSpeed(void) const {
    return speed;
}

void TemperatureSensor::setSpeed(const float p_speed) {
    speed = p_speed;
}

const WSADATA TemperatureSensor::getWs(void) const {
    return ws;
}

void TemperatureSensor::setWs(const WSADATA p_ws) {
    ws = p_ws;
}

const AirConditioner* TemperatureSensor::getItsAirConditioner(void) const {
    return itsAirConditioner;
}

void TemperatureSensor::setItsAirConditioner(AirConditioner* const p_AirConditioner) {
    if(p_AirConditioner != NULL)
        {
            p_AirConditioner->_setItsTemperatureSensor(this);
        }
    _setItsAirConditioner(p_AirConditioner);
}

const AirConditioner* TemperatureSensor::getItsAirConditioner_2(void) const {
    return itsAirConditioner_2;
}

void TemperatureSensor::setItsAirConditioner_2(AirConditioner* const p_AirConditioner) {
    if(p_AirConditioner != NULL)
        {
            p_AirConditioner->_setItsTemperatureSensor_2(this);
        }
    _setItsAirConditioner_2(p_AirConditioner);
}

void TemperatureSensor::__setItsAirConditioner(AirConditioner* const p_AirConditioner) {
    itsAirConditioner = p_AirConditioner;
    if(p_AirConditioner != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsAirConditioner", p_AirConditioner, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsAirConditioner");
        }
}

void TemperatureSensor::_setItsAirConditioner(AirConditioner* const p_AirConditioner) {
    if(itsAirConditioner != NULL)
        {
            itsAirConditioner->__setItsTemperatureSensor(NULL);
        }
    __setItsAirConditioner(p_AirConditioner);
}

void TemperatureSensor::_clearItsAirConditioner(void) {
    NOTIFY_RELATION_CLEARED("itsAirConditioner");
    itsAirConditioner = NULL;
}

void TemperatureSensor::__setItsAirConditioner_2(AirConditioner* const p_AirConditioner) {
    itsAirConditioner_2 = p_AirConditioner;
    if(p_AirConditioner != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsAirConditioner_2", p_AirConditioner, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsAirConditioner_2");
        }
}

void TemperatureSensor::_setItsAirConditioner_2(AirConditioner* const p_AirConditioner) {
    if(itsAirConditioner_2 != NULL)
        {
            itsAirConditioner_2->__setItsTemperatureSensor_2(NULL);
        }
    __setItsAirConditioner_2(p_AirConditioner);
}

void TemperatureSensor::_clearItsAirConditioner_2(void) {
    NOTIFY_RELATION_CLEARED("itsAirConditioner_2");
    itsAirConditioner_2 = NULL;
}

void TemperatureSensor::setModifying_bool(bool newValue) {
    NOTIFY_OPERATION(setModifying_bool, setModifying_bool(bool), 1, Default_TemperatureSensor_setModifying_bool_SERIALIZE);
    //#[ operation setModifying_bool(bool)
    modifying_bool=newValue;
    //#]
    NOTIFY_SET_OPERATION;
}

const DTSR* TemperatureSensor::getItsDTSR(void) const {
    return itsDTSR;
}

void TemperatureSensor::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_setItsTemperatureSensor(this);
        }
    _setItsDTSR(p_DTSR);
}

const OccupancySensor* TemperatureSensor::getItsOccupancySensor(void) const {
    return itsOccupancySensor;
}

void TemperatureSensor::setItsOccupancySensor(OccupancySensor* const p_OccupancySensor) {
    if(p_OccupancySensor != NULL)
        {
            p_OccupancySensor->_setItsTemperatureSensor(this);
        }
    _setItsOccupancySensor(p_OccupancySensor);
}

void TemperatureSensor::__setItsDTSR(DTSR* const p_DTSR) {
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

void TemperatureSensor::_setItsDTSR(DTSR* const p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->__setItsTemperatureSensor(NULL);
        }
    __setItsDTSR(p_DTSR);
}

void TemperatureSensor::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

void TemperatureSensor::__setItsOccupancySensor(OccupancySensor* const p_OccupancySensor) {
    itsOccupancySensor = p_OccupancySensor;
    if(p_OccupancySensor != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsOccupancySensor", p_OccupancySensor, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsOccupancySensor");
        }
}

void TemperatureSensor::_setItsOccupancySensor(OccupancySensor* const p_OccupancySensor) {
    if(itsOccupancySensor != NULL)
        {
            itsOccupancySensor->__setItsTemperatureSensor(NULL);
        }
    __setItsOccupancySensor(p_OccupancySensor);
}

void TemperatureSensor::_clearItsOccupancySensor(void) {
    NOTIFY_RELATION_CLEARED("itsOccupancySensor");
    itsOccupancySensor = NULL;
}

void TemperatureSensor::state_5_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_5");
    rootState_subState = state_5;
    rootState_active = state_5;
    state_10_entDef();
    state_11_entDef();
}

void TemperatureSensor::state_5_exit(void) {
    state_10_exit();
    state_11_exit();
    
    NOTIFY_STATE_EXITED("ROOT.state_5");
}

IOxfReactive::TakeEventStatus TemperatureSensor::state_5_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    IOxfReactive::TakeEventStatus omComponentStatus = eventNotConsumed;
    bool dispatchDone = false;
    {
        // State state_10
        omComponentStatus = state_10_processEvent();
        if(omComponentStatus != eventNotConsumed)
            {
                res = eventConsumed;
                if(IS_IN(state_5) == false)
                    {
                        dispatchDone = true;
                    }
            }
    }
    if(!dispatchDone)
        {
            // State state_11
            omComponentStatus = state_11_processEvent();
            if(omComponentStatus != eventNotConsumed)
                {
                    res = eventConsumed;
                }
        }
    
    return res;
}

void TemperatureSensor::state_11_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_11");
    NOTIFY_TRANSITION_STARTED("ROOT.state_5.9");
    NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_11.SendAndRecieve");
    state_11_subState = SendAndRecieve;
    state_11_active = SendAndRecieve;
    //#[ state state_5.state_5.state_11.SendAndRecieve.(Entry) 
    callMain();
     
    //#]
    state_11_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.state_11.SendAndRecieve");
    NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.9");
}

void TemperatureSensor::state_11_exit(void) {
    // State SendAndRecieve
    if(state_11_subState == SendAndRecieve)
        {
            cancel(state_11_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_11.SendAndRecieve");
        }
    state_11_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_11");
}

IOxfReactive::TakeEventStatus TemperatureSensor::state_11_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State SendAndRecieve
    if(state_11_active == SendAndRecieve)
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_11_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.10");
                            cancel(state_11_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_11.SendAndRecieve");
                            NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_11.SendAndRecieve");
                            state_11_subState = SendAndRecieve;
                            state_11_active = SendAndRecieve;
                            //#[ state state_5.state_5.state_11.SendAndRecieve.(Entry) 
                            callMain();
                             
                            //#]
                            state_11_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.state_11.SendAndRecieve");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.10");
                            res = eventConsumed;
                        }
                }
            
            
        }
    return res;
}

void TemperatureSensor::state_10_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_10");
    NOTIFY_TRANSITION_STARTED("ROOT.state_5.0");
    //#[ transition state_5.0 
    speed=itsAirConditioner->getSpeed();
    //#]
    NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_10.Normal");
    state_10_subState = Normal;
    state_10_active = Normal;
    state_10_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.state_10.Normal");
    NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.0");
}

void TemperatureSensor::state_10_exit(void) {
    switch (state_10_subState) {
        // State Normal
        case Normal:
        {
            cancel(state_10_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_10.Normal");
        }
        break;
        // State Modifying
        case Modifying:
        {
            cancel(state_10_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_10.Modifying");
        }
        break;
        case accepttimeevent_3:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_10.accepttimeevent_3");
        }
        break;
        case accepttimeevent_4:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_10.accepttimeevent_4");
        }
        break;
        default:
            break;
    }
    state_10_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_10");
}

IOxfReactive::TakeEventStatus TemperatureSensor::state_10_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_10_active) {
        // State Normal
        case Normal:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_10_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.1");
                            cancel(state_10_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_10.Normal");
                            NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_10.accepttimeevent_3");
                            pushNullTransition();
                            state_10_subState = accepttimeevent_3;
                            state_10_active = accepttimeevent_3;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.1");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        // State Modifying
        case Modifying:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_10_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.5");
                            cancel(state_10_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_10.Modifying");
                            NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_10.accepttimeevent_4");
                            pushNullTransition();
                            state_10_subState = accepttimeevent_4;
                            state_10_active = accepttimeevent_4;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.5");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        case accepttimeevent_3:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    //## transition state_5.3 
                    if(modifying_bool==false)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.2");
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.3");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_10.accepttimeevent_3");
                            //#[ transition state_5.3 
                            changeFromAirConditioner();
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_10.Normal");
                            state_10_subState = Normal;
                            state_10_active = Normal;
                            state_10_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.state_10.Normal");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.3");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.2");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition state_5.4 
                            if(modifying_bool==true)
                                {
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_5.2");
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_5.4");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_10.accepttimeevent_3");
                                    NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_10.Modifying");
                                    state_10_subState = Modifying;
                                    state_10_active = Modifying;
                                    state_10_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.state_10.Modifying");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.4");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.2");
                                    res = eventConsumed;
                                }
                        }
                }
            
            
        }
        break;
        case accepttimeevent_4:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    //## transition state_5.7 
                    if(modifying_bool==true)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.6");
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.7");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_10.accepttimeevent_4");
                            NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_10.Modifying");
                            state_10_subState = Modifying;
                            state_10_active = Modifying;
                            state_10_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.state_10.Modifying");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.7");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.6");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition state_5.8 
                            if(modifying_bool==false)
                                {
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_5.6");
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_5.8");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_10.accepttimeevent_4");
                                    NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_10.Normal");
                                    state_10_subState = Normal;
                                    state_10_active = Normal;
                                    state_10_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.state_10.Normal");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.8");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.6");
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

void TemperatureSensor::rootState_entDef(void) {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        state_5_entDef();
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus TemperatureSensor::rootState_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State state_5
    if(rootState_active == state_5)
        {
            res = state_5_processEvent();
        }
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedTemperatureSensor::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("address_temperatureroom", UNKNOWN2STRING(myReal->address_temperatureroom));
    aomsAttributes->addAttribute("iResultTemperatureroom", x2String(myReal->iResultTemperatureroom));
    aomsAttributes->addAttribute("iSendResultTemperatureroom", x2String(myReal->iSendResultTemperatureroom));
    aomsAttributes->addAttribute("listenSocketForTemperatureroom", UNKNOWN2STRING(myReal->listenSocketForTemperatureroom));
    aomsAttributes->addAttribute("portTemperatureroom", x2String(myReal->portTemperatureroom));
    aomsAttributes->addAttribute("recvbuf", array2String(DEFAULT_BUFLEN, myReal->recvbuf, sizeof(char), &x2String));
    aomsAttributes->addAttribute("recvbuflen", x2String(myReal->recvbuflen));
    aomsAttributes->addAttribute("serverName", x2String(myReal->serverName));
    aomsAttributes->addAttribute("ws", UNKNOWN2STRING(myReal->ws));
    aomsAttributes->addAttribute("modifying_bool", x2String(myReal->modifying_bool));
    aomsAttributes->addAttribute("temperatureroom", x2String(myReal->temperatureroom));
    aomsAttributes->addAttribute("speed", x2String(myReal->speed));
}

void OMAnimatedTemperatureSensor::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsHVAC", false, true);
    if(myReal->itsHVAC)
        {
            aomsRelations->ADD_ITEM(myReal->itsHVAC);
        }
    aomsRelations->addRelation("itsAirConditioner", false, true);
    if(myReal->itsAirConditioner)
        {
            aomsRelations->ADD_ITEM(myReal->itsAirConditioner);
        }
    aomsRelations->addRelation("itsAirConditioner_2", false, true);
    if(myReal->itsAirConditioner_2)
        {
            aomsRelations->ADD_ITEM(myReal->itsAirConditioner_2);
        }
    aomsRelations->addRelation("itsDTSR", false, true);
    if(myReal->itsDTSR)
        {
            aomsRelations->ADD_ITEM(myReal->itsDTSR);
        }
    aomsRelations->addRelation("itsOccupancySensor", false, true);
    if(myReal->itsOccupancySensor)
        {
            aomsRelations->ADD_ITEM(myReal->itsOccupancySensor);
        }
}

void OMAnimatedTemperatureSensor::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    if(myReal->rootState_subState == TemperatureSensor::state_5)
        {
            state_5_serializeStates(aomsState);
        }
}

void OMAnimatedTemperatureSensor::state_5_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5");
    state_10_serializeStates(aomsState);
    state_11_serializeStates(aomsState);
}

void OMAnimatedTemperatureSensor::state_11_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.state_11");
    if(myReal->state_11_subState == TemperatureSensor::SendAndRecieve)
        {
            SendAndRecieve_serializeStates(aomsState);
        }
}

void OMAnimatedTemperatureSensor::SendAndRecieve_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.state_11.SendAndRecieve");
}

void OMAnimatedTemperatureSensor::state_10_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.state_10");
    switch (myReal->state_10_subState) {
        case TemperatureSensor::Normal:
        {
            Normal_serializeStates(aomsState);
        }
        break;
        case TemperatureSensor::Modifying:
        {
            Modifying_serializeStates(aomsState);
        }
        break;
        case TemperatureSensor::accepttimeevent_3:
        {
            accepttimeevent_3_serializeStates(aomsState);
        }
        break;
        case TemperatureSensor::accepttimeevent_4:
        {
            accepttimeevent_4_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedTemperatureSensor::Normal_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.state_10.Normal");
}

void OMAnimatedTemperatureSensor::Modifying_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.state_10.Modifying");
}

void OMAnimatedTemperatureSensor::accepttimeevent_4_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.state_10.accepttimeevent_4");
}

void OMAnimatedTemperatureSensor::accepttimeevent_3_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.state_10.accepttimeevent_3");
}
//#]

IMPLEMENT_REACTIVE_META_P(TemperatureSensor, Default, Default, false, OMAnimatedTemperatureSensor)

IMPLEMENT_META_OP(OMAnimatedTemperatureSensor, Default_TemperatureSensor_callMain, "callMain", FALSE, "callMain()", 0)

IMPLEMENT_OP_CALL(Default_TemperatureSensor_callMain, TemperatureSensor, callMain(), int animRetVal = )

IMPLEMENT_META_OP(OMAnimatedTemperatureSensor, Default_TemperatureSensor_changeFromAirConditioner, "changeFromAirConditioner", FALSE, "changeFromAirConditioner()", 0)

IMPLEMENT_OP_CALL(Default_TemperatureSensor_changeFromAirConditioner, TemperatureSensor, changeFromAirConditioner(), int animRetVal = )

IMPLEMENT_META_OP(OMAnimatedTemperatureSensor, Default_TemperatureSensor_getTemperatureroom, "getTemperatureroom", FALSE, "getTemperatureroom()", 0)

IMPLEMENT_OP_CALL(Default_TemperatureSensor_getTemperatureroom, TemperatureSensor, getTemperatureroom(), float animRetVal = )

IMPLEMENT_META_OP(OMAnimatedTemperatureSensor, Default_TemperatureSensor_setModifying_bool_bool, "setModifying_bool", FALSE, "setModifying_bool(bool)", 1)

IMPLEMENT_OP_CALL(Default_TemperatureSensor_setModifying_bool_bool, TemperatureSensor, setModifying_bool(newValue), NO_OP())

IMPLEMENT_META_OP(OMAnimatedTemperatureSensor, Default_TemperatureSensor_setTemperatureroom_float, "setTemperatureroom", FALSE, "setTemperatureroom(float)", 1)

IMPLEMENT_OP_CALL(Default_TemperatureSensor_setTemperatureroom_float, TemperatureSensor, setTemperatureroom(p_temperatureroom), NO_OP())
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\TemperatureSensor.cpp
*********************************************************************/
