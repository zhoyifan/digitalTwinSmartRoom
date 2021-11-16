/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: SoftwareController
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\SoftwareController.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "SoftwareController.h"
//## link itsDTSR
#include "DTSR.h"
//#[ ignore
#define Default_SoftwareController_SoftwareController_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class SoftwareController
SoftwareController::SoftwareController(void) : itsDTSR(NULL) {
    NOTIFY_CONSTRUCTOR(SoftwareController, SoftwareController(), 0, Default_SoftwareController_SoftwareController_SERIALIZE);
}

SoftwareController::~SoftwareController(void) {
    NOTIFY_DESTRUCTOR(~SoftwareController, true);
    cleanUpRelations();
}

const DTSR* SoftwareController::getItsDTSR(void) const {
    return itsDTSR;
}

void SoftwareController::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_setItsSoftwareController(this);
        }
    _setItsDTSR(p_DTSR);
}

void SoftwareController::cleanUpRelations(void) {
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            const SoftwareController* p_SoftwareController = itsDTSR->getItsSoftwareController();
            if(p_SoftwareController != NULL)
                {
                    itsDTSR->__setItsSoftwareController(NULL);
                }
            itsDTSR = NULL;
        }
}

void SoftwareController::__setItsDTSR(DTSR* const p_DTSR) {
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

void SoftwareController::_setItsDTSR(DTSR* const p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->__setItsSoftwareController(NULL);
        }
    __setItsDTSR(p_DTSR);
}

void SoftwareController::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedSoftwareController::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsDTSR", false, true);
    if(myReal->itsDTSR)
        {
            aomsRelations->ADD_ITEM(myReal->itsDTSR);
        }
}
//#]

IMPLEMENT_META_P(SoftwareController, Default, Default, false, OMAnimatedSoftwareController)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: component_3\DefaultConfig\SoftwareController.cpp
*********************************************************************/
