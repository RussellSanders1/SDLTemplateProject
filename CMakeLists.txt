cmake_minimum_required(VERSION 3.14)
project(Project)
set(CMAKE_CXX_STANDARD 17)

##WINDOWS SETUP:
# download your desired SDL packages, store them in a directory that you can
# easily access (C:\SDL or similar is a good, easy-to-remember option)
# combine all SDL packages (mixer, ttf, image, etc.) into one directory
#       - lib folders from all packages merged into one, etc.
# add SDL binary folder to PATH in environment variables in Windows (SDL\bin)
##

##MAC SETUP NOT AVAILABLE YET

##THIS IS WHERE THE FIND.cmake FILES ARE
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

##THESE USE THE CMAKE FILES TO FIND THE SDL2 PACKAGES
find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

##THESE FLAGS MUST BE SET
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

##DIRECTORIES FOR SDL INCLUDES GO HERE
include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_MIXER_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        )

##ADD SOURCE FILES HERE
add_executable(Project main.cpp SDL_Plotter.h SDL_Plotter.cpp)

##AFTER EXECUTABLE IS ADDED, LINK THE SDL LIBRARIES
target_link_libraries(Project
        ${SDL2_MAIN_LIBRARY}
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES}
        )

