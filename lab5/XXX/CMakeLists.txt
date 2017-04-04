
project(XXX)

set(HEDEAR_FILES XXX.h)
set(SOURCE_FILES XXX.cpp)

add_library(libxxx STATIC ${SOURCE_FILES})
target_include_directories(libxxx PUBLIC .)

add_executable(XXX ${SOURCE_FILES} main.cpp)

target_link_libraries(XXX libxxx)

