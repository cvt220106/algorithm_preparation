cmake_minimum_required(VERSION 3.22)

project(MyAlgorithmPreparation)

set(CMAKE_CXX_STANDARD 17)

include_directories(dp/lengthOfLIS)

# Function to add executables for each .cpp file in a directory
function(add_executables_from_directory dir)
    file(GLOB_RECURSE cpp_files "${dir}/*.cpp")
    foreach (cpp_file ${cpp_files})
        get_filename_component(exe_name ${cpp_file} NAME_WE)
        add_executable(${exe_name} ${cpp_file})
    endforeach ()
endfunction()

# Add executables from the specified directories
add_executables_from_directory("${CMAKE_SOURCE_DIR}/backtrack")
add_executables_from_directory("${CMAKE_SOURCE_DIR}/dp")
add_executables_from_directory("${CMAKE_SOURCE_DIR}/mock_test")
add_executables_from_directory("${CMAKE_SOURCE_DIR}/StackAndQueue")
add_executables_from_directory("${CMAKE_SOURCE_DIR}/SearchAndSort")
