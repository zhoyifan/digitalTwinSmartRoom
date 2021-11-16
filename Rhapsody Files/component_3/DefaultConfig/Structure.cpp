/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: Structure
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\Structure.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Structure.h"
//#[ ignore
#define event_5_SERIALIZE OMADD_SER(argument_0, x2String(myEvent->argument_0))

#define event_5_UNSERIALIZE OMADD_UNSER(int, argument_0, OMDestructiveString2X)

#define event_5_CONSTRUCTOR event_5(argument_0)

#define evFireStart_SERIALIZE OM_NO_OP

#define evFireStart_UNSERIALIZE OM_NO_OP

#define evFireStart_CONSTRUCTOR evFireStart()

#define evFireAlarmStart_SERIALIZE OM_NO_OP

#define evFireAlarmStart_UNSERIALIZE OM_NO_OP

#define evFireAlarmStart_CONSTRUCTOR evFireAlarmStart()

#define evFireEnd_SERIALIZE OM_NO_OP

#define evFireEnd_UNSERIALIZE OM_NO_OP

#define evFireEnd_CONSTRUCTOR evFireEnd()

#define evFireAlarmEnd_SERIALIZE OM_NO_OP

#define evFireAlarmEnd_UNSERIALIZE OM_NO_OP

#define evFireAlarmEnd_CONSTRUCTOR evFireAlarmEnd()

#define evSensingFire_SERIALIZE OM_NO_OP

#define evSensingFire_UNSERIALIZE OM_NO_OP

#define evSensingFire_CONSTRUCTOR evSensingFire()

#define evSensingNoFire_SERIALIZE OM_NO_OP

#define evSensingNoFire_UNSERIALIZE OM_NO_OP

#define evSensingNoFire_CONSTRUCTOR evSensingNoFire()
//#]

//## package Structure


#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */);

IMPLEMENT_META_PACKAGE(Structure, Structure)

static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */) {
}
#endif // _OMINSTRUMENT

//## event event_5(int)
event_5::event_5(void) {
    NOTIFY_EVENT_CONSTRUCTOR(event_5)
    setId(event_5_Structure_id);
}

event_5::event_5(const int p_argument_0) : OMEvent() ,argument_0(p_argument_0) {
    NOTIFY_EVENT_CONSTRUCTOR(event_5)
    setId(event_5_Structure_id);
}

int event_5::getArgument_0(void) const {
    return argument_0;
}

void event_5::setArgument_0(const int p_argument_0) {
    argument_0 = p_argument_0;
}

//#[ ignore
const IOxfEvent::ID event_5_Structure_id(10601);
//#]

IMPLEMENT_META_EVENT_P(event_5, Structure, Structure, event_5(int))

//## event evFireStart()
evFireStart::evFireStart(void) : OMEvent() {
    NOTIFY_EVENT_CONSTRUCTOR(evFireStart)
    setId(evFireStart_Structure_id);
}

//#[ ignore
const IOxfEvent::ID evFireStart_Structure_id(10602);
//#]

IMPLEMENT_META_EVENT_P(evFireStart, Structure, Structure, evFireStart())

//## event evFireAlarmStart()
evFireAlarmStart::evFireAlarmStart(void) : OMEvent() {
    NOTIFY_EVENT_CONSTRUCTOR(evFireAlarmStart)
    setId(evFireAlarmStart_Structure_id);
}

//#[ ignore
const IOxfEvent::ID evFireAlarmStart_Structure_id(10603);
//#]

IMPLEMENT_META_EVENT_P(evFireAlarmStart, Structure, Structure, evFireAlarmStart())

//## event evFireEnd()
evFireEnd::evFireEnd(void) : OMEvent() {
    NOTIFY_EVENT_CONSTRUCTOR(evFireEnd)
    setId(evFireEnd_Structure_id);
}

//#[ ignore
const IOxfEvent::ID evFireEnd_Structure_id(10604);
//#]

IMPLEMENT_META_EVENT_P(evFireEnd, Structure, Structure, evFireEnd())

//## event evFireAlarmEnd()
evFireAlarmEnd::evFireAlarmEnd(void) : OMEvent() {
    NOTIFY_EVENT_CONSTRUCTOR(evFireAlarmEnd)
    setId(evFireAlarmEnd_Structure_id);
}

//#[ ignore
const IOxfEvent::ID evFireAlarmEnd_Structure_id(10605);
//#]

IMPLEMENT_META_EVENT_P(evFireAlarmEnd, Structure, Structure, evFireAlarmEnd())

//## event evSensingFire()
evSensingFire::evSensingFire(void) : OMEvent() {
    NOTIFY_EVENT_CONSTRUCTOR(evSensingFire)
    setId(evSensingFire_Structure_id);
}

//#[ ignore
const IOxfEvent::ID evSensingFire_Structure_id(10606);
//#]

IMPLEMENT_META_EVENT_P(evSensingFire, Structure, Structure, evSensingFire())

//## event evSensingNoFire()
evSensingNoFire::evSensingNoFire(void) : OMEvent() {
    NOTIFY_EVENT_CONSTRUCTOR(evSensingNoFire)
    setId(evSensingNoFire_Structure_id);
}

//#[ ignore
const IOxfEvent::ID evSensingNoFire_Structure_id(10607);
//#]

IMPLEMENT_META_EVENT_P(evSensingNoFire, Structure, Structure, evSensingNoFire())

/*********************************************************************
	File Path	: component_3\DefaultConfig\Structure.cpp
*********************************************************************/
