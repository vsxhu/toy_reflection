#pragma once

#define CATCH_CONFIG_RUNNER
#include "catch2/catch.hpp"

namespace tmp::test
{
std::string test_folder{};
}
int main(int argc, char *argv[])
{
    Catch::Session session;

    using namespace Catch::clara;
    auto cli = session.cli() | Opt(tmp::test::test_folder,
                                   "path")["-p"]["--test_folder"]("path to the test data folder");
    session.cli(cli);

    int ec = session.applyCommandLine(argc, argv);
    if (ec != 0)  // Indicates a command line error
    {
        return ec;
    }

    return session.run();
}