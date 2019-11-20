#include <iostream>
#include "Test.h"

int main(int argc, char** argv)
{
    Test test;
    test.SetName("MyName");
    std::cout << test.GetName() << std::endl ;    
    return 0;
}