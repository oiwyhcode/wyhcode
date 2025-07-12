################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Mycode/pid.c 

OBJS += \
./Core/Mycode/pid.o 

C_DEPS += \
./Core/Mycode/pid.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Mycode/%.o Core/Mycode/%.su Core/Mycode/%.cyclo: ../Core/Mycode/%.c Core/Mycode/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -IC:/Users/14931/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/STM32F1xx_HAL_Driver/Inc -IC:/Users/14931/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -IC:/Users/14931/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/CMSIS/Device/ST/STM32F1xx/Include -IC:/Users/14931/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/CMSIS/Include -I"A:/STM32CUBEIDE/PROJECT/Myproject/Core/Mycode" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Mycode

clean-Core-2f-Mycode:
	-$(RM) ./Core/Mycode/pid.cyclo ./Core/Mycode/pid.d ./Core/Mycode/pid.o ./Core/Mycode/pid.su

.PHONY: clean-Core-2f-Mycode

