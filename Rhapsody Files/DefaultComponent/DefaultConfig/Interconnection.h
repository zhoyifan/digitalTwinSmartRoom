/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Interconnection
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\Interconnection.h
*********************************************************************/

#ifndef Interconnection_H
#define Interconnection_H

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
//## link itsDTSR
class DTSR;

//## package Default

//## class Interconnection
class Interconnection {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedInterconnection;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Interconnection(void);
    
    //## auto_generated
    ~Interconnection(void);
    
    ////    Additional operations    ////
    
    //## auto_generated
    const DTSR* getItsDTSR(void) const;
    
    //## auto_generated
    void setItsDTSR(DTSR* const p_DTSR);

protected :

    //## auto_generated
    void cleanUpRelations(void);
    
    ////    Relations and components    ////

private :

    DTSR* itsDTSR;		//## link itsDTSR
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    void _setItsDTSR(DTSR* const p_DTSR);
    
    //## auto_generated
    void _clearItsDTSR(void);
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedInterconnection : virtual public AOMInstance {
    DECLARE_META(Interconnection, OMAnimatedInterconnection)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Interconnection.h
*********************************************************************/