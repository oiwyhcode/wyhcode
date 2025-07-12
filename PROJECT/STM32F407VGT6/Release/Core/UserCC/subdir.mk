################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/UserCC/exti.c 

OBJS += \
./Core/UserCC/exti.o 

C_DEPS += \
./Core/UserCC/exti.d 


# Each subdirectory must supply rules for building sources it contributes
Core/UserCC/%.o Core/UserCC/%.su Core/UserCC/%.cyclo: ../Core/UserCC/%.c Core/UserCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-UserCC

clean-Core-2f-UserCC:
	-$(RM) ./Core/UserCC/exti.cyclo ./Core/UserCC/exti.d ./Core/UserCC/exti.o ./Core/UserCC/exti.su

.PHONY: clean-Core-2f-UserCC

