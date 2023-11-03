#include "../includes/Functions.h"

std::vector<int> CalculateDF(std::vector<std::vector<std::string>> &matrix)
{
    std::vector<int> resultDF;
    int count = 0;
    for (int j = 0; j < matrix[0].size(); j++)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            if (std::stod(matrix[j][i]) != 0)
            {
                count++;
            }
        }
        resultDF.push_back(count);
        count = 0;
    }
    return resultDF;
}