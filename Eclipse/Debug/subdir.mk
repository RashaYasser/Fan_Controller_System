################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Fan_Controller_system.c \
../adc.c \
../dc.c \
../gpio.c \
../lcd.c \
../lm35.c \
../pwm.c 

OBJS += \
./Fan_Controller_system.o \
./adc.o \
./dc.o \
./gpio.o \
./lcd.o \
./lm35.o \
./pwm.o 

C_DEPS += \
./Fan_Controller_system.d \
./adc.d \
./dc.d \
./gpio.d \
./lcd.d \
./lm35.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

