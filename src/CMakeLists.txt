cmake_minimum_required(VERSION 3.10)

# 2. Define the project name and language
project(ShipShapeCpp LANGUAGES CXX)

# 3. Specify the C++ standard (optional but recommended)
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)
# 4. Create an executable target from the source file
add_executable(ShipShapeCpp ${MY_SOURCES})