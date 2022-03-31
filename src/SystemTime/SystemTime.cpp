#include "SystemTime.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <string>
#include <cstring>
#include <ctime>

// static method
double SystemTime::Since(SystemTime* time)
{
    std::chrono::duration<double> elapsed = Now() - time->Clock();

    return elapsed.count();
}

std::string SystemTime::ToString(SystemTime* st)
{
    time_t tt = std::chrono::system_clock::to_time_t(st->Clock());
    auto lt = localtime(&tt);
    char strTime[] = {0};
    strftime(strTime, 20, "%Y-%m-%d %H:%M:%S", lt);
    return std::string(strTime);
}

const char* SystemTime::ToCStr(SystemTime* st)
{
    std::string str = ToString(st);
    int len = str.length();
    char* cstr = (char*) malloc(sizeof(char) * len);
    strcpy(cstr, str.c_str());
    return cstr;
}

void SystemTime::Wait(double seconds)
{
    SystemTime* started = new SystemTime();

    double elapsed = Since(started);

    printf("Started: %s\n", SystemTime::ToCStr(started));

    while(elapsed < seconds)
    {
        elapsed = Since(started);
        printf("%s Waiting...\n", SystemTime::ToCStr(new SystemTime()));
    }

    printf("Finished: %s\n", SystemTime::ToCStr(new SystemTime()));
}