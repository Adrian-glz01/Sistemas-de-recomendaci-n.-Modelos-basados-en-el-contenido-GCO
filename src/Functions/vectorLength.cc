#include "../includes/Functions.h"

/**
 * @author @Adrian-glz01
 * @author @AlejandroGarciaBautista
 * @author @Lucasperez02
 * 
 * @brief Calculate the length of a vector adding the square of each element
 * 
 * @param article -- The vector to calculate the length
 * @return double -- The length of the vector
 */
double VectorLength(std::vector<double> article)
{
    double sum = 0.0;
    for (int i = 0; i < article.size(); i++)
    {
        sum += (article[i] * article[i]);
    }
    return sqrt(sum);
}