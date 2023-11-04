#include "../includes/Functions.h"

/**
 * @author @Adrian-glz01
 * @author @AlejandroGarciaBautista
 * @author @Lucasperez02
 * 
 * @brief -- Calculate the DF of an article(document)
 * 
 * @param articles - The vector of articles
 * @param actual_article - The actual article
 * @param pos_article - The position of the actual article
 * @return std::vector<int> - The vector with the DF of the article
 */
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