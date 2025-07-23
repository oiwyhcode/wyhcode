################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
usercc/%.o: ../usercc/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"A:/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"A:/git/WYHCODE/ccs/M0G3507" -I"A:/git/WYHCODE/ccs/M0G3507/Debug" -I"A:/CCS/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"A:/CCS/mspm0_sdk_2_05_01_00/source" -I"A:/git/WYHCODE/ccs/M0G3507/userr" -gdwarf-3 -MMD -MP -MF"usercc/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


