#include "./includes/Utils.h"

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
    
    std::cout << "Fichero documento: " << document_file << std::endl;
    std::cout << "Fichero corpus: " << corpus_file << std::endl;
    std::cout << "Fichero stop words: " << stop_word_file << std::endl << std::endl;
    
    //std::ifstream corpus{argv[1]};
    std::ifstream corpus{corpus_file};
    std::ifstream stop_word{stop_word_file};
    std::ifstream document{document_file};

    std::string line;
    //* Reading corpus file: 
    std::getline(corpus,line);

    line.erase(std::remove(line.begin(), line.end(), '"'), line.end());
    line.erase(std::remove(line.begin(), line.end(), '{'), line.end());
    line.erase(std::remove(line.begin(), line.end(), '}'), line.end());

    std::vector<std::pair<std::string,std::string>> corpus_vec = fill_corpus_vec(line);
    // printCorpus(corpus_vec);

    //* Reading stop word file 
    line = "";
    std::vector<std::string> stop_words_vec;

    while(std::getline(stop_word,line))
    {
        stop_words_vec.emplace_back(line);
    }
    printStopWords(stop_words_vec);


    return 0;
}