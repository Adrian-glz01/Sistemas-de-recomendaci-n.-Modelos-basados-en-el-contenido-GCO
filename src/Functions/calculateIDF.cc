#include "../includes/Functions.h"

/**
 * @author @Adrian-glz01
 * @author @AlejandroGarciaBautista
 * @author @Lucasperez02
 * 
 * @brief - Calculate the IDF of an article(document)
 * 
 * @param resultDF -- The vector DF of the article
 * @param numOfArticles -- The number of articles
 * @return std::vector<double> -- The vector with the IDF of the article
 */
std::vector<double> CalculateIDF(std::vector<int> resultDF, int numOfArticles)
{
    std::vector<double> resultIDF;
    double numOfArticles_d = numOfArticles;
    for (int i = 0; i < resultDF.size(); i++)
    {
        double resultDF_d = resultDF[i];
        resultIDF.push_back(log10((numOfArticles_d/resultDF_d)));
    }
    return resultIDF;
}