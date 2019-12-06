
#include <cstddef>
#include <WaitingPolicy.h>
#include <LMS7002M/LMS7002M_time.h>
#include <LMS7002M/LMS7002M_config.h>

typedef hw::BusyWaitingPolicy<1,2> Wainting1msPolicy;
Wainting1msPolicy waiting1mspolicy;

extern "C" LMS7002M_API long long LMS7_time_tps()
{
    return 1000;
}

//extern "C" LMS7002M_API long long LMS7_time_now()
//{
//    return 0;
//}

extern "C" LMS7002M_API void LMS7_sleep_for(const long long ticks)
{
    long long tocks = ticks;
    if(tocks < 1) return;
    while(tocks--)
        waiting1mspolicy.wait<1, boost::chrono::milliseconds>();
}

//extern "C" LMS7002M_API void LMS7_sleep_until(const long long ticks)
//{
//    LMS7_sleep_for(ticks);
//}
