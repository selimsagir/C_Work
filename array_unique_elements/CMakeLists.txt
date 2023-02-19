cmake_minimum_required(VERSION 3.0)
project(MyProject)

add_executable(main main.c)

add_custom_target(run
    COMMAND ./main
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
