include(fetch/catch2)

list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/contrib)

include(Catch)
set(test_sources
        test_tmp_lib.cpp
        )

foreach (test ${test_sources})
    get_filename_component(test_target ${test} NAME_WE)

    message(STATUS "${PROJECT_NAME} add test ${test_target}")

    add_executable(${test_target} ${test})

    target_link_libraries(${test_target}
            PRIVATE
            Catch2::Catch2
            ${PROJECT_NAME}
            )
    catch_discover_tests(${test_target})
endforeach ()