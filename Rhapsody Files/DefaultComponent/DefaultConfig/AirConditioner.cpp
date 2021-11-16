/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AirConditioner
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\AirConditioner.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "AirConditioner.h"
//## link itsHVAC
#include "HVAC.h"
//## link itsTemperatureSensor
#include "TemperatureSensor.h"
//#[ ignore
#define Default_AirConditioner_AirConditioner_SERIALIZE OM_NO_OP

#define Default_AirConditioner_SettingAirConditioner_SERIALIZE OM_NO_OP

#define OMAnim_Default_AirConditioner_SettingAirConditioner_UNSERIALIZE_ARGS

#define OMAnim_Default_AirConditioner_SettingAirConditioner_SERIALIZE_RET_VAL OP_SET_RET_VAL(animRetVal)

#define Default_AirConditioner_callMain_SERIALIZE OM_NO_OP

#define OMAnim_Default_AirConditioner_callMain_UNSERIALIZE_ARGS

#define OMAnim_Default_AirConditioner_callMain_SERIALIZE_RET_VAL OP_SET_RET_VAL(animRetVal)

#define Default_AirConditioner_callMain_copy_SERIALIZE OM_NO_OP

#define OMAnim_Default_AirConditioner_callMain_copy_UNSERIALIZE_ARGS

#define OMAnim_Default_AirConditioner_callMain_copy_SERIALIZE_RET_VAL OP_SET_RET_VAL(animRetVal)

#define Default_AirConditioner_getSpeed_SERIALIZE OM_NO_OP

#define OMAnim_Default_AirConditioner_getSpeed_UNSERIALIZE_ARGS

#define OMAnim_Default_AirConditioner_getSpeed_SERIALIZE_RET_VAL OP_SET_RET_VAL(animRetVal)

#define Default_AirConditioner_getTemperaturegoal_SERIALIZE OM_NO_OP

#define OMAnim_Default_AirConditioner_getTemperaturegoal_UNSERIALIZE_ARGS

#define OMAnim_Default_AirConditioner_getTemperaturegoal_SERIALIZE_RET_VAL OP_SET_RET_VAL(animRetVal)

#define OMAnim_Default_AirConditioner_setDif_float_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_dif)

#define OMAnim_Default_AirConditioner_setDif_float_SERIALIZE_RET_VAL

#define OMAnim_Default_AirConditioner_setHvac_float_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_hvac)

#define OMAnim_Default_AirConditioner_setHvac_float_SERIALIZE_RET_VAL

#define OMAnim_Default_AirConditioner_setTemperaturegoal_float_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_temperaturegoal)

#define OMAnim_Default_AirConditioner_setTemperaturegoal_float_SERIALIZE_RET_VAL

#define OMAnim_Default_AirConditioner_setTemperatureroom_float_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_temperatureroom)

#define OMAnim_Default_AirConditioner_setTemperatureroom_float_SERIALIZE_RET_VAL
//#]

//## package Default

//## class AirConditioner
AirConditioner::AirConditioner(IOxfActive* const theActiveContext) : OMReactive(), hvac(0), listenSocketForTemperaturegoal(INVALID_SOCKET), mode(0), portTemperaturegoal(10010), recvbuflen(DEFAULT_BUFLEN), serverName("127.0.0.1"), speed(5), temperaturegoal(20), itsHVAC(NULL), itsTemperatureSensor(NULL), itsTemperatureSensor_1(NULL), itsTemperatureSensor_2(NULL) {
    NOTIFY_REACTIVE_CONSTRUCTOR(AirConditioner, AirConditioner(), 0, Default_AirConditioner_AirConditioner_SERIALIZE);
    setActiveContext(theActiveContext, false);
    initStatechart();
}

AirConditioner::~AirConditioner(void) {
    NOTIFY_DESTRUCTOR(~AirConditioner, true);
    cleanUpRelations();
    cancelTimeouts();
}

int AirConditioner::SettingAirConditioner(void) {
    NOTIFY_OPERATION(SettingAirConditioner, SettingAirConditioner(), 0, Default_AirConditioner_SettingAirConditioner_SERIALIZE);
    //#[ operation SettingAirConditioner()
    temperatureroom=itsTemperatureSensor->getTemperatureroom();
    //std::cout<<"itsTemperatureSensor->getTemperatureroom() : "<<itsTemperatureSensor->getTemperatureroom()<<std::endl;
    if(temperatureroom==1000){//actually the value is 1000, but float sometimes presicion error.
    	hvac=0;
    	return 0;
    }
    float dif=temperaturegoal-temperatureroom;
    if(dif>-0.5 && dif<0.5){
    	hvac=0;
    	return 0;
    }
    if(dif>0){
    	hvac=1;
    }else{
    	hvac=2;
    }
    return 0;
    //#]
}

int AirConditioner::callMain(void) {
    NOTIFY_OPERATION(callMain, callMain(), 0, Default_AirConditioner_callMain_SERIALIZE);
    //#[ operation callMain()
    #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
    #define _WINSOCK_DEPRECATED_NO_WARNINGS
    #endif
    
    #include <stdlib.h>
    
    WSAStartup(0x0101,&ws);
    
    char out_string_for_temperaturegoal [1024];
    
    //TEMPERATUREGOAL
    ZeroMemory(&address_temperaturegoal, sizeof(address_temperaturegoal));
    address_temperaturegoal.sin_family = AF_INET;
    address_temperaturegoal.sin_port = htons(portTemperaturegoal);
    address_temperaturegoal.sin_addr.s_addr=inet_addr(serverName);
    
    //INITIALIZE ALL SOCKETS
    listenSocketForTemperaturegoal = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    //CONNECT ALL THE SOCKETS
    iResultTemperaturegoal = connect(listenSocketForTemperaturegoal,(SOCKADDR*)&address_temperaturegoal, sizeof(address_temperaturegoal)); 
    
    
    
    //ASSIGN VALUES TO SEND 
    sprintf(out_string_for_temperaturegoal, "%f", temperaturegoal);
    
    
    
    //SEND VALUE
    iSendResultTemperaturegoal = sendto(listenSocketForTemperaturegoal, (char *)&out_string_for_temperaturegoal ,sizeof(uint32_t), 0 ,(SOCKADDR *) & address_temperaturegoal, sizeof (address_temperaturegoal) );
    //SHOW SENT VALUES IN CONSOLE
    //printf("Temperaturegoal value sent: %s \n",out_string_for_temperaturegoal);
    
    //RECIEVED VALUE OF TEMPERATUREGOAL
    iResultTemperaturegoal = recv(listenSocketForTemperaturegoal, recvbuf, recvbuflen, 0); 
    float temperaturegoaltocheck = atof(recvbuf);
    printf("TEMPERATUREGOAL value recieved: %f\n",atof(recvbuf));
    //CLOSE ALL THE SOCKETS
    closesocket(listenSocketForTemperaturegoal);
    return 0;
    
    //#]
}

int AirConditioner::callMain_copy(void) {
    NOTIFY_OPERATION(callMain_copy, callMain_copy(), 0, Default_AirConditioner_callMain_copy_SERIALIZE);
    //#[ operation callMain_copy()
    #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
    #define _WINSOCK_DEPRECATED_NO_WARNINGS
    #endif
    
    #include <stdlib.h>
    
    WSAStartup(0x0101,&ws);
    
    char out_string_for_temperaturegoal [1024];
    
    //TEMPERATUREGOAL
    ZeroMemory(&address_temperaturegoal, sizeof(address_temperaturegoal));
    address_temperaturegoal.sin_family = AF_INET;
    address_temperaturegoal.sin_port = htons(portTemperaturegoal);
    address_temperaturegoal.sin_addr.s_addr=inet_addr(serverName);
    
    //INITIALIZE ALL SOCKETS
    listenSocketForTemperaturegoal = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    //CONNECT ALL THE SOCKETS
    iResultTemperaturegoal = connect(listenSocketForTemperaturegoal,(SOCKADDR*)&address_temperaturegoal, sizeof(address_temperaturegoal)); 
    
    
    
    //ASSIGN VALUES TO SEND 
    sprintf(out_string_for_temperaturegoal, "%f", temperaturegoal);
    
    
    
    //SEND VALUE
    iSendResultTemperaturegoal = sendto(listenSocketForTemperaturegoal, (char *)&out_string_for_temperaturegoal ,sizeof(uint32_t), 0 ,(SOCKADDR *) & address_temperaturegoal, sizeof (address_temperaturegoal) );
    //SHOW SENT VALUES IN CONSOLE
    //printf("Temperaturegoal value sent: %s \n",out_string_for_temperaturegoal);
    
    //RECIEVED VALUE OF TEMPERATUREGOAL
    iResultTemperaturegoal = recv(listenSocketForTemperaturegoal, recvbuf, recvbuflen, 0); 
    float temperaturegoaltocheck = atof(recvbuf);
    printf("TEMPERATUREGOAL value recieved: %f\n",atof(recvbuf));
    //CLOSE ALL THE SOCKETS
    closesocket(listenSocketForTemperaturegoal);
    return 0;
    
    //#]
}

float AirConditioner::getSpeed(void) {
    NOTIFY_OPERATION(getSpeed, getSpeed(), 0, Default_AirConditioner_getSpeed_SERIALIZE);
    //#[ operation getSpeed()
    return speed;
    //#]
}

float AirConditioner::getTemperaturegoal(void) {
    NOTIFY_OPERATION(getTemperaturegoal, getTemperaturegoal(), 0, Default_AirConditioner_getTemperaturegoal_SERIALIZE);
    //#[ operation getTemperaturegoal()
    return temperaturegoal;
    //#]
}

const SOCKADDR_IN AirConditioner::getAddress_temperaturegoal(void) const {
    return address_temperaturegoal;
}

void AirConditioner::setAddress_temperaturegoal(const SOCKADDR_IN p_address_temperaturegoal) {
    address_temperaturegoal = p_address_temperaturegoal;
}

const float AirConditioner::getDif(void) const {
    return dif;
}

void AirConditioner::setDif(const float p_dif) {
    dif = p_dif;
    NOTIFY_SET_OPERATION;
}

const float AirConditioner::getHvac(void) const {
    return hvac;
}

void AirConditioner::setHvac(const float p_hvac) {
    hvac = p_hvac;
    NOTIFY_SET_OPERATION;
}

const int AirConditioner::getIResultTemperaturegoal(void) const {
    return iResultTemperaturegoal;
}

void AirConditioner::setIResultTemperaturegoal(const int p_iResultTemperaturegoal) {
    iResultTemperaturegoal = p_iResultTemperaturegoal;
}

const int AirConditioner::getISendResultTemperaturegoal(void) const {
    return iSendResultTemperaturegoal;
}

void AirConditioner::setISendResultTemperaturegoal(const int p_iSendResultTemperaturegoal) {
    iSendResultTemperaturegoal = p_iSendResultTemperaturegoal;
}

const SOCKET AirConditioner::getListenSocketForTemperaturegoal(void) const {
    return listenSocketForTemperaturegoal;
}

void AirConditioner::setListenSocketForTemperaturegoal(const SOCKET p_listenSocketForTemperaturegoal) {
    listenSocketForTemperaturegoal = p_listenSocketForTemperaturegoal;
}

const int AirConditioner::getMode(void) const {
    return mode;
}

void AirConditioner::setMode(const int p_mode) {
    mode = p_mode;
}

const int AirConditioner::getPortTemperaturegoal(void) const {
    return portTemperaturegoal;
}

void AirConditioner::setPortTemperaturegoal(const int p_portTemperaturegoal) {
    portTemperaturegoal = p_portTemperaturegoal;
}

const char AirConditioner::getRecvbuf(const Rhp_int32_t iterI1) const {
    return recvbuf[iterI1];
}

void AirConditioner::setRecvbuf(const Rhp_int32_t iterI1, const char p_recvbuf) {
    recvbuf[iterI1] = p_recvbuf;
}

const int AirConditioner::getRecvbuflen(void) const {
    return recvbuflen;
}

void AirConditioner::setRecvbuflen(const int p_recvbuflen) {
    recvbuflen = p_recvbuflen;
}

const char* AirConditioner::getServerName(void) const {
    return serverName;
}

void AirConditioner::setServerName(char* const p_serverName) {
    serverName = p_serverName;
}

void AirConditioner::setTemperaturegoal(const float p_temperaturegoal) {
    temperaturegoal = p_temperaturegoal;
    NOTIFY_SET_OPERATION;
}

const float AirConditioner::getTemperatureroom(void) const {
    return temperatureroom;
}

void AirConditioner::setTemperatureroom(const float p_temperatureroom) {
    temperatureroom = p_temperatureroom;
    NOTIFY_SET_OPERATION;
}

const WSADATA AirConditioner::getWs(void) const {
    return ws;
}

void AirConditioner::setWs(const WSADATA p_ws) {
    ws = p_ws;
}

const HVAC* AirConditioner::getItsHVAC(void) const {
    return itsHVAC;
}

void AirConditioner::setItsHVAC(HVAC* const p_HVAC) {
    if(p_HVAC != NULL)
        {
            p_HVAC->_setItsAirConditioner(this);
        }
    _setItsHVAC(p_HVAC);
}

const TemperatureSensor* AirConditioner::getItsTemperatureSensor(void) const {
    return itsTemperatureSensor;
}

void AirConditioner::setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor) {
    if(p_TemperatureSensor != NULL)
        {
            p_TemperatureSensor->_setItsAirConditioner(this);
        }
    _setItsTemperatureSensor(p_TemperatureSensor);
}

const TemperatureSensor* AirConditioner::getItsTemperatureSensor_1(void) const {
    return itsTemperatureSensor_1;
}

void AirConditioner::setItsTemperatureSensor_1(TemperatureSensor* const p_TemperatureSensor) {
    itsTemperatureSensor_1 = p_TemperatureSensor;
    if(p_TemperatureSensor != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsTemperatureSensor_1", p_TemperatureSensor, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsTemperatureSensor_1");
        }
}

const TemperatureSensor* AirConditioner::getItsTemperatureSensor_2(void) const {
    return itsTemperatureSensor_2;
}

void AirConditioner::setItsTemperatureSensor_2(TemperatureSensor* const p_TemperatureSensor) {
    if(p_TemperatureSensor != NULL)
        {
            p_TemperatureSensor->_setItsAirConditioner_2(this);
        }
    _setItsTemperatureSensor_2(p_TemperatureSensor);
}

bool AirConditioner::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(state_9_timeout == arg)
        {
            state_9_timeout = NULL;
            res = true;
        }
    if(state_10_timeout == arg)
        {
            state_10_timeout = NULL;
            res = true;
        }
    return res;
}

bool AirConditioner::startBehavior(void) {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void AirConditioner::initStatechart(void) {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    state_9_subState = OMNonState;
    state_9_active = OMNonState;
    state_9_timeout = NULL;
    state_10_subState = OMNonState;
    state_10_active = OMNonState;
    state_10_timeout = NULL;
}

void AirConditioner::cleanUpRelations(void) {
    if(itsHVAC != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsHVAC");
            const AirConditioner* p_AirConditioner = itsHVAC->getItsAirConditioner();
            if(p_AirConditioner != NULL)
                {
                    itsHVAC->__setItsAirConditioner(NULL);
                }
            itsHVAC = NULL;
        }
    if(itsTemperatureSensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsTemperatureSensor");
            const AirConditioner* p_AirConditioner = itsTemperatureSensor->getItsAirConditioner();
            if(p_AirConditioner != NULL)
                {
                    itsTemperatureSensor->__setItsAirConditioner(NULL);
                }
            itsTemperatureSensor = NULL;
        }
    if(itsTemperatureSensor_1 != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsTemperatureSensor_1");
            itsTemperatureSensor_1 = NULL;
        }
    if(itsTemperatureSensor_2 != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsTemperatureSensor_2");
            const AirConditioner* p_AirConditioner = itsTemperatureSensor_2->getItsAirConditioner_2();
            if(p_AirConditioner != NULL)
                {
                    itsTemperatureSensor_2->__setItsAirConditioner_2(NULL);
                }
            itsTemperatureSensor_2 = NULL;
        }
}

void AirConditioner::cancelTimeouts(void) {
    cancel(state_9_timeout);
    cancel(state_10_timeout);
}

void AirConditioner::__setItsHVAC(HVAC* const p_HVAC) {
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

void AirConditioner::_setItsHVAC(HVAC* const p_HVAC) {
    if(itsHVAC != NULL)
        {
            itsHVAC->__setItsAirConditioner(NULL);
        }
    __setItsHVAC(p_HVAC);
}

void AirConditioner::_clearItsHVAC(void) {
    NOTIFY_RELATION_CLEARED("itsHVAC");
    itsHVAC = NULL;
}

void AirConditioner::__setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor) {
    itsTemperatureSensor = p_TemperatureSensor;
    if(p_TemperatureSensor != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsTemperatureSensor", p_TemperatureSensor, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsTemperatureSensor");
        }
}

void AirConditioner::_setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor) {
    if(itsTemperatureSensor != NULL)
        {
            itsTemperatureSensor->__setItsAirConditioner(NULL);
        }
    __setItsTemperatureSensor(p_TemperatureSensor);
}

void AirConditioner::_clearItsTemperatureSensor(void) {
    NOTIFY_RELATION_CLEARED("itsTemperatureSensor");
    itsTemperatureSensor = NULL;
}

void AirConditioner::__setItsTemperatureSensor_2(TemperatureSensor* const p_TemperatureSensor) {
    itsTemperatureSensor_2 = p_TemperatureSensor;
    if(p_TemperatureSensor != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsTemperatureSensor_2", p_TemperatureSensor, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsTemperatureSensor_2");
        }
}

void AirConditioner::_setItsTemperatureSensor_2(TemperatureSensor* const p_TemperatureSensor) {
    if(itsTemperatureSensor_2 != NULL)
        {
            itsTemperatureSensor_2->__setItsAirConditioner_2(NULL);
        }
    __setItsTemperatureSensor_2(p_TemperatureSensor);
}

void AirConditioner::_clearItsTemperatureSensor_2(void) {
    NOTIFY_RELATION_CLEARED("itsTemperatureSensor_2");
    itsTemperatureSensor_2 = NULL;
}

void AirConditioner::state_8_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_8");
    rootState_subState = state_8;
    rootState_active = state_8;
    state_9_entDef();
    state_10_entDef();
}

void AirConditioner::state_8_exit(void) {
    state_9_exit();
    state_10_exit();
    
    NOTIFY_STATE_EXITED("ROOT.state_8");
}

IOxfReactive::TakeEventStatus AirConditioner::state_8_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    IOxfReactive::TakeEventStatus omComponentStatus = eventNotConsumed;
    bool dispatchDone = false;
    {
        // State state_9
        omComponentStatus = state_9_processEvent();
        if(omComponentStatus != eventNotConsumed)
            {
                res = eventConsumed;
                if(IS_IN(state_8) == false)
                    {
                        dispatchDone = true;
                    }
            }
    }
    if(!dispatchDone)
        {
            // State state_10
            omComponentStatus = state_10_processEvent();
            if(omComponentStatus != eventNotConsumed)
                {
                    res = eventConsumed;
                }
        }
    
    return res;
}

void AirConditioner::state_9_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_9");
    NOTIFY_TRANSITION_STARTED("ROOT.state_8.0");
    NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_9.Off");
    state_9_subState = Off;
    state_9_active = Off;
    state_9_timeout = scheduleTimeout(1000, "ROOT.state_8.ROOT.state_8.state_9.Off");
    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.0");
}

void AirConditioner::state_9_exit(void) {
    switch (state_9_subState) {
        // State Off
        case Off:
        {
            cancel(state_9_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.Off");
        }
        break;
        case accepttimeevent_13:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_13");
        }
        break;
        // State Heating
        case Heating:
        {
            cancel(state_9_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.Heating");
        }
        break;
        // State Cooling
        case Cooling:
        {
            cancel(state_9_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.Cooling");
        }
        break;
        case accepttimeevent_4:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_4");
        }
        break;
        case accepttimeevent_5:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_5");
        }
        break;
        case accepttimeevent_6:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_6");
        }
        break;
        default:
            break;
    }
    state_9_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9");
}

IOxfReactive::TakeEventStatus AirConditioner::state_9_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_9_active) {
        // State Off
        case Off:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_9_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_8.9");
                            cancel(state_9_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.Off");
                            NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_4");
                            pushNullTransition();
                            state_9_subState = accepttimeevent_4;
                            state_9_active = accepttimeevent_4;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.9");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        case accepttimeevent_13:
        {
            res = accepttimeevent_13_handleEvent();
        }
        break;
        // State Heating
        case Heating:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_9_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_8.11");
                            cancel(state_9_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.Heating");
                            NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_5");
                            pushNullTransition();
                            state_9_subState = accepttimeevent_5;
                            state_9_active = accepttimeevent_5;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.11");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        // State Cooling
        case Cooling:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_9_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_8.13");
                            cancel(state_9_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.Cooling");
                            NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_6");
                            pushNullTransition();
                            state_9_subState = accepttimeevent_6;
                            state_9_active = accepttimeevent_6;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.13");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        case accepttimeevent_4:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.state_8.8");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_4");
                    NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_13");
                    pushNullTransition();
                    state_9_subState = accepttimeevent_13;
                    state_9_active = accepttimeevent_13;
                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.8");
                    res = eventConsumed;
                }
            
            
        }
        break;
        case accepttimeevent_5:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.state_8.10");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_5");
                    NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_13");
                    pushNullTransition();
                    state_9_subState = accepttimeevent_13;
                    state_9_active = accepttimeevent_13;
                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.10");
                    res = eventConsumed;
                }
            
            
        }
        break;
        case accepttimeevent_6:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.state_8.12");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_6");
                    NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_13");
                    pushNullTransition();
                    state_9_subState = accepttimeevent_13;
                    state_9_active = accepttimeevent_13;
                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.12");
                    res = eventConsumed;
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

IOxfReactive::TakeEventStatus AirConditioner::accepttimeevent_13TakeNull(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    //## transition state_8.17 
    if(hvac==3)
        {
            NOTIFY_TRANSITION_STARTED("ROOT.state_8.2");
            NOTIFY_TRANSITION_STARTED("ROOT.state_8.17");
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_13");
            //#[ transition state_8.2 
            hvac=itsHVAC->getHvac();
            //#]
            NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_9.Off");
            state_9_subState = Off;
            state_9_active = Off;
            state_9_timeout = scheduleTimeout(1000, "ROOT.state_8.ROOT.state_8.state_9.Off");
            NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.17");
            NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.2");
            res = eventConsumed;
        }
    else
        {
            //## transition state_8.1 
            if(temperatureroom==1000)
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.state_8.2");
                    NOTIFY_TRANSITION_STARTED("ROOT.state_8.16");
                    NOTIFY_TRANSITION_STARTED("ROOT.state_8.1");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_13");
                    //#[ transition state_8.2 
                    hvac=itsHVAC->getHvac();
                    //#]
                    //#[ transition state_8.16 
                    temperatureroom=itsTemperatureSensor->getTemperatureroom();
                    //#]
                    //#[ transition state_8.1 
                    itsHVAC->setHvac(0);
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_9.Off");
                    state_9_subState = Off;
                    state_9_active = Off;
                    state_9_timeout = scheduleTimeout(1000, "ROOT.state_8.ROOT.state_8.state_9.Off");
                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.1");
                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.16");
                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.2");
                    res = eventConsumed;
                }
            else
                {
                    //## transition state_8.6 
                    if(temperatureroom!=1000)
                        {
                            //## transition state_8.4 
                            if(dif>0)
                                {
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_8.2");
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_8.16");
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_8.6");
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_8.4");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_13");
                                    //#[ transition state_8.2 
                                    hvac=itsHVAC->getHvac();
                                    //#]
                                    //#[ transition state_8.16 
                                    temperatureroom=itsTemperatureSensor->getTemperatureroom();
                                    //#]
                                    //#[ transition state_8.6 
                                    temperatureroom=itsTemperatureSensor->getTemperatureroom();
                                    dif=temperaturegoal-temperatureroom;
                                    //#]
                                    //#[ transition state_8.4 
                                    itsHVAC->setHvac(1);
                                    //#]
                                    NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_9.Heating");
                                    state_9_subState = Heating;
                                    state_9_active = Heating;
                                    state_9_timeout = scheduleTimeout(1000, "ROOT.state_8.ROOT.state_8.state_9.Heating");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.4");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.6");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.16");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.2");
                                    res = eventConsumed;
                                }
                            else
                                {
                                    //## transition state_8.5 
                                    if(dif<0)
                                        {
                                            NOTIFY_TRANSITION_STARTED("ROOT.state_8.2");
                                            NOTIFY_TRANSITION_STARTED("ROOT.state_8.16");
                                            NOTIFY_TRANSITION_STARTED("ROOT.state_8.6");
                                            NOTIFY_TRANSITION_STARTED("ROOT.state_8.5");
                                            popNullTransition();
                                            NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_13");
                                            //#[ transition state_8.2 
                                            hvac=itsHVAC->getHvac();
                                            //#]
                                            //#[ transition state_8.16 
                                            temperatureroom=itsTemperatureSensor->getTemperatureroom();
                                            //#]
                                            //#[ transition state_8.6 
                                            temperatureroom=itsTemperatureSensor->getTemperatureroom();
                                            dif=temperaturegoal-temperatureroom;
                                            //#]
                                            //#[ transition state_8.5 
                                            itsHVAC->setHvac(2);
                                            //#]
                                            NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_9.Cooling");
                                            state_9_subState = Cooling;
                                            state_9_active = Cooling;
                                            state_9_timeout = scheduleTimeout(1000, "ROOT.state_8.ROOT.state_8.state_9.Cooling");
                                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.5");
                                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.6");
                                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.16");
                                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.2");
                                            res = eventConsumed;
                                        }
                                    else
                                        {
                                            //## transition state_8.7 
                                            if(dif==0)
                                                {
                                                    NOTIFY_TRANSITION_STARTED("ROOT.state_8.2");
                                                    NOTIFY_TRANSITION_STARTED("ROOT.state_8.16");
                                                    NOTIFY_TRANSITION_STARTED("ROOT.state_8.6");
                                                    NOTIFY_TRANSITION_STARTED("ROOT.state_8.7");
                                                    popNullTransition();
                                                    NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_13");
                                                    //#[ transition state_8.2 
                                                    hvac=itsHVAC->getHvac();
                                                    //#]
                                                    //#[ transition state_8.16 
                                                    temperatureroom=itsTemperatureSensor->getTemperatureroom();
                                                    //#]
                                                    //#[ transition state_8.6 
                                                    temperatureroom=itsTemperatureSensor->getTemperatureroom();
                                                    dif=temperaturegoal-temperatureroom;
                                                    //#]
                                                    //#[ transition state_8.7 
                                                    itsHVAC->setHvac(0);
                                                    //#]
                                                    NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_9.Off");
                                                    state_9_subState = Off;
                                                    state_9_active = Off;
                                                    state_9_timeout = scheduleTimeout(1000, "ROOT.state_8.ROOT.state_8.state_9.Off");
                                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.7");
                                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.6");
                                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.16");
                                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.2");
                                                    res = eventConsumed;
                                                }
                                        }
                                }
                        }
                }
        }
    return res;
}

IOxfReactive::TakeEventStatus AirConditioner::accepttimeevent_13_handleEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
        {
            res = accepttimeevent_13TakeNull();
        }
    
    
    return res;
}

void AirConditioner::state_10_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_10");
    NOTIFY_TRANSITION_STARTED("ROOT.state_8.14");
    NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_10.SendAndRecieve");
    state_10_subState = SendAndRecieve;
    state_10_active = SendAndRecieve;
    //#[ state state_8.state_8.state_10.SendAndRecieve.(Entry) 
    callMain();
    //std::cout<<"fire_bool in fire sensor is : "<<itsFireSensor->getFire_bool()<<"************************"<<std::endl;
    
     
    //#]
    state_10_timeout = scheduleTimeout(2000, "ROOT.state_8.ROOT.state_8.state_10.SendAndRecieve");
    NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.14");
}

void AirConditioner::state_10_exit(void) {
    // State SendAndRecieve
    if(state_10_subState == SendAndRecieve)
        {
            cancel(state_10_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_10.SendAndRecieve");
        }
    state_10_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_10");
}

IOxfReactive::TakeEventStatus AirConditioner::state_10_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State SendAndRecieve
    if(state_10_active == SendAndRecieve)
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_10_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_8.15");
                            cancel(state_10_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_8.ROOT.state_8.state_10.SendAndRecieve");
                            NOTIFY_STATE_ENTERED("ROOT.state_8.ROOT.state_8.state_10.SendAndRecieve");
                            state_10_subState = SendAndRecieve;
                            state_10_active = SendAndRecieve;
                            //#[ state state_8.state_8.state_10.SendAndRecieve.(Entry) 
                            callMain();
                            //std::cout<<"fire_bool in fire sensor is : "<<itsFireSensor->getFire_bool()<<"************************"<<std::endl;
                            
                             
                            //#]
                            state_10_timeout = scheduleTimeout(2000, "ROOT.state_8.ROOT.state_8.state_10.SendAndRecieve");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_8.15");
                            res = eventConsumed;
                        }
                }
            
            
        }
    return res;
}

void AirConditioner::rootState_entDef(void) {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        state_8_entDef();
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus AirConditioner::rootState_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State state_8
    if(rootState_active == state_8)
        {
            res = state_8_processEvent();
        }
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedAirConditioner::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("temperaturegoal", x2String(myReal->temperaturegoal));
    aomsAttributes->addAttribute("temperatureroom", x2String(myReal->temperatureroom));
    aomsAttributes->addAttribute("hvac", x2String(myReal->hvac));
    aomsAttributes->addAttribute("address_temperaturegoal", UNKNOWN2STRING(myReal->address_temperaturegoal));
    aomsAttributes->addAttribute("iResultTemperaturegoal", x2String(myReal->iResultTemperaturegoal));
    aomsAttributes->addAttribute("iSendResultTemperaturegoal", x2String(myReal->iSendResultTemperaturegoal));
    aomsAttributes->addAttribute("listenSocketForTemperaturegoal", UNKNOWN2STRING(myReal->listenSocketForTemperaturegoal));
    aomsAttributes->addAttribute("portTemperaturegoal", x2String(myReal->portTemperaturegoal));
    aomsAttributes->addAttribute("dif", x2String(myReal->dif));
    aomsAttributes->addAttribute("speed", x2String(myReal->speed));
    aomsAttributes->addAttribute("recvbuf", array2String(DEFAULT_BUFLEN, myReal->recvbuf, sizeof(char), &x2String));
    aomsAttributes->addAttribute("recvbuflen", x2String(myReal->recvbuflen));
    aomsAttributes->addAttribute("serverName", x2String(myReal->serverName));
    aomsAttributes->addAttribute("ws", UNKNOWN2STRING(myReal->ws));
    aomsAttributes->addAttribute("mode", x2String(myReal->mode));
}

void OMAnimatedAirConditioner::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsHVAC", false, true);
    if(myReal->itsHVAC)
        {
            aomsRelations->ADD_ITEM(myReal->itsHVAC);
        }
    aomsRelations->addRelation("itsTemperatureSensor", false, true);
    if(myReal->itsTemperatureSensor)
        {
            aomsRelations->ADD_ITEM(myReal->itsTemperatureSensor);
        }
    aomsRelations->addRelation("itsTemperatureSensor_1", false, true);
    if(myReal->itsTemperatureSensor_1)
        {
            aomsRelations->ADD_ITEM(myReal->itsTemperatureSensor_1);
        }
    aomsRelations->addRelation("itsTemperatureSensor_2", false, true);
    if(myReal->itsTemperatureSensor_2)
        {
            aomsRelations->ADD_ITEM(myReal->itsTemperatureSensor_2);
        }
}

void OMAnimatedAirConditioner::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    if(myReal->rootState_subState == AirConditioner::state_8)
        {
            state_8_serializeStates(aomsState);
        }
}

void OMAnimatedAirConditioner::state_8_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_8");
    state_9_serializeStates(aomsState);
    state_10_serializeStates(aomsState);
}

void OMAnimatedAirConditioner::state_9_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_8.ROOT.state_8.state_9");
    switch (myReal->state_9_subState) {
        case AirConditioner::Off:
        {
            Off_serializeStates(aomsState);
        }
        break;
        case AirConditioner::accepttimeevent_13:
        {
            accepttimeevent_13_serializeStates(aomsState);
        }
        break;
        case AirConditioner::Heating:
        {
            Heating_serializeStates(aomsState);
        }
        break;
        case AirConditioner::Cooling:
        {
            Cooling_serializeStates(aomsState);
        }
        break;
        case AirConditioner::accepttimeevent_4:
        {
            accepttimeevent_4_serializeStates(aomsState);
        }
        break;
        case AirConditioner::accepttimeevent_5:
        {
            accepttimeevent_5_serializeStates(aomsState);
        }
        break;
        case AirConditioner::accepttimeevent_6:
        {
            accepttimeevent_6_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedAirConditioner::Off_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_8.ROOT.state_8.state_9.Off");
}

void OMAnimatedAirConditioner::Heating_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_8.ROOT.state_8.state_9.Heating");
}

void OMAnimatedAirConditioner::Cooling_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_8.ROOT.state_8.state_9.Cooling");
}

void OMAnimatedAirConditioner::accepttimeevent_6_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_6");
}

void OMAnimatedAirConditioner::accepttimeevent_5_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_5");
}

void OMAnimatedAirConditioner::accepttimeevent_4_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_4");
}

void OMAnimatedAirConditioner::accepttimeevent_13_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_8.ROOT.state_8.state_9.accepttimeevent_13");
}

void OMAnimatedAirConditioner::state_10_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_8.ROOT.state_8.state_10");
    if(myReal->state_10_subState == AirConditioner::SendAndRecieve)
        {
            SendAndRecieve_serializeStates(aomsState);
        }
}

void OMAnimatedAirConditioner::SendAndRecieve_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_8.ROOT.state_8.state_10.SendAndRecieve");
}
//#]

IMPLEMENT_REACTIVE_META_P(AirConditioner, Default, Default, false, OMAnimatedAirConditioner)

IMPLEMENT_META_OP(OMAnimatedAirConditioner, Default_AirConditioner_SettingAirConditioner, "SettingAirConditioner", FALSE, "SettingAirConditioner()", 0)

IMPLEMENT_OP_CALL(Default_AirConditioner_SettingAirConditioner, AirConditioner, SettingAirConditioner(), int animRetVal = )

IMPLEMENT_META_OP(OMAnimatedAirConditioner, Default_AirConditioner_callMain, "callMain", FALSE, "callMain()", 0)

IMPLEMENT_OP_CALL(Default_AirConditioner_callMain, AirConditioner, callMain(), int animRetVal = )

IMPLEMENT_META_OP(OMAnimatedAirConditioner, Default_AirConditioner_callMain_copy, "callMain_copy", FALSE, "callMain_copy()", 0)

IMPLEMENT_OP_CALL(Default_AirConditioner_callMain_copy, AirConditioner, callMain_copy(), int animRetVal = )

IMPLEMENT_META_OP(OMAnimatedAirConditioner, Default_AirConditioner_getSpeed, "getSpeed", FALSE, "getSpeed()", 0)

IMPLEMENT_OP_CALL(Default_AirConditioner_getSpeed, AirConditioner, getSpeed(), float animRetVal = )

IMPLEMENT_META_OP(OMAnimatedAirConditioner, Default_AirConditioner_getTemperaturegoal, "getTemperaturegoal", FALSE, "getTemperaturegoal()", 0)

IMPLEMENT_OP_CALL(Default_AirConditioner_getTemperaturegoal, AirConditioner, getTemperaturegoal(), float animRetVal = )

IMPLEMENT_META_OP(OMAnimatedAirConditioner, Default_AirConditioner_setDif_float, "setDif", FALSE, "setDif(float)", 1)

IMPLEMENT_OP_CALL(Default_AirConditioner_setDif_float, AirConditioner, setDif(p_dif), NO_OP())

IMPLEMENT_META_OP(OMAnimatedAirConditioner, Default_AirConditioner_setHvac_float, "setHvac", FALSE, "setHvac(float)", 1)

IMPLEMENT_OP_CALL(Default_AirConditioner_setHvac_float, AirConditioner, setHvac(p_hvac), NO_OP())

IMPLEMENT_META_OP(OMAnimatedAirConditioner, Default_AirConditioner_setTemperaturegoal_float, "setTemperaturegoal", FALSE, "setTemperaturegoal(float)", 1)

IMPLEMENT_OP_CALL(Default_AirConditioner_setTemperaturegoal_float, AirConditioner, setTemperaturegoal(p_temperaturegoal), NO_OP())

IMPLEMENT_META_OP(OMAnimatedAirConditioner, Default_AirConditioner_setTemperatureroom_float, "setTemperatureroom", FALSE, "setTemperatureroom(float)", 1)

IMPLEMENT_OP_CALL(Default_AirConditioner_setTemperatureroom_float, AirConditioner, setTemperatureroom(p_temperatureroom), NO_OP())
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AirConditioner.cpp
*********************************************************************/
