/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: AVSystem
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\AVSystem.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "AVSystem.h"
//## link itsDTSR
#include "DTSR.h"
//#[ ignore
#define Default_AVSystem_AVSystem_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class AVSystem
AVSystem::AVSystem(void) : itsDTSR(NULL) {
    NOTIFY_CONSTRUCTOR(AVSystem, AVSystem(), 0, Default_AVSystem_AVSystem_SERIALIZE);
}

AVSystem::~AVSystem(void) {
    NOTIFY_DESTRUCTOR(~AVSystem, true);
    cleanUpRelations();
}

const DTSR* AVSystem::getItsDTSR(void) const {
    return itsDTSR;
}

void AVSystem::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_setItsAVSystem(this);
        }
    _setItsDTSR(p_DTSR);
}

void AVSystem::cleanUpRelations(void) {
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            const AVSystem* p_AVSystem = itsDTSR->getItsAVSystem();
            if(p_AVSystem != NULL)
                {
                    itsDTSR->__setItsAVSystem(NULL);
                }
            itsDTSR = NULL;
        }
}

void AVSystem::__setItsDTSR(DTSR* const p_DTSR) {
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

void AVSystem::_setItsDTSR(DTSR* const p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->__setItsAVSystem(NULL);
        }
    __setItsDTSR(p_DTSR);
}

void AVSystem::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedAVSystem::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsDTSR", false, true);
    if(myReal->itsDTSR)
        {
            aomsRelations->ADD_ITEM(myReal->itsDTSR);
        }
}
//#]

IMPLEMENT_META_P(AVSystem, Default, Default, false, OMAnimatedAVSystem)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: component_3\DefaultConfig\AVSystem.cpp
*********************************************************************/
