################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
System/%.o: ../System/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/Software/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/auto_driving_car/System" -I"D:/auto_driving_car/Hardware" -I"D:/auto_driving_car" -I"D:/auto_driving_car/Debug" -I"D:/Software/ti/ccs2020/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"D:/Software/ti/ccs2020/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"System/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


