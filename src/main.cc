#include "./includes/Utils.h"
// #include "includes/Functions.h"
#include <stdio.h>
#include <set>
#include <iomanip>

double log10(double x) {
    return log(x) / log(10.0);
}

std::vector<double> CalculateIDF(std::vector<int> resultDF, int numOfArticles)
{
    std::vector<double> resultIDF;
    for (int i = 0; i < resultDF.size(); i++)
    {
        std::cout << numOfArticles << "/" << resultDF[i] << "-->" << log10(numOfArticles/resultDF[i]) << "\n";
        resultIDF.push_back(log10(static_cast<double>(numOfArticles/resultDF[i])));
    }
    std::cout << "-------------------------------\n";
    return resultIDF;
}

std::vector<double> CalculateTF(std::vector<double> termsRepeatedInArticle)
{
    std::vector<double> vectorTF;
    for (int i = 0; i < termsRepeatedInArticle.size(); i++)
    {
        vectorTF.push_back(1 + log10(termsRepeatedInArticle[i]));
    }
    return vectorTF;
}

std::vector<int> CalculateDF(std::vector<std::set<std::string>> articles, std::set<std::string> actual_article, int pos_article)
{
    std::vector<int> resultDF;
    int count;

    if (pos_article == 0)
    {
        for (auto actual_term : actual_article)
        {
            count = 1;
            for (int i = 1; i < articles.size(); i++)
            {
                std::set<std::string> article_n = articles[i];
                for (auto aux : article_n)
                {
                    if (actual_term == aux)
                    {
                        count++;
                        break;
                    }
                }  
            }
            resultDF.push_back(count);
        }
    } else {
        for (auto actual_term : actual_article)
        {
            int i = 0;
            count = 1;
            for (i; i < pos_article; i++)
            {
                std::set<std::string> article_n = articles[i];
                for (auto aux : article_n)
                {
                    if (actual_term == aux)
                    {
                        count++;
                        break;
                    }
                }  
            }

            for (i = pos_article + 1; i < articles.size(); i++)
            {
                std::set<std::string> article_n = articles[i];
                for (auto aux : article_n)
                {
                    if (actual_term == aux)
                    {
                        count++;
                        break;
                    }
                }  
            }
            resultDF.push_back(count);
        }
    }
    return resultDF;
}


void changeDocumentWithCorpusWords(std::vector<std::vector<std::string>> &articles, std::vector<std::pair<std::string,std::string>> corpus) 
{
    for (int i = 0; i < articles.size(); i++)
    {
        for (int j = 0; j < articles[i].size(); j++)
        {
            for (int k = 0; k < corpus.size(); k++)
            {
                if (articles[i][j] == corpus[k].first)
                {
                    articles[i][j] = corpus[k].second;
                }
            }
        }
    }
}

std::vector<std::pair<std::string,std::string>> fill_corpus_vec(std::string text)
{
    std::vector<std::pair<std::string,std::string>> result_pair_vec;
    std::string key{""}, value{""};
    bool start_value = false;
    for (int i = 0; i < text.size(); i++) 
    {
        if(text[i] == ':') 
        {
            start_value = true;
        } else if (text[i] == ',')
        {
            result_pair_vec.emplace_back(std::make_pair(key,value));
            key = "";
            value = "";
            start_value = false;
            
        }

        if (start_value)
        {
            if (text[i] != ':') 
            {
                value += text[i];
            }
        } else 
        {
            if (text[i] != ',')
            {
                key += text[i];
            }
        }
        
    }
    return result_pair_vec;
}

void printCorpus(std::vector<std::pair<std::string,std::string>> corpus) 
{   
    for (int i = 0; i < corpus.size(); i++)
    {
        std::cout << corpus[i].first << " " << corpus[i].second << "\n";
    }
}

void printStopWords(std::vector<std::string> stop_words)
{
    int i = 0;
    for (auto element: stop_words)
    {
        i++;
        if (i > stop_words.size() - 20)
        {
            std::cout << element << "\n";
        }
    }
}

int main(int argc, char* argv[]) 
{
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
    //printCorpus(corpus_vec);

    //* Reading stop word file
    std::vector<std::string> stop_words_vec;
    std::string actual_stop_word{""};
    std::getline(stop_word, actual_stop_word);
    while (std::getline(stop_word, actual_stop_word)) {
        // Eliminar los espacios en blanco del principio y del final de la palabra  

        if (!actual_stop_word.empty() && actual_stop_word.back() == '\r') {
            actual_stop_word.pop_back(); // Eliminar el carácter de retorno de carro ('\r') si está presente
        }
        if (!actual_stop_word.empty() && actual_stop_word.back() == '\n') {
            actual_stop_word.pop_back(); // Eliminar el carácter de salto de línea ('\n') si está presente
        }
        stop_words_vec.push_back(actual_stop_word);
    }

    //std::ofstream archivo("archivo.txt", std::ios::out);
    // Eliminar los signos de inicio de fichero y de salto de linea de las palabras del fichero de stop words
    for (auto element: stop_words_vec)
    {
        //archivo << element << " ";
        int counter = 0;
        for (int i = 0; i < element.size(); i++)
        {   
            counter++;
        }
        //archivo << counter << "\n";
    }
    //archivo << "-----------------------------------\n";
    //archivo.close();

    /* Procesar el docmuent*/
    std::string actual_line;
    // std::vector<std::string> document_vec;
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
                    //std::cout << "Entro: " << actual_article[i] << " " << stop_words_vec[j] << std::endl; 
                    is_stop_word = true;
                    break;  // Sal del bucle interno tan pronto como encuentres una "stop word"
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
    // std::cout << n_articles << std::endl;
    for (int i = 0; i < n_articles; i++) {
        ARTICLE_IDF.emplace_back(CalculateIDF(ARTICLE_DF[i], n_articles));
    }

    int n = 0;
    for (auto element: WORDS) {
        int i = 0;
        std::cout << "**Articulo** " << n << std::endl;
        std::cout << "-----------" << "\n";
        for (auto word : element)
        {
            std::cout << word << " " << VALUES[n][i]<< " " << ARTICLE_DF[n][i] << " " << ARTICLE_IDF[n][i] << " " << ARTICLE_TF[n][i] << std::endl;
            i++;
        }
        std::cout << std::endl << std::endl;
        n++;
    }
}
