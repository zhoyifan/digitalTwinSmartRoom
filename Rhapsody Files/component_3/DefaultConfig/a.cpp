/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: a
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\a.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "a.h"
//#[ ignore
#define Default_a_a_SERIALIZE OM_NO_OP

#define Default_a_callMain_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class a
a::a(void) : listenSocketForTest(INVALID_SOCKET), portTest(52051), recvbuflen(DEFAULT_BUFLEN), serverName("127.0.0.1") {
    NOTIFY_CONSTRUCTOR(a, a(), 0, Default_a_a_SERIALIZE);
}

a::~a(void) {
    NOTIFY_DESTRUCTOR(~a, true);
}

int a::callMain(void) {
    NOTIFY_OPERATION(callMain, callMain(), 0, Default_a_callMain_SERIALIZE);
    //#[ operation callMain()
    return 0;
    //#]
}

const SOCKADDR_IN a::getAddress_test(void) const {
    return address_test;
}

void a::setAddress_test(const SOCKADDR_IN p_address_test) {
    address_test = p_address_test;
}

const int a::getIResultTest(void) const {
    return iResultTest;
}

void a::setIResultTest(const int p_iResultTest) {
    iResultTest = p_iResultTest;
}

const int a::getISendResultTest(void) const {
    return iSendResultTest;
}

void a::setISendResultTest(const int p_iSendResultTest) {
    iSendResultTest = p_iSendResultTest;
}

const SOCKET a::getListenSocketForTest(void) const {
    return listenSocketForTest;
}

void a::setListenSocketForTest(const SOCKET p_listenSocketForTest) {
    listenSocketForTest = p_listenSocketForTest;
}

const int a::getPortTest(void) const {
    return portTest;
}

void a::setPortTest(const int p_portTest) {
    portTest = p_portTest;
}

const char a::getRecvbuf(const Rhp_int32_t iterI1) const {
    return recvbuf[iterI1];
}

void a::setRecvbuf(const Rhp_int32_t iterI1, const char p_recvbuf) {
    recvbuf[iterI1] = p_recvbuf;
}

const int a::getRecvbuflen(void) const {
    return recvbuflen;
}

void a::setRecvbuflen(const int p_recvbuflen) {
    recvbuflen = p_recvbuflen;
}

const char* a::getServerName(void) const {
    return serverName;
}

void a::setServerName(char* const p_serverName) {
    serverName = p_serverName;
}

const float a::getTest(void) const {
    return test;
}

void a::setTest(const float p_test) {
    test = p_test;
}

const WSADATA a::getWs(void) const {
    return ws;
}

void a::setWs(const WSADATA p_ws) {
    ws = p_ws;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimateda::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("address_test", UNKNOWN2STRING(myReal->address_test));
    aomsAttributes->addAttribute("serverName", x2String(myReal->serverName));
    aomsAttributes->addAttribute("portTest", x2String(myReal->portTest));
    aomsAttributes->addAttribute("listenSocketForTest", UNKNOWN2STRING(myReal->listenSocketForTest));
    aomsAttributes->addAttribute("iResultTest", x2String(myReal->iResultTest));
    aomsAttributes->addAttribute("iSendResultTest", x2String(myReal->iSendResultTest));
    aomsAttributes->addAttribute("recvbuf", array2String(DEFAULT_BUFLEN, myReal->recvbuf, sizeof(char), &x2String));
    aomsAttributes->addAttribute("recvbuflen", x2String(myReal->recvbuflen));
    aomsAttributes->addAttribute("ws", UNKNOWN2STRING(myReal->ws));
    aomsAttributes->addAttribute("test", x2String(myReal->test));
}
//#]

IMPLEMENT_META_P(a, Default, Default, false, OMAnimateda)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: component_3\DefaultConfig\a.cpp
*********************************************************************/
