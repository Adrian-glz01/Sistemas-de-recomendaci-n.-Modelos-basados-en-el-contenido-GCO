#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <set>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <getopt.h>
#include <stdio.h>

void Usage(int argc, char *argv[], std::string& document, std::string& corpus, std::string& stop_words);
void printStopWords(std::vector<std::string> stop_words);
void printCorpus(std::vector<std::pair<std::string,std::string>> corpus);
std::vector<std::pair<std::string,std::string>> fill_corpus_vec(std::string text);
void changeDocumentWithCorpusWords(std::vector<std::vector<std::string>> &articles, std::vector<std::pair<std::string,std::string>> corpus);
