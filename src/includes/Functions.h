#pragma once
#include <cmath>
#include <vector>
#include <cstring>
#include <iostream>
#include <set>
#include "Utils.h"

std::vector<double> CalculateIDF(std::vector<int> resultDF, int numOfArticles);
std::vector<double> CalculateTF_IDF(std::vector<double> vectorTF, std::vector<double> resultIDF);
std::vector<double> CalculateTF(std::vector<double> termsRepeatedInArticle);
std::vector<int> CalculateDF(std::vector<std::set<std::string>> articles, std::set<std::string> actual_article, int pos_article);
double VectorLength(std::vector<double> article);
std::vector<double> Normalize(std::vector<double> article);
double Similarity(std::vector<double> article1, std::set<std::string> terms_a1, std::vector<double> article2, std::set<std::string> terms_a2);
void SimilarityMatrix(std::vector<std::vector<double>> normalizeVect, std::vector<std::set<std::string>> terms);
