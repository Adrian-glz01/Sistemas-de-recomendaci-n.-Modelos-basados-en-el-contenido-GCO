#pragma once
#include <cmath>
#include <vector>
#include <cstring>
#include <iostream>
#include <set>
#include "Utils.h"

// double VectorLength(std::vector<double> article);
std::vector<int> CalculateDF(std::vector<std::set<std::string>> articles, std::set<std::string> actual_article, int pos_article);
// double Similarity(std::vector<double> article1, std::vector<double> article2);
// void NormalizeMatrix(std::vector<std::vector<double>> &matrix);
std::vector<double> CalculateTF(std::vector<double> termsRepeatedInArticle);
// std::vector<double> CalculateIDF(std::vector<int> resultDF, int numOfArticles);
// std::vector<double> CalculateTF_IDF(std::vector<double> matrixTF, std::vector<double> resultIDF);