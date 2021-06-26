#ifndef TIMER_HEADER
#define TIMER_HEADER

/// Timer Class
//By YangZhengshi
// Time:2021 06 26
#include <chrono>
#include <ctime>


class WallTimer
{
private:
    typedef std::chrono::high_resolution_clock TimerClock;				
    typedef std::chrono::time_point<TimerClock> TimerTimePoint;			
    typedef std::chrono::duration<double, std::milli> TimerDurationMs;	

    TimerTimePoint start;							

public:
    WallTimer (void);
    void reset (void);								

    std::size_t get_elapsed (void) const;

    float get_elapsed_sec (void) const;
};



class ClockTimer
{
private:
    std::size_t start;

public:
    ClockTimer (void);
    void reset (void);

    static float now_sec (void);
    static std::size_t now (void);

    std::size_t get_elapsed (void) const;
    float get_elapsed_sec (void) const;
};

/* ---------------------------------------------------------------- */

inline
WallTimer::WallTimer (void)
{
    this->reset();
}

inline void
WallTimer::reset (void)
{
    this->start = TimerClock::now();
}

inline std::size_t
WallTimer::get_elapsed (void) const
{
    TimerDurationMs diff = TimerClock::now() - this->start;
    return diff.count();
}

inline float
WallTimer::get_elapsed_sec (void) const
{
    return static_cast<float>(this->get_elapsed()) / 1000.0f;
}

/* ---------------------------------------------------------------- */

inline
ClockTimer::ClockTimer (void)
{
    this->reset();
}

inline void
ClockTimer::reset (void)
{
    this->start = ClockTimer::now();
}

inline float
ClockTimer::now_sec (void)
{
    return (float)std::clock() / (float)CLOCKS_PER_SEC;
}

inline std::size_t
ClockTimer::now (void)
{
    return ((std::size_t)(std::clock()) * 1000) / (std::size_t)CLOCKS_PER_SEC;
}

inline float
ClockTimer::get_elapsed_sec (void) const
{
    return (1.0f / 1000.0f) * (float)this->get_elapsed();
}

inline std::size_t
ClockTimer::get_elapsed (void) const
{
    return ClockTimer::now() - start;
}


#endif 
