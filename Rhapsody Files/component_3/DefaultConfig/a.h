/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: a
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\a.h
*********************************************************************/

#ifndef a_H
#define a_H

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
//## package Default

//## class a
class a {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimateda;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    a(void);
    
    //## auto_generated
    virtual ~a(void);
    
    ////    Operations    ////
    
    //## operation callMain()
    virtual int callMain(void);
    
    ////    Additional operations    ////
    
    //## auto_generated
    const SOCKADDR_IN getAddress_test(void) const;
    
    //## auto_generated
    void setAddress_test(const SOCKADDR_IN p_address_test);
    
    //## auto_generated
    const int getIResultTest(void) const;
    
    //## auto_generated
    void setIResultTest(const int p_iResultTest);
    
    //## auto_generated
    const int getISendResultTest(void) const;
    
    //## auto_generated
    void setISendResultTest(const int p_iSendResultTest);
    
    //## auto_generated
    const SOCKET getListenSocketForTest(void) const;
    
    //## auto_generated
    void setListenSocketForTest(const SOCKET p_listenSocketForTest);
    
    //## auto_generated
    const int getPortTest(void) const;
    
    //## auto_generated
    void setPortTest(const int p_portTest);
    
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
    const float getTest(void) const;
    
    //## auto_generated
    void setTest(const float p_test);
    
    //## auto_generated
    const WSADATA getWs(void) const;
    
    //## auto_generated
    void setWs(const WSADATA p_ws);
    
    ////    Attributes    ////

private :

    SOCKADDR_IN address_test;		//## attribute address_test
    
    int iResultTest;		//## attribute iResultTest
    
    int iSendResultTest;		//## attribute iSendResultTest
    
    SOCKET listenSocketForTest;		//## attribute listenSocketForTest
    
    int portTest;		//## attribute portTest
    
    char recvbuf[DEFAULT_BUFLEN];		//## attribute recvbuf
    
    int recvbuflen;		//## attribute recvbuflen
    
    char* serverName;		//## attribute serverName
    
    float test;		//## attribute test
    
    WSADATA ws;		//## attribute ws
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimateda : virtual public AOMInstance {
    DECLARE_META(a, OMAnimateda)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: component_3\DefaultConfig\a.h
*********************************************************************/
