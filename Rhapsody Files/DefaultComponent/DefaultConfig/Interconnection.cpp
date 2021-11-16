/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Interconnection
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\Interconnection.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Interconnection.h"
//## link itsDTSR
#include "DTSR.h"
//#[ ignore
#define Default_Interconnection_Interconnection_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Interconnection
Interconnection::Interconnection(void) : itsDTSR(NULL) {
    NOTIFY_CONSTRUCTOR(Interconnection, Interconnection(), 0, Default_Interconnection_Interconnection_SERIALIZE);
}

Interconnection::~Interconnection(void) {
    NOTIFY_DESTRUCTOR(~Interconnection, true);
    cleanUpRelations();
}

const DTSR* Interconnection::getItsDTSR(void) const {
    return itsDTSR;
}

void Interconnection::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_setItsInterconnection(this);
        }
    _setItsDTSR(p_DTSR);
}

void Interconnection::cleanUpRelations(void) {
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            const Interconnection* p_Interconnection = itsDTSR->getItsInterconnection();
            if(p_Interconnection != NULL)
                {
                    itsDTSR->__setItsInterconnection(NULL);
                }
            itsDTSR = NULL;
        }
}

void Interconnection::__setItsDTSR(DTSR* const p_DTSR) {
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

void Interconnection::_setItsDTSR(DTSR* const p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->__setItsInterconnection(NULL);
        }
    __setItsDTSR(p_DTSR);
}

void Interconnection::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedInterconnection::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsDTSR", false, true);
    if(myReal->itsDTSR)
        {
            aomsRelations->ADD_ITEM(myReal->itsDTSR);
        }
}
//#]

IMPLEMENT_META_P(Interconnection, Default, Default, false, OMAnimatedInterconnection)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Interconnection.cpp
*********************************************************************/
