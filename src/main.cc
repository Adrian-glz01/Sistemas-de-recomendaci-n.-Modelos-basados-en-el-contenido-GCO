#include "./includes/Utils.h"

void RemoveWordFromLine(std::string& line, const std::string& word)
{
    auto n = line.find(word);
    std::cout << "word: " << word << std::endl;
    std::cout << "n: " << n << std::endl;
    if (n != std::string::npos)
    {
        line.erase(n, word.length());
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
    std::vector<std::string> stop_words_vec = GetStopWords(stop_word);
    //printStopWords(stop_words_vec);


    /* Procesar el docmuent*/
    std::string actual_line;
    // std::vector<std::string> document_vec;
    std::vector<std::vector<std::string>> articles;

    while(std::getline(document, actual_line))
    {
        actual_line.erase(std::remove(actual_line.begin(), actual_line.end(), '.'), actual_line.end());
        actual_line.erase(std::remove(actual_line.begin(), actual_line.end(), ','), actual_line.end());
        
        std::istringstream stream(actual_line);

        std::vector<std::string> actual_article;

        
        std::string palabra;
        
        for (int i = 0; i < stop_words_vec.size(); i++)
        {
            if (stop_words_vec[i] != palabra) 
            {
                std::cout << "Tamaño PALATE: " << stop_words_vec[i].length() << std::endl;
            }

            for (int j = 0; j < stop_words_vec[i].length(); j++)
            {
                std::cout << stop_words_vec[i][j] << "|";
            }
            std::cout << std::endl;
        }

        while (stream >> palabra) {
            for (int i = 0; i < stop_words_vec.size(); i++)
            {
                if (stop_words_vec[i] != palabra) 
                {
                    actual_article.push_back(palabra);
                }
            }
            
        }

        std::cout << "Linea original" << std::endl;
        for (const std::string& palabra : actual_article) {
            std::cout << palabra << " ";
        }
        std::cout << std::endl;

        std::vector<std::string> aux;

        for (int i = 0; i < actual_article.size(); i++) 
        {
            for (int j = 0; j < stop_words_vec.size(); j++)
            {
                std::cout << "palabra: " << actual_article[i] << " VS Stop word: " << stop_words_vec[j] << std::endl;
                if (actual_article[i] == stop_words_vec[j])
                {
                    std::cout << "Encontramos PALATE" << std::endl;
                }
            }
        }        

        // std::cout << "Linea modificada" << std::endl;
        // for (const std::string& palabra : aux) {
        //     std::cout << palabra << " ";
        // }
        // std::cout << std::endl;


    }

    //Imprimir documento 
    // for (std::string element: document_vec)
    // {    // std::string linea("This is a wrong line");
    // RemoveWordFromLine(linea, "wrong");
    // printf("line is: '%s'\n", linea.c_str());
    //     std::cout << element << "\n";
    // }

    // const std::string str = "wrong"; 
    // std::string linea("This is a wrong line");
    // RemoveWordFromLine(linea, str);
    // printf("line is: '%s'\n", linea.c_str());

    return 0;
}
