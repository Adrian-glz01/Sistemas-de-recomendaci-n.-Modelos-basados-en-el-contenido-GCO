#include "../includes/Functions.h"
#include <set>
#include <vector>

std::vector<int> CalculateDF(std::vector<std::set<std::string>> articles, std::set<std::string> actual_article, int pos_article)
{
    std::vector<int> resultDF;
    int count;

    if (pos_article == 0)
    {
        for (auto actual_term : actual_article)
        {
            count = 0;
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
        int i = 0;

        for (auto actual_term : actual_article)
        {
            count = 0;
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
