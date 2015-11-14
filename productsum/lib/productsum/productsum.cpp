#include "productsum.h"
#include <stdio.h>
#include <stdexcept>

double ProductSum::calcProductSum ( std::vector<int> &_vector, unsigned int _start_idx, unsigned int _end_idx )
{
    // TODO: Add your implementation here!

    if(!(_vector.size() > 0))
    {
        throw std::invalid_argument("vector size <0");
    }
    if(!(_start_idx >= 0 && _start_idx < _vector.size() && _start_idx < _end_idx))
    {
        throw std::invalid_argument("invalid start_index");
    }
    if(!(_end_idx > 0 && _end_idx > _start_idx && _end_idx <= _vector.size()))
    {
        throw std::invalid_argument("invalid end_index");
    }

    int result = _vector[_start_idx];
    for (int i =_start_idx +1 ; i <_end_idx ;i++)
    {
        //printf("result_before * vector: %d * %d \n",result,_vector[i]);
        result *=_vector[i];
        //printf("result_after: %d \n",result);
    }

    return result;

        std::logic_error("Not implemented yet.");

    return -1;
}

