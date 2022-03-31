#include "HighResolutionTime.hpp"

#include <chrono>
#include <string>
#include <cstring>
#include <ctime>

// static method
double HighResolutionTime::Since(HighResolutionTime* time)
{
    std::chrono::duration<double> elapsed = Now() - time->Clock();

    return elapsed.count();
}

std::string HighResolutionTime::String()
{
    time_t tt = std::chrono::high_resolution_clock::to_time_t(_clock);
    auto lt = localtime(&tt);
    char strTime[] = {0};
    strftime(strTime, 20, "%Y-%m-%d %H:%M:%S", lt);
    return std::string(strTime);
}

const char* HighResolutionTime::CStr()
{
    std::string str = String();
    int len = str.length();
    char* cstr = (char*) malloc(sizeof(char) * len);
    strcpy(cstr, str.c_str());
    return cstr;
}