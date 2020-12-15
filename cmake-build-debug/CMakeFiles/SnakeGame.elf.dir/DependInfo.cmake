# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  "C"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/home/kalibri/STM32/projects/SnakeGame/startup/startup_stm32f051x8.s" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/startup/startup_stm32f051x8.s.obj"
  )
set(CMAKE_ASM_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_ASM
  "DATA_CACHE_ENABLE=0"
  "HSE_STARTUP_TIMEOUT=100"
  "HSE_VALUE=8000000"
  "HSI_VALUE=8000000"
  "INSTRUCTION_CACHE_ENABLE=0"
  "LSE_STARTUP_TIMEOUT=5000"
  "LSE_VALUE=32768"
  "LSI_VALUE=40000"
  "PREFETCH_ENABLE=1"
  "STM32F051x8"
  "USE_FULL_LL_DRIVER"
  "VDD_VALUE=3300"
  )

# The include file search paths:
set(CMAKE_ASM_TARGET_INCLUDE_PATH
  "../Core/Inc"
  "../Drivers/STM32F0xx_HAL_Driver/Inc"
  "../Drivers/CMSIS/Device/ST/STM32F0xx/Include"
  "../Drivers/CMSIS/Include"
  )
set(CMAKE_DEPENDS_CHECK_C
  "/home/kalibri/STM32/projects/SnakeGame/Core/Src/main.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Core/Src/main.c.obj"
  "/home/kalibri/STM32/projects/SnakeGame/Core/Src/stm32f0xx_it.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Core/Src/stm32f0xx_it.c.obj"
  "/home/kalibri/STM32/projects/SnakeGame/Core/Src/syscalls.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Core/Src/syscalls.c.obj"
  "/home/kalibri/STM32/projects/SnakeGame/Core/Src/system_stm32f0xx.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Core/Src/system_stm32f0xx.c.obj"
  "/home/kalibri/STM32/projects/SnakeGame/Drivers/Lib/Point.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Drivers/Lib/Point.c.obj"
  "/home/kalibri/STM32/projects/SnakeGame/Drivers/Lib/Snake.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Drivers/Lib/Snake.c.obj"
  "/home/kalibri/STM32/projects/SnakeGame/Drivers/Lib/font5x7.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Drivers/Lib/font5x7.c.obj"
  "/home/kalibri/STM32/projects/SnakeGame/Drivers/Lib/oled_driver.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Drivers/Lib/oled_driver.c.obj"
  "/home/kalibri/STM32/projects/SnakeGame/Drivers/Lib/xprintf.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Drivers/Lib/xprintf.c.obj"
  "/home/kalibri/STM32/projects/SnakeGame/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_dma.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_dma.c.obj"
  "/home/kalibri/STM32/projects/SnakeGame/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_exti.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_exti.c.obj"
  "/home/kalibri/STM32/projects/SnakeGame/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_gpio.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_gpio.c.obj"
  "/home/kalibri/STM32/projects/SnakeGame/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_i2c.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_i2c.c.obj"
  "/home/kalibri/STM32/projects/SnakeGame/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_pwr.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_pwr.c.obj"
  "/home/kalibri/STM32/projects/SnakeGame/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_rcc.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_rcc.c.obj"
  "/home/kalibri/STM32/projects/SnakeGame/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_utils.c" "/home/kalibri/STM32/projects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.elf.dir/Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_utils.c.obj"
  )
set(CMAKE_C_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_C
  "DATA_CACHE_ENABLE=0"
  "HSE_STARTUP_TIMEOUT=100"
  "HSE_VALUE=8000000"
  "HSI_VALUE=8000000"
  "INSTRUCTION_CACHE_ENABLE=0"
  "LSE_STARTUP_TIMEOUT=5000"
  "LSE_VALUE=32768"
  "LSI_VALUE=40000"
  "PREFETCH_ENABLE=1"
  "STM32F051x8"
  "USE_FULL_LL_DRIVER"
  "VDD_VALUE=3300"
  )

# The include file search paths:
set(CMAKE_C_TARGET_INCLUDE_PATH
  "../Core/Inc"
  "../Drivers/STM32F0xx_HAL_Driver/Inc"
  "../Drivers/CMSIS/Device/ST/STM32F0xx/Include"
  "../Drivers/CMSIS/Include"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
