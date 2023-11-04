#include "./includes/Utils.h"
#include "includes/Functions.h"

/**
 * @brief - Main function
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]) 
{
    std::ofstream outFile("result.txt", std::ios::out | std::ios::trunc);
    std::string corpus_file{""}, document_file{""}, stop_word_file{""};
    Usage(argc, argv, document_file, corpus_file, stop_word_file);

    /* Openning all files */
    std::ifstream corpus{corpus_file};
    std::ifstream stop_word{stop_word_file};
    std::ifstream document{document_file};
    
    //* Reading corpus file: 
    std::string line;
    std::getline(corpus,line);

    line.erase(std::remove(line.begin(), line.end(), '"'), line.end());
    line.erase(std::remove(line.begin(), line.end(), '{'), line.end());
    line.erase(std::remove(line.begin(), line.end(), '}'), line.end());

    std::vector<std::pair<std::string,std::string>> corpus_vec = fill_corpus_vec(line);

    //* Reading stop word file
    std::vector<std::string> stop_words_vec;
    std::string actual_stop_word{""};
    std::getline(stop_word, actual_stop_word);
    while (std::getline(stop_word, actual_stop_word)) {
        // Remove whitespace from the beginning and end of the word

        if (!actual_stop_word.empty() && actual_stop_word.back() == '\r') {
            actual_stop_word.pop_back(); // Remove carriage return character ('\r') if present
        }
        if (!actual_stop_word.empty() && actual_stop_word.back() == '\n') {
            actual_stop_word.pop_back(); // Remove line break character ('\n') if present
        }
        stop_words_vec.push_back(actual_stop_word);
    }

    // Remove the start of file and line break signs from the words in the stop words file
    for (auto element: stop_words_vec)
    {
        int counter = 0;
        for (int i = 0; i < element.size(); i++)
        {   
            counter++;
        }
    }

    /* Procesar el docmuent*/
    std::string actual_line;
    std::vector<std::vector<std::string>> articles;

    while(std::getline(document, actual_line))
    {
        actual_line.erase(std::remove(actual_line.begin(), actual_line.end(), '.'), actual_line.end());
        actual_line.erase(std::remove(actual_line.begin(), actual_line.end(), ','), actual_line.end());
        
        std::istringstream stream(actual_line);
        std::vector<std::string> actual_article, aux;
        
        std::string word;

        while (stream >> word) 
        {
            std::string word_tolower{""};
            for (auto character : word)
            {
                word_tolower += std::tolower(character);
            }
            actual_article.push_back(word_tolower);
        }

        for (int i = 0; i < actual_article.size(); i++) 
        {
            bool is_stop_word = false;
            for (int j = 0; j < stop_words_vec.size(); j++)
            {
                if (actual_article[i] == stop_words_vec[j])
                {
                    is_stop_word = true;
                    break;  // Exit the inner loop as soon as stop word is found
                }
            }
            
            if (!is_stop_word)
            {
                aux.push_back(actual_article[i]);
            }
        }

        articles.push_back(aux);
    }

    changeDocumentWithCorpusWords(articles, corpus_vec);

    std::vector<std::set<std::string>> WORDS;
    std::vector<std::vector<double>> VALUES;

    for (int i = 0; i < articles.size(); i++)
    {
        std::set<std::string> aux;
        for (int j = 0; j < articles[i].size(); j++)
        {
            aux.insert(articles[i][j]);
        }
        WORDS.push_back(aux);
    }

    for (int i = 0; i < WORDS.size(); i++)
    {
        std::vector<double> aux;
        for (auto word : WORDS[i])
        {
            int counter = 0;
            for (int j = 0; j < articles[i].size(); j++)
            {
                if (word == articles[i][j])
                {
                    counter++;
                }
            }
            aux.push_back(counter);
        }
        VALUES.push_back(aux);
    }

    std::vector<std::vector<int>> ARTICLE_DF;
    for (int i = 0; i < WORDS.size(); i++ )
    {
        ARTICLE_DF.emplace_back(CalculateDF(WORDS, WORDS[i], i));
    }

    std::vector<std::vector<double>> ARTICLE_TF;
    for (int i = 0; i < VALUES.size(); i++)
    {
        ARTICLE_TF.emplace_back(CalculateTF(VALUES[i]));
    }

    std::vector<std::vector<double>> ARTICLE_IDF;
    int n_articles = ARTICLE_DF.size();
    for (int i = 0; i < n_articles; i++) {
        ARTICLE_IDF.emplace_back(CalculateIDF(ARTICLE_DF[i], n_articles));
    }

    std::vector<std::vector<double>> ARTICLE_TF_IDF;
    for (int i = 0; i < n_articles; i++)
    {
        ARTICLE_TF_IDF.emplace_back(CalculateTF_IDF(ARTICLE_TF[i], ARTICLE_IDF[i]));
    }

    std::vector<std::vector<double>> normalize_vec;
    for (int i = 0; i < n_articles; i++)
    {
        normalize_vec.emplace_back(Normalize(ARTICLE_TF[i]));
    }


    
    int n = 0;
    for (auto element: WORDS) {
        int i = 0;
        outFile << "**Articulo** " << n + 1 << std::endl;
        outFile << "-----------" << "\n";
        outFile << std::left << std::setw(35) << "Termino" << std::setw(10) << "Rep" << std::setw(10) << "DF" << std::setw(10) << "IDF" << std::setw(10) << "TF" << std::setw(10) << "TF-IDF" << "\n";
        for (auto word : element)
        {
            outFile << std::left<< std::setw(35) << word << std::setw(10) << VALUES[n][i] << std::setw(10) << ARTICLE_DF[n][i] << std::setw(10) << ARTICLE_IDF[n][i] << std::setw(10) << ARTICLE_TF[n][i]<< std::setw(10) << ARTICLE_TF_IDF[n][i] << std::endl;
            i++;
        }
        outFile << std::endl << std::endl;
        n++;
    }

    outFile << "-----Similitudes-----\n";
    SimilarityPrint(normalize_vec, WORDS, outFile);
    outFile.close();
    return 0;
}
