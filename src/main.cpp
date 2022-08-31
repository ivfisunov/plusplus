#include <iostream>
#include "matrix.h"

int main(int, char**)
{
    Matrix<int, 0> matrix;

    for (int i = 0; i < 10; ++i) {
        matrix[i][i] = i;
        matrix[i][9 - i] = 9 - i;
    }

    for (int y = 1; y < 9; ++y) {
        for (int x = 1; x < 9; ++x) {
            std::cout << matrix[x][y] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "Matrix size = " << matrix.size() << std::endl;

    std::cout << std::endl << "All matrix elements:" << std::endl;
    for (const auto& elem : matrix) {
        const auto& [x, y, v] = elem;
        std::cout << x << y << v << std::endl;
    }

    return 0;
}
