cmake_minimum_required(VERSION 3.31)
project(Gatto)

set(CMAKE_CXX_STANDARD 11)
set(SFML_STATIC_LIBRARIES FALSE)
set(SFML_DIR "/opt/homebrew/opt/sfml@2/lib/cmake/SFML")

find_package(SFML 2.6 COMPONENTS system window graphics audio REQUIRED)

add_executable(Gatto src/main.cpp)

# Linka as bibliotecas SFML
target_link_libraries(${PROJECT_NAME}
        sfml-system sfml-window sfml-graphics sfml-audio
)