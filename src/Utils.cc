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
                std::cout << "f" << "\n";
                document = optarg;
                std::cout << document << "\n";
                break;
            case 'c':
                std::cout << "Entro en el corpus\n";
                corpus = optarg;
                std::cout << corpus << "\n";
                break;
            case 's':
                std::cout << "s" << "\n";
                stop_words = optarg;
                std::cout << stop_words << "\n";
                break;
            case '?':
                exit(EXIT_FAILURE);
            default:
                break;
        }
    }

    // if (document == "" || corpus == "" || stop_words == "")
    // {
    //     std::cout << "Error, faltan argumentos, ejecute " << argv[0] << " --help para más ayuda" << std::endl;
    //     exit(EXIT_FAILURE);
    // }
}

std::vector<std::string> GetStopWords(std::ifstream& sw_file) 
{
    std::vector<std::string> sw;
    std::string actual_line;
    while (std::getline(sw_file, actual_line))
    {
        sw.push_back(actual_line);
    }
    return sw;
}
