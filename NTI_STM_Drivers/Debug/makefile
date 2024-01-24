################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STM32F103C8T6_NVIC/subdir.mk
-include STM32F103C8T6_DRIVERS_SYSTICK/subdir.mk
-include STM32F103C8T6_DRIVERS_RCC/subdir.mk
-include STM32F103C8T6_DRIVERS_GPIO/subdir.mk
-include LCD/subdir.mk
-include KeyPad/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := NTI_STM_Drivers
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
NTI_STM_Drivers.axf \

MAP_FILES += \
NTI_STM_Drivers.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
NTI_STM_Drivers.list \

OBJCOPY_HEX += \
NTI_STM_Drivers.hex \


# All Target
all: main-build

# Main-build Target
main-build: NTI_STM_Drivers.axf secondary-outputs

# Tool invocations
NTI_STM_Drivers.axf NTI_STM_Drivers.map: $(OBJS) $(USER_OBJS) G:\STMWORKSPACE\NTI_STM_Drivers\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -gdwarf-2 -o "NTI_STM_Drivers.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"G:\STMWORKSPACE\NTI_STM_Drivers\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="NTI_STM_Drivers.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

NTI_STM_Drivers.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "NTI_STM_Drivers.list"
	@echo 'Finished building: $@'
	@echo ' '

NTI_STM_Drivers.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "NTI_STM_Drivers.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) NTI_STM_Drivers.axf NTI_STM_Drivers.hex NTI_STM_Drivers.list NTI_STM_Drivers.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
