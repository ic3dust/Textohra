# CMakeList.txt : CMake project for Kariera, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Kariera "Kariera.cpp" "Kariera.h" "Verze0.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Kariera PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
