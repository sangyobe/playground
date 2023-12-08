#include <tclap/CmdLine.h>
#include <iostream>

int main(int argc, char** argv)
{
    try 
    {
        // parse command line
        TCLAP::CmdLine cmd("TCLAP(Templatized C++ Command Line Arguments Parser Library) tester");
        TCLAP::ValueArg<uint16_t> port("p", "port", "Port number.", false, 50051, "unsigned short int");
        TCLAP::ValueArg<std::string> ip_addr("a", "ip_addr",
                                            "IP address.",
                                            false, "127.0.0.1", "string");
        cmd.add(ip_addr);
        cmd.add(port);
        cmd.parse(argc, argv);


        std::cout << "ip address= " << ip_addr.getValue() << std::endl;
        std::cout << "port= " << port.getValue() << std::endl;
    }
    catch (TCLAP::ArgException &e) // catch any exceptions
    {
        std::cout << "error: " << e.error() << " for arg " << e.argId();
        return -1;
    }


    return 0;

}