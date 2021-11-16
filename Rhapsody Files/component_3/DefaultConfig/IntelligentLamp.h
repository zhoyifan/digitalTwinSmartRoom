/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: IntelligentLamp
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\IntelligentLamp.h
*********************************************************************/

#ifndef IntelligentLamp_H
#define IntelligentLamp_H

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

//#[ ignore
#define OMAnim_Default_IntelligentLamp_setLight_float_ARGS_DECLARATION float p_light;
//#]

//## package Default

//## class IntelligentLamp
class IntelligentLamp : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedIntelligentLamp;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    explicit IntelligentLamp(IOxfActive* const theActiveContext = NULL);
    
    //## auto_generated
    virtual ~IntelligentLamp(void);
    
    ////    Operations    ////
    
    //## operation callMain()
    virtual int callMain(void);
    
    ////    Additional operations    ////
    
    //## auto_generated
    const SOCKADDR_IN getAddress_light(void) const;
    
    //## auto_generated
    void setAddress_light(const SOCKADDR_IN p_address_light);
    
    //## auto_generated
    const int getIResultLight(void) const;
    
    //## auto_generated
    void setIResultLight(const int p_iResultLight);
    
    //## auto_generated
    const int getISendResultLight(void) const;
    
    //## auto_generated
    void setISendResultLight(const int p_iSendResultLight);
    
    //## auto_generated
    const float getLight(void) const;
    
    //## auto_generated
    void setLight(const float p_light);
    
    //## auto_generated
    const SOCKET getListenSocketForLight(void) const;
    
    //## auto_generated
    void setListenSocketForLight(const SOCKET p_listenSocketForLight);
    
    //## auto_generated
    const int getPortLight(void) const;
    
    //## auto_generated
    void setPortLight(const int p_portLight);
    
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
    const DTSR* getItsDTSR(void) const;
    
    //## auto_generated
    void setItsDTSR(DTSR* const p_DTSR);
    
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

    SOCKADDR_IN address_light;		//## attribute address_light
    
    int iResultLight;		//## attribute iResultLight
    
    int iSendResultLight;		//## attribute iSendResultLight
    
    float light;		//## attribute light
    
    SOCKET listenSocketForLight;		//## attribute listenSocketForLight
    
    int portLight;		//## attribute portLight
    
    char recvbuf[DEFAULT_BUFLEN];		//## attribute recvbuf
    
    int recvbuflen;		//## attribute recvbuflen
    
    char* serverName;		//## attribute serverName
    
    WSADATA ws;		//## attribute ws
    
    ////    Relations and components    ////
    
    DTSR* itsDTSR;		//## link itsDTSR
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    void _setItsDTSR(DTSR* p_DTSR);
    
    //## auto_generated
    void _clearItsDTSR(void);
    
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
    enum IntelligentLamp_Enum {
        OMNonState = 0,
        SendAndRecieve = 1
    };
//#]

private :

//#[ ignore
    IntelligentLamp_Enum rootState_subState;
    
    IntelligentLamp_Enum rootState_active;
    
    IOxfTimeout* rootState_timeout;
//#]
};

#ifdef _OMINSTRUMENT
DECLARE_OPERATION_CLASS(Default_IntelligentLamp_setLight_float)

//#[ ignore
class OMAnimatedIntelligentLamp : virtual public AOMInstance {
    DECLARE_REACTIVE_META(IntelligentLamp, OMAnimatedIntelligentLamp)
    
    DECLARE_META_OP(Default_IntelligentLamp_setLight_float)
    
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

inline RhpBoolean IntelligentLamp::rootState_IN(void) const {
    return true;
}

inline RhpBoolean IntelligentLamp::SendAndRecieve_IN(void) const {
    return rootState_subState == SendAndRecieve;
}

#endif
/*********************************************************************
	File Path	: component_3\DefaultConfig\IntelligentLamp.h
*********************************************************************/
