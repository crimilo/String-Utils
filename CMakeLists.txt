cmake_minimum_required(VERSION 3.0)

# Set the project name and version
project(string_utils VERSION 1.0)

# Create a static library
add_library(${PROJECT_NAME} STATIC
   string_utils.c
)

# Set the include directories for the library
target_include_directories(${PROJECT_NAME} PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the installation directories for the library
install(TARGETS ${PROJECT_NAME}
   ARCHIVE DESTINATION lib
)

# Set the installation directories for the header files
install(DIRECTORY ./ DESTINATION include)

# Define the test target
add_executable(test test.c)

# Add the test to the project
add_test(NAME test COMMAND test)

# Link the test with the library
target_link_libraries(test ${PROJECT_NAME})