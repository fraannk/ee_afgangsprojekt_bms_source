################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FlashPrg.c \
../src/utilities.c 

OBJS += \
./src/FlashPrg.o \
./src/utilities.o 

C_DEPS += \
./src/FlashPrg.d \
./src/utilities.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -D__USE_CMSIS -DDEBUG -D__CODE_RED -DCORE_M0PLUS -DCR_INTEGER_PRINTF -I"C:\Users\fraannk\Documents\ee_afgangsprojekt_bms_source\peripherals_lib\inc" -I"C:\Users\fraannk\Documents\ee_afgangsprojekt_bms_source\utilities_lib\inc" -I"C:\Users\fraannk\Documents\ee_afgangsprojekt_bms_source\common\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


