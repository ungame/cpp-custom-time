#ifndef HIGH_RESOLUTION_TIME_HPP
#define HIGH_RESOLUTION_TIME_HPP

#include <string>
#include <chrono>

class HighResolutionTime
{
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> _clock;

    public:
        HighResolutionTime() { _clock = Now(); }
        inline std::chrono::time_point<std::chrono::high_resolution_clock> Clock() { return _clock; }

    public:
        inline static std::chrono::time_point<std::chrono::high_resolution_clock> Now() { return std::chrono::high_resolution_clock::now(); }

    public:
        static double Since(HighResolutionTime* time);

    public:
        std::string String();
        const char* CStr();
};

#endif
