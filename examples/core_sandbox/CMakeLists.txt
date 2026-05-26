cmake_minimum_required(VERSION 3.20)

project(project_v_core_sandbox LANGUAGES CXX)

add_executable(project_v_core_sandbox
    main.cpp
)

# Link against the core library
target_link_libraries(project_v_core_sandbox
    PRIVATE
        engine_core
)