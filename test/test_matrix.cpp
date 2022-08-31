#include <gtest/gtest.h>

#include "../lib/include/matrix.h"

namespace {

TEST(Matrix, 2D_Matrix_test)
{
    Matrix<int, -1> matrix;
    EXPECT_EQ(matrix.size(), 0);

    // populate matrix
    for (int i = 0; i < 20; ++i) {
        matrix[i][i] = i;
    }
    EXPECT_EQ(matrix.size(), 20);

    // reset all elements
    for (int i = 0; i < 20; ++i) {
        matrix[i][i] = -1;
    }
    EXPECT_EQ(matrix.size(), 0);

    ((matrix[5][5] = 5) = 55) = 555;
    EXPECT_EQ(matrix.size(), 1);
    int elem = matrix[5][5];
    EXPECT_EQ(elem, 555);

    auto it = matrix.begin();
    const auto& [x, y, v] = *it;
    EXPECT_EQ(x, 5);
    EXPECT_EQ(y, 5);
    EXPECT_EQ(v, 555);
}

TEST(Matrix, 3D_Matrix_test)
{
    Matrix<int, 0, 3> matrix;
    EXPECT_EQ(matrix.size(), 0);

    // populate matrix
    for (int i = 0; i < 20; ++i) {
        for (int z = 0; z < 10; ++z) {
            matrix[i][i][z] = 5;
        }
    }
    EXPECT_EQ(matrix.size(), 200);

    int elem = matrix[5][5][5];
    EXPECT_EQ(elem, 5);

    int empty = matrix[50][50][50];
    EXPECT_EQ(empty, 0);
}

}  // namespace
