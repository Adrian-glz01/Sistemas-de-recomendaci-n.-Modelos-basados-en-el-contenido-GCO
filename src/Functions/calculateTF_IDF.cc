#include "../includes/Functions.h"

/**
 * @author @Adrian-glz01
 * @author @AlejandroGarciaBautista
 * @author @Lucasperez02
 * 
 * @brief - Calculate the TF_IDF of an article(document)
 * 
 * @param vectorTF -- The vector TF of the article
 * @param resultIDF -- The vector IDF of the article
 * @return std::vector<double> -- The vector with the TF_IDF of the article
 */
std::vector<double> CalculateTF_IDF(std::vector<double> vectorTF, std::vector<double> resultIDF)
{
    std::vector<double> vectorTF_IDF;
    for (int i = 0; i < vectorTF.size(); i++)
    {
        vectorTF_IDF.push_back(vectorTF[i] * resultIDF[i]);  
    }

    return vectorTF_IDF;
}