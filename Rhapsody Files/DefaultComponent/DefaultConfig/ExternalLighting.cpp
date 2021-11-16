/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ExternalLighting
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\ExternalLighting.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "ExternalLighting.h"
//#[ ignore
#define Default_ExternalLighting_ExternalLighting_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class ExternalLighting
ExternalLighting::ExternalLighting(void) {
    NOTIFY_CONSTRUCTOR(ExternalLighting, ExternalLighting(), 0, Default_ExternalLighting_ExternalLighting_SERIALIZE);
}

ExternalLighting::~ExternalLighting(void) {
    NOTIFY_DESTRUCTOR(~ExternalLighting, true);
}

#ifdef _OMINSTRUMENT
IMPLEMENT_META_P(ExternalLighting, Default, Default, false, OMAnimatedExternalLighting)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ExternalLighting.cpp
*********************************************************************/
