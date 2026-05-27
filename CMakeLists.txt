cmake_minimum_required(VERSION 3.20)

project(project-v-core
    VERSION 0.1.0
    LANGUAGES CXX
)

# Options (you can expand these later)
option(PROJECT_V_BUILD_EXAMPLES "Build example applications" ON)

# Global C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# engine_core library
add_library(engine_core STATIC)

# Add sources
target_sources(engine_core
    PUBLIC
        include/projectV/core/logger.hpp
        include/projectV/core/renderer.hpp
        include/projectV/core/raytracer.hpp
        include/projectV/core/mesh.hpp
        include/projectV/core/meshLoader.hpp
    PRIVATE
        src/core/core.cpp
)

# Public headers
target_include_directories(engine_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Basic compile definitions / features (extend later as needed)
target_compile_features(engine_core PUBLIC cxx_std_20)

# Example executable(s)
if(PROJECT_V_BUILD_EXAMPLES)
    add_subdirectory(examples/core_sandbox)
endif()