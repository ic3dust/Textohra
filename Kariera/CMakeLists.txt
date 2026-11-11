# CMakeList.txt : CMake project for Kariera, include source and define
# project specific logic here.
#

project(Kariera)

add_executable(Kariera
    Kariera.cpp
    Kariera.h
    Otazky_1.cpp
    Otazky_1.h
    Random.cpp
    Random.h
    Textove_funkce.cpp
    Textove_funkce.h
    Etapa_1.cpp
    Etapa_1.h
 "Colors.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Kariera PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
