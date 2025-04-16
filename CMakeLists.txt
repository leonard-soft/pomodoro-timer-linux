cmake_minimum_required(VERSION 3.10)

project(ptimer VERSION 1.0)

add_executable(ptimer src/main.cpp
src/app/App.cpp
src/separators/Separators.cpp
src/timer/Timer.cpp
libs/include/miniaudio.c)

include_directories(libs/include/)

# Instalar el ejecutable
install(TARGETS ptimer DESTINATION bin)

# Instalar archivos de sonido
install(FILES assets/sound.wav DESTINATION share/ptimer/assets)

# Instalar licencia MIT
install(FILES LICENSE DESTINATION share/ptimer)
