#include <iostream>
#include "server.h"
int main()
{
    std::cout << "Hello Server \n";
    Server server;
    server.run();
    return 0;
}