cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

#FILE(SCRIPTS src/script/*.cpp)
#add_executable(main src/main.cpp ${SCRIPTS} ${CMAKE_SOURCE_DIR}/glad/src/glad.c)

file(COPY "${CMAKE_SOURCE_DIR}/src/font" DESTINATION "${CMAKE_BINARY_DIR}/bin")
file(COPY "${CMAKE_SOURCE_DIR}/src/shader" DESTINATION "${CMAKE_BINARY_DIR}/bin")

add_executable(main src/main.cpp ${CMAKE_SOURCE_DIR}/glad/src/gl.c)
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/glad/include)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)