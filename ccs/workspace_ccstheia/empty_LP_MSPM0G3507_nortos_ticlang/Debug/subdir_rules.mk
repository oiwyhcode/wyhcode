################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"A:/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/soft" -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/userhh" -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/usercc" -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/OLED" -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang" -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/Debug" -I"A:/CCS/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"A:/CCS/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1548898625: ../empty.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"A:/CCS/ccs/utils/sysconfig_1.24.0/sysconfig_cli.bat" --script "A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/empty.syscfg" -o "." -s "A:/CCS/mspm0_sdk_2_05_01_00/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-1548898625 ../empty.syscfg
device.opt: build-1548898625
device.cmd.genlibs: build-1548898625
ti_msp_dl_config.c: build-1548898625
ti_msp_dl_config.h: build-1548898625
Event.dot: build-1548898625

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"A:/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/soft" -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/userhh" -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/usercc" -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/OLED" -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang" -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/Debug" -I"A:/CCS/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"A:/CCS/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: A:/CCS/mspm0_sdk_2_05_01_00/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"A:/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/soft" -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/userhh" -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/usercc" -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/OLED" -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang" -I"A:/git/WYHCODE/ccs/workspace_ccstheia/empty_LP_MSPM0G3507_nortos_ticlang/Debug" -I"A:/CCS/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"A:/CCS/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


