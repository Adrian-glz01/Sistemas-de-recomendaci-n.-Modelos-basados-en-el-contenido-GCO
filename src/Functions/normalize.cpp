#include <vector>

void NormalizeMatrix(std::vector<std::vector<double>> &matrix) 
{
    for (int i = 0; i < matrix.size(); i++) 
    {
        for (int j = 0; j  < matrix[i].size(); j++)
        {
            matrix[i][j] = (matrix[i][j] / matrix[i][matrix.size()-1]);

        }
    }
}