################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32_f103c6_drivers/stm32_f103c6_drivers_EXTI.c \
../stm32_f103c6_drivers/stm32_f103c6_drivers_RCC.c \
../stm32_f103c6_drivers/stm32_f103c6_drivers_SPI.c \
../stm32_f103c6_drivers/stm32_f103c6_drivers_USART.c \
../stm32_f103c6_drivers/stm32_f103c6_drivers_gpio.c \
../stm32_f103c6_drivers/stm32_f103c6_drivers_timers.c 

OBJS += \
./stm32_f103c6_drivers/stm32_f103c6_drivers_EXTI.o \
./stm32_f103c6_drivers/stm32_f103c6_drivers_RCC.o \
./stm32_f103c6_drivers/stm32_f103c6_drivers_SPI.o \
./stm32_f103c6_drivers/stm32_f103c6_drivers_USART.o \
./stm32_f103c6_drivers/stm32_f103c6_drivers_gpio.o \
./stm32_f103c6_drivers/stm32_f103c6_drivers_timers.o 

C_DEPS += \
./stm32_f103c6_drivers/stm32_f103c6_drivers_EXTI.d \
./stm32_f103c6_drivers/stm32_f103c6_drivers_RCC.d \
./stm32_f103c6_drivers/stm32_f103c6_drivers_SPI.d \
./stm32_f103c6_drivers/stm32_f103c6_drivers_USART.d \
./stm32_f103c6_drivers/stm32_f103c6_drivers_gpio.d \
./stm32_f103c6_drivers/stm32_f103c6_drivers_timers.d 


# Each subdirectory must supply rules for building sources it contributes
stm32_f103c6_drivers/%.o stm32_f103c6_drivers/%.su stm32_f103c6_drivers/%.cyclo: ../stm32_f103c6_drivers/%.c stm32_f103c6_drivers/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Drivers/HAL/Includes" -I"D:/Drivers/stm32_f103c6_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-stm32_f103c6_drivers

clean-stm32_f103c6_drivers:
	-$(RM) ./stm32_f103c6_drivers/stm32_f103c6_drivers_EXTI.cyclo ./stm32_f103c6_drivers/stm32_f103c6_drivers_EXTI.d ./stm32_f103c6_drivers/stm32_f103c6_drivers_EXTI.o ./stm32_f103c6_drivers/stm32_f103c6_drivers_EXTI.su ./stm32_f103c6_drivers/stm32_f103c6_drivers_RCC.cyclo ./stm32_f103c6_drivers/stm32_f103c6_drivers_RCC.d ./stm32_f103c6_drivers/stm32_f103c6_drivers_RCC.o ./stm32_f103c6_drivers/stm32_f103c6_drivers_RCC.su ./stm32_f103c6_drivers/stm32_f103c6_drivers_SPI.cyclo ./stm32_f103c6_drivers/stm32_f103c6_drivers_SPI.d ./stm32_f103c6_drivers/stm32_f103c6_drivers_SPI.o ./stm32_f103c6_drivers/stm32_f103c6_drivers_SPI.su ./stm32_f103c6_drivers/stm32_f103c6_drivers_USART.cyclo ./stm32_f103c6_drivers/stm32_f103c6_drivers_USART.d ./stm32_f103c6_drivers/stm32_f103c6_drivers_USART.o ./stm32_f103c6_drivers/stm32_f103c6_drivers_USART.su ./stm32_f103c6_drivers/stm32_f103c6_drivers_gpio.cyclo ./stm32_f103c6_drivers/stm32_f103c6_drivers_gpio.d ./stm32_f103c6_drivers/stm32_f103c6_drivers_gpio.o ./stm32_f103c6_drivers/stm32_f103c6_drivers_gpio.su ./stm32_f103c6_drivers/stm32_f103c6_drivers_timers.cyclo ./stm32_f103c6_drivers/stm32_f103c6_drivers_timers.d ./stm32_f103c6_drivers/stm32_f103c6_drivers_timers.o ./stm32_f103c6_drivers/stm32_f103c6_drivers_timers.su

.PHONY: clean-stm32_f103c6_drivers

