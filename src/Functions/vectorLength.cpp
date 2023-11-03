#include "../includes/Functions.h"

double VectorLength(std::vector<std::string> article)
{

    double sum = 0.0;
    for (int i = 0; i < article.size(); i++)
    {
        sum += pow(std::stod(article[i]), 2);
    }

    return sqrt(sum);
}