/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: CO2Sensor
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\CO2Sensor.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "CO2Sensor.h"
//## link itsDTSR
#include "DTSR.h"
//## link itsHVAC
#include "HVAC.h"
//## link itsOccupancySensor
#include "OccupancySensor.h"
//## link itsVentilation
#include "Ventilation.h"
//#[ ignore
#define Default_CO2Sensor_CO2Sensor_SERIALIZE OM_NO_OP

#define Default_CO2Sensor_callMain_SERIALIZE OM_NO_OP

#define Default_CO2Sensor_changeFromHVAC_SERIALIZE OM_NO_OP

#define Default_CO2Sensor_getCo2density_SERIALIZE OM_NO_OP

#define Default_CO2Sensor_initilializeCo2sensor_SERIALIZE OM_NO_OP

#define Default_CO2Sensor_setModifying_bool_SERIALIZE aomsmethod->addAttribute("newValue", x2String(newValue));

#define OMAnim_Default_CO2Sensor_setCo2density_float_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_co2density)

#define OMAnim_Default_CO2Sensor_setCo2density_float_SERIALIZE_RET_VAL
//#]

//## package Default

//## class CO2Sensor
CO2Sensor::CO2Sensor(IOxfActive* const theActiveContext) : OMReactive(), co2density(200), co2highgoal(1000), co2lowgoal(400), listenSocketForCo2density(INVALID_SOCKET), modifying_bool(0), portCo2density(10012), recvbuflen(DEFAULT_BUFLEN), serverName("127.0.0.1"), speed(10), itsDTSR(NULL), itsHVAC(NULL), itsOccupancySensor(NULL), itsVentilation(NULL) {
    NOTIFY_REACTIVE_CONSTRUCTOR(CO2Sensor, CO2Sensor(), 0, Default_CO2Sensor_CO2Sensor_SERIALIZE);
    setActiveContext(theActiveContext, false);
    initStatechart();
}

CO2Sensor::~CO2Sensor(void) {
    NOTIFY_DESTRUCTOR(~CO2Sensor, true);
    cleanUpRelations();
    cancelTimeouts();
}

int CO2Sensor::callMain(void) {
    NOTIFY_OPERATION(callMain, callMain(), 0, Default_CO2Sensor_callMain_SERIALIZE);
    //#[ operation callMain()
    #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
    #define _WINSOCK_DEPRECATED_NO_WARNINGS
    #endif
    
    #include <stdlib.h>
    
    WSAStartup(0x0101,&ws);
    
    char out_string_for_co2density [1024];
    
    //CO2DENSITY
    ZeroMemory(&address_co2density, sizeof(address_co2density));
    address_co2density.sin_family = AF_INET;
    address_co2density.sin_port = htons(portCo2density);
    address_co2density.sin_addr.s_addr=inet_addr(serverName);
    
    //INITIALIZE ALL SOCKETS
    listenSocketForCo2density = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    //CONNECT ALL THE SOCKETS
    iResultCo2density = connect(listenSocketForCo2density,(SOCKADDR*)&address_co2density, sizeof(address_co2density)); 
    
    
    
    //ASSIGN VALUES TO SEND 
    sprintf(out_string_for_co2density, "%f", co2density);
    
    
    
    //SEND VALUE
    iSendResultCo2density = sendto(listenSocketForCo2density, (char *)&out_string_for_co2density ,sizeof(uint32_t), 0 ,(SOCKADDR *) & address_co2density, sizeof (address_co2density) );
    //SHOW SENT VALUES IN CONSOLE
    //printf("Co2density value sent: %s \n",out_string_for_co2density);
    
    //RECIEVED VALUE OF CO2DENSITY
    iResultCo2density = recv(listenSocketForCo2density, recvbuf, recvbuflen, 0); 
    float co2densitytocheck = atof(recvbuf);
    printf("CO2DENSITY value recieved: %f\n",atof(recvbuf));
    //CLOSE ALL THE SOCKETS
    closesocket(listenSocketForCo2density);
    return 0;
    
    //#]
}

int CO2Sensor::changeFromHVAC(void) {
    NOTIFY_OPERATION(changeFromHVAC, changeFromHVAC(), 0, Default_CO2Sensor_changeFromHVAC_SERIALIZE);
    //#[ operation changeFromHVAC()
    //std::cout<<"itsHVAC->getMode() : "<<itsHVAC->getMode()<<std::endl;
    if(itsHVAC->getHvac()<3) return 0;
    
    float dif=co2density-co2lowgoal;
    if((dif<speed) && (dif>speed*(-1))){
    	co2density=co2lowgoal;
    }else if(dif>=speed){
    	co2density-=speed;
    }
    return 0;
    //std::cout<<"itsHVAC->getHvac() : "<<itsHVAC->getHvac()<<std::endl;
    //#]
}

float CO2Sensor::getCo2density(void) {
    NOTIFY_OPERATION(getCo2density, getCo2density(), 0, Default_CO2Sensor_getCo2density_SERIALIZE);
    //#[ operation getCo2density()
    return modifying_bool? 100000 : co2density;
    //#]
}

void CO2Sensor::initilializeCo2sensor(void) {
    NOTIFY_OPERATION(initilializeCo2sensor, initilializeCo2sensor(), 0, Default_CO2Sensor_initilializeCo2sensor_SERIALIZE);
    //#[ operation initilializeCo2sensor()
    co2highgoal=itsVentilation->getCo2highgoal();
    co2lowgoal=itsVentilation->getCo2lowgoal();
    speed=itsVentilation->getSpeed();
    //#]
}

void CO2Sensor::setModifying_bool(bool newValue) {
    NOTIFY_OPERATION(setModifying_bool, setModifying_bool(bool), 1, Default_CO2Sensor_setModifying_bool_SERIALIZE);
    //#[ operation setModifying_bool(bool)
    modifying_bool=newValue;
    //#]
    NOTIFY_SET_OPERATION;
}

const SOCKADDR_IN CO2Sensor::getAddress_co2density(void) const {
    return address_co2density;
}

void CO2Sensor::setAddress_co2density(const SOCKADDR_IN p_address_co2density) {
    address_co2density = p_address_co2density;
}

void CO2Sensor::setCo2density(const float p_co2density) {
    co2density = p_co2density;
    NOTIFY_SET_OPERATION;
}

const float CO2Sensor::getCo2highgoal(void) const {
    return co2highgoal;
}

void CO2Sensor::setCo2highgoal(const float p_co2highgoal) {
    co2highgoal = p_co2highgoal;
}

const float CO2Sensor::getCo2lowgoal(void) const {
    return co2lowgoal;
}

void CO2Sensor::setCo2lowgoal(const float p_co2lowgoal) {
    co2lowgoal = p_co2lowgoal;
}

const int CO2Sensor::getIResultCo2density(void) const {
    return iResultCo2density;
}

void CO2Sensor::setIResultCo2density(const int p_iResultCo2density) {
    iResultCo2density = p_iResultCo2density;
}

const int CO2Sensor::getISendResultCo2density(void) const {
    return iSendResultCo2density;
}

void CO2Sensor::setISendResultCo2density(const int p_iSendResultCo2density) {
    iSendResultCo2density = p_iSendResultCo2density;
}

const SOCKET CO2Sensor::getListenSocketForCo2density(void) const {
    return listenSocketForCo2density;
}

void CO2Sensor::setListenSocketForCo2density(const SOCKET p_listenSocketForCo2density) {
    listenSocketForCo2density = p_listenSocketForCo2density;
}

const bool CO2Sensor::getModifying_bool(void) const {
    return modifying_bool;
}

const int CO2Sensor::getPortCo2density(void) const {
    return portCo2density;
}

void CO2Sensor::setPortCo2density(const int p_portCo2density) {
    portCo2density = p_portCo2density;
}

const char CO2Sensor::getRecvbuf(const Rhp_int32_t iterI1) const {
    return recvbuf[iterI1];
}

void CO2Sensor::setRecvbuf(const Rhp_int32_t iterI1, const char p_recvbuf) {
    recvbuf[iterI1] = p_recvbuf;
}

const int CO2Sensor::getRecvbuflen(void) const {
    return recvbuflen;
}

void CO2Sensor::setRecvbuflen(const int p_recvbuflen) {
    recvbuflen = p_recvbuflen;
}

const char* CO2Sensor::getServerName(void) const {
    return serverName;
}

void CO2Sensor::setServerName(char* const p_serverName) {
    serverName = p_serverName;
}

const float CO2Sensor::getSpeed(void) const {
    return speed;
}

void CO2Sensor::setSpeed(const float p_speed) {
    speed = p_speed;
}

const WSADATA CO2Sensor::getWs(void) const {
    return ws;
}

void CO2Sensor::setWs(const WSADATA p_ws) {
    ws = p_ws;
}

const DTSR* CO2Sensor::getItsDTSR(void) const {
    return itsDTSR;
}

void CO2Sensor::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_setItsCO2Sensor(this);
        }
    _setItsDTSR(p_DTSR);
}

const HVAC* CO2Sensor::getItsHVAC(void) const {
    return itsHVAC;
}

void CO2Sensor::setItsHVAC(HVAC* const p_HVAC) {
    if(p_HVAC != NULL)
        {
            p_HVAC->_setItsCO2Sensor(this);
        }
    _setItsHVAC(p_HVAC);
}

const OccupancySensor* CO2Sensor::getItsOccupancySensor(void) const {
    return itsOccupancySensor;
}

void CO2Sensor::setItsOccupancySensor(OccupancySensor* const p_OccupancySensor) {
    if(p_OccupancySensor != NULL)
        {
            p_OccupancySensor->_setItsCO2Sensor(this);
        }
    _setItsOccupancySensor(p_OccupancySensor);
}

const Ventilation* CO2Sensor::getItsVentilation(void) const {
    return itsVentilation;
}

void CO2Sensor::setItsVentilation(Ventilation* const p_Ventilation) {
    if(p_Ventilation != NULL)
        {
            p_Ventilation->_setItsCO2Sensor(this);
        }
    _setItsVentilation(p_Ventilation);
}

bool CO2Sensor::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(state_7_timeout == arg)
        {
            state_7_timeout = NULL;
            res = true;
        }
    if(state_6_timeout == arg)
        {
            state_6_timeout = NULL;
            res = true;
        }
    return res;
}

bool CO2Sensor::startBehavior(void) {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void CO2Sensor::initStatechart(void) {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    state_7_subState = OMNonState;
    state_7_active = OMNonState;
    state_7_timeout = NULL;
    state_6_subState = OMNonState;
    state_6_active = OMNonState;
    state_6_timeout = NULL;
}

void CO2Sensor::cleanUpRelations(void) {
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            const CO2Sensor* p_CO2Sensor = itsDTSR->getItsCO2Sensor();
            if(p_CO2Sensor != NULL)
                {
                    itsDTSR->__setItsCO2Sensor(NULL);
                }
            itsDTSR = NULL;
        }
    if(itsHVAC != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsHVAC");
            const CO2Sensor* p_CO2Sensor = itsHVAC->getItsCO2Sensor();
            if(p_CO2Sensor != NULL)
                {
                    itsHVAC->__setItsCO2Sensor(NULL);
                }
            itsHVAC = NULL;
        }
    if(itsOccupancySensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsOccupancySensor");
            const CO2Sensor* p_CO2Sensor = itsOccupancySensor->getItsCO2Sensor();
            if(p_CO2Sensor != NULL)
                {
                    itsOccupancySensor->__setItsCO2Sensor(NULL);
                }
            itsOccupancySensor = NULL;
        }
    if(itsVentilation != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsVentilation");
            const CO2Sensor* p_CO2Sensor = itsVentilation->getItsCO2Sensor();
            if(p_CO2Sensor != NULL)
                {
                    itsVentilation->__setItsCO2Sensor(NULL);
                }
            itsVentilation = NULL;
        }
}

void CO2Sensor::cancelTimeouts(void) {
    cancel(state_7_timeout);
    cancel(state_6_timeout);
}

void CO2Sensor::__setItsDTSR(DTSR* const p_DTSR) {
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

void CO2Sensor::_setItsDTSR(DTSR* const p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->__setItsCO2Sensor(NULL);
        }
    __setItsDTSR(p_DTSR);
}

void CO2Sensor::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

void CO2Sensor::__setItsHVAC(HVAC* const p_HVAC) {
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

void CO2Sensor::_setItsHVAC(HVAC* const p_HVAC) {
    if(itsHVAC != NULL)
        {
            itsHVAC->__setItsCO2Sensor(NULL);
        }
    __setItsHVAC(p_HVAC);
}

void CO2Sensor::_clearItsHVAC(void) {
    NOTIFY_RELATION_CLEARED("itsHVAC");
    itsHVAC = NULL;
}

void CO2Sensor::__setItsOccupancySensor(OccupancySensor* const p_OccupancySensor) {
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

void CO2Sensor::_setItsOccupancySensor(OccupancySensor* const p_OccupancySensor) {
    if(itsOccupancySensor != NULL)
        {
            itsOccupancySensor->__setItsCO2Sensor(NULL);
        }
    __setItsOccupancySensor(p_OccupancySensor);
}

void CO2Sensor::_clearItsOccupancySensor(void) {
    NOTIFY_RELATION_CLEARED("itsOccupancySensor");
    itsOccupancySensor = NULL;
}

void CO2Sensor::__setItsVentilation(Ventilation* const p_Ventilation) {
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

void CO2Sensor::_setItsVentilation(Ventilation* const p_Ventilation) {
    if(itsVentilation != NULL)
        {
            itsVentilation->__setItsCO2Sensor(NULL);
        }
    __setItsVentilation(p_Ventilation);
}

void CO2Sensor::_clearItsVentilation(void) {
    NOTIFY_RELATION_CLEARED("itsVentilation");
    itsVentilation = NULL;
}

void CO2Sensor::state_5_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_5");
    rootState_subState = state_5;
    rootState_active = state_5;
    state_6_entDef();
    state_7_entDef();
}

void CO2Sensor::state_5_exit(void) {
    state_6_exit();
    state_7_exit();
    
    NOTIFY_STATE_EXITED("ROOT.state_5");
}

IOxfReactive::TakeEventStatus CO2Sensor::state_5_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    IOxfReactive::TakeEventStatus omComponentStatus = eventNotConsumed;
    bool dispatchDone = false;
    {
        // State state_6
        omComponentStatus = state_6_processEvent();
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
            // State state_7
            omComponentStatus = state_7_processEvent();
            if(omComponentStatus != eventNotConsumed)
                {
                    res = eventConsumed;
                }
        }
    
    return res;
}

void CO2Sensor::state_7_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_7");
    NOTIFY_TRANSITION_STARTED("ROOT.state_5.9");
    NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_7.SendAndRecieve");
    state_7_subState = SendAndRecieve;
    state_7_active = SendAndRecieve;
    //#[ state state_5.state_5.state_7.SendAndRecieve.(Entry) 
    callMain();
    
    //#]
    state_7_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.state_7.SendAndRecieve");
    NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.9");
}

void CO2Sensor::state_7_exit(void) {
    // State SendAndRecieve
    if(state_7_subState == SendAndRecieve)
        {
            cancel(state_7_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_7.SendAndRecieve");
        }
    state_7_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_7");
}

IOxfReactive::TakeEventStatus CO2Sensor::state_7_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State SendAndRecieve
    if(state_7_active == SendAndRecieve)
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_7_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.10");
                            cancel(state_7_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_7.SendAndRecieve");
                            NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_7.SendAndRecieve");
                            state_7_subState = SendAndRecieve;
                            state_7_active = SendAndRecieve;
                            //#[ state state_5.state_5.state_7.SendAndRecieve.(Entry) 
                            callMain();
                            
                            //#]
                            state_7_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.state_7.SendAndRecieve");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.10");
                            res = eventConsumed;
                        }
                }
            
            
        }
    return res;
}

void CO2Sensor::state_6_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_6");
    NOTIFY_TRANSITION_STARTED("ROOT.state_5.0");
    //#[ transition state_5.0 
    initilializeCo2sensor();
    //#]
    NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_6.Normal");
    state_6_subState = Normal;
    state_6_active = Normal;
    state_6_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.state_6.Normal");
    NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.0");
}

void CO2Sensor::state_6_exit(void) {
    switch (state_6_subState) {
        // State Normal
        case Normal:
        {
            cancel(state_6_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_6.Normal");
        }
        break;
        // State Modifying
        case Modifying:
        {
            cancel(state_6_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_6.Modifying");
        }
        break;
        case accepttimeevent_3:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_6.accepttimeevent_3");
        }
        break;
        case accepttimeevent_4:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_6.accepttimeevent_4");
        }
        break;
        default:
            break;
    }
    state_6_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_6");
}

IOxfReactive::TakeEventStatus CO2Sensor::state_6_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_6_active) {
        // State Normal
        case Normal:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_6_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.1");
                            cancel(state_6_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_6.Normal");
                            NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_6.accepttimeevent_3");
                            pushNullTransition();
                            state_6_subState = accepttimeevent_3;
                            state_6_active = accepttimeevent_3;
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
                    if(getCurrentEvent() == state_6_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.2");
                            cancel(state_6_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_6.Modifying");
                            NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_6.accepttimeevent_4");
                            pushNullTransition();
                            state_6_subState = accepttimeevent_4;
                            state_6_active = accepttimeevent_4;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.2");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        case accepttimeevent_3:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    //## transition state_5.4 
                    if(modifying_bool==false)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.3");
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.4");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_6.accepttimeevent_3");
                            //#[ transition state_5.4 
                            changeFromHVAC();
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_6.Normal");
                            state_6_subState = Normal;
                            state_6_active = Normal;
                            state_6_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.state_6.Normal");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.4");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.3");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition state_5.5 
                            if(modifying_bool==true)
                                {
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_5.3");
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_5.5");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_6.accepttimeevent_3");
                                    NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_6.Modifying");
                                    state_6_subState = Modifying;
                                    state_6_active = Modifying;
                                    state_6_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.state_6.Modifying");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.5");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.3");
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
                    if(modifying_bool==false)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.6");
                            NOTIFY_TRANSITION_STARTED("ROOT.state_5.7");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_6.accepttimeevent_4");
                            NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_6.Normal");
                            state_6_subState = Normal;
                            state_6_active = Normal;
                            state_6_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.state_6.Normal");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.7");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_5.6");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition state_5.8 
                            if(modifying_bool==true)
                                {
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_5.6");
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_5.8");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_5.ROOT.state_5.state_6.accepttimeevent_4");
                                    NOTIFY_STATE_ENTERED("ROOT.state_5.ROOT.state_5.state_6.Modifying");
                                    state_6_subState = Modifying;
                                    state_6_active = Modifying;
                                    state_6_timeout = scheduleTimeout(1000, "ROOT.state_5.ROOT.state_5.state_6.Modifying");
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

void CO2Sensor::rootState_entDef(void) {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        state_5_entDef();
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus CO2Sensor::rootState_processEvent(void) {
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
void OMAnimatedCO2Sensor::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("co2density", x2String(myReal->co2density));
    aomsAttributes->addAttribute("modifying_bool", x2String(myReal->modifying_bool));
    aomsAttributes->addAttribute("co2highgoal", x2String(myReal->co2highgoal));
    aomsAttributes->addAttribute("co2lowgoal", x2String(myReal->co2lowgoal));
    aomsAttributes->addAttribute("address_co2density", UNKNOWN2STRING(myReal->address_co2density));
    aomsAttributes->addAttribute("iResultCo2density", x2String(myReal->iResultCo2density));
    aomsAttributes->addAttribute("iSendResultCo2density", x2String(myReal->iSendResultCo2density));
    aomsAttributes->addAttribute("listenSocketForCo2density", UNKNOWN2STRING(myReal->listenSocketForCo2density));
    aomsAttributes->addAttribute("portCo2density", x2String(myReal->portCo2density));
    aomsAttributes->addAttribute("recvbuf", array2String(DEFAULT_BUFLEN, myReal->recvbuf, sizeof(char), &x2String));
    aomsAttributes->addAttribute("recvbuflen", x2String(myReal->recvbuflen));
    aomsAttributes->addAttribute("serverName", x2String(myReal->serverName));
    aomsAttributes->addAttribute("ws", UNKNOWN2STRING(myReal->ws));
    aomsAttributes->addAttribute("speed", x2String(myReal->speed));
}

void OMAnimatedCO2Sensor::serializeRelations(AOMSRelations* aomsRelations) const {
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
    aomsRelations->addRelation("itsOccupancySensor", false, true);
    if(myReal->itsOccupancySensor)
        {
            aomsRelations->ADD_ITEM(myReal->itsOccupancySensor);
        }
}

void OMAnimatedCO2Sensor::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    if(myReal->rootState_subState == CO2Sensor::state_5)
        {
            state_5_serializeStates(aomsState);
        }
}

void OMAnimatedCO2Sensor::state_5_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5");
    state_6_serializeStates(aomsState);
    state_7_serializeStates(aomsState);
}

void OMAnimatedCO2Sensor::state_7_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.state_7");
    if(myReal->state_7_subState == CO2Sensor::SendAndRecieve)
        {
            SendAndRecieve_serializeStates(aomsState);
        }
}

void OMAnimatedCO2Sensor::SendAndRecieve_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.state_7.SendAndRecieve");
}

void OMAnimatedCO2Sensor::state_6_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.state_6");
    switch (myReal->state_6_subState) {
        case CO2Sensor::Normal:
        {
            Normal_serializeStates(aomsState);
        }
        break;
        case CO2Sensor::Modifying:
        {
            Modifying_serializeStates(aomsState);
        }
        break;
        case CO2Sensor::accepttimeevent_3:
        {
            accepttimeevent_3_serializeStates(aomsState);
        }
        break;
        case CO2Sensor::accepttimeevent_4:
        {
            accepttimeevent_4_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedCO2Sensor::Normal_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.state_6.Normal");
}

void OMAnimatedCO2Sensor::Modifying_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.state_6.Modifying");
}

void OMAnimatedCO2Sensor::accepttimeevent_4_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.state_6.accepttimeevent_4");
}

void OMAnimatedCO2Sensor::accepttimeevent_3_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_5.ROOT.state_5.state_6.accepttimeevent_3");
}
//#]

IMPLEMENT_REACTIVE_META_P(CO2Sensor, Default, Default, false, OMAnimatedCO2Sensor)

IMPLEMENT_META_OP(OMAnimatedCO2Sensor, Default_CO2Sensor_setCo2density_float, "setCo2density", FALSE, "setCo2density(float)", 1)

IMPLEMENT_OP_CALL(Default_CO2Sensor_setCo2density_float, CO2Sensor, setCo2density(p_co2density), NO_OP())
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: component_3\DefaultConfig\CO2Sensor.cpp
*********************************************************************/
