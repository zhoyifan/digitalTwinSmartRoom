/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: SASystem
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\SASystem.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "SASystem.h"
//## link itsDTSR
#include "DTSR.h"
//#[ ignore
#define Default_SASystem_SASystem_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class SASystem
SASystem::SASystem(void) : itsDTSR(NULL) {
    NOTIFY_CONSTRUCTOR(SASystem, SASystem(), 0, Default_SASystem_SASystem_SERIALIZE);
}

SASystem::~SASystem(void) {
    NOTIFY_DESTRUCTOR(~SASystem, true);
    cleanUpRelations();
}

const DTSR* SASystem::getItsDTSR(void) const {
    return itsDTSR;
}

void SASystem::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_setItsSASystem(this);
        }
    _setItsDTSR(p_DTSR);
}

void SASystem::cleanUpRelations(void) {
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            const SASystem* p_SASystem = itsDTSR->getItsSASystem();
            if(p_SASystem != NULL)
                {
                    itsDTSR->__setItsSASystem(NULL);
                }
            itsDTSR = NULL;
        }
}

void SASystem::__setItsDTSR(DTSR* const p_DTSR) {
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

void SASystem::_setItsDTSR(DTSR* const p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->__setItsSASystem(NULL);
        }
    __setItsDTSR(p_DTSR);
}

void SASystem::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedSASystem::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsDTSR", false, true);
    if(myReal->itsDTSR)
        {
            aomsRelations->ADD_ITEM(myReal->itsDTSR);
        }
}
//#]

IMPLEMENT_META_P(SASystem, Default, Default, false, OMAnimatedSASystem)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\SASystem.cpp
*********************************************************************/
