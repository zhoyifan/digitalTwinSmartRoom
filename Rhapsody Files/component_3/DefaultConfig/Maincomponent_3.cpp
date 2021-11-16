/********************************************************************
	Rhapsody	: 9.0 
	Login		: legion
	Component	: component_3 
	Configuration 	: DefaultConfig
	Model Element	: DefaultConfig
//!	Generated Date	: Sat, 10, Jul 2021  
	File Path	: component_3\DefaultConfig\Maincomponent_3.cpp
*********************************************************************/

//## auto_generated
#include "Maincomponent_3.h"
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
component_3::component_3(void) {
    Default_initRelations();
    (void) Default_startBehavior();
}

RhpInteger main( void) {
    RhpInteger status = 0;
    try {
        if(OXF::initialize(0,NULL))
            {
                component_3 initializer_component_3;
                //#[ configuration component_3::DefaultConfig 
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
	File Path	: component_3\DefaultConfig\Maincomponent_3.cpp
*********************************************************************/
