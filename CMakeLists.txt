cmake_minimum_required(VERSION 3.16)
project(abstractVM)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(includes)
include_directories(includes/IOperand)
include_directories(src/VirtualMachine)

include_directories(src/VirtualMachine/CPU)
include_directories(src/VirtualMachine/IOInterface)
include_directories(src/VirtualMachine/Memory)

include_directories(includes/MyTypes/MyDouble)
include_directories(includes/MyTypes/MyFloat)
include_directories(includes/MyTypes/MyInt16)
include_directories(includes/MyTypes/MyInt32)
include_directories(includes/MyTypes/MyInt8)

include_directories(src/Factory)

add_executable(abstractVM
        # Main
        src/Main.cpp

        # Utils
        src/AbstractVM.cpp
        src/Utils/Help.cpp
        src/Utils/ErrorHandling.cpp

        src/eOperandType/eOperandType.cpp

        # Class
        includes/IOperand/IOperand.cpp

        src/VirtualMachine/VirtualMachine.cpp
        src/VirtualMachine/CPU/CPU.cpp
        src/VirtualMachine/IOInterface/IOInterface.cpp
        src/VirtualMachine/Memory/Memory.cpp

        includes/MyTypes/MyDouble/MyDouble.cpp
        includes/MyTypes/MyFloat/MyFloat.cpp
        includes/MyTypes/MyInt16/MyInt16.cpp
        includes/MyTypes/MyInt32/MyInt32.cpp
        includes/MyTypes/MyInt8/MyInt8.cpp

        src/Factory/Factory.cpp

        )

target_compile_options(abstractVM PRIVATE -Wall -Wextra)
