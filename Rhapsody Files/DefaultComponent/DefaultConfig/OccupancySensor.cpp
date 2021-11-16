/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: OccupancySensor
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\OccupancySensor.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "OccupancySensor.h"
//## link itsCO2Sensor
#include "CO2Sensor.h"
//## link itsDTSR
#include "DTSR.h"
//## link itsTemperatureSensor
#include "TemperatureSensor.h"
//#[ ignore
#define Default_OccupancySensor_OccupancySensor_SERIALIZE OM_NO_OP

#define Default_OccupancySensor_callMain_SERIALIZE OM_NO_OP

#define OMAnim_Default_OccupancySensor_callMain_UNSERIALIZE_ARGS

#define OMAnim_Default_OccupancySensor_callMain_SERIALIZE_RET_VAL OP_SET_RET_VAL(animRetVal)

#define OMAnim_Default_OccupancySensor_setModifying_bool_bool_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_modifying_bool)

#define OMAnim_Default_OccupancySensor_setModifying_bool_bool_SERIALIZE_RET_VAL

#define OMAnim_Default_OccupancySensor_setOccupancy_bool_int_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_occupancy_bool)

#define OMAnim_Default_OccupancySensor_setOccupancy_bool_int_SERIALIZE_RET_VAL
//#]

//## package Default

//## class OccupancySensor
OccupancySensor::OccupancySensor(IOxfActive* const theActiveContext) : OMReactive(), listenSocketForOccupancy(INVALID_SOCKET), modifying_bool(1), portOccupancy(10014), recvbuflen(DEFAULT_BUFLEN), serverName("127.0.0.1"), itsCO2Sensor(NULL), itsDTSR(NULL), itsTemperatureSensor(NULL) {
    NOTIFY_REACTIVE_CONSTRUCTOR(OccupancySensor, OccupancySensor(), 0, Default_OccupancySensor_OccupancySensor_SERIALIZE);
    setActiveContext(theActiveContext, false);
    initStatechart();
}

OccupancySensor::~OccupancySensor(void) {
    NOTIFY_DESTRUCTOR(~OccupancySensor, true);
    cleanUpRelations();
    cancelTimeouts();
}

int OccupancySensor::callMain(void) {
    NOTIFY_OPERATION(callMain, callMain(), 0, Default_OccupancySensor_callMain_SERIALIZE);
    //#[ operation callMain()
    #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
    #define _WINSOCK_DEPRECATED_NO_WARNINGS
    #endif
    
    #include <stdlib.h>
    
    WSAStartup(0x0101,&ws);
    
    char out_string_for_occupancy [1024];
    
    //OCCUPANCY
    ZeroMemory(&address_occupancy, sizeof(address_occupancy));
    address_occupancy.sin_family = AF_INET;
    address_occupancy.sin_port = htons(portOccupancy);
    address_occupancy.sin_addr.s_addr=inet_addr(serverName);
    
    //INITIALIZE ALL SOCKETS
    listenSocketForOccupancy = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    //CONNECT ALL THE SOCKETS
    iResultOccupancy = connect(listenSocketForOccupancy,(SOCKADDR*)&address_occupancy, sizeof(address_occupancy)); 
    
    
    
    //ASSIGN VALUES TO SEND 
    sprintf(out_string_for_occupancy, "%f", occupancy);
    
    
    
    //SEND VALUE
    iSendResultOccupancy = sendto(listenSocketForOccupancy, (char *)&out_string_for_occupancy ,sizeof(uint32_t), 0 ,(SOCKADDR *) & address_occupancy, sizeof (address_occupancy) );
    //SHOW SENT VALUES IN CONSOLE
    //printf("Occupancy value sent: %s \n",out_string_for_occupancy);
    
    //RECIEVED VALUE OF OCCUPANCY
    iResultOccupancy = recv(listenSocketForOccupancy, recvbuf, recvbuflen, 0); 
    occupancy = atof(recvbuf);
    printf("OCCUPANCY value recieved: %f\n",atof(recvbuf));
    //CLOSE ALL THE SOCKETS
    closesocket(listenSocketForOccupancy);
    return 0;
    
    //#]
}

const SOCKADDR_IN OccupancySensor::getAddress_occupancy(void) const {
    return address_occupancy;
}

void OccupancySensor::setAddress_occupancy(const SOCKADDR_IN p_address_occupancy) {
    address_occupancy = p_address_occupancy;
}

const int OccupancySensor::getIResultOccupancy(void) const {
    return iResultOccupancy;
}

void OccupancySensor::setIResultOccupancy(const int p_iResultOccupancy) {
    iResultOccupancy = p_iResultOccupancy;
}

const int OccupancySensor::getISendResultOccupancy(void) const {
    return iSendResultOccupancy;
}

void OccupancySensor::setISendResultOccupancy(const int p_iSendResultOccupancy) {
    iSendResultOccupancy = p_iSendResultOccupancy;
}

const SOCKET OccupancySensor::getListenSocketForOccupancy(void) const {
    return listenSocketForOccupancy;
}

void OccupancySensor::setListenSocketForOccupancy(const SOCKET p_listenSocketForOccupancy) {
    listenSocketForOccupancy = p_listenSocketForOccupancy;
}

const bool OccupancySensor::getModifying_bool(void) const {
    return modifying_bool;
}

void OccupancySensor::setModifying_bool(const bool p_modifying_bool) {
    modifying_bool = p_modifying_bool;
    NOTIFY_SET_OPERATION;
}

const float OccupancySensor::getOccupancy(void) const {
    return occupancy;
}

void OccupancySensor::setOccupancy(const float p_occupancy) {
    occupancy = p_occupancy;
}

const int OccupancySensor::getOccupancy_bool(void) const {
    return occupancy_bool;
}

void OccupancySensor::setOccupancy_bool(const int p_occupancy_bool) {
    occupancy_bool = p_occupancy_bool;
    NOTIFY_SET_OPERATION;
}

const int OccupancySensor::getPortOccupancy(void) const {
    return portOccupancy;
}

void OccupancySensor::setPortOccupancy(const int p_portOccupancy) {
    portOccupancy = p_portOccupancy;
}

const char OccupancySensor::getRecvbuf(const Rhp_int32_t iterI1) const {
    return recvbuf[iterI1];
}

void OccupancySensor::setRecvbuf(const Rhp_int32_t iterI1, const char p_recvbuf) {
    recvbuf[iterI1] = p_recvbuf;
}

const int OccupancySensor::getRecvbuflen(void) const {
    return recvbuflen;
}

void OccupancySensor::setRecvbuflen(const int p_recvbuflen) {
    recvbuflen = p_recvbuflen;
}

const char* OccupancySensor::getServerName(void) const {
    return serverName;
}

void OccupancySensor::setServerName(char* const p_serverName) {
    serverName = p_serverName;
}

const WSADATA OccupancySensor::getWs(void) const {
    return ws;
}

void OccupancySensor::setWs(const WSADATA p_ws) {
    ws = p_ws;
}

const CO2Sensor* OccupancySensor::getItsCO2Sensor(void) const {
    return itsCO2Sensor;
}

void OccupancySensor::setItsCO2Sensor(CO2Sensor* const p_CO2Sensor) {
    if(p_CO2Sensor != NULL)
        {
            p_CO2Sensor->_setItsOccupancySensor(this);
        }
    _setItsCO2Sensor(p_CO2Sensor);
}

const DTSR* OccupancySensor::getItsDTSR(void) const {
    return itsDTSR;
}

void OccupancySensor::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_setItsOccupancySensor(this);
        }
    _setItsDTSR(p_DTSR);
}

const TemperatureSensor* OccupancySensor::getItsTemperatureSensor(void) const {
    return itsTemperatureSensor;
}

void OccupancySensor::setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor) {
    if(p_TemperatureSensor != NULL)
        {
            p_TemperatureSensor->_setItsOccupancySensor(this);
        }
    _setItsTemperatureSensor(p_TemperatureSensor);
}

bool OccupancySensor::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(rootState_timeout == arg)
        {
            rootState_timeout = NULL;
            res = true;
        }
    return res;
}

bool OccupancySensor::startBehavior(void) {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void OccupancySensor::initStatechart(void) {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    rootState_timeout = NULL;
}

void OccupancySensor::cleanUpRelations(void) {
    if(itsCO2Sensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsCO2Sensor");
            const OccupancySensor* p_OccupancySensor = itsCO2Sensor->getItsOccupancySensor();
            if(p_OccupancySensor != NULL)
                {
                    itsCO2Sensor->__setItsOccupancySensor(NULL);
                }
            itsCO2Sensor = NULL;
        }
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            const OccupancySensor* p_OccupancySensor = itsDTSR->getItsOccupancySensor();
            if(p_OccupancySensor != NULL)
                {
                    itsDTSR->__setItsOccupancySensor(NULL);
                }
            itsDTSR = NULL;
        }
    if(itsTemperatureSensor != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsTemperatureSensor");
            const OccupancySensor* p_OccupancySensor = itsTemperatureSensor->getItsOccupancySensor();
            if(p_OccupancySensor != NULL)
                {
                    itsTemperatureSensor->__setItsOccupancySensor(NULL);
                }
            itsTemperatureSensor = NULL;
        }
}

void OccupancySensor::cancelTimeouts(void) {
    cancel(rootState_timeout);
}

void OccupancySensor::__setItsCO2Sensor(CO2Sensor* const p_CO2Sensor) {
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

void OccupancySensor::_setItsCO2Sensor(CO2Sensor* const p_CO2Sensor) {
    if(itsCO2Sensor != NULL)
        {
            itsCO2Sensor->__setItsOccupancySensor(NULL);
        }
    __setItsCO2Sensor(p_CO2Sensor);
}

void OccupancySensor::_clearItsCO2Sensor(void) {
    NOTIFY_RELATION_CLEARED("itsCO2Sensor");
    itsCO2Sensor = NULL;
}

void OccupancySensor::__setItsDTSR(DTSR* const p_DTSR) {
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

void OccupancySensor::_setItsDTSR(DTSR* const p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->__setItsOccupancySensor(NULL);
        }
    __setItsDTSR(p_DTSR);
}

void OccupancySensor::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

void OccupancySensor::__setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor) {
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

void OccupancySensor::_setItsTemperatureSensor(TemperatureSensor* const p_TemperatureSensor) {
    if(itsTemperatureSensor != NULL)
        {
            itsTemperatureSensor->__setItsOccupancySensor(NULL);
        }
    __setItsTemperatureSensor(p_TemperatureSensor);
}

void OccupancySensor::_clearItsTemperatureSensor(void) {
    NOTIFY_RELATION_CLEARED("itsTemperatureSensor");
    itsTemperatureSensor = NULL;
}

void OccupancySensor::rootState_entDef(void) {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.SendAndRecieve");
        rootState_subState = SendAndRecieve;
        rootState_active = SendAndRecieve;
        //#[ state SendAndRecieve.(Entry) 
        callMain();
        if(occupancy==0){
        	occupancy_bool=false;
        }else{
        	occupancy_bool=true;
        }
        modifying_bool=(!occupancy_bool);
        itsCO2Sensor->setModifying_bool(modifying_bool);
        itsTemperatureSensor->setModifying_bool(modifying_bool);
        //#]
        rootState_timeout = scheduleTimeout(1000, "ROOT.SendAndRecieve");
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus OccupancySensor::rootState_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    // State SendAndRecieve
    if(rootState_active == SendAndRecieve)
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId) == 1)
                {
                    if(getCurrentEvent() == rootState_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("1");
                            cancel(rootState_timeout);
                            NOTIFY_STATE_EXITED("ROOT.SendAndRecieve");
                            NOTIFY_STATE_ENTERED("ROOT.SendAndRecieve");
                            rootState_subState = SendAndRecieve;
                            rootState_active = SendAndRecieve;
                            //#[ state SendAndRecieve.(Entry) 
                            callMain();
                            if(occupancy==0){
                            	occupancy_bool=false;
                            }else{
                            	occupancy_bool=true;
                            }
                            modifying_bool=(!occupancy_bool);
                            itsCO2Sensor->setModifying_bool(modifying_bool);
                            itsTemperatureSensor->setModifying_bool(modifying_bool);
                            //#]
                            rootState_timeout = scheduleTimeout(1000, "ROOT.SendAndRecieve");
                            NOTIFY_TRANSITION_TERMINATED("1");
                            res = eventConsumed;
                        }
                }
            
        }
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedOccupancySensor::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("address_occupancy", UNKNOWN2STRING(myReal->address_occupancy));
    aomsAttributes->addAttribute("iResultOccupancy", x2String(myReal->iResultOccupancy));
    aomsAttributes->addAttribute("iSendResultOccupancy", x2String(myReal->iSendResultOccupancy));
    aomsAttributes->addAttribute("listenSocketForOccupancy", UNKNOWN2STRING(myReal->listenSocketForOccupancy));
    aomsAttributes->addAttribute("portOccupancy", x2String(myReal->portOccupancy));
    aomsAttributes->addAttribute("recvbuf", array2String(DEFAULT_BUFLEN, myReal->recvbuf, sizeof(char), &x2String));
    aomsAttributes->addAttribute("recvbuflen", x2String(myReal->recvbuflen));
    aomsAttributes->addAttribute("serverName", x2String(myReal->serverName));
    aomsAttributes->addAttribute("occupancy", x2String(myReal->occupancy));
    aomsAttributes->addAttribute("ws", UNKNOWN2STRING(myReal->ws));
    aomsAttributes->addAttribute("modifying_bool", x2String(myReal->modifying_bool));
    aomsAttributes->addAttribute("occupancy_bool", x2String(myReal->occupancy_bool));
}

void OMAnimatedOccupancySensor::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsDTSR", false, true);
    if(myReal->itsDTSR)
        {
            aomsRelations->ADD_ITEM(myReal->itsDTSR);
        }
    aomsRelations->addRelation("itsCO2Sensor", false, true);
    if(myReal->itsCO2Sensor)
        {
            aomsRelations->ADD_ITEM(myReal->itsCO2Sensor);
        }
    aomsRelations->addRelation("itsTemperatureSensor", false, true);
    if(myReal->itsTemperatureSensor)
        {
            aomsRelations->ADD_ITEM(myReal->itsTemperatureSensor);
        }
}

void OMAnimatedOccupancySensor::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    if(myReal->rootState_subState == OccupancySensor::SendAndRecieve)
        {
            SendAndRecieve_serializeStates(aomsState);
        }
}

void OMAnimatedOccupancySensor::SendAndRecieve_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.SendAndRecieve");
}
//#]

IMPLEMENT_REACTIVE_META_P(OccupancySensor, Default, Default, false, OMAnimatedOccupancySensor)

IMPLEMENT_META_OP(OMAnimatedOccupancySensor, Default_OccupancySensor_callMain, "callMain", FALSE, "callMain()", 0)

IMPLEMENT_OP_CALL(Default_OccupancySensor_callMain, OccupancySensor, callMain(), int animRetVal = )

IMPLEMENT_META_OP(OMAnimatedOccupancySensor, Default_OccupancySensor_setModifying_bool_bool, "setModifying_bool", FALSE, "setModifying_bool(bool)", 1)

IMPLEMENT_OP_CALL(Default_OccupancySensor_setModifying_bool_bool, OccupancySensor, setModifying_bool(p_modifying_bool), NO_OP())

IMPLEMENT_META_OP(OMAnimatedOccupancySensor, Default_OccupancySensor_setOccupancy_bool_int, "setOccupancy_bool", FALSE, "setOccupancy_bool(int)", 1)

IMPLEMENT_OP_CALL(Default_OccupancySensor_setOccupancy_bool_int, OccupancySensor, setOccupancy_bool(p_occupancy_bool), NO_OP())
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\OccupancySensor.cpp
*********************************************************************/
