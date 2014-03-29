project(testopengl)

add_executable(testopengl brol.cpp sdlglutils.cpp TrackBallCamera.cpp)

install(TARGETS testopengl RUNTIME DESTINATION bin)

set(CMAKE_CXX_FLAGS "-g -std=c++11 -lSDL -lGL -lGLU -lSDL_image")

