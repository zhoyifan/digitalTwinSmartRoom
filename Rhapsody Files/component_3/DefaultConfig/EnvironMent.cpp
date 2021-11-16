/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: EnvironMent
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\EnvironMent.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "EnvironMent.h"
//## link itsDTSR
#include "DTSR.h"
//#[ ignore
#define Default_EnvironMent_EnvironMent_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class EnvironMent
EnvironMent::EnvironMent(void) : itsDTSR(NULL) {
    NOTIFY_CONSTRUCTOR(EnvironMent, EnvironMent(), 0, Default_EnvironMent_EnvironMent_SERIALIZE);
}

EnvironMent::~EnvironMent(void) {
    NOTIFY_DESTRUCTOR(~EnvironMent, true);
    cleanUpRelations();
}

const DTSR* EnvironMent::getItsDTSR(void) const {
    return itsDTSR;
}

void EnvironMent::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_setItsEnvironMent(this);
        }
    _setItsDTSR(p_DTSR);
}

const ExternalLighting* EnvironMent::getItsExternalLighting(void) const {
    return &itsExternalLighting;
}

const Temperature* EnvironMent::getItsTemperature(void) const {
    return &itsTemperature;
}

const Weather* EnvironMent::getItsWeather(void) const {
    return &itsWeather;
}

void EnvironMent::cleanUpRelations(void) {
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            const EnvironMent* p_EnvironMent = itsDTSR->getItsEnvironMent();
            if(p_EnvironMent != NULL)
                {
                    itsDTSR->__setItsEnvironMent(NULL);
                }
            itsDTSR = NULL;
        }
}

void EnvironMent::__setItsDTSR(DTSR* const p_DTSR) {
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

void EnvironMent::_setItsDTSR(DTSR* const p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->__setItsEnvironMent(NULL);
        }
    __setItsDTSR(p_DTSR);
}

void EnvironMent::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedEnvironMent::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsWeather", true, true);
    aomsRelations->ADD_ITEM(&myReal->itsWeather);
    aomsRelations->addRelation("itsExternalLighting", true, true);
    aomsRelations->ADD_ITEM(&myReal->itsExternalLighting);
    aomsRelations->addRelation("itsTemperature", true, true);
    aomsRelations->ADD_ITEM(&myReal->itsTemperature);
    aomsRelations->addRelation("itsDTSR", false, true);
    if(myReal->itsDTSR)
        {
            aomsRelations->ADD_ITEM(myReal->itsDTSR);
        }
}
//#]

IMPLEMENT_META_P(EnvironMent, Default, Default, false, OMAnimatedEnvironMent)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: component_3\DefaultConfig\EnvironMent.cpp
*********************************************************************/
