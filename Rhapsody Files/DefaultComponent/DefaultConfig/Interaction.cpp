/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Interaction
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\Interaction.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Interaction.h"
//## link itsDTSR
#include "DTSR.h"
//#[ ignore
#define Default_Interaction_Interaction_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Interaction
Interaction::Interaction(void) : TouchPanel(), GUI(), itsDTSR(NULL) {
    NOTIFY_CONSTRUCTOR(Interaction, Interaction(), 0, Default_Interaction_Interaction_SERIALIZE);
}

Interaction::~Interaction(void) {
    NOTIFY_DESTRUCTOR(~Interaction, false);
    cleanUpRelations();
}

const DTSR* Interaction::getItsDTSR(void) const {
    return itsDTSR;
}

void Interaction::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_setItsInteraction(this);
        }
    _setItsDTSR(p_DTSR);
}

void Interaction::cleanUpRelations(void) {
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            const Interaction* p_Interaction = itsDTSR->getItsInteraction();
            if(p_Interaction != NULL)
                {
                    itsDTSR->__setItsInteraction(NULL);
                }
            itsDTSR = NULL;
        }
}

void Interaction::__setItsDTSR(DTSR* const p_DTSR) {
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

void Interaction::_setItsDTSR(DTSR* const p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->__setItsInteraction(NULL);
        }
    __setItsDTSR(p_DTSR);
}

void Interaction::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedInteraction::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    OMAnimatedTouchPanel::serializeAttributes(aomsAttributes);
    OMAnimatedGUI::serializeAttributes(aomsAttributes);
}

void OMAnimatedInteraction::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsDTSR", false, true);
    if(myReal->itsDTSR)
        {
            aomsRelations->ADD_ITEM(myReal->itsDTSR);
        }
    OMAnimatedTouchPanel::serializeRelations(aomsRelations);
    OMAnimatedGUI::serializeRelations(aomsRelations);
}

static AOMClass* _InteractionSuper[2] = {
OMAnimatedTouchPanel::staticGetClass(),
OMAnimatedGUI::staticGetClass()};
//#]

IMPLEMENT_META_M_P(Interaction, Default, false, _InteractionSuper, 2, OMAnimatedInteraction)

OMINIT_SUPERCLASS(TouchPanel, OMAnimatedTouchPanel)

OMINIT_SUPERCLASS(GUI, OMAnimatedGUI)

OMREGISTER_CLASS
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Interaction.cpp
*********************************************************************/
