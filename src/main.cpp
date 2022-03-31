#include <iostream>
#include <stdio.h>
#include "SystemTime.hpp"
#include "HighResolutionTime.hpp"

int main(int argc, char* argv[])
{
    SystemTime* st = new SystemTime();
    printf("System Time________________%s\n", SystemTime::ToCStr(st));

    SystemTime::Wait(3);

    HighResolutionTime* hrt = new HighResolutionTime();
    printf("High Resolution Time_______%s\n", hrt->CStr());

    return EXIT_SUCCESS;
}
