################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/UserCC/define.c \
../Core/UserCC/font.c \
../Core/UserCC/jy62.c \
../Core/UserCC/oled.c \
../Core/UserCC/pid.c 

OBJS += \
./Core/UserCC/define.o \
./Core/UserCC/font.o \
./Core/UserCC/jy62.o \
./Core/UserCC/oled.o \
./Core/UserCC/pid.o 

C_DEPS += \
./Core/UserCC/define.d \
./Core/UserCC/font.d \
./Core/UserCC/jy62.d \
./Core/UserCC/oled.d \
./Core/UserCC/pid.d 


# Each subdirectory must supply rules for building sources it contributes
Core/UserCC/%.o Core/UserCC/%.su Core/UserCC/%.cyclo: ../Core/UserCC/%.c Core/UserCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/UserCC -I../Core/UserHH -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-UserCC

clean-Core-2f-UserCC:
	-$(RM) ./Core/UserCC/define.cyclo ./Core/UserCC/define.d ./Core/UserCC/define.o ./Core/UserCC/define.su ./Core/UserCC/font.cyclo ./Core/UserCC/font.d ./Core/UserCC/font.o ./Core/UserCC/font.su ./Core/UserCC/jy62.cyclo ./Core/UserCC/jy62.d ./Core/UserCC/jy62.o ./Core/UserCC/jy62.su ./Core/UserCC/oled.cyclo ./Core/UserCC/oled.d ./Core/UserCC/oled.o ./Core/UserCC/oled.su ./Core/UserCC/pid.cyclo ./Core/UserCC/pid.d ./Core/UserCC/pid.o ./Core/UserCC/pid.su

.PHONY: clean-Core-2f-UserCC

