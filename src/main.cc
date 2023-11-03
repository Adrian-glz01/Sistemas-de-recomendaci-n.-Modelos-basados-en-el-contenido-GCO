#include "./includes/Utils.h"
#include <stdio.h>

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
            actual_article.push_back(word);
        }

        for (auto element: stop_words_vec) {
            std::cout << element << std::endl;
            std::cout << element.size() << std::endl;
        }

        for (int i = 0; i < actual_article.size(); i++) 
        {
            bool is_stop_word = false;
            for (int j = 0; j < stop_words_vec.size(); j++)
            {
                if (actual_article[i] == stop_words_vec[j])
                {
                    std::cout << "Entro: " << actual_article[i] << " " << stop_words_vec[j] << std::endl; 
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

    for (auto element: articles)
    {
        for (auto word: element)
        {
            std::cout << word << " ";
        }
        std::cout << "\n";
    }
    std::cout << "-----------------------------------\n";
    changeDocumentWithCorpusWords(articles, corpus_vec);
    for (auto element: articles)
    {
        for (auto word: element)
        {
            std::cout << word << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
