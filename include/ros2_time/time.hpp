#ifndef ROS2_TIME_TIME_HPP
#define ROS2_TIME_TIME_HPP


// standard headers
#include <chrono>

// project headers
#include <ros2_time/duration.hpp>


namespace ros2_time
{

  
// various types
typedef std::chrono::time_point<std::chrono::steady_clock> TimePoint;

  
class Time
{
public:
    Time();

    bool isValid() const;
  
    int32_t toSec() const;
    uint64_t toNSec() const;

    Time& fromSec(const long sec);
    Time& fromNSec(const long time);

    TimePoint getTimePoint() const;
  
    static Time now();
  
    bool operator<(const Time& rhs);
    Time operator+(const Duration& dur);
    Time& operator+=(const Duration& dur);
    Duration operator-(const Time& rhs);
  
protected:
    void normalizeSecNSec(unsigned long& sec, unsigned long& nsec);

    TimePoint m_time;
};


}  // end of the ros2_time namespace


#endif  // ROS2_TIME_TIME_HPP