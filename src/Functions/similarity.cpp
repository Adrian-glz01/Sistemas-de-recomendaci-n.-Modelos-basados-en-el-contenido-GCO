#include <vector>

double Similarity(std::vector<double> article1, std::vector<double> article2) {
    double result = 0.0;
    for (int i = 0; i < article1.size(); i++) {
        result += article1[i]*article2[i];
    }

    return result;
}