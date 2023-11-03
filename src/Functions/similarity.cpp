#include "../includes/Functions.h"

double Similarity(std::vector<std::string> article1, std::vector<std::string> article2)
{
    double result = 0.0;
    for (int i = 0; i < article1.size(); i++)
    {
        result += std::stod(article1[i]) * std::stod(article2[i]);
    }

    return result;
}