#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "..\..\include\duration.h"

// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file.

TEST_CASE("constructors + getDuration")
{

    // testing duration and tick methods
    Duration d0 = Duration();
    Duration d1 = Duration(5);
    Duration d2 = Duration(10);
    Duration d3 = Duration(1000000);

    REQUIRE(d0.getDuration() == 0);
    REQUIRE(d1.getDuration() == 5);
    REQUIRE(d2.getDuration() == 10);
    REQUIRE(d3.getDuration() == 1000000);
}

TEST_CASE("tick")
{
    Duration d0 = Duration();
    Duration d1 = Duration(5);
    Duration d2 = Duration(10);
    Duration d3 = Duration(1000);

    d0.tick();
    d1.tick(0);
    d2.tick(10);
    d3.tick(9000);

    REQUIRE(d0.getDuration() == 0 + 1);
    REQUIRE(d1.getDuration() == 5 + 0);
    REQUIRE(d2.getDuration() == 10 + 10);
    REQUIRE(d3.getDuration() == 1000 + 9000);

    d1.tick(100);
    REQUIRE(d1.getDuration() == 100 + 5);
}

TEST_CASE("alarm stuff")
{
    Duration d0 = Duration();
    Duration d1 = Duration(5);
    Duration d2 = Duration(10);
    d0.setAlarm(1000);
    d1.setAlarm(2000);

    REQUIRE(d0.getAlarm() == 1000);
    REQUIRE(d1.getAlarm() == 2000);
    REQUIRE(d0.getAlarmHasBeenSet() == true);
    REQUIRE(d1.getAlarmHasBeenSet() == true);
    REQUIRE(d2.getAlarmHasBeenSet() == false);

    REQUIRE(d0.tick(500) == false);
    REQUIRE(d0.tick(1000) == true);            // time should be greater than alarm now, so return true
    REQUIRE(d0.getAlarm() != 1000);            // we check that it reassigns the alarm to limit
    REQUIRE(d0.getAlarmHasBeenSet() == false); // we check alarm is no longer set
}