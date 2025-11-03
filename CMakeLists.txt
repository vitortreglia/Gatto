cmake_minimum_required(VERSION 3.16)
project(Gatto)

set(CMAKE_CXX_STANDARD 11)

# --- Configuração específica por sistema ---
if(APPLE)
    message(STATUS "Configurando para macOS...")

    # Caminho padrão da SFML instalada via Homebrew
    set(SFML_STATIC_LIBRARIES FALSE)
    set(SFML_DIR "/opt/homebrew/opt/sfml@2/lib/cmake/SFML")

elseif(WIN32)
    message(STATUS "Configurando para Windows...")

    # Caminho onde a SFML foi extraída no Windows
    # (ajuste se necessário)
    set(SFML_STATIC_LIBRARIES FALSE)
    set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.2/lib/cmake/SFML")
endif()

# --- Encontra a SFML ---
find_package(SFML 2.6 COMPONENTS system window graphics audio REQUIRED)

# --- Busca recursiva por arquivos .cpp e .h ---
file(GLOB_RECURSE SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/includes/*.h"
)

# --- Cria o executável ---
add_executable(Gatto ${SOURCES}
        src/Entidade/Obstaculo/Plataforma.cpp
        includes/Entidade/Obstaculo/Plataforma.h
        src/Entidade/Obstaculo/ObstaculoMedio.cpp
        includes/Entidade/Obstaculo/ObstaculoMedio.h
        src/Entidade/Obstaculo/PlataformaMovel.cpp
        includes/Entidade/Obstaculo/PlataformaMovel.h
        src/Entidade/Obstaculo/PlataformaGiratoria.cpp
        includes/Entidade/Obstaculo/PlataformaGiratoria.h
        src/Fase/FaseJardim.cpp
        includes/Fase/FaseJardim.h
        src/Entidade/Personagem/Inimigos/Gaivota.cpp
        includes/Entidade/Personagem/Inimigos/inimigo.h
        src/Entidade/Personagem/Inimigos/inimigo.cpp

        src/main.cpp
)

# --- Diretórios de include ---
target_include_directories(Gatto PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/includes
)

# --- Linka as bibliotecas da SFML ---
target_link_libraries(Gatto
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
)

# --- Onde o executável será salvo ---
set_target_properties(Gatto PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)

# --- Copiar DLLs automaticamente no Windows ---
if(WIN32)
    add_custom_command(TARGET Gatto POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.2/bin"
            "$<TARGET_FILE_DIR:Gatto>"
                )
endif()