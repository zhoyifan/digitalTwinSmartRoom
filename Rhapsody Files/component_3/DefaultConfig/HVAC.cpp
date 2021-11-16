/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: HVAC
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\HVAC.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "HVAC.h"
//## link itsAirConditioner
#include "AirConditioner.h"
//## link itsCO2Sensor
#include "CO2Sensor.h"
//## link itsDTSR
#include "DTSR.h"
//## link itsFireAlarm
#include "FireAlarm.h"
//## link itsFireSensor
#include "FireSensor.h"
//## link itsTemperatureSensor
#include "TemperatureSensor.h"
//## link itsVentilation
#include "Ventilation.h"
//#[ ignore
#define Default_HVAC_HVAC_SERIALIZE OM_NO_OP

#define Default_HVAC_callMain_SERIALIZE OM_NO_OP

#define Default_HVAC_getHvac_SERIALIZE OM_NO_OP

#define Default_HVAC_getMode_SERIALIZE OM_NO_OP

#define Default_HVAC_setHvac_SERIALIZE aomsmethod->addAttribute("newValue", x2String(newValue));

#define OMAnim_Default_HVAC_setMode_int_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_mode)

#define OMAnim_Default_HVAC_setMode_int_SERIALIZE_RET_VAL
//#]

//## package Default

//## class HVAC
HVAC::HVAC(IOxfActive* const theActiveContext) : OMReactive(), hvac(0), listenSocketForHvac(INVALID_SOCKET), mode(0), portHvac(10006), recvbuflen(DEFAULT_BUFLEN), serverName("127.0.0.1"), itsAirConditioner(NULL), itsCO2Sensor(NULL), itsDTSR(NULL), itsFireAlarm(NULL), itsFireSensor(NULL), itsTemperatureSensor(NULL), itsVentilation(NULL), itsVentilation_1(NULL) {
    NOTIFY_REACTIVE_CONSTRUCTOR(HVAC, HVAC(), 0, Default_HVAC_HVAC_SERIALIZE);
    setActiveContext(theActiveContext, false);
    initStatechart();
}

HVAC::~HVAC(void) {
    NOTIFY_DESTRUCTOR(~HVAC, true);
    cleanUpRelations();
    cancelTimeouts();
}

int HVAC::callMain(void) {
    NOTIFY_OPERATION(callMain, callMain(), 0, Default_HVAC_callMain_SERIALIZE);
    //#[ operation callMain()
    #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
    #define _WINSOCK_DEPRECATED_NO_WARNINGS
    #endif
    
    #include <stdlib.h>
    
    WSAStartup(0x0101,&ws);
    
    char out_string_for_hvac [1024];
    
    //HVAC
    ZeroMemory(&address_hvac, sizeof(address_hvac));
    address_hvac.sin_family = AF_INET;
    address_hvac.sin_port = htons(portHvac);
    address_hvac.sin_addr.s_addr=inet_addr(serverName);
    
    //INITIALIZE ALL SOCKETS
    listenSocketForHvac = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    //CONNECT ALL THE SOCKETS
    iResultHvac = connect(listenSocketForHvac,(SOCKADDR*)&address_hvac, sizeof(address_hvac)); 
    
    
    
    //ASSIGN VALUES TO SEND 
    sprintf(out_string_for_hvac, "%f", hvac);
    
    
    
    //SEND VALUE
    iSendResultHvac = sendto(listenSocketForHvac, (char *)&out_string_for_hvac ,sizeof(uint32_t), 0 ,(SOCKADDR *) & address_hvac, sizeof (address_hvac) );
    //SHOW SENT VALUES IN CONSOLE
    //printf("Hvac value sent: %s \n",out_string_for_hvac);
    
    //RECIEVED VALUE OF HVAC
    iResultHvac = recv(listenSocketForHvac, recvbuf, recvbuflen, 0); 
    float hvactocheck = atof(recvbuf);
    printf("HVAC value recieved: %f\n",atof(recvbuf));
    //CLOSE ALL THE SOCKETS
    closesocket(listenSocketForHvac);
    return 0;
    
    //#]
}

float HVAC::getHvac(void) {
    NOTIFY_OPERATION(getHvac, getHvac(), 0, Default_HVAC_getHvac_SERIALIZE);
    //#[ operation getHvac()
    return hvac;
    //#]
}

int HVAC::getMode(void) {
    NOTIFY_OPERATION(getMode, getMode(), 0, Default_HVAC_getMode_SERIALIZE);
    //#[ operation getMode()
    return mode;
    //#]
}

void HVAC::setHvac(float newValue) {
    NOTIFY_OPERATION(setHvac, setHvac(float), 1, Default_HVAC_setHvac_SERIALIZE);
    //#[ operation setHvac(float)
    hvac=newValue;
    //#]
    NOTIFY_SET_OPERATION;
}

const SOCKADDR_IN HVAC::getAddress_hvac(void) const {
    return address_hvac;
}

void HVAC::setAddress_hvac(const SOCKADDR_IN p_address_hvac) {
    address_hvac = p_address_hvac;
}

const int HVAC::getIResultHvac(void) const {
    return iResultHvac;
}

void HVAC::setIResultHvac(const int p_iResultHvac) {
    iResultHvac = p_iResultHvac;
}

const int HVAC::getISendResultHvac(void) const {
    return iSendResultHvac;
}

void HVAC::setISendResultHvac(const int p_iSendResultHvac) {
    iSendResultHvac = p_iSendResultHvac;
}

const SOCKET HVAC::getListenSocketForHvac(void) const {
    return listenSocketForHvac;
}

void HVAC::setListenSocketForHvac(const SOCKET p_listenSocketForHvac) {
    listenSocketForHvac = p_listenSocketForHvac;
}

void HVAC::setMode(const int p_mode) {
    mode = p_mode;
    NOTIFY_SET_OPERATION;
}

const int HVAC::getPortHvac(void) const {
    return portHvac;
}

void HVAC::setPortHvac(const int p_portHvac) {
    portHvac = p_portHvac;
}

const char HVAC::getRecvbuf(const Rhp_int32_t iterI1) const {
    return recvbuf[iterI1];
}

void HVAC::setRecvbuf(const Rhp_int32_t iterI1, const char p_recvbuf) {
    recvbuf[iterI1] = p_recvbuf;
}

const int HVAC::getRecvbuflen(void) const {
    return recvbuflen;
}

void HVAC::setRecvbuflen(const int p_recvbuflen) {
    recvbuflen = p_recvbuflen;
}

const char* HVAC::getServerName(void) const {
    return serverName;
}

void HVAC::setServerName(char* const p_serverName) {
    serverName = p_serverName;
}

const WSADATA HVAC::getWs(void) const {
    return ws;
}

void HVAC::setWs(const WSADATA p_ws) {
    ws = p_ws;
}

const AirConditioner* HVAC::getItsAirConditioner(void) const {
    return itsAirConditioner;
}

void HVAC::setItsAirConditioner(AirConditioner* const p_AirConditioner) {
    if(p_AirConditioner != NULL)
        {
            p_AirConditioner->_setItsHVAC(this);
        }
    _setItsAirConditioner(p_AirConditioner);
}

const CO2Sensor* HVAC::getItsCO2Sensor(void) const {
    return itsCO2Sensor;
}

void HVAC::setItsCO2Sensor(CO2Sensor* const p_CO2Sensor) {
    if(p_CO2Sensor != NULL)
        {
            p_CO2Sensor->_setItsHVAC(this);
        }
    _setItsCO2Sensor(p_CO2Sensor);
}

const DTSR* HVAC::getItsDTSR(void) const {
    return itsDTSR;
}

void HVAC::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_setItsHVAC(this);
        }
    _setItsDTSR(p_DTSR);
}

const FireAlarm* HVAC::getItsFireAlarm(void) const {
    return itsFireAlarm;
}

void HVAC::setItsFireAlarm(FireAlarm* const p_FireAlarm) {
    if(p_FireAlarm != NULL)
        {
            p_FireAlarm->_setItsHVAC(this);
        }
    _setItsFireAlarm(p_FireAlarm);
}

const FireSensor* HVAC::getItsFireSensor(void) const {
    return itsFireSensor;
}

void HVAC::setItsFireSensor(FireSensor* const p_FireSensor) {
    if(p_FireSensor != NULL)
        {
            p_FireSensor->_setItsHVAC(this);
        }
    _setItsFireSensor(p_FireSensor);
}

const TemperatureSensor* HVAC::getItsTemperatureSensor(void) const {
    return itsTemperatureSensor;
}

void HVAC::setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor) {
    if(p_TemperatureSensor != NULL)
        {
            p_TemperatureSensor->_setItsHVAC(this);
        }
    _setItsTemperatureSensor(p_TemperatureSensor);
}

const Ventilation* HVAC::getItsVentilation(void) const {
    return itsVentilation;
}

void HVAC::setItsVentilation(Ventilation* const p_Ventilation) {
    if(p_Ventilation != NULL)
        {
            p_Ventilation->_setItsHVAC(this);
        }
    _setItsVentilation(p_Ventilation);
}

const Ventilation* HVAC::getItsVentilation_1(void) const {
    return itsVentilation_1;
}

void HVAC::setItsVentilation_1(Ventilation* const p_Ventilation) {
    if(p_Ventilation != NULL)
        {
            p_Ventilation->_setItsHVAC_1(this);
        }
    _setItsVentilation_1(p_Ventilation);
}

bool HVAC::cancelTimeout(const IOxfTimeout* arg) {
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

bool HVAC::startBehavior(void) {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void HVAC::initStatechart(void) {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    state_2_subState = OMNonState;
    state_2_active = OMNonState;
    state_2_timeout = NULL;
    state_1_subState = OMNonState;
    state_1_active = OMNonState;
    state_1_timeout = NULL;
}

void HVAC::cleanUpRelations(void) {
    if(itsAirConditioner != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsAirConditioner");
            const HVAC* p_HVAC = itsAirConditioner->getItsHVAC();
            if(p_HVAC != NULL)
                {
                    itsAirConditioner->__setItsHVAC(NULL);
                }
            itsAirConditioner = NULL;
        }
    if(itsCO2Sensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsCO2Sensor");
            const HVAC* p_HVAC = itsCO2Sensor->getItsHVAC();
            if(p_HVAC != NULL)
                {
                    itsCO2Sensor->__setItsHVAC(NULL);
                }
            itsCO2Sensor = NULL;
        }
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            const HVAC* p_HVAC = itsDTSR->getItsHVAC();
            if(p_HVAC != NULL)
                {
                    itsDTSR->__setItsHVAC(NULL);
                }
            itsDTSR = NULL;
        }
    if(itsFireAlarm != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsFireAlarm");
            const HVAC* p_HVAC = itsFireAlarm->getItsHVAC();
            if(p_HVAC != NULL)
                {
                    itsFireAlarm->__setItsHVAC(NULL);
                }
            itsFireAlarm = NULL;
        }
    if(itsFireSensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsFireSensor");
            const HVAC* p_HVAC = itsFireSensor->getItsHVAC();
            if(p_HVAC != NULL)
                {
                    itsFireSensor->__setItsHVAC(NULL);
                }
            itsFireSensor = NULL;
        }
    if(itsTemperatureSensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsTemperatureSensor");
            const HVAC* p_HVAC = itsTemperatureSensor->getItsHVAC();
            if(p_HVAC != NULL)
                {
                    itsTemperatureSensor->__setItsHVAC(NULL);
                }
            itsTemperatureSensor = NULL;
        }
    if(itsVentilation != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsVentilation");
            const HVAC* p_HVAC = itsVentilation->getItsHVAC();
            if(p_HVAC != NULL)
                {
                    itsVentilation->__setItsHVAC(NULL);
                }
            itsVentilation = NULL;
        }
    if(itsVentilation_1 != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsVentilation_1");
            const HVAC* p_HVAC = itsVentilation_1->getItsHVAC_1();
            if(p_HVAC != NULL)
                {
                    itsVentilation_1->__setItsHVAC_1(NULL);
                }
            itsVentilation_1 = NULL;
        }
}

void HVAC::cancelTimeouts(void) {
    cancel(state_2_timeout);
    cancel(state_1_timeout);
}

void HVAC::__setItsAirConditioner(AirConditioner* const p_AirConditioner) {
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

void HVAC::_setItsAirConditioner(AirConditioner* const p_AirConditioner) {
    if(itsAirConditioner != NULL)
        {
            itsAirConditioner->__setItsHVAC(NULL);
        }
    __setItsAirConditioner(p_AirConditioner);
}

void HVAC::_clearItsAirConditioner(void) {
    NOTIFY_RELATION_CLEARED("itsAirConditioner");
    itsAirConditioner = NULL;
}

void HVAC::__setItsCO2Sensor(CO2Sensor* const p_CO2Sensor) {
    itsCO2Sensor = p_CO2Sensor;
    if(p_CO2Sensor != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsCO2Sensor", p_CO2Sensor, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsCO2Sensor");
        }
}

void HVAC::_setItsCO2Sensor(CO2Sensor* const p_CO2Sensor) {
    if(itsCO2Sensor != NULL)
        {
            itsCO2Sensor->__setItsHVAC(NULL);
        }
    __setItsCO2Sensor(p_CO2Sensor);
}

void HVAC::_clearItsCO2Sensor(void) {
    NOTIFY_RELATION_CLEARED("itsCO2Sensor");
    itsCO2Sensor = NULL;
}

void HVAC::__setItsDTSR(DTSR* const p_DTSR) {
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

void HVAC::_setItsDTSR(DTSR* const p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->__setItsHVAC(NULL);
        }
    __setItsDTSR(p_DTSR);
}

void HVAC::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

void HVAC::__setItsFireAlarm(FireAlarm* const p_FireAlarm) {
    itsFireAlarm = p_FireAlarm;
    if(p_FireAlarm != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsFireAlarm", p_FireAlarm, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsFireAlarm");
        }
}

void HVAC::_setItsFireAlarm(FireAlarm* const p_FireAlarm) {
    if(itsFireAlarm != NULL)
        {
            itsFireAlarm->__setItsHVAC(NULL);
        }
    __setItsFireAlarm(p_FireAlarm);
}

void HVAC::_clearItsFireAlarm(void) {
    NOTIFY_RELATION_CLEARED("itsFireAlarm");
    itsFireAlarm = NULL;
}

void HVAC::__setItsFireSensor(FireSensor* const p_FireSensor) {
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

void HVAC::_setItsFireSensor(FireSensor* const p_FireSensor) {
    if(itsFireSensor != NULL)
        {
            itsFireSensor->__setItsHVAC(NULL);
        }
    __setItsFireSensor(p_FireSensor);
}

void HVAC::_clearItsFireSensor(void) {
    NOTIFY_RELATION_CLEARED("itsFireSensor");
    itsFireSensor = NULL;
}

void HVAC::__setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor) {
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

void HVAC::_setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor) {
    if(itsTemperatureSensor != NULL)
        {
            itsTemperatureSensor->__setItsHVAC(NULL);
        }
    __setItsTemperatureSensor(p_TemperatureSensor);
}

void HVAC::_clearItsTemperatureSensor(void) {
    NOTIFY_RELATION_CLEARED("itsTemperatureSensor");
    itsTemperatureSensor = NULL;
}

void HVAC::__setItsVentilation(Ventilation* const p_Ventilation) {
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

void HVAC::_setItsVentilation(Ventilation* const p_Ventilation) {
    if(itsVentilation != NULL)
        {
            itsVentilation->__setItsHVAC(NULL);
        }
    __setItsVentilation(p_Ventilation);
}

void HVAC::_clearItsVentilation(void) {
    NOTIFY_RELATION_CLEARED("itsVentilation");
    itsVentilation = NULL;
}

void HVAC::__setItsVentilation_1(Ventilation* const p_Ventilation) {
    itsVentilation_1 = p_Ventilation;
    if(p_Ventilation != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsVentilation_1", p_Ventilation, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsVentilation_1");
        }
}

void HVAC::_setItsVentilation_1(Ventilation* const p_Ventilation) {
    if(itsVentilation_1 != NULL)
        {
            itsVentilation_1->__setItsHVAC_1(NULL);
        }
    __setItsVentilation_1(p_Ventilation);
}

void HVAC::_clearItsVentilation_1(void) {
    NOTIFY_RELATION_CLEARED("itsVentilation_1");
    itsVentilation_1 = NULL;
}

void HVAC::state_0_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_0");
    rootState_subState = state_0;
    rootState_active = state_0;
    state_1_entDef();
    state_2_entDef();
}

void HVAC::state_0_exit(void) {
    state_1_exit();
    state_2_exit();
    
    NOTIFY_STATE_EXITED("ROOT.state_0");
}

IOxfReactive::TakeEventStatus HVAC::state_0_processEvent(void) {
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

void HVAC::state_2_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_2");
    NOTIFY_TRANSITION_STARTED("ROOT.state_0.5");
    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_2.SendAndRecieve");
    state_2_subState = SendAndRecieve;
    state_2_active = SendAndRecieve;
    //#[ state state_0.state_0.state_2.SendAndRecieve.(Entry) 
    callMain();
     
    //#]
    state_2_timeout = scheduleTimeout(1000, "ROOT.state_0.ROOT.state_0.state_2.SendAndRecieve");
    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.5");
}

void HVAC::state_2_exit(void) {
    // State SendAndRecieve
    if(state_2_subState == SendAndRecieve)
        {
            cancel(state_2_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_2.SendAndRecieve");
        }
    state_2_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_2");
}

IOxfReactive::TakeEventStatus HVAC::state_2_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State SendAndRecieve
    if(state_2_active == SendAndRecieve)
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_2_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_0.6");
                            cancel(state_2_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_2.SendAndRecieve");
                            NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_2.SendAndRecieve");
                            state_2_subState = SendAndRecieve;
                            state_2_active = SendAndRecieve;
                            //#[ state state_0.state_0.state_2.SendAndRecieve.(Entry) 
                            callMain();
                             
                            //#]
                            state_2_timeout = scheduleTimeout(1000, "ROOT.state_0.ROOT.state_0.state_2.SendAndRecieve");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.6");
                            res = eventConsumed;
                        }
                }
            
            
        }
    return res;
}

void HVAC::state_1_entDef(void) {
    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1");
    NOTIFY_TRANSITION_STARTED("ROOT.state_0.4");
    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.Off");
    state_1_subState = Off;
    state_1_active = Off;
    state_1_timeout = scheduleTimeout(1000, "ROOT.state_0.ROOT.state_0.state_1.Off");
    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.4");
}

void HVAC::state_1_exit(void) {
    switch (state_1_subState) {
        // State Off
        case Off:
        {
            cancel(state_1_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.Off");
        }
        break;
        case accepttimeevent_18:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_18");
        }
        break;
        case accepttimeevent_19:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_19");
        }
        break;
        case accepttimeevent_20:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_20");
        }
        break;
        case accepttimeevent_21:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_21");
        }
        break;
        // State Ventilation_
        case Ventilation_:
        {
            cancel(state_1_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.Ventilation_");
        }
        break;
        // State AirConditioner_
        case AirConditioner_:
        {
            cancel(state_1_timeout);
            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.AirConditioner_");
        }
        break;
        default:
            break;
    }
    state_1_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1");
}

IOxfReactive::TakeEventStatus HVAC::state_1_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (state_1_active) {
        // State Off
        case Off:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_1_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_0.3");
                            cancel(state_1_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.Off");
                            NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_18");
                            pushNullTransition();
                            state_1_subState = accepttimeevent_18;
                            state_1_active = accepttimeevent_18;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.3");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        case accepttimeevent_18:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.state_0.7");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_18");
                    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_21");
                    pushNullTransition();
                    state_1_subState = accepttimeevent_21;
                    state_1_active = accepttimeevent_21;
                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.7");
                    res = eventConsumed;
                }
            
            
        }
        break;
        case accepttimeevent_19:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.state_0.10");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_19");
                    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_21");
                    pushNullTransition();
                    state_1_subState = accepttimeevent_21;
                    state_1_active = accepttimeevent_21;
                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.10");
                    res = eventConsumed;
                }
            
            
        }
        break;
        case accepttimeevent_20:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.state_0.11");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_20");
                    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_21");
                    pushNullTransition();
                    state_1_subState = accepttimeevent_21;
                    state_1_active = accepttimeevent_21;
                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.11");
                    res = eventConsumed;
                }
            
            
        }
        break;
        case accepttimeevent_21:
        {
            res = accepttimeevent_21_handleEvent();
        }
        break;
        // State Ventilation_
        case Ventilation_:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_1_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_0.2");
                            cancel(state_1_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.Ventilation_");
                            NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_20");
                            pushNullTransition();
                            state_1_subState = accepttimeevent_20;
                            state_1_active = accepttimeevent_20;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.2");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        // State AirConditioner_
        case AirConditioner_:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == state_1_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_0.1");
                            cancel(state_1_timeout);
                            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.AirConditioner_");
                            NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_19");
                            pushNullTransition();
                            state_1_subState = accepttimeevent_19;
                            state_1_active = accepttimeevent_19;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.1");
                            res = eventConsumed;
                        }
                }
            
            
        }
        break;
        default:
            break;
    }
    return res;
}

IOxfReactive::TakeEventStatus HVAC::accepttimeevent_21_handleEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
        {
            //## transition state_0.0 
            if(mode==0)
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.state_0.13");
                    NOTIFY_TRANSITION_STARTED("ROOT.state_0.0");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_21");
                    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.Off");
                    state_1_subState = Off;
                    state_1_active = Off;
                    state_1_timeout = scheduleTimeout(1000, "ROOT.state_0.ROOT.state_0.state_1.Off");
                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.0");
                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.13");
                    res = eventConsumed;
                }
            else
                {
                    //## transition state_0.8 
                    if(mode==1)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.state_0.13");
                            NOTIFY_TRANSITION_STARTED("ROOT.state_0.8");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_21");
                            NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.AirConditioner_");
                            state_1_subState = AirConditioner_;
                            state_1_active = AirConditioner_;
                            state_1_timeout = scheduleTimeout(1000, "ROOT.state_0.ROOT.state_0.state_1.AirConditioner_");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.8");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.13");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition state_0.9 
                            if(mode==2)
                                {
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_0.13");
                                    NOTIFY_TRANSITION_STARTED("ROOT.state_0.9");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_21");
                                    NOTIFY_STATE_ENTERED("ROOT.state_0.ROOT.state_0.state_1.Ventilation_");
                                    state_1_subState = Ventilation_;
                                    state_1_active = Ventilation_;
                                    state_1_timeout = scheduleTimeout(1000, "ROOT.state_0.ROOT.state_0.state_1.Ventilation_");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.9");
                                    NOTIFY_TRANSITION_TERMINATED("ROOT.state_0.13");
                                    res = eventConsumed;
                                }
                        }
                }
        }
    
    
    return res;
}

void HVAC::rootState_entDef(void) {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        state_0_entDef();
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus HVAC::rootState_processEvent(void) {
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
void OMAnimatedHVAC::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("address_hvac", UNKNOWN2STRING(myReal->address_hvac));
    aomsAttributes->addAttribute("iResultHvac", x2String(myReal->iResultHvac));
    aomsAttributes->addAttribute("iSendResultHvac", x2String(myReal->iSendResultHvac));
    aomsAttributes->addAttribute("listenSocketForHvac", UNKNOWN2STRING(myReal->listenSocketForHvac));
    aomsAttributes->addAttribute("portHvac", x2String(myReal->portHvac));
    aomsAttributes->addAttribute("recvbuf", array2String(DEFAULT_BUFLEN, myReal->recvbuf, sizeof(char), &x2String));
    aomsAttributes->addAttribute("recvbuflen", x2String(myReal->recvbuflen));
    aomsAttributes->addAttribute("serverName", x2String(myReal->serverName));
    aomsAttributes->addAttribute("hvac", x2String(myReal->hvac));
    aomsAttributes->addAttribute("ws", UNKNOWN2STRING(myReal->ws));
    aomsAttributes->addAttribute("mode", x2String(myReal->mode));
}

void OMAnimatedHVAC::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsTemperatureSensor", false, true);
    if(myReal->itsTemperatureSensor)
        {
            aomsRelations->ADD_ITEM(myReal->itsTemperatureSensor);
        }
    aomsRelations->addRelation("itsCO2Sensor", false, true);
    if(myReal->itsCO2Sensor)
        {
            aomsRelations->ADD_ITEM(myReal->itsCO2Sensor);
        }
    aomsRelations->addRelation("itsFireSensor", false, true);
    if(myReal->itsFireSensor)
        {
            aomsRelations->ADD_ITEM(myReal->itsFireSensor);
        }
    aomsRelations->addRelation("itsFireAlarm", false, true);
    if(myReal->itsFireAlarm)
        {
            aomsRelations->ADD_ITEM(myReal->itsFireAlarm);
        }
    aomsRelations->addRelation("itsAirConditioner", false, true);
    if(myReal->itsAirConditioner)
        {
            aomsRelations->ADD_ITEM(myReal->itsAirConditioner);
        }
    aomsRelations->addRelation("itsVentilation", false, true);
    if(myReal->itsVentilation)
        {
            aomsRelations->ADD_ITEM(myReal->itsVentilation);
        }
    aomsRelations->addRelation("itsVentilation_1", false, true);
    if(myReal->itsVentilation_1)
        {
            aomsRelations->ADD_ITEM(myReal->itsVentilation_1);
        }
    aomsRelations->addRelation("itsDTSR", false, true);
    if(myReal->itsDTSR)
        {
            aomsRelations->ADD_ITEM(myReal->itsDTSR);
        }
}

void OMAnimatedHVAC::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    if(myReal->rootState_subState == HVAC::state_0)
        {
            state_0_serializeStates(aomsState);
        }
}

void OMAnimatedHVAC::state_0_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0");
    state_1_serializeStates(aomsState);
    state_2_serializeStates(aomsState);
}

void OMAnimatedHVAC::state_2_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_2");
    if(myReal->state_2_subState == HVAC::SendAndRecieve)
        {
            SendAndRecieve_serializeStates(aomsState);
        }
}

void OMAnimatedHVAC::SendAndRecieve_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_2.SendAndRecieve");
}

void OMAnimatedHVAC::state_1_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_1");
    switch (myReal->state_1_subState) {
        case HVAC::Off:
        {
            Off_serializeStates(aomsState);
        }
        break;
        case HVAC::accepttimeevent_18:
        {
            accepttimeevent_18_serializeStates(aomsState);
        }
        break;
        case HVAC::accepttimeevent_19:
        {
            accepttimeevent_19_serializeStates(aomsState);
        }
        break;
        case HVAC::accepttimeevent_20:
        {
            accepttimeevent_20_serializeStates(aomsState);
        }
        break;
        case HVAC::accepttimeevent_21:
        {
            accepttimeevent_21_serializeStates(aomsState);
        }
        break;
        case HVAC::Ventilation_:
        {
            Ventilation__serializeStates(aomsState);
        }
        break;
        case HVAC::AirConditioner_:
        {
            AirConditioner__serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedHVAC::Ventilation__serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_1.Ventilation_");
}

void OMAnimatedHVAC::Off_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_1.Off");
}

void OMAnimatedHVAC::AirConditioner__serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_1.AirConditioner_");
}

void OMAnimatedHVAC::accepttimeevent_21_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_21");
}

void OMAnimatedHVAC::accepttimeevent_20_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_20");
}

void OMAnimatedHVAC::accepttimeevent_19_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_19");
}

void OMAnimatedHVAC::accepttimeevent_18_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.state_0.ROOT.state_0.state_1.accepttimeevent_18");
}
//#]

IMPLEMENT_REACTIVE_META_P(HVAC, Default, Default, false, OMAnimatedHVAC)

IMPLEMENT_META_OP(OMAnimatedHVAC, Default_HVAC_setMode_int, "setMode", FALSE, "setMode(int)", 1)

IMPLEMENT_OP_CALL(Default_HVAC_setMode_int, HVAC, setMode(p_mode), NO_OP())
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: component_3\DefaultConfig\HVAC.cpp
*********************************************************************/
