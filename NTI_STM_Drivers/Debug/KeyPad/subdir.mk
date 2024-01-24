################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../KeyPad/KeyPad.c 

OBJS += \
./KeyPad/KeyPad.o 

C_DEPS += \
./KeyPad/KeyPad.d 


# Each subdirectory must supply rules for building sources it contributes
KeyPad/%.o KeyPad/%.su KeyPad/%.cyclo: ../KeyPad/%.c KeyPad/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"G:/STMWORKSPACE/NTI_STM_Drivers/KeyPad" -I"G:/STMWORKSPACE/NTI_STM_Drivers/STM32F103C8T6_DRIVERS_SYSTICK/Inc" -I"G:/STMWORKSPACE/NTI_STM_Drivers/LCD" -I"G:/STMWORKSPACE/NTI_STM_Drivers/STM32F103C8T6_NVIC/NVIC_Inc" -I"G:/STMWORKSPACE/NTI_STM_Drivers/STM32F103C8T6_DRIVERS_GPIO/Inc" -I"G:/STMWORKSPACE/NTI_STM_Drivers/STM32F103C8T6_DRIVERS_RCC/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-KeyPad

clean-KeyPad:
	-$(RM) ./KeyPad/KeyPad.cyclo ./KeyPad/KeyPad.d ./KeyPad/KeyPad.o ./KeyPad/KeyPad.su

.PHONY: clean-KeyPad

