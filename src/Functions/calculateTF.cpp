#include <vector>
#include <cmath>

void CalculateTF(std::vector<std::vector<double>> &matrix) 
{
    for (int i = 0; i < matrix.size(); i++) 
    {
        for (int j = 0; j  < matrix[i].size(); j++)
        {
            matrix[i][j] = 1+log10(matrix[i][j]);

        }
    }
}