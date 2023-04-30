file(GLOB sources *.cpp *.h)

if (BUILD_STATIC_LIB)
    add_library(${CMAKE_PROJECT_NAME}
            STATIC
            ${sources}
            )
else ()
    add_library(${CMAKE_PROJECT_NAME}
            SHARED
            ${sources}
            )
    set_target_properties(${CMAKE_PROJECT_NAME}
            PROPERTIES
            POSITION_INDEPENDENT_CODE ON
            )
endif ()

target_include_directories(${CMAKE_PROJECT_NAME}
        INTERFACE
        ${PROJECT_SOURCE_DIR}/include
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
        )
target_link_libraries(${CMAKE_PROJECT_NAME}
        PRIVATE
        spdlog::spdlog
        )