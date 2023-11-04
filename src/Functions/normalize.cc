#include "../includes/Functions.h"

/**
 * @author @Adrian-glz01
 * @author @AlejandroGarciaBautista
 * @author @Lucasperez02
 * 
 * @brief - Calculate the normalize vector
 * 
 * @param article - The vector to normalize
 * @return std::vector<double> - The normalize vector
 */
std::vector<double> Normalize(std::vector<double> article)
{
    std::vector<double> normalize_vec;
    for (int i = 0; i < article.size(); i++)
    {
        normalize_vec.push_back(article[i] / VectorLength(article));

    }
    return normalize_vec;
}