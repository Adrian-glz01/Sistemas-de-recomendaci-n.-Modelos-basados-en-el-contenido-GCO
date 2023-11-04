#include "../includes/Functions.h"

/**
 * @author @Adrian-glz01
 * @author @AlejandroGarciaBautista
 * @author @Lucasperez02
 * 
 * @brief - Calculate the TF of an article(document)
 * 
 * @param termsRepeatedInArticle  - The terms repeated in the article
 * @return std::vector<double> - The vector with the TF of the article
 */
std::vector<double> CalculateTF(std::vector<double> termsRepeatedInArticle)
{
    std::vector<double> vectorTF;
    for (int i = 0; i < termsRepeatedInArticle.size(); i++)
    {
        vectorTF.push_back(1.0 + log10(termsRepeatedInArticle[i]));
    }
    return vectorTF;
}
