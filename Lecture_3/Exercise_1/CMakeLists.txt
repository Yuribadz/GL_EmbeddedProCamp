cmake_minimum_required (VERSION 3.2 FATAL_ERROR)
project (excercise)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Lookup for necessary libraries in system
find_package(Threads)
# Target server
add_executable(excercise src/main.c)
target_include_directories(excercise
    PUBLIC 
      inc
    PRIVATE 
)
#target_compile_definitions(server
#    PRIVATE
#)
target_sources(excercise
  PRIVATE 
  src/main.c
)
target_compile_options(excercise
    PUBLIC
    -g
)
target_compile_features(excercise
  PUBLIC
)
target_link_libraries(excercise 
    PUBLIC
)
set_target_properties(excercise
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)


