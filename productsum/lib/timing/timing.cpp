#include "timing.h"

#include <time.h>
#include <stdexcept>

long Timing::getTime()
{
    timespec timestamp;
    clock_gettime ( CLOCK_REALTIME, &timestamp );
    return timestamp.tv_sec * 1e9 + timestamp.tv_nsec;
}

long Timing::getTimeDifference ( long _start, long _end )
{
    if ( _start > _end )
    {
        throw std::invalid_argument ( "Timing::getTimeDifference - PreCondition violation: _start <= _end." );
    }

    return _end - _start;
}
