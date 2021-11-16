/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: VisualEntity
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\VisualEntity.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "VisualEntity.h"
//## link itsDTSR
#include "DTSR.h"
//#[ ignore
#define Default_VisualEntity_VisualEntity_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class VisualEntity
VisualEntity::VisualEntity(void) : itsDTSR(NULL) {
    NOTIFY_CONSTRUCTOR(VisualEntity, VisualEntity(), 0, Default_VisualEntity_VisualEntity_SERIALIZE);
}

VisualEntity::~VisualEntity(void) {
    NOTIFY_DESTRUCTOR(~VisualEntity, true);
    cleanUpRelations();
}

const DTSR* VisualEntity::getItsDTSR(void) const {
    return itsDTSR;
}

void VisualEntity::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_setItsVisualEntity(this);
        }
    _setItsDTSR(p_DTSR);
}

void VisualEntity::cleanUpRelations(void) {
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            const VisualEntity* p_VisualEntity = itsDTSR->getItsVisualEntity();
            if(p_VisualEntity != NULL)
                {
                    itsDTSR->__setItsVisualEntity(NULL);
                }
            itsDTSR = NULL;
        }
}

void VisualEntity::__setItsDTSR(DTSR* const p_DTSR) {
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

void VisualEntity::_setItsDTSR(DTSR* const p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->__setItsVisualEntity(NULL);
        }
    __setItsDTSR(p_DTSR);
}

void VisualEntity::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedVisualEntity::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsDTSR", false, true);
    if(myReal->itsDTSR)
        {
            aomsRelations->ADD_ITEM(myReal->itsDTSR);
        }
}
//#]

IMPLEMENT_META_P(VisualEntity, Default, Default, false, OMAnimatedVisualEntity)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: component_3\DefaultConfig\VisualEntity.cpp
*********************************************************************/
