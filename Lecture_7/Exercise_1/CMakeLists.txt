cmake_minimum_required (VERSION 3.2 FATAL_ERROR)
# Lookup for necessary libraries in system
find_package(Threads)
# Target proto
add_executable(proto src/main.c)
target_include_directories(proto
    PUBLIC 
      inc
    PRIVATE 
)
#target_compile_definitions(proto
#    PRIVATE
#)
target_sources(proto
	PRIVATE 
      src/main.c
)
target_compile_options(proto
    PUBLIC
)
target_compile_features(proto
    PUBLIC
)
target_link_libraries(proto
    PUBLIC
)
set_target_properties(proto
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)