cmake_minimum_required(VERSION 3.15)

project(FortranCppIntegration LANGUAGES CXX Fortran)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# Set directories (updated paths)
set(CPP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/CPPtests")
set(FORTRAN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/kernel")

# Include directory for C++ headers
include_directories(${CPP_DIR})

# Gather your C++ source files (list them explicitly or use glob)
set(CPP_SOURCES
    ${CPP_DIR}/testBed.cpp
    ${CPP_DIR}/processTest.cpp
    ${CPP_DIR}/rbTest.cpp
)


# Add executable target
add_executable(UnitTestExe ${CPP_SOURCES})

# Add Fortran module directory so compiler can find .mod files
target_include_directories(UnitTestExe PRIVATE ${FORTRAN_DIR})

# Link Fortran shared libraries (specify full paths to .so files)
target_link_libraries(UnitTestExe
    PRIVATE
    ${FORTRAN_DIR}/VOID_Verb.o
    ${FORTRAN_DIR}/numtype.o
    ${FORTRAN_DIR}/ringBuffer.o
    ${FORTRAN_DIR}/libVOID_Verb.so
)

# Link Fortran runtime libraries (adjust if needed)
target_link_libraries(UnitTestExe PRIVATE gfortran)

# Optionally, specify additional linker flags to help the linker find libraries
set_target_properties(UnitTestExe PROPERTIES LINK_FLAGS "-L${FORTRAN_DIR}")
