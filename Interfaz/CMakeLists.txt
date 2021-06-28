cmake_minimum_required(VERSION 3.19)
project(Interfaz C)

set(CMAKE_C_STANDARD 99)
set(SDL2_INCLUDE_DIR C:/SDL/include)
set(SDL2_LIB_DIR C:/SDL/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})
add_executable(Interfaz main.c Headers/enemigo.h Headers/jugador.h Headers/misil.h Headers/muro.h Sources/enemigo.c Sources/jugador.c Sources/misil.c Sources/muro.c)

TARGET_LINK_LIBRARIES(Interfaz
        SDL2main SDL2
        )