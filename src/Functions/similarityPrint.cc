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
void SimilarityMatrix(std::vector<std::vector<double>> normalizeVect, std::vector<std::set<std::string>> terms)
{
    for (int i = 0; i < normalizeVect.size(); i++)
    {
        if (i == 0)
        {
            std::vector<double> aux;
            for (int j = 1; j < normalizeVect.size(); j++)
            {
                std::cout << "A" << i + 1<< ", A" << j + 1 << ": " << Similarity(normalizeVect[i], terms[i], normalizeVect[j], terms[j]) << std::endl;
            }
        } else {
            for (int j = 0; j < i; j++)
            {
                std::cout << "A" << i + 1 << ", A" << j + 1 << ": " << Similarity(normalizeVect[i], terms[i], normalizeVect[j], terms[j]) << std::endl;
            }

            for (int j = i + 1; j < normalizeVect.size(); j++)
            {
                std::cout << "A" << i << ", A" << j << ": " << Similarity(normalizeVect[i], terms[i], normalizeVect[j], terms[j]) << std::endl;
            }
        }
    }
} 