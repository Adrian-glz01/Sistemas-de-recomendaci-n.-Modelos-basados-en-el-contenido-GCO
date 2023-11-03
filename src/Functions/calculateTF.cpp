#include "../includes/Functions.h"

std::vector<double> CalculateTF(std::vector<double> termsRepeatedInArticle)
{
    std::vector<double> vectorTF;
    for (int i = 0; i < termsRepeatedInArticle.size(); i++)
    {
        vectorTF.push_back(1 + log10(termsRepeatedInArticle[i]));
    }
    return vectorTF;
}