################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C8T6_DRIVERS_SYSTICK/SYSTICK.c 

OBJS += \
./STM32F103C8T6_DRIVERS_SYSTICK/SYSTICK.o 

C_DEPS += \
./STM32F103C8T6_DRIVERS_SYSTICK/SYSTICK.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C8T6_DRIVERS_SYSTICK/%.o STM32F103C8T6_DRIVERS_SYSTICK/%.su STM32F103C8T6_DRIVERS_SYSTICK/%.cyclo: ../STM32F103C8T6_DRIVERS_SYSTICK/%.c STM32F103C8T6_DRIVERS_SYSTICK/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"G:/STMWORKSPACE/NTI_STM_Drivers/KeyPad" -I"G:/STMWORKSPACE/NTI_STM_Drivers/STM32F103C8T6_DRIVERS_SYSTICK/Inc" -I"G:/STMWORKSPACE/NTI_STM_Drivers/LCD" -I"G:/STMWORKSPACE/NTI_STM_Drivers/STM32F103C8T6_NVIC/NVIC_Inc" -I"G:/STMWORKSPACE/NTI_STM_Drivers/STM32F103C8T6_DRIVERS_GPIO/Inc" -I"G:/STMWORKSPACE/NTI_STM_Drivers/STM32F103C8T6_DRIVERS_RCC/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C8T6_DRIVERS_SYSTICK

clean-STM32F103C8T6_DRIVERS_SYSTICK:
	-$(RM) ./STM32F103C8T6_DRIVERS_SYSTICK/SYSTICK.cyclo ./STM32F103C8T6_DRIVERS_SYSTICK/SYSTICK.d ./STM32F103C8T6_DRIVERS_SYSTICK/SYSTICK.o ./STM32F103C8T6_DRIVERS_SYSTICK/SYSTICK.su

.PHONY: clean-STM32F103C8T6_DRIVERS_SYSTICK

