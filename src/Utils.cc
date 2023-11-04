#include "./includes/Utils.h"

void Usage(int argc, char *argv[], std::string& document, std::string& corpus, std::string& stop_words)
{
    struct option long_options[] = {
        {"help", no_argument, nullptr, 'h'},
        {"fichero", required_argument, nullptr, 'f'},
        {"corpus", required_argument, nullptr, 'c'},
        {"stop", required_argument, nullptr, 's'},
        {nullptr, 0, nullptr, 0}
    };

    int option, option_index = 0;

    while ((option = getopt_long(argc, argv, "h:f:c:s:", long_options, &option_index)) != -1)
    {
        switch (option)
        {
            case 'h':
                std::cout << "Uso: " << argv[0] << " y añadir las siguientes opciones" << std::endl;
                std::cout << "Opciones:" << std::endl;
                std::cout << "  -f, --fichero <nombre> Especifica la ruta al fichero donde se encuentran los articulos" << std::endl;
                std::cout << "  -c, --corpus <nombre>  Especifica la ruta al fichero corpus" << std::endl;
                std::cout << "  -s, --stop <nombres>   Especifica la ruta al fichero de stop words" << std::endl;          
                exit(EXIT_SUCCESS);
            case 'f':
                document = optarg;
                break;
            case 'c':
                corpus = optarg;
                break;
            case 's':
                stop_words = optarg;
                break;
            case '?':
                exit(EXIT_FAILURE);
            default:
                break;
        }
    }

    if (document == "" || corpus == "" || stop_words == "")
    {
        std::cout << "Error, faltan argumentos, ejecute " << argv[0] << " --help para más ayuda" << std::endl;
        exit(EXIT_FAILURE);
    }
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
