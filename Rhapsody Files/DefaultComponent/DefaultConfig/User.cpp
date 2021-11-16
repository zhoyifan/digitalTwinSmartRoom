/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: User
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\User.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "User.h"
//## link itsDTSR
#include "DTSR.h"
//#[ ignore
#define ActorPkg_User_User_SERIALIZE OM_NO_OP
//#]

//## package ActorPkg

//## actor User
User::User(void) : itsDTSR(NULL) {
    NOTIFY_CONSTRUCTOR(User, User(), 0, ActorPkg_User_User_SERIALIZE);
}

User::~User(void) {
    NOTIFY_DESTRUCTOR(~User, true);
    cleanUpRelations();
}

const DTSR* User::getItsDTSR(void) const {
    return itsDTSR;
}

void User::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_setItsUser(this);
        }
    _setItsDTSR(p_DTSR);
}

void User::cleanUpRelations(void) {
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            const User* p_User = itsDTSR->getItsUser();
            if(p_User != NULL)
                {
                    itsDTSR->__setItsUser(NULL);
                }
            itsDTSR = NULL;
        }
}

void User::__setItsDTSR(DTSR* const p_DTSR) {
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

void User::_setItsDTSR(DTSR* const p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->__setItsUser(NULL);
        }
    __setItsDTSR(p_DTSR);
}

void User::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedUser::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsDTSR", false, true);
    if(myReal->itsDTSR)
        {
            aomsRelations->ADD_ITEM(myReal->itsDTSR);
        }
}
//#]

IMPLEMENT_META_P(User, ActorPkg, ActorPkg, false, OMAnimatedUser)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\User.cpp
*********************************************************************/
