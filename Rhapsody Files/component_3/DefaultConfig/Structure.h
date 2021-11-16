/*********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: Structure
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\Structure.h
*********************************************************************/

#ifndef Structure_H
#define Structure_H

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
#include <event.h>
//## package Structure



//## event event_5(int)
class event_5 : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevent_5;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    event_5(void);
    
    //## auto_generated
    event_5(const int p_argument_0);
    
    ////    Additional operations    ////
    
    //## auto_generated
    int getArgument_0(void) const;
    
    //## auto_generated
    void setArgument_0(const int p_argument_0);
    
    ////    Framework    ////

private :

    int argument_0;		//## auto_generated
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevent_5 : virtual public AOMEvent {
    DECLARE_META_EVENT(event_5)
};
//#]
#endif // _OMINSTRUMENT

//#[ ignore
extern const IOxfEvent::ID event_5_Structure_id;
//#]

//## event evFireStart()
class evFireStart : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevFireStart;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evFireStart(void);
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevFireStart : virtual public AOMEvent {
    DECLARE_META_EVENT(evFireStart)
};
//#]
#endif // _OMINSTRUMENT

//#[ ignore
extern const IOxfEvent::ID evFireStart_Structure_id;
//#]

//## event evFireAlarmStart()
class evFireAlarmStart : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevFireAlarmStart;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evFireAlarmStart(void);
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevFireAlarmStart : virtual public AOMEvent {
    DECLARE_META_EVENT(evFireAlarmStart)
};
//#]
#endif // _OMINSTRUMENT

//#[ ignore
extern const IOxfEvent::ID evFireAlarmStart_Structure_id;
//#]

//## event evFireEnd()
class evFireEnd : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevFireEnd;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evFireEnd(void);
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevFireEnd : virtual public AOMEvent {
    DECLARE_META_EVENT(evFireEnd)
};
//#]
#endif // _OMINSTRUMENT

//#[ ignore
extern const IOxfEvent::ID evFireEnd_Structure_id;
//#]

//## event evFireAlarmEnd()
class evFireAlarmEnd : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevFireAlarmEnd;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evFireAlarmEnd(void);
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevFireAlarmEnd : virtual public AOMEvent {
    DECLARE_META_EVENT(evFireAlarmEnd)
};
//#]
#endif // _OMINSTRUMENT

//#[ ignore
extern const IOxfEvent::ID evFireAlarmEnd_Structure_id;
//#]

//## event evSensingFire()
class evSensingFire : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevSensingFire;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evSensingFire(void);
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevSensingFire : virtual public AOMEvent {
    DECLARE_META_EVENT(evSensingFire)
};
//#]
#endif // _OMINSTRUMENT

//#[ ignore
extern const IOxfEvent::ID evSensingFire_Structure_id;
//#]

//## event evSensingNoFire()
class evSensingNoFire : public OMEvent {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedevSensingNoFire;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    evSensingNoFire(void);
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedevSensingNoFire : virtual public AOMEvent {
    DECLARE_META_EVENT(evSensingNoFire)
};
//#]
#endif // _OMINSTRUMENT

//#[ ignore
extern const IOxfEvent::ID evSensingNoFire_Structure_id;
//#]

#endif
/*********************************************************************
	File Path	: component_3\DefaultConfig\Structure.h
*********************************************************************/
