################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripherals/Src/adc.c \
../Peripherals/Src/exti.c \
../Peripherals/Src/gpio.c \
../Peripherals/Src/rcc.c \
../Peripherals/Src/tim.c \
../Peripherals/Src/uart.c 

OBJS += \
./Peripherals/Src/adc.o \
./Peripherals/Src/exti.o \
./Peripherals/Src/gpio.o \
./Peripherals/Src/rcc.o \
./Peripherals/Src/tim.o \
./Peripherals/Src/uart.o 

C_DEPS += \
./Peripherals/Src/adc.d \
./Peripherals/Src/exti.d \
./Peripherals/Src/gpio.d \
./Peripherals/Src/rcc.d \
./Peripherals/Src/tim.d \
./Peripherals/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Peripherals/Src/%.o Peripherals/Src/%.su: ../Peripherals/Src/%.c Peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -DUSE_HAL_DRIVER -c -I"D:/Javad/Projects/STM32/stm32_hal/stm32_hal/stm32_hal/Core/Inc" -I"D:/Javad/Projects/STM32/stm32_hal/stm32_hal/stm32_hal/CMSIS/Include" -I"D:/Javad/Projects/STM32/stm32_hal/stm32_hal/stm32_hal/CMSIS/Device" -I"D:/Javad/Projects/STM32/stm32_hal/stm32_hal/stm32_hal/Peripherals/Inc" -I"D:/Javad/Projects/STM32/stm32_hal/stm32_hal/stm32_hal/HAL/STM32F1xx_HAL_Driver/Inc" -I"D:/Javad/Projects/STM32/stm32_hal/stm32_hal/stm32_hal/HAL" -I"D:/Javad/Projects/STM32/stm32_hal/stm32_hal/stm32_hal/Application/Display" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Peripherals-2f-Src

clean-Peripherals-2f-Src:
	-$(RM) ./Peripherals/Src/adc.d ./Peripherals/Src/adc.o ./Peripherals/Src/adc.su ./Peripherals/Src/exti.d ./Peripherals/Src/exti.o ./Peripherals/Src/exti.su ./Peripherals/Src/gpio.d ./Peripherals/Src/gpio.o ./Peripherals/Src/gpio.su ./Peripherals/Src/rcc.d ./Peripherals/Src/rcc.o ./Peripherals/Src/rcc.su ./Peripherals/Src/tim.d ./Peripherals/Src/tim.o ./Peripherals/Src/tim.su ./Peripherals/Src/uart.d ./Peripherals/Src/uart.o ./Peripherals/Src/uart.su

.PHONY: clean-Peripherals-2f-Src

