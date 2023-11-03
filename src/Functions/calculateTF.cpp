#include "../includes/Functions.h"

void CalculateTF(std::vector<std::vector<std::string>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            matrix[i][j] = std::to_string(1 + log10(std::stod(matrix[i][j])));
        }
    }
}