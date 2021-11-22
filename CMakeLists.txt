cmake_minimum_required(VERSION 3.10)


# set the project name
project(Session04)

find_package(GLUT REQUIRED)

# add the executable
add_executable(ue04 src/opengl_cgr.cpp)


target_link_libraries(ue04 PRIVATE GLUT::GLUT)