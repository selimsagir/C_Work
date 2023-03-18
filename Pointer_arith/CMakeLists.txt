cmake_minimum_required(VERSION 3.26.0)

project(my_project)

# Add the main executable
add_executable(my_app main.c)

# Set the include directories
target_include_directories(my_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Add any additional libraries
target_link_libraries(my_app ${MY_LIBRARIES})
