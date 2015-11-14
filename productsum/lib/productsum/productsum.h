#ifndef _PRODUCTSUM_H_
#define _PRODUCTSUM_H_

#include <vector>

class ProductSum
{

    public:

        /**
         * @brief calcProductSum
         *  Calculates the sum of products of a certain part of the given vector _vector.
         *  The part is specified by a start index _start_idx and an end index _end_idx.
         * @param _vector
         *  The vector. It holds, that _vector.size() > 0. If not, the function throws
         *  an std::invalid_argument exception.
         * @param _start_idx
         *  The start index of the specified part of the vector. It holds, that
         *  _start_idx >= 0 && _start_idx < _vector.size() && _start_idx < _end_idx. If
         *  this condition fails, the function throws an std::invalid_argument exception.
         * @param _end_idx
         *  The end index of the specified part of the vector. It holds, that
         *  _end_idx > 0 && _end_idx > _start_idx && _end_idx <= _vector.size(). If
         *  this condition fails, the function thorws an std::invalid_argument exception.
         * @return
         *  Returns
         *      _vector[_start_idx] * _vector[_start_idx + 1] * ... * _vector[_end_idx - 1]
         */
        static double calcProductSum ( std::vector<int> &_vector, unsigned int _start_idx, unsigned int _end_idx );

};

#endif /* #define _PRODUCTSUM_H_ */
