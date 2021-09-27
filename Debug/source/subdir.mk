################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Blink_LED_A3.c \
../source/delay.c \
../source/led.c \
../source/mtb.c \
../source/semihost_hardfault.c \
../source/touch.c 

OBJS += \
./source/Blink_LED_A3.o \
./source/delay.o \
./source/led.o \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/touch.o 

C_DEPS += \
./source/Blink_LED_A3.d \
./source/delay.d \
./source/led.d \
./source/mtb.d \
./source/semihost_hardfault.d \
./source/touch.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\hwsin\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Blink_LED_A3\board" -I"C:\Users\hwsin\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Blink_LED_A3\source" -I"C:\Users\hwsin\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Blink_LED_A3" -I"C:\Users\hwsin\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Blink_LED_A3\drivers" -I"C:\Users\hwsin\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Blink_LED_A3\CMSIS" -I"C:\Users\hwsin\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Blink_LED_A3\utilities" -I"C:\Users\hwsin\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Blink_LED_A3\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


