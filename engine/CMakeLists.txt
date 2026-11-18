file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(brick_engine STATIC ${ENGINE_SOURCES})

target_include_directories(brick_engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(brick_engine PUBLIC
    glad
    glfw
    glm::glm
    OpenGL::GL
    spdlog::spdlog
)

target_precompile_headers(brick_engine PRIVATE
    <iostream>
    <memory>
    <algorithm>
    <string>
    <vector> 
    <unordered_map>
)