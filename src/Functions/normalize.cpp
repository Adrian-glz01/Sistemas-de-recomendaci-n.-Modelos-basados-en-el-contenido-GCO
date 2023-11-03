#include "../includes/Functions.h"

void NormalizeMatrix(std::vector<std::vector<std::string>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            matrix[i][j] = std::to_string(std::stod(matrix[i][j]) / VectorLength(matrix[i]));
        }
    }
}