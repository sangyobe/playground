#include "cmdopts.hpp"
#include <iostream>
#include <string>

int main(int argc, const char* argv[])
{
    struct MyOpts
    {
        std::string stringOpt{};
        int intOpt{};
        bool boolOpt{};
    };

    auto parser = CmdOpts<MyOpts>::Create({
        {"--opt1", &MyOpts::stringOpt },
        {"--opt2", &MyOpts::intOpt},
        {"--opt3", &MyOpts::boolOpt}});

    auto myopts = parser->parse(argc, argv);

    std::cout << "stringOpt = " << myopts.stringOpt << std::endl;
    std::cout << "intOpt = " << myopts.intOpt << std::endl;
    std::cout << "boolOpt = " << myopts.boolOpt << std::endl;

    return 0;
}