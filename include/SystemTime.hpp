#ifndef SYSTEM_TIME_HPP
#define SYSTEM_TIME_HPP

#include <chrono>
#include <string>

class SystemTime
{
    private:
        std::chrono::time_point<std::chrono::system_clock> _clock;

    public:
        SystemTime() { _clock = Now(); }
        inline std::chrono::time_point<std::chrono::system_clock> Clock() { return _clock; }

    public:
        inline static std::chrono::time_point<std::chrono::system_clock> Now() { return std::chrono::system_clock::now(); }

    public:
        static double Since(SystemTime* st);
        static std::string ToString(SystemTime* st);
        static const char* ToCStr(SystemTime* st);
        static void Wait(double seconds);
};

#endif