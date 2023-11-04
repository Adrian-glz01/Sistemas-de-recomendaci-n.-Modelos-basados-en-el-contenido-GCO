#include "../includes/Functions.h"

/**
 * @author @Adrian-glz01
 * @author @AlejandroGarciaBautista
 * @author @Lucasperez02
 * 
 * @brief - Calculate the similarity between two vectors
 * 
 * @param normalizeVect -- The vector normalized
 * @param terms -- The terms of the article
 */
void SimilarityPrint(std::vector<std::vector<double>> normalizeVect, std::vector<std::set<std::string>> terms, std::ofstream &outFile)
{
    for (int i = 0; i < normalizeVect.size(); i++)
    {
        std::vector<double> aux;
        for (int j = i + 1; j < normalizeVect.size(); j++)
        {
            outFile << "A" << i + 1<< " -> A" << j + 1 << ": " << Similarity(normalizeVect[i], terms[i], normalizeVect[j], terms[j]) << std::endl;
        }
    }
} 