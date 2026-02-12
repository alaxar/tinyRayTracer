add_library(VectorLib src/Vector.cpp)
target_include_directories(VectorLib
     PUBLIC
     ${CMAKE_CURRENT_SOURCE_DIR}/include
)