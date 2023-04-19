cmake_minimum_required(VERSION 3.10)
project(N05_CW_N05_RacingSim)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(N05_CW_N05_RacingSim_lib SHARED Race.h Race.cpp Vehicle.h Vehicle.cpp ResultVehicle.h ResultVehicle.cpp GroundVehicle.h GroundVehicle.cpp Camel.h Camel.cpp HighSpeed_Camel.h HighSpeed_Camel.cpp Centaur.h Centaur.cpp AllTerrain_Boots.h AllTerrain_Boots.cpp AirVehicle.h AirVehicle.cpp FlyingCarpet.h FlyingCarpet.cpp Eagle.h Eagle.cpp Broom.h Broom.cpp)



add_executable(cmake-RacingSim N05_CW_N05_RacingSim.cpp)
target_link_libraries(cmake-RacingSim N05_CW_N05_RacingSim_lib)