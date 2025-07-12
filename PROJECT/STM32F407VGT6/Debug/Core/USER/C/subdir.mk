################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/USER/C/it.c 

OBJS += \
./Core/USER/C/it.o 

C_DEPS += \
./Core/USER/C/it.d 


# Each subdirectory must supply rules for building sources it contributes
Core/USER/C/%.o Core/USER/C/%.su Core/USER/C/%.cyclo: ../Core/USER/C/%.c Core/USER/C/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-USER-2f-C

clean-Core-2f-USER-2f-C:
	-$(RM) ./Core/USER/C/it.cyclo ./Core/USER/C/it.d ./Core/USER/C/it.o ./Core/USER/C/it.su

.PHONY: clean-Core-2f-USER-2f-C

