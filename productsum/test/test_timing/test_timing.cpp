#include "gtest/gtest.h"

#include "timing/timing.h"

TEST ( TestGetTime, ReturnValidTimestamp )
{
    long timestamp = Timing::getTime();
    ASSERT_GT ( timestamp, 0 );
}

TEST ( TestGetTime, LogicalOrderOfTwoTimestamps )
{
    long ts1 = Timing::getTime();
    long ts2 = Timing::getTime();
    ASSERT_GT ( ts2, ts1 );
}

TEST ( TestGetTimeDifference, PositiveResult )
{
    long ts1 = Timing::getTime();
    long ts2 = Timing::getTime();
    long diff = Timing::getTimeDifference ( ts1, ts2 );
    ASSERT_GT ( diff, 0 );
}

TEST ( TestGetTimeDifference, CorrectResult )
{
    long ts1 = 100;
    long ts2 = 200;
    long ts3 = Timing::getTime();
    ASSERT_EQ ( Timing::getTimeDifference ( ts1, ts2 ), 100 );
    ASSERT_EQ ( Timing::getTimeDifference ( ts1, ts1 ), 0 );
    ASSERT_EQ ( Timing::getTimeDifference ( 0, ts3 ), ts3 );
}

TEST ( TestGetTimeDifference, ViolatePreCondition )
{
    long ts1 = 100;
    long ts2 = 200;
    ASSERT_THROW ( Timing::getTimeDifference ( ts2, ts1 ), std::invalid_argument );
}
