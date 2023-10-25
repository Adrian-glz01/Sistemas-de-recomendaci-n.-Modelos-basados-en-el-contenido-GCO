#include <cmath>
#include <vector>

double VectorLength(std::vector<double> article) {

    double sum = 0.0;
    for (int i = 0; i < article.size(); i++) {
        sum += pow(article[i],2);
    }

    return sqrt(sum);
}