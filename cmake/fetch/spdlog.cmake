FetchContent_Declare(spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.11.0
        GIT_SHALLOW ON
        )
message(STATUS "Fetching spdlog")
FetchContent_MakeAvailable(spdlog)
message(STATUS "Fetch spdlog done")