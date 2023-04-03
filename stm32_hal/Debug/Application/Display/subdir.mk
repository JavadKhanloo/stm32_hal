################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Display/tm1637.c 

OBJS += \
./Application/Display/tm1637.o 

C_DEPS += \
./Application/Display/tm1637.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Display/%.o Application/Display/%.su: ../Application/Display/%.c Application/Display/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -DUSE_HAL_DRIVER -c -I"D:/Javad/Projects/STM32/stm32_hal/stm32_hal/stm32_hal/Core/Inc" -I"D:/Javad/Projects/STM32/stm32_hal/stm32_hal/stm32_hal/CMSIS/Include" -I"D:/Javad/Projects/STM32/stm32_hal/stm32_hal/stm32_hal/CMSIS/Device" -I"D:/Javad/Projects/STM32/stm32_hal/stm32_hal/stm32_hal/Peripherals/Inc" -I"D:/Javad/Projects/STM32/stm32_hal/stm32_hal/stm32_hal/HAL/STM32F1xx_HAL_Driver/Inc" -I"D:/Javad/Projects/STM32/stm32_hal/stm32_hal/stm32_hal/HAL" -I"D:/Javad/Projects/STM32/stm32_hal/stm32_hal/stm32_hal/Application/Display" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-Display

clean-Application-2f-Display:
	-$(RM) ./Application/Display/tm1637.d ./Application/Display/tm1637.o ./Application/Display/tm1637.su

.PHONY: clean-Application-2f-Display

