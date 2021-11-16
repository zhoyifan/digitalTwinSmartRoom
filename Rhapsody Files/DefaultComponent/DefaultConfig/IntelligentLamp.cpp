/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: IntelligentLamp
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\IntelligentLamp.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "IntelligentLamp.h"
//## link itsDTSR
#include "DTSR.h"
//#[ ignore
#define Default_IntelligentLamp_IntelligentLamp_SERIALIZE OM_NO_OP

#define Default_IntelligentLamp_callMain_SERIALIZE OM_NO_OP

#define OMAnim_Default_IntelligentLamp_callMain_UNSERIALIZE_ARGS

#define OMAnim_Default_IntelligentLamp_callMain_SERIALIZE_RET_VAL OP_SET_RET_VAL(animRetVal)

#define OMAnim_Default_IntelligentLamp_setLight_float_UNSERIALIZE_ARGS OP_UNSER(OMDestructiveString2X,p_light)

#define OMAnim_Default_IntelligentLamp_setLight_float_SERIALIZE_RET_VAL
//#]

//## package Default

//## class IntelligentLamp
IntelligentLamp::IntelligentLamp(IOxfActive* const theActiveContext) : OMReactive(), light(1.5), listenSocketForLight(INVALID_SOCKET), portLight(10014), recvbuflen(DEFAULT_BUFLEN), serverName("127.0.0.1"), itsDTSR(NULL) {
    NOTIFY_REACTIVE_CONSTRUCTOR(IntelligentLamp, IntelligentLamp(), 0, Default_IntelligentLamp_IntelligentLamp_SERIALIZE);
    setActiveContext(theActiveContext, false);
    initStatechart();
}

IntelligentLamp::~IntelligentLamp(void) {
    NOTIFY_DESTRUCTOR(~IntelligentLamp, true);
    cleanUpRelations();
    cancelTimeouts();
}

int IntelligentLamp::callMain(void) {
    NOTIFY_OPERATION(callMain, callMain(), 0, Default_IntelligentLamp_callMain_SERIALIZE);
    //#[ operation callMain()
    #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
    #define _WINSOCK_DEPRECATED_NO_WARNINGS
    #endif
    
    #include <stdlib.h>
    
    WSAStartup(0x0101,&ws);
    
    char out_string_for_light [1024];
    
    //LIGHT
    ZeroMemory(&address_light, sizeof(address_light));
    address_light.sin_family = AF_INET;
    address_light.sin_port = htons(portLight);
    address_light.sin_addr.s_addr=inet_addr(serverName);
    
    //INITIALIZE ALL SOCKETS
    listenSocketForLight = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    //CONNECT ALL THE SOCKETS
    iResultLight = connect(listenSocketForLight,(SOCKADDR*)&address_light, sizeof(address_light)); 
    
    
    
    //ASSIGN VALUES TO SEND 
    sprintf(out_string_for_light, "%f", light);
    
    
    
    //SEND VALUE
    iSendResultLight = sendto(listenSocketForLight, (char *)&out_string_for_light ,sizeof(uint32_t), 0 ,(SOCKADDR *) & address_light, sizeof (address_light) );
    //SHOW SENT VALUES IN CONSOLE
    //printf("Light value sent: %s \n",out_string_for_light);
    
    //RECIEVED VALUE OF LIGHT
    iResultLight = recv(listenSocketForLight, recvbuf, recvbuflen, 0); 
    float lighttocheck = atof(recvbuf);
    printf("LIGHT value recieved: %f\n",atof(recvbuf));
    //CLOSE ALL THE SOCKETS
    closesocket(listenSocketForLight);
    return 0;
    
    //#]
}

const SOCKADDR_IN IntelligentLamp::getAddress_light(void) const {
    return address_light;
}

void IntelligentLamp::setAddress_light(const SOCKADDR_IN p_address_light) {
    address_light = p_address_light;
}

const int IntelligentLamp::getIResultLight(void) const {
    return iResultLight;
}

void IntelligentLamp::setIResultLight(const int p_iResultLight) {
    iResultLight = p_iResultLight;
}

const int IntelligentLamp::getISendResultLight(void) const {
    return iSendResultLight;
}

void IntelligentLamp::setISendResultLight(const int p_iSendResultLight) {
    iSendResultLight = p_iSendResultLight;
}

const float IntelligentLamp::getLight(void) const {
    return light;
}

void IntelligentLamp::setLight(const float p_light) {
    light = p_light;
    NOTIFY_SET_OPERATION;
}

const SOCKET IntelligentLamp::getListenSocketForLight(void) const {
    return listenSocketForLight;
}

void IntelligentLamp::setListenSocketForLight(const SOCKET p_listenSocketForLight) {
    listenSocketForLight = p_listenSocketForLight;
}

const int IntelligentLamp::getPortLight(void) const {
    return portLight;
}

void IntelligentLamp::setPortLight(const int p_portLight) {
    portLight = p_portLight;
}

const char IntelligentLamp::getRecvbuf(const Rhp_int32_t iterI1) const {
    return recvbuf[iterI1];
}

void IntelligentLamp::setRecvbuf(const Rhp_int32_t iterI1, const char p_recvbuf) {
    recvbuf[iterI1] = p_recvbuf;
}

const int IntelligentLamp::getRecvbuflen(void) const {
    return recvbuflen;
}

void IntelligentLamp::setRecvbuflen(const int p_recvbuflen) {
    recvbuflen = p_recvbuflen;
}

const char* IntelligentLamp::getServerName(void) const {
    return serverName;
}

void IntelligentLamp::setServerName(char* const p_serverName) {
    serverName = p_serverName;
}

const WSADATA IntelligentLamp::getWs(void) const {
    return ws;
}

void IntelligentLamp::setWs(const WSADATA p_ws) {
    ws = p_ws;
}

const DTSR* IntelligentLamp::getItsDTSR(void) const {
    return itsDTSR;
}

void IntelligentLamp::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_addItsIntelligentLamp(this);
        }
    _setItsDTSR(p_DTSR);
}

bool IntelligentLamp::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(rootState_timeout == arg)
        {
            rootState_timeout = NULL;
            res = true;
        }
    return res;
}

bool IntelligentLamp::startBehavior(void) {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void IntelligentLamp::initStatechart(void) {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    rootState_timeout = NULL;
}

void IntelligentLamp::cleanUpRelations(void) {
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            DTSR* current = itsDTSR;
            if(current != NULL)
                {
                    current->_removeItsIntelligentLamp(this);
                }
            itsDTSR = NULL;
        }
}

void IntelligentLamp::cancelTimeouts(void) {
    cancel(rootState_timeout);
}

void IntelligentLamp::__setItsDTSR(DTSR* const p_DTSR) {
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

void IntelligentLamp::_setItsDTSR(DTSR* p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->_removeItsIntelligentLamp(this);
        }
    __setItsDTSR(p_DTSR);
}

void IntelligentLamp::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

void IntelligentLamp::rootState_entDef(void) {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.SendAndRecieve");
        rootState_subState = SendAndRecieve;
        rootState_active = SendAndRecieve;
        //#[ state SendAndRecieve.(Entry) 
        callMain();
        //std::cout<<"fire_bool in fire sensor is : "<<itsFireSensor->getFire_bool()<<"************************"<<std::endl;
        
         
        //#]
        rootState_timeout = scheduleTimeout(1000, "ROOT.SendAndRecieve");
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus IntelligentLamp::rootState_processEvent(void) {
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
                            //std::cout<<"fire_bool in fire sensor is : "<<itsFireSensor->getFire_bool()<<"************************"<<std::endl;
                            
                             
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
void OMAnimatedIntelligentLamp::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("address_light", UNKNOWN2STRING(myReal->address_light));
    aomsAttributes->addAttribute("serverName", x2String(myReal->serverName));
    aomsAttributes->addAttribute("portLight", x2String(myReal->portLight));
    aomsAttributes->addAttribute("listenSocketForLight", UNKNOWN2STRING(myReal->listenSocketForLight));
    aomsAttributes->addAttribute("iResultLight", x2String(myReal->iResultLight));
    aomsAttributes->addAttribute("iSendResultLight", x2String(myReal->iSendResultLight));
    aomsAttributes->addAttribute("recvbuf", array2String(DEFAULT_BUFLEN, myReal->recvbuf, sizeof(char), &x2String));
    aomsAttributes->addAttribute("recvbuflen", x2String(myReal->recvbuflen));
    aomsAttributes->addAttribute("ws", UNKNOWN2STRING(myReal->ws));
    aomsAttributes->addAttribute("light", x2String(myReal->light));
}

void OMAnimatedIntelligentLamp::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsDTSR", false, true);
    if(myReal->itsDTSR)
        {
            aomsRelations->ADD_ITEM(myReal->itsDTSR);
        }
}

void OMAnimatedIntelligentLamp::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    if(myReal->rootState_subState == IntelligentLamp::SendAndRecieve)
        {
            SendAndRecieve_serializeStates(aomsState);
        }
}

void OMAnimatedIntelligentLamp::SendAndRecieve_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.SendAndRecieve");
}
//#]

IMPLEMENT_REACTIVE_META_P(IntelligentLamp, Default, Default, false, OMAnimatedIntelligentLamp)

IMPLEMENT_META_OP(OMAnimatedIntelligentLamp, Default_IntelligentLamp_callMain, "callMain", FALSE, "callMain()", 0)

IMPLEMENT_OP_CALL(Default_IntelligentLamp_callMain, IntelligentLamp, callMain(), int animRetVal = )

IMPLEMENT_META_OP(OMAnimatedIntelligentLamp, Default_IntelligentLamp_setLight_float, "setLight", FALSE, "setLight(float)", 1)

IMPLEMENT_OP_CALL(Default_IntelligentLamp_setLight_float, IntelligentLamp, setLight(p_light), NO_OP())
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\IntelligentLamp.cpp
*********************************************************************/
