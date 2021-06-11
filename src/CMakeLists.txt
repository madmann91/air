add_library(air server.cpp)
target_include_directories(air PUBLIC ../include)
target_link_libraries(air PUBLIC sol::sol asio spdlog::spdlog)

add_executable(air-server main.cpp)
target_link_libraries(air-server PUBLIC air)

set_target_properties(air-server air PROPERTIES
    CXX_STANDARD 20
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
