################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MCUXpresso_Retarget.c \
../src/MCUXpresso_cr_startup.c \
../src/MCUXpresso_crp.c \
../src/MCUXpresso_mtb.c \
../src/Serial.c \
../src/main.c \
../src/system.c 

OBJS += \
./src/MCUXpresso_Retarget.o \
./src/MCUXpresso_cr_startup.o \
./src/MCUXpresso_crp.o \
./src/MCUXpresso_mtb.o \
./src/Serial.o \
./src/main.o \
./src/system.o 

C_DEPS += \
./src/MCUXpresso_Retarget.d \
./src/MCUXpresso_cr_startup.d \
./src/MCUXpresso_crp.d \
./src/MCUXpresso_mtb.d \
./src/Serial.d \
./src/main.d \
./src/system.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -DCR_INTEGER_PRINTF -D__USE_CMSIS -D__CODE_RED -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -D__REDLIB__ -I"C:\Users\fraannk\Documents\ee_afgangsprojekt_bms_source\BMS\inc" -I"C:\Users\fraannk\Documents\ee_afgangsprojekt_bms_source\peripherals_lib\inc" -I"C:\Users\fraannk\Documents\ee_afgangsprojekt_bms_source\utilities_lib\inc" -I"C:\Users\fraannk\Documents\ee_afgangsprojekt_bms_source\common\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


