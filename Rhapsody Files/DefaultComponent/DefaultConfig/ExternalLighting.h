/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ExternalLighting
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\ExternalLighting.h
*********************************************************************/

#ifndef ExternalLighting_H
#define ExternalLighting_H

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

//## class ExternalLighting
class ExternalLighting {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedExternalLighting;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    ExternalLighting(void);
    
    //## auto_generated
    ~ExternalLighting(void);
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedExternalLighting : virtual public AOMInstance {
    DECLARE_META(ExternalLighting, OMAnimatedExternalLighting)
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ExternalLighting.h
*********************************************************************/
