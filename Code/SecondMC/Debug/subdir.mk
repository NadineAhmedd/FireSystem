################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DC_motor.c \
../gpio.c \
../main.c \
../sensor.c \
../uart.c 

OBJS += \
./ADC.o \
./DC_motor.o \
./gpio.o \
./main.o \
./sensor.o \
./uart.o 

C_DEPS += \
./ADC.d \
./DC_motor.d \
./gpio.d \
./main.d \
./sensor.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


