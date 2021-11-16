/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: MovementDetectionSensor
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\MovementDetectionSensor.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "MovementDetectionSensor.h"
//## link itsDTSR
#include "DTSR.h"
//#[ ignore
#define Default_MovementDetectionSensor_MovementDetectionSensor_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class MovementDetectionSensor
MovementDetectionSensor::MovementDetectionSensor(void) : itsDTSR(NULL) {
    NOTIFY_CONSTRUCTOR(MovementDetectionSensor, MovementDetectionSensor(), 0, Default_MovementDetectionSensor_MovementDetectionSensor_SERIALIZE);
}

MovementDetectionSensor::~MovementDetectionSensor(void) {
    NOTIFY_DESTRUCTOR(~MovementDetectionSensor, true);
    cleanUpRelations();
}

const DTSR* MovementDetectionSensor::getItsDTSR(void) const {
    return itsDTSR;
}

void MovementDetectionSensor::setItsDTSR(DTSR* const p_DTSR) {
    if(p_DTSR != NULL)
        {
            p_DTSR->_setItsMovementDetectionSensor(this);
        }
    _setItsDTSR(p_DTSR);
}

void MovementDetectionSensor::cleanUpRelations(void) {
    if(itsDTSR != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDTSR");
            const MovementDetectionSensor* p_MovementDetectionSensor = itsDTSR->getItsMovementDetectionSensor();
            if(p_MovementDetectionSensor != NULL)
                {
                    itsDTSR->__setItsMovementDetectionSensor(NULL);
                }
            itsDTSR = NULL;
        }
}

void MovementDetectionSensor::__setItsDTSR(DTSR* const p_DTSR) {
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

void MovementDetectionSensor::_setItsDTSR(DTSR* const p_DTSR) {
    if(itsDTSR != NULL)
        {
            itsDTSR->__setItsMovementDetectionSensor(NULL);
        }
    __setItsDTSR(p_DTSR);
}

void MovementDetectionSensor::_clearItsDTSR(void) {
    NOTIFY_RELATION_CLEARED("itsDTSR");
    itsDTSR = NULL;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedMovementDetectionSensor::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsDTSR", false, true);
    if(myReal->itsDTSR)
        {
            aomsRelations->ADD_ITEM(myReal->itsDTSR);
        }
}
//#]

IMPLEMENT_META_P(MovementDetectionSensor, Default, Default, false, OMAnimatedMovementDetectionSensor)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\MovementDetectionSensor.cpp
*********************************************************************/
