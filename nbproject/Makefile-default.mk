#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Alex46_HelloKit.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Alex46_HelloKit.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c leds.c DIO.c buttons.c output_devices.c mkeypad.c mLCD.c mlcd4.c mINT.c mADC.c mTimer.c mUART.c mSPI.c EEPROM_SPI.c mTWI.c EEPROM_TWI.c EEPROM_INTERFACE.c _7SEGMENT.c freertos/croutine.c freertos/event_groups.c freertos/heap_4.c freertos/list.c freertos/port.c freertos/queue.c freertos/stream_buffer.c freertos/tasks.c freertos/timers.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/leds.o ${OBJECTDIR}/DIO.o ${OBJECTDIR}/buttons.o ${OBJECTDIR}/output_devices.o ${OBJECTDIR}/mkeypad.o ${OBJECTDIR}/mLCD.o ${OBJECTDIR}/mlcd4.o ${OBJECTDIR}/mINT.o ${OBJECTDIR}/mADC.o ${OBJECTDIR}/mTimer.o ${OBJECTDIR}/mUART.o ${OBJECTDIR}/mSPI.o ${OBJECTDIR}/EEPROM_SPI.o ${OBJECTDIR}/mTWI.o ${OBJECTDIR}/EEPROM_TWI.o ${OBJECTDIR}/EEPROM_INTERFACE.o ${OBJECTDIR}/_7SEGMENT.o ${OBJECTDIR}/freertos/croutine.o ${OBJECTDIR}/freertos/event_groups.o ${OBJECTDIR}/freertos/heap_4.o ${OBJECTDIR}/freertos/list.o ${OBJECTDIR}/freertos/port.o ${OBJECTDIR}/freertos/queue.o ${OBJECTDIR}/freertos/stream_buffer.o ${OBJECTDIR}/freertos/tasks.o ${OBJECTDIR}/freertos/timers.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/leds.o.d ${OBJECTDIR}/DIO.o.d ${OBJECTDIR}/buttons.o.d ${OBJECTDIR}/output_devices.o.d ${OBJECTDIR}/mkeypad.o.d ${OBJECTDIR}/mLCD.o.d ${OBJECTDIR}/mlcd4.o.d ${OBJECTDIR}/mINT.o.d ${OBJECTDIR}/mADC.o.d ${OBJECTDIR}/mTimer.o.d ${OBJECTDIR}/mUART.o.d ${OBJECTDIR}/mSPI.o.d ${OBJECTDIR}/EEPROM_SPI.o.d ${OBJECTDIR}/mTWI.o.d ${OBJECTDIR}/EEPROM_TWI.o.d ${OBJECTDIR}/EEPROM_INTERFACE.o.d ${OBJECTDIR}/_7SEGMENT.o.d ${OBJECTDIR}/freertos/croutine.o.d ${OBJECTDIR}/freertos/event_groups.o.d ${OBJECTDIR}/freertos/heap_4.o.d ${OBJECTDIR}/freertos/list.o.d ${OBJECTDIR}/freertos/port.o.d ${OBJECTDIR}/freertos/queue.o.d ${OBJECTDIR}/freertos/stream_buffer.o.d ${OBJECTDIR}/freertos/tasks.o.d ${OBJECTDIR}/freertos/timers.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/leds.o ${OBJECTDIR}/DIO.o ${OBJECTDIR}/buttons.o ${OBJECTDIR}/output_devices.o ${OBJECTDIR}/mkeypad.o ${OBJECTDIR}/mLCD.o ${OBJECTDIR}/mlcd4.o ${OBJECTDIR}/mINT.o ${OBJECTDIR}/mADC.o ${OBJECTDIR}/mTimer.o ${OBJECTDIR}/mUART.o ${OBJECTDIR}/mSPI.o ${OBJECTDIR}/EEPROM_SPI.o ${OBJECTDIR}/mTWI.o ${OBJECTDIR}/EEPROM_TWI.o ${OBJECTDIR}/EEPROM_INTERFACE.o ${OBJECTDIR}/_7SEGMENT.o ${OBJECTDIR}/freertos/croutine.o ${OBJECTDIR}/freertos/event_groups.o ${OBJECTDIR}/freertos/heap_4.o ${OBJECTDIR}/freertos/list.o ${OBJECTDIR}/freertos/port.o ${OBJECTDIR}/freertos/queue.o ${OBJECTDIR}/freertos/stream_buffer.o ${OBJECTDIR}/freertos/tasks.o ${OBJECTDIR}/freertos/timers.o

# Source Files
SOURCEFILES=main.c leds.c DIO.c buttons.c output_devices.c mkeypad.c mLCD.c mlcd4.c mINT.c mADC.c mTimer.c mUART.c mSPI.c EEPROM_SPI.c mTWI.c EEPROM_TWI.c EEPROM_INTERFACE.c _7SEGMENT.c freertos/croutine.c freertos/event_groups.c freertos/heap_4.c freertos/list.c freertos/port.c freertos/queue.c freertos/stream_buffer.c freertos/tasks.c freertos/timers.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Alex46_HelloKit.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega32A
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/31a6eab2c8bb4aa8ed61f97b2062279674fb5725 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/leds.o: leds.c  .generated_files/flags/default/804ed7f59127dd2c9f48942f3cef19d02c03c657 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/leds.o.d 
	@${RM} ${OBJECTDIR}/leds.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/leds.o.d" -MT "${OBJECTDIR}/leds.o.d" -MT ${OBJECTDIR}/leds.o -o ${OBJECTDIR}/leds.o leds.c 
	
${OBJECTDIR}/DIO.o: DIO.c  .generated_files/flags/default/2905774e3c598be2f0b3fb5f234130cee0fe8f8c .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DIO.o.d 
	@${RM} ${OBJECTDIR}/DIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/DIO.o.d" -MT "${OBJECTDIR}/DIO.o.d" -MT ${OBJECTDIR}/DIO.o -o ${OBJECTDIR}/DIO.o DIO.c 
	
${OBJECTDIR}/buttons.o: buttons.c  .generated_files/flags/default/6ffb57836e752cc9229f5a6cf8455437a7cf4682 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buttons.o.d 
	@${RM} ${OBJECTDIR}/buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/buttons.o.d" -MT "${OBJECTDIR}/buttons.o.d" -MT ${OBJECTDIR}/buttons.o -o ${OBJECTDIR}/buttons.o buttons.c 
	
${OBJECTDIR}/output_devices.o: output_devices.c  .generated_files/flags/default/23bdbe41d67177fa42d868781111a2bff797005a .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/output_devices.o.d 
	@${RM} ${OBJECTDIR}/output_devices.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/output_devices.o.d" -MT "${OBJECTDIR}/output_devices.o.d" -MT ${OBJECTDIR}/output_devices.o -o ${OBJECTDIR}/output_devices.o output_devices.c 
	
${OBJECTDIR}/mkeypad.o: mkeypad.c  .generated_files/flags/default/fc29e17ad7f43e8860884751b605692db4f67575 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mkeypad.o.d 
	@${RM} ${OBJECTDIR}/mkeypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mkeypad.o.d" -MT "${OBJECTDIR}/mkeypad.o.d" -MT ${OBJECTDIR}/mkeypad.o -o ${OBJECTDIR}/mkeypad.o mkeypad.c 
	
${OBJECTDIR}/mLCD.o: mLCD.c  .generated_files/flags/default/8023f59ec39c493e4b5447dc2bec8f3e5c95af4e .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mLCD.o.d 
	@${RM} ${OBJECTDIR}/mLCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mLCD.o.d" -MT "${OBJECTDIR}/mLCD.o.d" -MT ${OBJECTDIR}/mLCD.o -o ${OBJECTDIR}/mLCD.o mLCD.c 
	
${OBJECTDIR}/mlcd4.o: mlcd4.c  .generated_files/flags/default/cfad8ac43a5c77c75ee59741c7e0dc9d0a2a0b46 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mlcd4.o.d 
	@${RM} ${OBJECTDIR}/mlcd4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mlcd4.o.d" -MT "${OBJECTDIR}/mlcd4.o.d" -MT ${OBJECTDIR}/mlcd4.o -o ${OBJECTDIR}/mlcd4.o mlcd4.c 
	
${OBJECTDIR}/mINT.o: mINT.c  .generated_files/flags/default/2b76cd0f45c6a1ce17b0e7869a9061265a485c83 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mINT.o.d 
	@${RM} ${OBJECTDIR}/mINT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mINT.o.d" -MT "${OBJECTDIR}/mINT.o.d" -MT ${OBJECTDIR}/mINT.o -o ${OBJECTDIR}/mINT.o mINT.c 
	
${OBJECTDIR}/mADC.o: mADC.c  .generated_files/flags/default/a04eae281bbf75808f8ef041e3e06a6f0dd3122e .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mADC.o.d 
	@${RM} ${OBJECTDIR}/mADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mADC.o.d" -MT "${OBJECTDIR}/mADC.o.d" -MT ${OBJECTDIR}/mADC.o -o ${OBJECTDIR}/mADC.o mADC.c 
	
${OBJECTDIR}/mTimer.o: mTimer.c  .generated_files/flags/default/b971d05a48d2cdf9ff69a145ad189e05f9b0846f .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mTimer.o.d 
	@${RM} ${OBJECTDIR}/mTimer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mTimer.o.d" -MT "${OBJECTDIR}/mTimer.o.d" -MT ${OBJECTDIR}/mTimer.o -o ${OBJECTDIR}/mTimer.o mTimer.c 
	
${OBJECTDIR}/mUART.o: mUART.c  .generated_files/flags/default/71077b1d8118afbc934405edd19e1eeb938a939c .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mUART.o.d 
	@${RM} ${OBJECTDIR}/mUART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mUART.o.d" -MT "${OBJECTDIR}/mUART.o.d" -MT ${OBJECTDIR}/mUART.o -o ${OBJECTDIR}/mUART.o mUART.c 
	
${OBJECTDIR}/mSPI.o: mSPI.c  .generated_files/flags/default/ca15aba41d911d05bce4b1a5352d30ccfc8b52ac .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mSPI.o.d 
	@${RM} ${OBJECTDIR}/mSPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mSPI.o.d" -MT "${OBJECTDIR}/mSPI.o.d" -MT ${OBJECTDIR}/mSPI.o -o ${OBJECTDIR}/mSPI.o mSPI.c 
	
${OBJECTDIR}/EEPROM_SPI.o: EEPROM_SPI.c  .generated_files/flags/default/618f600bf4600ccc0da43c7e3cbe17657de24e2b .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EEPROM_SPI.o.d 
	@${RM} ${OBJECTDIR}/EEPROM_SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/EEPROM_SPI.o.d" -MT "${OBJECTDIR}/EEPROM_SPI.o.d" -MT ${OBJECTDIR}/EEPROM_SPI.o -o ${OBJECTDIR}/EEPROM_SPI.o EEPROM_SPI.c 
	
${OBJECTDIR}/mTWI.o: mTWI.c  .generated_files/flags/default/80671be07bf558c9086daaec1f518411dceb795a .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mTWI.o.d 
	@${RM} ${OBJECTDIR}/mTWI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mTWI.o.d" -MT "${OBJECTDIR}/mTWI.o.d" -MT ${OBJECTDIR}/mTWI.o -o ${OBJECTDIR}/mTWI.o mTWI.c 
	
${OBJECTDIR}/EEPROM_TWI.o: EEPROM_TWI.c  .generated_files/flags/default/dad8a950d48383f9fd7de265e10b6df95de20795 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EEPROM_TWI.o.d 
	@${RM} ${OBJECTDIR}/EEPROM_TWI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/EEPROM_TWI.o.d" -MT "${OBJECTDIR}/EEPROM_TWI.o.d" -MT ${OBJECTDIR}/EEPROM_TWI.o -o ${OBJECTDIR}/EEPROM_TWI.o EEPROM_TWI.c 
	
${OBJECTDIR}/EEPROM_INTERFACE.o: EEPROM_INTERFACE.c  .generated_files/flags/default/500d68d031c0c2a7e66e422a910e3a5284b29021 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EEPROM_INTERFACE.o.d 
	@${RM} ${OBJECTDIR}/EEPROM_INTERFACE.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/EEPROM_INTERFACE.o.d" -MT "${OBJECTDIR}/EEPROM_INTERFACE.o.d" -MT ${OBJECTDIR}/EEPROM_INTERFACE.o -o ${OBJECTDIR}/EEPROM_INTERFACE.o EEPROM_INTERFACE.c 
	
${OBJECTDIR}/_7SEGMENT.o: _7SEGMENT.c  .generated_files/flags/default/efd71ab13e28e8008cd602bba54470ed31b1d6bc .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/_7SEGMENT.o.d 
	@${RM} ${OBJECTDIR}/_7SEGMENT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_7SEGMENT.o.d" -MT "${OBJECTDIR}/_7SEGMENT.o.d" -MT ${OBJECTDIR}/_7SEGMENT.o -o ${OBJECTDIR}/_7SEGMENT.o _7SEGMENT.c 
	
${OBJECTDIR}/freertos/croutine.o: freertos/croutine.c  .generated_files/flags/default/a747d24f0fcb9e6e78ab996c96f217cb97abf7ba .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/croutine.o.d 
	@${RM} ${OBJECTDIR}/freertos/croutine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/croutine.o.d" -MT "${OBJECTDIR}/freertos/croutine.o.d" -MT ${OBJECTDIR}/freertos/croutine.o -o ${OBJECTDIR}/freertos/croutine.o freertos/croutine.c 
	
${OBJECTDIR}/freertos/event_groups.o: freertos/event_groups.c  .generated_files/flags/default/ca1c8693877df61a258227fbd6d84392c33d0002 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/event_groups.o.d 
	@${RM} ${OBJECTDIR}/freertos/event_groups.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/event_groups.o.d" -MT "${OBJECTDIR}/freertos/event_groups.o.d" -MT ${OBJECTDIR}/freertos/event_groups.o -o ${OBJECTDIR}/freertos/event_groups.o freertos/event_groups.c 
	
${OBJECTDIR}/freertos/heap_4.o: freertos/heap_4.c  .generated_files/flags/default/302229dd8f25c6b7c7e38afcb882b3870f952588 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/heap_4.o.d 
	@${RM} ${OBJECTDIR}/freertos/heap_4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/heap_4.o.d" -MT "${OBJECTDIR}/freertos/heap_4.o.d" -MT ${OBJECTDIR}/freertos/heap_4.o -o ${OBJECTDIR}/freertos/heap_4.o freertos/heap_4.c 
	
${OBJECTDIR}/freertos/list.o: freertos/list.c  .generated_files/flags/default/e1fac6d276b3f22532865f1615c12ea593eceec4 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/list.o.d 
	@${RM} ${OBJECTDIR}/freertos/list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/list.o.d" -MT "${OBJECTDIR}/freertos/list.o.d" -MT ${OBJECTDIR}/freertos/list.o -o ${OBJECTDIR}/freertos/list.o freertos/list.c 
	
${OBJECTDIR}/freertos/port.o: freertos/port.c  .generated_files/flags/default/4aaaa828b36c0cd66c2243c692d2944d11c01034 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/port.o.d 
	@${RM} ${OBJECTDIR}/freertos/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/port.o.d" -MT "${OBJECTDIR}/freertos/port.o.d" -MT ${OBJECTDIR}/freertos/port.o -o ${OBJECTDIR}/freertos/port.o freertos/port.c 
	
${OBJECTDIR}/freertos/queue.o: freertos/queue.c  .generated_files/flags/default/c415bf2f06c914c887765265d1fee13e4e93e160 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/queue.o.d 
	@${RM} ${OBJECTDIR}/freertos/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/queue.o.d" -MT "${OBJECTDIR}/freertos/queue.o.d" -MT ${OBJECTDIR}/freertos/queue.o -o ${OBJECTDIR}/freertos/queue.o freertos/queue.c 
	
${OBJECTDIR}/freertos/stream_buffer.o: freertos/stream_buffer.c  .generated_files/flags/default/39bd90ef92a7629a382011fef75470108af11a8a .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/freertos/stream_buffer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/stream_buffer.o.d" -MT "${OBJECTDIR}/freertos/stream_buffer.o.d" -MT ${OBJECTDIR}/freertos/stream_buffer.o -o ${OBJECTDIR}/freertos/stream_buffer.o freertos/stream_buffer.c 
	
${OBJECTDIR}/freertos/tasks.o: freertos/tasks.c  .generated_files/flags/default/2f898989e7f499bf26b4efe4ebca60fc483e26bc .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/tasks.o.d 
	@${RM} ${OBJECTDIR}/freertos/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/tasks.o.d" -MT "${OBJECTDIR}/freertos/tasks.o.d" -MT ${OBJECTDIR}/freertos/tasks.o -o ${OBJECTDIR}/freertos/tasks.o freertos/tasks.c 
	
${OBJECTDIR}/freertos/timers.o: freertos/timers.c  .generated_files/flags/default/e04e058f7e0bcf9d21bca83b0664b3e828a91be6 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/timers.o.d 
	@${RM} ${OBJECTDIR}/freertos/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/timers.o.d" -MT "${OBJECTDIR}/freertos/timers.o.d" -MT ${OBJECTDIR}/freertos/timers.o -o ${OBJECTDIR}/freertos/timers.o freertos/timers.c 
	
else
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/69a3054bcb2b07983865e49f9810088d9fdbe8e .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/leds.o: leds.c  .generated_files/flags/default/6dc72ec078eebba9d5ed50ca2bd6077877a19a29 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/leds.o.d 
	@${RM} ${OBJECTDIR}/leds.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/leds.o.d" -MT "${OBJECTDIR}/leds.o.d" -MT ${OBJECTDIR}/leds.o -o ${OBJECTDIR}/leds.o leds.c 
	
${OBJECTDIR}/DIO.o: DIO.c  .generated_files/flags/default/a48d2f07a131a6a5f862a0d876241f8b2f01f42a .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DIO.o.d 
	@${RM} ${OBJECTDIR}/DIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/DIO.o.d" -MT "${OBJECTDIR}/DIO.o.d" -MT ${OBJECTDIR}/DIO.o -o ${OBJECTDIR}/DIO.o DIO.c 
	
${OBJECTDIR}/buttons.o: buttons.c  .generated_files/flags/default/1f9788aa9678b710a8f3e673251c8d494b6bef65 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buttons.o.d 
	@${RM} ${OBJECTDIR}/buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/buttons.o.d" -MT "${OBJECTDIR}/buttons.o.d" -MT ${OBJECTDIR}/buttons.o -o ${OBJECTDIR}/buttons.o buttons.c 
	
${OBJECTDIR}/output_devices.o: output_devices.c  .generated_files/flags/default/23a950b8ef316ac560a269fdf409d1da468bd0 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/output_devices.o.d 
	@${RM} ${OBJECTDIR}/output_devices.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/output_devices.o.d" -MT "${OBJECTDIR}/output_devices.o.d" -MT ${OBJECTDIR}/output_devices.o -o ${OBJECTDIR}/output_devices.o output_devices.c 
	
${OBJECTDIR}/mkeypad.o: mkeypad.c  .generated_files/flags/default/ed5f1faca73d1e5ac0680b6bdfe1d3b2cd3d0bab .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mkeypad.o.d 
	@${RM} ${OBJECTDIR}/mkeypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mkeypad.o.d" -MT "${OBJECTDIR}/mkeypad.o.d" -MT ${OBJECTDIR}/mkeypad.o -o ${OBJECTDIR}/mkeypad.o mkeypad.c 
	
${OBJECTDIR}/mLCD.o: mLCD.c  .generated_files/flags/default/6aeb8b56795ca7c4a6e871865a2bb3114117799 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mLCD.o.d 
	@${RM} ${OBJECTDIR}/mLCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mLCD.o.d" -MT "${OBJECTDIR}/mLCD.o.d" -MT ${OBJECTDIR}/mLCD.o -o ${OBJECTDIR}/mLCD.o mLCD.c 
	
${OBJECTDIR}/mlcd4.o: mlcd4.c  .generated_files/flags/default/498a5e5ab652c3a0892c22081501f4808951ca9c .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mlcd4.o.d 
	@${RM} ${OBJECTDIR}/mlcd4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mlcd4.o.d" -MT "${OBJECTDIR}/mlcd4.o.d" -MT ${OBJECTDIR}/mlcd4.o -o ${OBJECTDIR}/mlcd4.o mlcd4.c 
	
${OBJECTDIR}/mINT.o: mINT.c  .generated_files/flags/default/84245a201033422aa69b780b24f2fc596a93288a .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mINT.o.d 
	@${RM} ${OBJECTDIR}/mINT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mINT.o.d" -MT "${OBJECTDIR}/mINT.o.d" -MT ${OBJECTDIR}/mINT.o -o ${OBJECTDIR}/mINT.o mINT.c 
	
${OBJECTDIR}/mADC.o: mADC.c  .generated_files/flags/default/701c469a8ef803b0df4e0fea139bf723071c25a6 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mADC.o.d 
	@${RM} ${OBJECTDIR}/mADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mADC.o.d" -MT "${OBJECTDIR}/mADC.o.d" -MT ${OBJECTDIR}/mADC.o -o ${OBJECTDIR}/mADC.o mADC.c 
	
${OBJECTDIR}/mTimer.o: mTimer.c  .generated_files/flags/default/f4b2d0b2e37b1c2bfc616a076e79855bc12b934c .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mTimer.o.d 
	@${RM} ${OBJECTDIR}/mTimer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mTimer.o.d" -MT "${OBJECTDIR}/mTimer.o.d" -MT ${OBJECTDIR}/mTimer.o -o ${OBJECTDIR}/mTimer.o mTimer.c 
	
${OBJECTDIR}/mUART.o: mUART.c  .generated_files/flags/default/ecdbcb34732b94863d73b5f2c30de18b648d2243 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mUART.o.d 
	@${RM} ${OBJECTDIR}/mUART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mUART.o.d" -MT "${OBJECTDIR}/mUART.o.d" -MT ${OBJECTDIR}/mUART.o -o ${OBJECTDIR}/mUART.o mUART.c 
	
${OBJECTDIR}/mSPI.o: mSPI.c  .generated_files/flags/default/3d5a161119c60755dc27531cbb21b7dd6c9e4c01 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mSPI.o.d 
	@${RM} ${OBJECTDIR}/mSPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mSPI.o.d" -MT "${OBJECTDIR}/mSPI.o.d" -MT ${OBJECTDIR}/mSPI.o -o ${OBJECTDIR}/mSPI.o mSPI.c 
	
${OBJECTDIR}/EEPROM_SPI.o: EEPROM_SPI.c  .generated_files/flags/default/e3fa80d6ef15c2dbb65402e9d3df242ad3826567 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EEPROM_SPI.o.d 
	@${RM} ${OBJECTDIR}/EEPROM_SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/EEPROM_SPI.o.d" -MT "${OBJECTDIR}/EEPROM_SPI.o.d" -MT ${OBJECTDIR}/EEPROM_SPI.o -o ${OBJECTDIR}/EEPROM_SPI.o EEPROM_SPI.c 
	
${OBJECTDIR}/mTWI.o: mTWI.c  .generated_files/flags/default/302186c8b3079c7907a769dffeb9a96a0fc9cc9c .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mTWI.o.d 
	@${RM} ${OBJECTDIR}/mTWI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/mTWI.o.d" -MT "${OBJECTDIR}/mTWI.o.d" -MT ${OBJECTDIR}/mTWI.o -o ${OBJECTDIR}/mTWI.o mTWI.c 
	
${OBJECTDIR}/EEPROM_TWI.o: EEPROM_TWI.c  .generated_files/flags/default/7d00636b41a0af806dbb17098a83292d23a236b0 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EEPROM_TWI.o.d 
	@${RM} ${OBJECTDIR}/EEPROM_TWI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/EEPROM_TWI.o.d" -MT "${OBJECTDIR}/EEPROM_TWI.o.d" -MT ${OBJECTDIR}/EEPROM_TWI.o -o ${OBJECTDIR}/EEPROM_TWI.o EEPROM_TWI.c 
	
${OBJECTDIR}/EEPROM_INTERFACE.o: EEPROM_INTERFACE.c  .generated_files/flags/default/1654189ddc573b1070b9a2098177233c26732caf .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EEPROM_INTERFACE.o.d 
	@${RM} ${OBJECTDIR}/EEPROM_INTERFACE.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/EEPROM_INTERFACE.o.d" -MT "${OBJECTDIR}/EEPROM_INTERFACE.o.d" -MT ${OBJECTDIR}/EEPROM_INTERFACE.o -o ${OBJECTDIR}/EEPROM_INTERFACE.o EEPROM_INTERFACE.c 
	
${OBJECTDIR}/_7SEGMENT.o: _7SEGMENT.c  .generated_files/flags/default/6b4af8070093c960107ccb57a13e2968f47cb5dd .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/_7SEGMENT.o.d 
	@${RM} ${OBJECTDIR}/_7SEGMENT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_7SEGMENT.o.d" -MT "${OBJECTDIR}/_7SEGMENT.o.d" -MT ${OBJECTDIR}/_7SEGMENT.o -o ${OBJECTDIR}/_7SEGMENT.o _7SEGMENT.c 
	
${OBJECTDIR}/freertos/croutine.o: freertos/croutine.c  .generated_files/flags/default/fcae8e4f9a17ab5c703cfeccbb9aa7e95ef8b365 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/croutine.o.d 
	@${RM} ${OBJECTDIR}/freertos/croutine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/croutine.o.d" -MT "${OBJECTDIR}/freertos/croutine.o.d" -MT ${OBJECTDIR}/freertos/croutine.o -o ${OBJECTDIR}/freertos/croutine.o freertos/croutine.c 
	
${OBJECTDIR}/freertos/event_groups.o: freertos/event_groups.c  .generated_files/flags/default/b73070ec377dd0c84ebddc3165b85e8f757f03d5 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/event_groups.o.d 
	@${RM} ${OBJECTDIR}/freertos/event_groups.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/event_groups.o.d" -MT "${OBJECTDIR}/freertos/event_groups.o.d" -MT ${OBJECTDIR}/freertos/event_groups.o -o ${OBJECTDIR}/freertos/event_groups.o freertos/event_groups.c 
	
${OBJECTDIR}/freertos/heap_4.o: freertos/heap_4.c  .generated_files/flags/default/df0f74445a945202716519507da5d621450441c4 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/heap_4.o.d 
	@${RM} ${OBJECTDIR}/freertos/heap_4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/heap_4.o.d" -MT "${OBJECTDIR}/freertos/heap_4.o.d" -MT ${OBJECTDIR}/freertos/heap_4.o -o ${OBJECTDIR}/freertos/heap_4.o freertos/heap_4.c 
	
${OBJECTDIR}/freertos/list.o: freertos/list.c  .generated_files/flags/default/d70419bcea83f549c68ebbb326574a1a191452fd .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/list.o.d 
	@${RM} ${OBJECTDIR}/freertos/list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/list.o.d" -MT "${OBJECTDIR}/freertos/list.o.d" -MT ${OBJECTDIR}/freertos/list.o -o ${OBJECTDIR}/freertos/list.o freertos/list.c 
	
${OBJECTDIR}/freertos/port.o: freertos/port.c  .generated_files/flags/default/64f849d258f51e6e1d40bcbd44d6c9ad2ead22f3 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/port.o.d 
	@${RM} ${OBJECTDIR}/freertos/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/port.o.d" -MT "${OBJECTDIR}/freertos/port.o.d" -MT ${OBJECTDIR}/freertos/port.o -o ${OBJECTDIR}/freertos/port.o freertos/port.c 
	
${OBJECTDIR}/freertos/queue.o: freertos/queue.c  .generated_files/flags/default/6c34c894d5f4afda3bd6258cc1e0a2eb738f338c .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/queue.o.d 
	@${RM} ${OBJECTDIR}/freertos/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/queue.o.d" -MT "${OBJECTDIR}/freertos/queue.o.d" -MT ${OBJECTDIR}/freertos/queue.o -o ${OBJECTDIR}/freertos/queue.o freertos/queue.c 
	
${OBJECTDIR}/freertos/stream_buffer.o: freertos/stream_buffer.c  .generated_files/flags/default/18d5bb650e91fd227c0857879c2b74f2dc5d6e9f .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/freertos/stream_buffer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/stream_buffer.o.d" -MT "${OBJECTDIR}/freertos/stream_buffer.o.d" -MT ${OBJECTDIR}/freertos/stream_buffer.o -o ${OBJECTDIR}/freertos/stream_buffer.o freertos/stream_buffer.c 
	
${OBJECTDIR}/freertos/tasks.o: freertos/tasks.c  .generated_files/flags/default/67591e3e359e89bbc88f871227cddf75656a1b59 .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/tasks.o.d 
	@${RM} ${OBJECTDIR}/freertos/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/tasks.o.d" -MT "${OBJECTDIR}/freertos/tasks.o.d" -MT ${OBJECTDIR}/freertos/tasks.o -o ${OBJECTDIR}/freertos/tasks.o freertos/tasks.c 
	
${OBJECTDIR}/freertos/timers.o: freertos/timers.c  .generated_files/flags/default/7c322e89e0d8415870651455774faf0ac2b2f37e .generated_files/flags/default/2f9e58fd8ce1a2611b0e0fd33168db129b9285f3
	@${MKDIR} "${OBJECTDIR}/freertos" 
	@${RM} ${OBJECTDIR}/freertos/timers.o.d 
	@${RM} ${OBJECTDIR}/freertos/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/freertos/timers.o.d" -MT "${OBJECTDIR}/freertos/timers.o.d" -MT ${OBJECTDIR}/freertos/timers.o -o ${OBJECTDIR}/freertos/timers.o freertos/timers.c 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Alex46_HelloKit.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Alex46_HelloKit.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"   -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Alex46_HelloKit.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/Alex46_HelloKit.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/Alex46_HelloKit.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Alex46_HelloKit.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Alex46_HelloKit.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Alex46_HelloKit.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/Alex46_HelloKit.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/Alex46_HelloKit.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Alex46_HelloKit.X.${IMAGE_TYPE}.hex"
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
