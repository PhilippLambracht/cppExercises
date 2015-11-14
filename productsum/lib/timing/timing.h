#ifndef _TIMING_H_
#define _TIMING_H_

class Timing
{

    public:
        /**
             * @brief getTime Calculates the current time in nanoseconds.
             * @return Returns the current time in nanoseconds using the CLOCK_REALTIME:
             */
        static long getTime();

        /**
         * @brief getTimeDifference Calculates the difference of two timestamps.
         * @param _start The start timestamp.
         * @param _end The end timestamp. It holds, that _start <= _end. If not, the function
         *  throws an std::invalid_argument exception.
         * @return Returns _end - _start.
         */
        static long getTimeDifference ( long _start, long _end );

};

#endif /* _TIMING_H_ */
