#include "gtest/gtest.h"

#include "productsum/productsum.h"

TEST ( TestCalcProductSum, CorrectResult )
{
    std::vector<int> vector = { 1 , 2 , 3};

    ASSERT_EQ ( ProductSum::calcProductSum ( vector, 0, 3 ), 1 * 2 * 3 );
    ASSERT_EQ ( ProductSum::calcProductSum ( vector, 1, 3 ), 2 * 3 );
    ASSERT_EQ ( ProductSum::calcProductSum ( vector, 0, 1 ), 1 );
}

TEST ( TestCalcProductSum, CorrectResultWithZero )
{
    std::vector<int> vector = {0, 1, 2, 3};

    ASSERT_EQ ( ProductSum::calcProductSum ( vector, 0, 4 ), 0 );
    ASSERT_EQ ( ProductSum::calcProductSum ( vector, 0, 1 ), 0 );
    ASSERT_EQ ( ProductSum::calcProductSum ( vector, 1, 4 ), 1 * 2 * 3 );
}

TEST ( TestCalcProductSum, ViolatePreCondition )
{
    std::vector<int> empty_vector = {};
    std::vector<int> vector = {0, 8, 15};

    // Empty vector test.
    ASSERT_THROW ( ProductSum::calcProductSum ( empty_vector, 0, 1 ), std::invalid_argument );

    // Invalid start index.
    // ----------------------
    // _start_idx < _vector.size()
    ASSERT_THROW ( ProductSum::calcProductSum ( vector, 3, 3 ), std::invalid_argument );
    // _start_idx < _end_idx
    ASSERT_THROW ( ProductSum::calcProductSum ( vector, 3, 2 ), std::invalid_argument );

    // Invalid end index.
    // ----------------------
    // _end_idx > 0
    ASSERT_THROW ( ProductSum::calcProductSum ( vector, 0, 0 ), std::invalid_argument );
    // _end_idx > _start_idx
    ASSERT_THROW ( ProductSum::calcProductSum ( vector, 2, 1 ), std::invalid_argument );
    // _end_idx <= _vector.size()
    ASSERT_THROW ( ProductSum::calcProductSum ( vector, 0, 4 ), std::invalid_argument );
}
