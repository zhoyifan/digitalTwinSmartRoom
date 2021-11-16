
############# Target type (Debug/Release) ##################
############################################################
CPPCompileDebug= /Zi /Od /D "_DEBUG" $(LIBCRT_FLAG)d  /Fd"$(TARGET_NAME)" 
CPPCompileRelease= /Ox /D"NDEBUG" $(LIBCRT_FLAG) /Fd"$(TARGET_NAME)" 
LinkDebug=
LinkRelease=
BuildSet=Debug
SUBSYSTEM=/SUBSYSTEM:console
RPFrameWorkDll=False
SimulinkLibName=

ConfigurationCPPCompileSwitches=   /I . /I . /I $(OMROOT)\LangCpp /I $(OMROOT)\LangCpp\oxf /nologo /W3 $(ENABLE_EH) $(CRT_FLAGS) $(CPPCompileDebug) /D "_AFXDLL" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "_WINDOWS" $(INST_FLAGS) $(INCLUDE_PATH) $(INST_INCLUDES) /c   

SIMULINK_CONFIG=False
!IF "$(SIMULINK_CONFIG)" == "True"
ConfigurationCPPCompileSwitches=$(ConfigurationCPPCompileSwitches) /D "OM_WITH_CLEANUP"
!ENDIF


!IF "$(RPFrameWorkDll)" == "True"
ConfigurationCPPCompileSwitches=$(ConfigurationCPPCompileSwitches) /D "FRAMEWORK_DLL"
!ENDIF

################### Compilation flags ######################
############################################################
INCLUDE_QUALIFIER=/I
DEFINE_QUALIFIER=/D

!IF "False" == "True"
MT_PREFIX=MT
LIBCRT_FLAG=/MT
!ELSE
MT_PREFIX=
LIBCRT_FLAG=/MD
!ENDIF

LIB_PREFIX=MSVC15x86$(MT_PREFIX)

CRT_FLAGS=$(DEFINE_QUALIFIER)_CRT_SECURE_NO_DEPRECATE $(DEFINE_QUALIFIER)_CRT_SECURE_NO_WARNINGS
ENABLE_EH=/EHa

WINMM_LIB=winmm.lib

################### Commands definition #########################
#################################################################
RMDIR = rmdir
LIB_CMD=link.exe -lib
LINK_CMD=link.exe
LIB_FLAGS=$(LinkDebug)  /NOLOGO   
LINK_FLAGS=$(LinkDebug)  /NOLOGO    $(SUBSYSTEM) /MACHINE:x86 

############### Generated macros #################
##################################################

FLAGSFILE=
RULESFILE=
OMROOT="C:\Program Files (x86)\IBM\Rhapsody\9.0\Share"
RHPROOT="C:\Program Files (x86)\IBM\Rhapsody\9.0"
FRAMEWORK_LIB_ROOT="C:\ProgramData\IBM\Rhapsody\9.0\UserShare"

CPP_EXT=.cpp
H_EXT=.h
OBJ_EXT=.obj
EXE_EXT=.exe
LIB_EXT=.lib

INSTRUMENTATION=Animation

TIME_MODEL=RealTime

TARGET_TYPE=Executable

TARGET_NAME=component_3

all : $(TARGET_NAME)$(EXE_EXT) component_3.mak

TARGET_MAIN=Maincomponent_3

LIBS= \
  ws2_32.lib \
  WSOCK32.LIB

INCLUDE_PATH= \
  $(INCLUDE_QUALIFIER)$(OMROOT)/LangCpp/osconfig/WIN32

ADDITIONAL_OBJS=

OBJS= \
  FireAlarm.obj \
  a.obj \
  FireSensor.obj \
  HVAC.obj \
  TemperatureSensor.obj \
  CO2Sensor.obj \
  AirConditioner.obj \
  Ventilation.obj \
  IntelligentLamp.obj \
  AVSystem.obj \
  TouchPanel.obj \
  SASystem.obj \
  Interconnection.obj \
  EnvironMent.obj \
  Weather.obj \
  Temperature.obj \
  ExternalLighting.obj \
  VisualEntity.obj \
  UCHVACBlk.obj \
  UCDynamicLightingBlk.obj \
  UCFireBlk.obj \
  GUI.obj \
  Interaction.obj \
  SoftwareController.obj \
  DTSR.obj \
  MovementDetectionSensor.obj \
  OccupancySensor.obj \
  User.obj \
  Default.obj \
  Structure.obj \
  ActorPkg.obj \
  UcHVACPkg.obj \
  UcLightingPkg.obj \
  UcFirePkg.obj




OBJ_DIR=

!IF "$(OBJ_DIR)"!=""
CREATE_OBJ_DIR=if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
CLEAN_OBJ_DIR= if exist $(OBJ_DIR) $(RMDIR) $(OBJ_DIR)
!ELSE
CREATE_OBJ_DIR=
CLEAN_OBJ_DIR=
!ENDIF

######################## Predefined macros ############################
#######################################################################
!IF "$(OBJS)" != ""
$(OBJS) : $(INST_LIBS) $(OXF_LIBS)
!ENDIF

LIB_POSTFIX=
!IF "$(BuildSet)"=="Release"
LIB_POSTFIX=R
!ENDIF

!IF "$(TARGET_TYPE)" == "Executable"
LinkDebug=$(LinkDebug) /DEBUG
LinkRelease=$(LinkRelease) /OPT:NOREF
!ELSEIF "$(TARGET_TYPE)" == "Library"
LinkDebug=$(LinkDebug)
!ENDIF


!IF "$(INSTRUMENTATION)" == "Animation"
INST_FLAGS=/D "OMANIMATOR"
INST_INCLUDES=/I $(OMROOT)\LangCpp\aom /I $(OMROOT)\LangCpp\tom
!IF "$(RPFrameWorkDll)" == "True"
INST_LIBS= 
OXF_LIBS=$(OMROOT)\LangCpp\lib\$(LIB_PREFIX)oxfanimdll$(LIB_POSTFIX)$(LIB_EXT) 
!ELSE
INST_LIBS= $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)aomanim$(LIB_POSTFIX)$(LIB_EXT) $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxsiminst$(LIB_POSTFIX)$(LIB_EXT)
OXF_LIBS=$(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxfinst$(LIB_POSTFIX)$(LIB_EXT) $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)omComAppl$(LIB_POSTFIX)$(LIB_EXT) $(SimulinkLibName)
!ENDIF
SOCK_LIB=wsock32.lib

!ELSEIF "$(INSTRUMENTATION)" == "Tracing"
INST_FLAGS=/D "OMTRACER"
INST_INCLUDES=/I $(OMROOT)\LangCpp\aom /I $(OMROOT)\LangCpp\tom
!IF "$(RPFrameWorkDll)" == "True"
INST_LIBS=
OXF_LIBS= $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxftracedll$(LIB_POSTFIX)$(LIB_EXT) 
!ELSE
INST_LIBS=$(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)tomtrace$(LIB_POSTFIX)$(LIB_EXT) $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)aomtrace$(LIB_POSTFIX)$(LIB_EXT) $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxsiminst$(LIB_POSTFIX)$(LIB_EXT)
OXF_LIBS= $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxfinst$(LIB_POSTFIX)$(LIB_EXT) $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)omComAppl$(LIB_POSTFIX)$(LIB_EXT) $(SimulinkLibName)
!ENDIF
SOCK_LIB=wsock32.lib

!ELSEIF "$(INSTRUMENTATION)" == "None" 
INST_FLAGS=
INST_INCLUDES=
INST_LIBS=
!IF "$(RPFrameWorkDll)" == "True"
OXF_LIBS=$(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxfdll$(LIB_POSTFIX)$(LIB_EXT) $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxsim$(LIB_POSTFIX)$(LIB_EXT)
!ELSE
OXF_LIBS=$(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxf$(LIB_POSTFIX)$(LIB_EXT) $(SimulinkLibName) $(FRAMEWORK_LIB_ROOT)\LangCpp\lib\$(LIB_PREFIX)oxsim$(LIB_POSTFIX)$(LIB_EXT)
!ENDIF
SOCK_LIB=

!ELSE
!ERROR An invalid Instrumentation $(INSTRUMENTATION) is specified.
!ENDIF



################## Generated dependencies ########################
##################################################################






FireAlarm.obj : FireAlarm.cpp FireAlarm.h    Default.h FireSensor.h HVAC.h Ventilation.h DTSR.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FireAlarm.obj" "FireAlarm.cpp" 



a.obj : a.cpp a.h    Default.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"a.obj" "a.cpp" 



FireSensor.obj : FireSensor.cpp FireSensor.h    Default.h FireAlarm.h HVAC.h DTSR.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FireSensor.obj" "FireSensor.cpp" 



HVAC.obj : HVAC.cpp HVAC.h    Default.h TemperatureSensor.h CO2Sensor.h FireSensor.h FireAlarm.h AirConditioner.h Ventilation.h DTSR.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"HVAC.obj" "HVAC.cpp" 



TemperatureSensor.obj : TemperatureSensor.cpp TemperatureSensor.h    Default.h HVAC.h AirConditioner.h DTSR.h OccupancySensor.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"TemperatureSensor.obj" "TemperatureSensor.cpp" 



CO2Sensor.obj : CO2Sensor.cpp CO2Sensor.h    Default.h HVAC.h Ventilation.h DTSR.h OccupancySensor.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"CO2Sensor.obj" "CO2Sensor.cpp" 



AirConditioner.obj : AirConditioner.cpp AirConditioner.h    Default.h HVAC.h TemperatureSensor.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"AirConditioner.obj" "AirConditioner.cpp" 



Ventilation.obj : Ventilation.cpp Ventilation.h    Default.h HVAC.h FireAlarm.h CO2Sensor.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Ventilation.obj" "Ventilation.cpp" 



IntelligentLamp.obj : IntelligentLamp.cpp IntelligentLamp.h    Default.h DTSR.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"IntelligentLamp.obj" "IntelligentLamp.cpp" 



AVSystem.obj : AVSystem.cpp AVSystem.h    Default.h DTSR.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"AVSystem.obj" "AVSystem.cpp" 



TouchPanel.obj : TouchPanel.cpp TouchPanel.h    Default.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"TouchPanel.obj" "TouchPanel.cpp" 



SASystem.obj : SASystem.cpp SASystem.h    Default.h DTSR.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"SASystem.obj" "SASystem.cpp" 



Interconnection.obj : Interconnection.cpp Interconnection.h    Default.h DTSR.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Interconnection.obj" "Interconnection.cpp" 



EnvironMent.obj : EnvironMent.cpp EnvironMent.h    Default.h Weather.h ExternalLighting.h Temperature.h DTSR.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"EnvironMent.obj" "EnvironMent.cpp" 



Weather.obj : Weather.cpp Weather.h    Default.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Weather.obj" "Weather.cpp" 



Temperature.obj : Temperature.cpp Temperature.h    Default.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Temperature.obj" "Temperature.cpp" 



ExternalLighting.obj : ExternalLighting.cpp ExternalLighting.h    Default.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ExternalLighting.obj" "ExternalLighting.cpp" 



VisualEntity.obj : VisualEntity.cpp VisualEntity.h    Default.h DTSR.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"VisualEntity.obj" "VisualEntity.cpp" 



UCHVACBlk.obj : UCHVACBlk.cpp UCHVACBlk.h    Default.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"UCHVACBlk.obj" "UCHVACBlk.cpp" 



UCDynamicLightingBlk.obj : UCDynamicLightingBlk.cpp UCDynamicLightingBlk.h    Default.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"UCDynamicLightingBlk.obj" "UCDynamicLightingBlk.cpp" 



UCFireBlk.obj : UCFireBlk.cpp UCFireBlk.h    Default.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"UCFireBlk.obj" "UCFireBlk.cpp" 



GUI.obj : GUI.cpp GUI.h    Default.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"GUI.obj" "GUI.cpp" 



Interaction.obj : Interaction.cpp Interaction.h    Default.h DTSR.h TouchPanel.h GUI.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Interaction.obj" "Interaction.cpp" 



SoftwareController.obj : SoftwareController.cpp SoftwareController.h    Default.h DTSR.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"SoftwareController.obj" "SoftwareController.cpp" 



DTSR.obj : DTSR.cpp DTSR.h    Default.h FireSensor.h User.h IntelligentLamp.h EnvironMent.h SASystem.h TemperatureSensor.h Interaction.h Interconnection.h CO2Sensor.h HVAC.h AVSystem.h FireAlarm.h MovementDetectionSensor.h OccupancySensor.h VisualEntity.h UCFireBlk.h UCHVACBlk.h UCDynamicLightingBlk.h SoftwareController.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"DTSR.obj" "DTSR.cpp" 



MovementDetectionSensor.obj : MovementDetectionSensor.cpp MovementDetectionSensor.h    Default.h DTSR.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"MovementDetectionSensor.obj" "MovementDetectionSensor.cpp" 



OccupancySensor.obj : OccupancySensor.cpp OccupancySensor.h    Default.h DTSR.h CO2Sensor.h TemperatureSensor.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"OccupancySensor.obj" "OccupancySensor.cpp" 



User.obj : User.cpp User.h    ActorPkg.h DTSR.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"User.obj" "User.cpp" 



Default.obj : Default.cpp Default.h    FireAlarm.h a.h FireSensor.h HVAC.h TemperatureSensor.h CO2Sensor.h AirConditioner.h Ventilation.h IntelligentLamp.h AVSystem.h TouchPanel.h SASystem.h Interconnection.h EnvironMent.h Weather.h Temperature.h ExternalLighting.h VisualEntity.h UCHVACBlk.h UCDynamicLightingBlk.h UCFireBlk.h GUI.h Interaction.h SoftwareController.h DTSR.h MovementDetectionSensor.h OccupancySensor.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Default.obj" "Default.cpp" 



Structure.obj : Structure.cpp Structure.h    
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Structure.obj" "Structure.cpp" 



ActorPkg.obj : ActorPkg.cpp ActorPkg.h    
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ActorPkg.obj" "ActorPkg.cpp" 



UcHVACPkg.obj : UcHVACPkg.cpp UcHVACPkg.h    
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"UcHVACPkg.obj" "UcHVACPkg.cpp" 



UcLightingPkg.obj : UcLightingPkg.cpp UcLightingPkg.h    
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"UcLightingPkg.obj" "UcLightingPkg.cpp" 



UcFirePkg.obj : UcFirePkg.cpp UcFirePkg.h    
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"UcFirePkg.obj" "UcFirePkg.cpp" 






$(TARGET_MAIN)$(OBJ_EXT) : $(TARGET_MAIN)$(CPP_EXT) $(OBJS) 
	$(CPP) $(ConfigurationCPPCompileSwitches) /Fo"$(TARGET_MAIN)$(OBJ_EXT)" $(TARGET_MAIN)$(CPP_EXT)

########################## Linking instructions ###############################
###############################################################################
$(TARGET_NAME)$(EXE_EXT): $(OBJS) $(ADDITIONAL_OBJS) $(TARGET_MAIN)$(OBJ_EXT) component_3.mak 
	@echo Linking $(TARGET_NAME)$(EXE_EXT)
	$(LINK_CMD)  $(TARGET_MAIN)$(OBJ_EXT) $(OBJS) $(ADDITIONAL_OBJS) \
	$(LIBS) \
	$(INST_LIBS) \
	$(OXF_LIBS) \
	$(SOCK_LIB) \
	$(WINMM_LIB) \
	$(LINK_FLAGS) /out:$(TARGET_NAME)$(EXE_EXT)
	if exist $(TARGET_NAME)$(EXE_EXT).manifest mt.exe -manifest $@.manifest -outputresource:$(TARGET_NAME)$(EXE_EXT);1



$(TARGET_NAME)$(LIB_EXT) : $(OBJS) $(ADDITIONAL_OBJS) component_3.mak
	@echo Building library $@
	$(LIB_CMD) $(LIB_FLAGS) /out:$(TARGET_NAME)$(LIB_EXT) $(OBJS) $(ADDITIONAL_OBJS) $(LIBS)

clean:
	@echo Cleanup
	if exist FireAlarm.obj erase FireAlarm.obj
	if exist a.obj erase a.obj
	if exist FireSensor.obj erase FireSensor.obj
	if exist HVAC.obj erase HVAC.obj
	if exist TemperatureSensor.obj erase TemperatureSensor.obj
	if exist CO2Sensor.obj erase CO2Sensor.obj
	if exist AirConditioner.obj erase AirConditioner.obj
	if exist Ventilation.obj erase Ventilation.obj
	if exist IntelligentLamp.obj erase IntelligentLamp.obj
	if exist AVSystem.obj erase AVSystem.obj
	if exist TouchPanel.obj erase TouchPanel.obj
	if exist SASystem.obj erase SASystem.obj
	if exist Interconnection.obj erase Interconnection.obj
	if exist EnvironMent.obj erase EnvironMent.obj
	if exist Weather.obj erase Weather.obj
	if exist Temperature.obj erase Temperature.obj
	if exist ExternalLighting.obj erase ExternalLighting.obj
	if exist VisualEntity.obj erase VisualEntity.obj
	if exist UCHVACBlk.obj erase UCHVACBlk.obj
	if exist UCDynamicLightingBlk.obj erase UCDynamicLightingBlk.obj
	if exist UCFireBlk.obj erase UCFireBlk.obj
	if exist GUI.obj erase GUI.obj
	if exist Interaction.obj erase Interaction.obj
	if exist SoftwareController.obj erase SoftwareController.obj
	if exist DTSR.obj erase DTSR.obj
	if exist MovementDetectionSensor.obj erase MovementDetectionSensor.obj
	if exist OccupancySensor.obj erase OccupancySensor.obj
	if exist User.obj erase User.obj
	if exist Default.obj erase Default.obj
	if exist Structure.obj erase Structure.obj
	if exist ActorPkg.obj erase ActorPkg.obj
	if exist UcHVACPkg.obj erase UcHVACPkg.obj
	if exist UcLightingPkg.obj erase UcLightingPkg.obj
	if exist UcFirePkg.obj erase UcFirePkg.obj
	if exist $(TARGET_MAIN)$(OBJ_EXT) erase $(TARGET_MAIN)$(OBJ_EXT)
	if exist *$(OBJ_EXT) erase *$(OBJ_EXT)
	if exist $(TARGET_NAME).pdb erase $(TARGET_NAME).pdb
	if exist $(TARGET_NAME)$(LIB_EXT) erase $(TARGET_NAME)$(LIB_EXT)
	if exist $(TARGET_NAME).ilk erase $(TARGET_NAME).ilk
	if exist $(TARGET_NAME)$(EXE_EXT) erase $(TARGET_NAME)$(EXE_EXT)
	if exist $(TARGET_NAME)$(EXE_EXT).manifest erase $(TARGET_NAME)$(EXE_EXT).manifest
	$(CLEAN_OBJ_DIR)
	
