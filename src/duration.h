#ifndef __DURATION__H
#define __DURATION__H

#include <assert.h>

class Duration
{
private:
    int time;
    int alarm;
    bool alarmHasBeenSet;
    bool checkAndUpdateAlarm();

public:
    Duration();
    Duration(int t);
    ~Duration();
    int getDuration();
    bool tick();
    bool tick(int t);
    void setAlarm(int t);

    void resetAlarm();         // extra method to tidy up code
    int getAlarm();            // for testing purposes since alarm is private
    bool getAlarmHasBeenSet(); // for testing purpose since alarmHasBeenSet is also private
};

#endif
