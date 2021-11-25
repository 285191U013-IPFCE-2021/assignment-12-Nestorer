#include "duration.h"

#include <assert.h>
#include <limits>

Duration::Duration()
{
    resetAlarm();
    time = 0;
}

Duration::Duration(int t)
{
    assert(t >= 0);
    resetAlarm();
    time = t;
}

Duration::~Duration()
{
}

bool Duration::tick()
{
    time = time + 1;
    return checkAndUpdateAlarm();
}

int Duration::getDuration()
{
    return time;
}

bool Duration::tick(int t)
{
    assert(t >= 0);

    time = time + t;
    return checkAndUpdateAlarm();
}

void Duration::setAlarm(int t)
{
    assert(t > time);
    alarm = t;
    alarmHasBeenSet = true;
}

bool Duration::checkAndUpdateAlarm()
{
    if (time > alarm)
    {
        resetAlarm();
        return true;
    }
    return false;
}

void Duration::resetAlarm()
{
    alarm = std::numeric_limits<int>::max();
    alarmHasBeenSet = false;

    // having the alarm default to max_int we can do the simple check (time>alarm) in all methods
    // without ever worrying about time accidentally crossing the alarm value without it being intended.
}

int Duration::getAlarm()
{
    return alarm;
}

bool Duration::getAlarmHasBeenSet()
{
    return alarmHasBeenSet;
}