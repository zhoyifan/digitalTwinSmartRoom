/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: DefaultConfig
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: DefaultComponent\DefaultConfig\MainDefaultComponent.cpp
*********************************************************************/

//## auto_generated
#include "MainDefaultComponent.h"
//## auto_generated
#include "ActorPkg.h"
//## auto_generated
#include "Default.h"
//## auto_generated
#include "Structure.h"
//## auto_generated
#include "UcFirePkg.h"
//## auto_generated
#include "UcHVACPkg.h"
//## auto_generated
#include "UcLightingPkg.h"
DefaultComponent::DefaultComponent(void) {
    Default_initRelations();
    (void) Default_startBehavior();
}

RhpInteger main( void) {
    RhpInteger status = 0;
    try {
        if(OXF::initialize(0,NULL))
            {
                DefaultComponent initializer_DefaultComponent;
                //#[ configuration DefaultComponent::DefaultConfig 
                //#]
                OXF::start();
                status = 0;
            }
        else
            {
                status = 1;
            }
    }
    catch (...)
    {
        status = 0;
    }
    return status;
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\MainDefaultComponent.cpp
*********************************************************************/
