#include "../includes/Functions.h"

/**
 * @author @Adrian-glz01
 * @author @AlejandroGarciaBautista
 * @author @Lucasperez02
 * 
 * @brief Calculate the similarity between two articles
 * 
 * @param article1 -- The first article
 * @param terms_a1 -- The terms of the first article
 * @param article2 -- The second article 
 * @param terms_a2 -- The terms of the second article
 * @return double -- The similarity between two articles
 */
double Similarity(std::vector<double> article1, std::set<std::string> terms_a1, std::vector<double> article2, std::set<std::string> terms_a2)
{
    std::vector<std::pair<std::string, double>> aux1, aux2;
    int i = 0;
    for (auto term : terms_a1)
    {
        std::pair<std::string,double> aux = std::make_pair(term, article1[i]);
        aux1.push_back(aux);
        i++;
    }

    i = 0;
    for (auto term : terms_a2)
    {
        std::pair<std::string,double> aux = std::make_pair(term, article2[i]);
        aux2.push_back(aux);
        i++;
    }

    std::vector<std::pair<std::string, double>> a1, a2;

    if (aux1.size() > aux2.size())
    {
        for (auto actual_pair : aux1)
        {
            for (auto compare_pair : aux2)
            {
                if (actual_pair.first == compare_pair.first)
                {
                    a1.push_back(actual_pair);
                    a2.push_back(compare_pair);
                }
            }
        }
    } else {
        for (auto actual_pair : aux2)
        {
            for (auto compare_pair : aux1)
            {
                if (actual_pair.first == compare_pair.first)
                {
                    a2.push_back(actual_pair);
                    a1.push_back(compare_pair);
                }
            }
        }
    }

    double result = 0.0;
    if (a1.size() != 0)
    {
        for (int i = 0; i < a1.size(); i++)
        {
            result += (a1[i].second * a2[i].second);
        }
    }
    
    return result;
}