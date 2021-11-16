/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: FireAlarm
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\FireAlarm.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "FireAlarm.h"
//## link itsDTSR
#include "DTSR.h"
//## link itsFireSensor
#include "FireSensor.h"
//## link itsHVAC
#include "HVAC.h"
//## link itsVentilation
#include "Ventilation.h"
//#[ ignore
#define Default_FireAlarm_FireAlarm_SERIALIZE OM_NO_OP

#define Default_FireAlarm_FireNow_SERIALIZE OM_NO_OP

#define Default_FireAlarm_FireStop_SERIALIZE OM_NO_OP

#define Default_FireAlarm_callMain_SERIALIZE OM_NO_OP

#define Default_FireAlarm_getFirealarm_bool_SERIALIZE OM_NO_OP

#define OMAnim_Default_FireAlarm_setFirealarm_bool_bool_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_firealarm_bool)

#define OMAnim_Default_FireAlarm_setFirealarm_bool_bool_SERIALIZE_RET_VAL
//#]

//## package Default

//## class FireAlarm
FireAlarm::FireAlarm(IOxfActive* const theActiveContext) : OMReactive(), fire_bool(0), firealarm_bool(0), listenSocketForFire(INVALID_SOCKET), listenSocketForFirealarm(INVALID_SOCKET), portFire(10002), portFirealarm(10004), recvbuflen(DEFAULT_BUFLEN), serverName("127.0.0.1"), itsDTSR(NULL), itsFireSensor(NULL), itsHVAC(NULL), itsVentilation(NULL) {
    NOTIFY_REACTIVE_CONSTRUCTOR(FireAlarm, FireAlarm(), 0, Default_FireAlarm_FireAlarm_SERIALIZE);
    setActiveContext(theActiveContext, false);
    initStatechart();
}

FireAlarm::~FireAlarm(void) {
    NOTIFY_DESTRUCTOR(~FireAlarm, true);
    cleanUpRelations();
    cancelTimeouts();
}

void FireAlarm::FireNow(void) {
    NOTIFY_OPERATION(FireNow, FireNow(), 0, Default_FireAlarm_FireNow_SERIALIZE);
    //#[ operation FireNow()
    std::cout<<"Firing!**********************************\n";
    //#]
}

void FireAlarm::FireStop(void) {
    NOTIFY_OPERATION(FireStop, FireStop(), 0, Default_FireAlarm_FireStop_SERIALIZE);
    //#[ operation FireStop()
    std::cout<<"fire stop ******************************\n";
    //#]
}

int FireAlarm::callMain(void) {
    NOTIFY_OPERATION(callMain, callMain(), 0, Default_FireAlarm_callMain_SERIALIZE);
    //#[ operation callMain()
    #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
    #define _WINSOCK_DEPRECATED_NO_WARNINGS
    #endif
    
    #include <stdlib.h>
    
    WSAStartup(0x0101,&ws);
    
    char out_string_for_fire [1024];
    char out_string_for_firealarm [1024];
    
    //<built-in method upper of str object at 0x000002144880B430>
    ZeroMemory(&address_fire, sizeof(address_fire));
    address_fire.sin_family = AF_INET;
    address_fire.sin_port = htons(portFire);
    address_fire.sin_addr.s_addr=inet_addr(serverName);
    //<built-in method upper of str object at 0x000002144880B270>
    ZeroMemory(&address_firealarm, sizeof(address_firealarm));
    address_firealarm.sin_family = AF_INET;
    address_firealarm.sin_port = htons(portFirealarm);
    address_firealarm.sin_addr.s_addr=inet_addr(serverName);
    
    //INITIALIZE ALL SOCKETS
    listenSocketForFire = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    listenSocketForFirealarm = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    //CONNECT ALL THE SOCKETS
    iResultFire = connect(listenSocketForFire,(SOCKADDR*)&address_fire, sizeof(address_fire)); 
    iResultFirealarm = connect(listenSocketForFirealarm,(SOCKADDR*)&address_firealarm, sizeof(address_firealarm)); 
    
    
    //ASSIGN VALUES TO SEND 
    sprintf(out_string_for_fire, "%f", fire);
    sprintf(out_string_for_firealarm, "%f", firealarm);
    
    
    
    //SEND VALUE
    iSendResultFire = sendto(listenSocketForFire, (char *)&out_string_for_fire ,sizeof(uint32_t), 0 ,(SOCKADDR *) & address_fire, sizeof (address_fire) );
    iSendResultFirealarm = sendto(listenSocketForFirealarm, (char *)&out_string_for_firealarm ,sizeof(uint32_t), 0 ,(SOCKADDR *) & address_firealarm, sizeof (address_firealarm) );
    //SHOW SENT VALUES IN CONSOLE
    //printf("Fire value sent: %s \n",out_string_for_fire);
    //printf("Firealarm value sent: %s \n",out_string_for_firealarm);
    
    //RECIEVED VALUE OF FIRE
    iResultFire = recv(listenSocketForFire, recvbuf, recvbuflen, 0); 
    float firetocheck = atof(recvbuf);
    //printf("FIRE value recieved: %f\n",atof(recvbuf));
    //RECIEVED VALUE OF FIREALARM
    iResultFirealarm = recv(listenSocketForFirealarm, recvbuf, recvbuflen, 0); 
    float firealarmtocheck = atof(recvbuf);
    //printf("FIREALARM value recieved: %f\n",atof(recvbuf));
    //CLOSE ALL THE SOCKETS
    closesocket(listenSocketForFire);
    closesocket(listenSocketForFirealarm);
    return 0;
    //#]
}

bool FireAlarm::getFirealarm_bool(void) {
    NOTIFY_OPERATION(getFirealarm_bool, getFirealarm_bool(), 0, Default_FireAlarm_getFirealarm_bool_SERIALIZE);
    //#[ operation getFirealarm_bool()
    return firealarm_bool;
    //#]
}

const SOCKADDR_IN FireAlarm::getAddress_fire(void) const {
    return address_fire;
}

void FireAlarm::setAddress_fire(const SOCKADDR_IN p_address_fire) {
    address_fire = p_address_fire;
}

const SOCKADDR_IN FireAlarm::getAddress_firealarm(void) const {
    return address_firealarm;
}

void FireAlarm::setAddress_firealarm(const SOCKADDR_IN p_address_firealarm) {
    address_firealarm = p_address_firealarm;
}

const float FireAlarm::getFire(void) const {
    return fire;
}

void FireAlarm::setFire(const float p_fire) {
    fire = p_fire;
}

const bool FireAlarm::getFire_bool(void) const {
    return fire_bool;
}

void FireAlarm::setFire_bool(const bool p_fire_bool) {
    fire_bool = p_fire_bool;
    NOTIFY_SET_OPERATION;
}

const float FireAlarm::getFirealarm(void) const {
    return firealarm;
}

void FireAlarm::setFirealarm(const float p_firealarm) {
    firealarm = p_firealarm;
}

void FireAlarm::setFirealarm_bool(const bool p_firealarm_bool) {
    firealarm_bool = p_firealarm_bool;
    NOTIFY_SET_OPERATION;
}

const int FireAlarm::getIResultFire(void) const {
    return iResultFire;
}

void FireAlarm::setIResultFire(const int p_iResultFire) {
    iResultFire = p_iResultFire;
}

const int FireAlarm::getIResultFirealarm(void) const {
    return iResultFirealarm;
}

void FireAlarm::setIResultFirealarm(const int p_iResultFirealarm) {
    iResultFirealarm = p_iResultFirealarm;
}

const int FireAlarm::getISendResultFire(void) const {
    return iSendResultFire;
}

void FireAlarm::setISendResultFire(const int p_iSendResultFire) {
    iSendResultFire = p_iSendResultFire;
}

const int FireAlarm::getISendResultFirealarm(void) const {
    return iSendResultFirealarm;
}

void FireAlarm::setISendResultFirealarm(const int p_iSendResultFirealarm) {
    iSendResultFirealarm = p_iSendResultFirealarm;
}

const SOCKET FireAlarm::getListenSocketForFire(void) const {
    return listenSocketForFire;
}

void FireAlarm::setListenSocketForFire(const SOCKET p_listenSocketForFire) {
    listenSocketForFire = p_listenSocketForFire;
}

const SOCKET FireAlarm::getListenSocketForFirealarm(void) const {
    return listenSocketForFirealarm;
}

void FireAlarm::setListenSocketForFirealarm(const SOCKET p_listenSocketForFirealarm) {
    listenSocketForFirealarm = p_listenSocketForFirealarm;
}

const int FireAlarm::getPortFire(void) const {
    return portFire;
}

void FireAlarm::setPortFire(const int p_portFire) {
    portFire = p_portFire;
}

const int FireAlarm::getPortFirealarm(void) const {
    return portFirealarm;
}

void FireAlarm::setPortFirealarm(const int p_portFirealarm) {
    portFirealarm = p_portFirealarm;
}

const char FireAlarm::getRecvbuf(const Rhp_int32_t iterI1) const {
    return recvbuf[iterI1];
}

void FireAlarm::setRecvbuf(const Rhp_int32_t iterI1, const char p_recvbuf) {
    recvbuf[iterI1] = p_recvbuf;
}

const int FireAlarm::getRecvbuflen(void) const {
    return recvbuflen;
}

void FireAlarm::setRecvbuflen(const int p_recvbuflen) {
    recvbuflen = p_recvbuflen;
}

const char* FireAlarm::getServerName(void) const {
    return serverName;
}

void FireAlarm::setServerName(char* const p_serverName) {
    serverName = p_serverName;
}

const WSADATA FireAlarm::getWs(void) const {
    return ws;
}

void FireAlarm::setWs(const WSADATA p_ws) {
    ws = p_ws;
}

const DTSR* FireAlarm::getItsDTSR(void) const {
    return itsDTSR;
}

void FireAlarm::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_setItsFireAlarm(this);
        }
    _setItsDTSR(p_DTSR);
}

const FireSensor* FireAlarm::getItsFireSensor(void) const {
    return itsFireSensor;
}

void FireAlarm::setItsFireSensor(FireSensor* const p_FireSensor) {
    if(p_FireSensor != NULL)
        {
            p_FireSensor->_setItsFireAlarm(this);
        }
    _setItsFireSensor(p_FireSensor);
}

const HVAC* FireAlarm::getItsHVAC(void) const {
    return itsHVAC;
}

void FireAlarm::setItsHVAC(HVAC* const p_HVAC) {
    if(p_HVAC != NULL)
        {
            p_HVAC->_setItsFireAlarm(this);
        }
    _setItsHVAC(p_HVAC);
}

const Ventilation* FireAlarm::getItsVentilation(void) const {
    return itsVentilation;
}

void FireAlarm::setItsVentilation(Ventilation* const p_Ventilation) {
    if(p_Ventilation != NULL)
        {
            p_Ventilation->_setItsFireAlarm(this);
        }
    _setItsVentilation(p_Ventilation);
}

bool FireAlarm::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(state_2_timeout == arg)
        {
            state_2_timeout = NULL;
            res = true;
        }
    if(state_1_timeout == arg)
        {
            state_1_timeout = NULL;
            res = true;
        }
    return res;
}

bool FireAlarm::startBehavior(void) {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void FireAlarm::initStatechart(void) {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    state_2_subState = OMNonState;
    state_2_active = OMNonState;
    state_2_timeout = NULL;
    state_1_subState = OMNonState;
    state_1_active = OMNonState;
    state_1_timeout = NULL;
}

void FireAlarm::cleanUpRelations(void) {
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            const FireAlarm* p_FireAlarm = itsDTSR->getItsFireAlarm();
            if(p_FireAlarm != NULL)
                {
                    itsDTSR->__setItsFireAlarm(NULL);
                }
            itsDTSR = NULL;
        }
    if(itsFireSensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsFireSensor");
            const FireAlarm* p_FireAlarm = itsFireSensor->getItsFireAlarm();
            if(p_FireAlarm != NULL)
                {
                    itsFireSensor->__setItsFireAlarm(NULL);
                }
            itsFireSensor = NULL;
        }
    if(itsHVAC != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsHVAC");
            const FireAlarm* p_FireAlarm = itsHVAC->getItsFireAlarm();
            if(p_FireAlarm != NULL)
                {
                    itsHVAC->__setItsFireAlarm(NULL);
                }
            itsHVAC = NULL;
        }
    if(itsVentilation != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsVentilation");
            const FireAlarm* p_FireAlarm = itsVentilation->getItsFireAlarm();
            if(p_FireAlarm != NULL)
                {
                    itsVentilation->__setItsFireAlarm(NULL);
                }
            itsVentilation = NULL;
        }
}

void FireAlarm::cancelTimeouts(void) {
    cancel(state_2_timeout);
    cancel(state_1_timeout);
}

void FireAlarm::__setItsDTSR(DTSR* const p_DTSR) {
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

void FireAlarm::_setItsDTSR(DTSR* const p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->__setItsFireAlarm(NULL);
        }
    __setItsDTSR(p_DTSR);
}

void FireAlarm::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

void FireAlarm::__setItsFireSensor(FireSensor* const p_FireSensor) {
    itsFireSensor = p_FireSensor;
    if(p_FireSensor != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsFireSensor", p_FireSensor, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsFireSensor");
        }
}

void FireAlarm::_setItsFireSensor(FireSensor* const p_FireSensor) {
    if(itsFireSensor != NULL)
        {
            itsFireSensor->__setItsFireAlarm(NULL);
        }
    __setItsFireSensor(p_FireSensor);
}

void FireAlarm::_clearItsFireSensor(void) {
    NOTIFY_RELATION_CLEARED("itsFireSensor");
    itsFireSensor = NULL;
}

void FireAlarm::__setItsHVAC(HVAC* const p_HVAC) {
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

void FireAlarm::_setItsHVAC(HVAC* const p_HVAC) {
    if(itsHVAC != NULL)
        {
            itsHVAC->__setItsFireAlarm(NULL);
        }
    __setItsHVAC(p_HVAC);
}

void FireAlarm::_clearItsHVAC(void) {
    NOTIFY_RELATION_CLEARED("itsHVAC");
    itsHVAC = NULL;
}

void FireAlarm::__setItsVentilation(Ventilation* const p_Ventilation) {
    itsVentilation = p_Ventilation;
    if(p_Ventilation != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsVentilation", p_Ventilation, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsVentilation");
        }
}

void FireAlarm::_setItsVentilation(Ventilation* const p_Ventilation) {
    if(itsVentilation != NULL)
        {
            itsVentilation->__setItsFireAlarm(NULL);
        }
    __setItsVentilation(p_Ventilation);
}

void FireAlarm::_clearItsVentilation(void) {
    NOTIFY_RELATION_CLEARED("itsVentilation");
    itsVentilation = NULL;
}

void FireAlarm::state_0_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_0");
    rootState_subState = state_0;
    rootState_active = state_0;
    state_1_entDef();
    state_2_entDef();
}

void FireAlarm::state_0_exit(void) {
    state_1_exit();
    state_2_exit();
    
    NOTIFY_STATE_EXITED("ROOT.state_0");
}

IOxfReactive::TakeEventStatus FireAlarm::state_0_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    IOxfReactive::TakeEventStatus omComponentStatus = eventNotConsumed;
    bool dispatchDone = false;
    {
        // State state_1
        omComponentStatus = state_1_processEvent();
        if(omComponentStatus != eventNotConsumed)
            {
                res = eventConsumed;
                if(IS_IN(state_0) == false)
                    {
                        dispatchDone = true;
                    }
            }
    }
    if(!dispatchDone)
        {
            // State state_2
            omComponentStatus = state_2_processEvent();
            if(omComponentStatus != eventNotConsumed)
                {
                    res = eventConsumed;
                }
        }
    
    return res;
}

void FireAlarm::state_2_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_2");
    NOTIFY_TRANSITION_STARTED("ROOT.state_0.1");
    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_2.SendAndRecieve");
    state_2_subState = SendAndRecieve;
    state_2_active = SendAndRecieve;
    //#[ state state_0.state_0.state_2.SendAndRecieve.(Entry) 
    if(fire_bool==false){
      fire=0;
    }else{
      fire=1;
    }
    if(firealarm_bool==false){
      firealarm=0;
    }else{
      firealarm=1;
    }
    callMain();
    //std::cout<<"fire_bool in fire sensor is : "<<itsFireSensor->getFire_bool()<<"************************"<<std::endl;
    
     
    //#]
    state_2_timeout = scheduleTimeout(1000, "ROOT.state_0.ROOT.state_0.state_2.SendAndRecieve");
    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.1");
}

void FireAlarm::state_2_exit(void) {
    // State SendAndRecieve
    if(state_2_subState == SendAndRecieve)
        {
            cancel(state_2_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_2.SendAndRecieve");
        }
    state_2_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_2");
}

IOxfReactive::TakeEventStatus FireAlarm::state_2_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State SendAndRecieve
    if(state_2_active == SendAndRecieve)
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_2_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_0.0");
                            cancel(state_2_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_2.SendAndRecieve");
                            NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_2.SendAndRecieve");
                            state_2_subState = SendAndRecieve;
                            state_2_active = SendAndRecieve;
                            //#[ state state_0.state_0.state_2.SendAndRecieve.(Entry) 
                            if(fire_bool==false){
                              fire=0;
                            }else{
                              fire=1;
                            }
                            if(firealarm_bool==false){
                              firealarm=0;
                            }else{
                              firealarm=1;
                            }
                            callMain();
                            //std::cout<<"fire_bool in fire sensor is : "<<itsFireSensor->getFire_bool()<<"************************"<<std::endl;
                            
                             
                            //#]
                            state_2_timeout = scheduleTimeout(1000, "ROOT.state_0.ROOT.state_0.state_2.SendAndRecieve");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.0");
                            res = eventConsumed;
                        }
                }
            
            
        }
    return res;
}

void FireAlarm::state_1_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1");
    NOTIFY_TRANSITION_STARTED("ROOT.state_0.2");
    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.Normal");
    state_1_subState = Normal;
    state_1_active = Normal;
    state_1_timeout = scheduleTimeout(1000, "ROOT.state_0.ROOT.state_0.state_1.Normal");
    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.2");
}

void FireAlarm::state_1_exit(void) {
    switch (state_1_subState) {
        // State Normal
        case Normal:
        {
            cancel(state_1_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.Normal");
        }
        break;
        case accepttimeevent_5:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_5");
        }
        break;
        case accepttimeevent_6:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_6");
        }
        break;
        // State Alarm
        case Alarm:
        {
            cancel(state_1_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.Alarm");
        }
        break;
        case accepttimeevent_8:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_8");
        }
        break;
        case accepttimeevent_9:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_9");
        }
        break;
        default:
            break;
    }
    state_1_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1");
}

IOxfReactive::TakeEventStatus FireAlarm::state_1_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_1_active) {
        // State Normal
        case Normal:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_1_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_0.3");
                            cancel(state_1_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.Normal");
                            NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_5");
                            pushNullTransition();
                            state_1_subState = accepttimeevent_5;
                            state_1_active = accepttimeevent_5;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.3");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        case accepttimeevent_5:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    //## transition state_0.5 
                    if(fire_bool==false)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_0.4");
                            NOTIFY_TRANSITION_STARTED("ROOT.state_0.5");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_5");
                            //#[ transition state_0.4 
                            fire_bool=itsFireSensor->getFire_bool();
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.Normal");
                            state_1_subState = Normal;
                            state_1_active = Normal;
                            state_1_timeout = scheduleTimeout(1000, "ROOT.state_0.ROOT.state_0.state_1.Normal");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.5");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.4");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition state_0.6 
                            if(fire_bool==true)
                                {
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_0.4");
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_0.6");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_5");
                                    //#[ transition state_0.4 
                                    fire_bool=itsFireSensor->getFire_bool();
                                    //#]
                                    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_6");
                                    pushNullTransition();
                                    state_1_subState = accepttimeevent_6;
                                    state_1_active = accepttimeevent_6;
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.6");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.4");
                                    res = eventConsumed;
                                }
                        }
                }
            
            
        }
        break;
        case accepttimeevent_6:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.state_0.7");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_6");
                    //#[ transition state_0.7 
                    firealarm_bool=true;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.Alarm");
                    state_1_subState = Alarm;
                    state_1_active = Alarm;
                    state_1_timeout = scheduleTimeout(1000, "ROOT.state_0.ROOT.state_0.state_1.Alarm");
                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.7");
                    res = eventConsumed;
                }
            
            
        }
        break;
        // State Alarm
        case Alarm:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_1_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_0.8");
                            cancel(state_1_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.Alarm");
                            NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_8");
                            pushNullTransition();
                            state_1_subState = accepttimeevent_8;
                            state_1_active = accepttimeevent_8;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.8");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        case accepttimeevent_8:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    //## transition state_0.10 
                    if(fire_bool==true)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_0.9");
                            NOTIFY_TRANSITION_STARTED("ROOT.state_0.10");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_8");
                            //#[ transition state_0.9 
                            fire_bool=itsFireSensor->getFire_bool();
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.Alarm");
                            state_1_subState = Alarm;
                            state_1_active = Alarm;
                            state_1_timeout = scheduleTimeout(1000, "ROOT.state_0.ROOT.state_0.state_1.Alarm");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.10");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.9");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition state_0.11 
                            if(fire_bool==false)
                                {
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_0.9");
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_0.11");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_8");
                                    //#[ transition state_0.9 
                                    fire_bool=itsFireSensor->getFire_bool();
                                    //#]
                                    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_9");
                                    pushNullTransition();
                                    state_1_subState = accepttimeevent_9;
                                    state_1_active = accepttimeevent_9;
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.11");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.9");
                                    res = eventConsumed;
                                }
                        }
                }
            
            
        }
        break;
        case accepttimeevent_9:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.state_0.12");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_9");
                    //#[ transition state_0.12 
                    firealarm_bool=false;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.Normal");
                    state_1_subState = Normal;
                    state_1_active = Normal;
                    state_1_timeout = scheduleTimeout(1000, "ROOT.state_0.ROOT.state_0.state_1.Normal");
                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.12");
                    res = eventConsumed;
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

void FireAlarm::rootState_entDef(void) {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        state_0_entDef();
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus FireAlarm::rootState_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State state_0
    if(rootState_active == state_0)
        {
            res = state_0_processEvent();
        }
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedFireAlarm::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("address_fire", UNKNOWN2STRING(myReal->address_fire));
    aomsAttributes->addAttribute("address_firealarm", UNKNOWN2STRING(myReal->address_firealarm));
    aomsAttributes->addAttribute("iResultFire", x2String(myReal->iResultFire));
    aomsAttributes->addAttribute("iResultFirealarm", x2String(myReal->iResultFirealarm));
    aomsAttributes->addAttribute("iSendResultFire", x2String(myReal->iSendResultFire));
    aomsAttributes->addAttribute("iSendResultFirealarm", x2String(myReal->iSendResultFirealarm));
    aomsAttributes->addAttribute("listenSocketForFire", UNKNOWN2STRING(myReal->listenSocketForFire));
    aomsAttributes->addAttribute("listenSocketForFirealarm", UNKNOWN2STRING(myReal->listenSocketForFirealarm));
    aomsAttributes->addAttribute("portFire", x2String(myReal->portFire));
    aomsAttributes->addAttribute("portFirealarm", x2String(myReal->portFirealarm));
    aomsAttributes->addAttribute("recvbuf", array2String(DEFAULT_BUFLEN, myReal->recvbuf, sizeof(char), &x2String));
    aomsAttributes->addAttribute("recvbuflen", x2String(myReal->recvbuflen));
    aomsAttributes->addAttribute("serverName", x2String(myReal->serverName));
    aomsAttributes->addAttribute("fire", x2String(myReal->fire));
    aomsAttributes->addAttribute("firealarm", x2String(myReal->firealarm));
    aomsAttributes->addAttribute("ws", UNKNOWN2STRING(myReal->ws));
    aomsAttributes->addAttribute("fire_bool", x2String(myReal->fire_bool));
    aomsAttributes->addAttribute("firealarm_bool", x2String(myReal->firealarm_bool));
}

void OMAnimatedFireAlarm::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsFireSensor", false, true);
    if(myReal->itsFireSensor)
        {
            aomsRelations->ADD_ITEM(myReal->itsFireSensor);
        }
    aomsRelations->addRelation("itsHVAC", false, true);
    if(myReal->itsHVAC)
        {
            aomsRelations->ADD_ITEM(myReal->itsHVAC);
        }
    aomsRelations->addRelation("itsVentilation", false, true);
    if(myReal->itsVentilation)
        {
            aomsRelations->ADD_ITEM(myReal->itsVentilation);
        }
    aomsRelations->addRelation("itsDTSR", false, true);
    if(myReal->itsDTSR)
        {
            aomsRelations->ADD_ITEM(myReal->itsDTSR);
        }
}

void OMAnimatedFireAlarm::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    if(myReal->rootState_subState == FireAlarm::state_0)
        {
            state_0_serializeStates(aomsState);
        }
}

void OMAnimatedFireAlarm::state_0_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0");
    state_1_serializeStates(aomsState);
    state_2_serializeStates(aomsState);
}

void OMAnimatedFireAlarm::state_2_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_2");
    if(myReal->state_2_subState == FireAlarm::SendAndRecieve)
        {
            SendAndRecieve_serializeStates(aomsState);
        }
}

void OMAnimatedFireAlarm::SendAndRecieve_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_2.SendAndRecieve");
}

void OMAnimatedFireAlarm::state_1_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_1");
    switch (myReal->state_1_subState) {
        case FireAlarm::Normal:
        {
            Normal_serializeStates(aomsState);
        }
        break;
        case FireAlarm::accepttimeevent_5:
        {
            accepttimeevent_5_serializeStates(aomsState);
        }
        break;
        case FireAlarm::accepttimeevent_6:
        {
            accepttimeevent_6_serializeStates(aomsState);
        }
        break;
        case FireAlarm::Alarm:
        {
            Alarm_serializeStates(aomsState);
        }
        break;
        case FireAlarm::accepttimeevent_8:
        {
            accepttimeevent_8_serializeStates(aomsState);
        }
        break;
        case FireAlarm::accepttimeevent_9:
        {
            accepttimeevent_9_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedFireAlarm::Normal_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_1.Normal");
}

void OMAnimatedFireAlarm::Alarm_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_1.Alarm");
}

void OMAnimatedFireAlarm::accepttimeevent_9_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_9");
}

void OMAnimatedFireAlarm::accepttimeevent_8_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_8");
}

void OMAnimatedFireAlarm::accepttimeevent_6_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_6");
}

void OMAnimatedFireAlarm::accepttimeevent_5_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_5");
}
//#]

IMPLEMENT_REACTIVE_META_P(FireAlarm, Default, Default, false, OMAnimatedFireAlarm)

IMPLEMENT_META_OP(OMAnimatedFireAlarm, Default_FireAlarm_setFirealarm_bool_bool, "setFirealarm_bool", FALSE, "setFirealarm_bool(bool)", 1)

IMPLEMENT_OP_CALL(Default_FireAlarm_setFirealarm_bool_bool, FireAlarm, setFirealarm_bool(p_firealarm_bool), NO_OP())
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: component_3\DefaultConfig\FireAlarm.cpp
*********************************************************************/
