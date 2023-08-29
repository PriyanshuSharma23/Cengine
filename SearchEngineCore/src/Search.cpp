#include "Search.hpp"

Search *Search::m_Instance;

Search *Search::GetInstance()
{
    if (!m_Instance)
    {
        m_Instance = new Search();
    }

    return m_Instance;
}

void Search::SetActiveDir(const char *absoluteDirPath)
{
    try
    {
        auto index = Indexer::RetrieveIndex(absoluteDirPath);
        m_ActiveDir = index;
    }
    catch (Indexer::IndexError &error)
    {
        throw;
    }
}

void Search::SearchQuery(const char *query)
{

    Lexer lexer(query);
    Lexer::Token token;
    std::vector<Lexer::Token> tokens;

    while ((token = lexer.NextToken()).type != Lexer::TokenType::END)
    {
        tokens.push_back(token);
        // std::cout << token.value << std::endl;
        // results.reserve(m_ActiveDir.size());
        // for (auto &pair : m_ActiveDir)
        // {
        //     double tfidf = _tf(token.value.c_str(), pair.second) * _idf(token.value.c_str(), m_ActiveDir);

        // }
    }

    std::vector<double> idfs;
    idfs.reserve(tokens.size());

    for (auto &token : tokens)
    {
        std::cout << token.value << " ";
        idfs.push_back(_idf(token.value.c_str(), m_ActiveDir));
    }
    std::cout << std::endl;

    std::vector<std::pair<std::string, double>> results;
    results.reserve(m_ActiveDir.size());
    for (auto &pair : m_ActiveDir)
    {
        auto &fileIndex = pair.second;
        double total = 0;
        for (size_t i = 0; i < tokens.size(); ++i)
        {
            auto &token = tokens[i];
            double tf = _tf(token.value.c_str(), fileIndex);
            double score = tf * idfs[i];
            total += score;
        }

        results.emplace_back(pair.first, total);
        // std::cout << pair.first << " => " << total << std::endl;
    }

    std::sort(results.begin(), results.end(),
              [&](const std::pair<std::string, double> &a, const std::pair<std::string, double> &b) {
                  return a.second > b.second;
              });

    int top = 50;
    int i = 0;
    for (auto pair = results.begin(); pair != results.end() && i < top; pair++)
    {
        std::cout << pair->first << " - " << pair->second << std::endl;
        i++;
    }
}

double Search::_tf(const char *token, TermFreq &doc)
{
    return (double)doc[token] / (double)doc.size();
}

double Search::_idf(const char *token, TermIndex &dirIndex)
{
    size_t count = 0;
    for (auto &pair : dirIndex)
    {
        count += pair.second[token];
    }

    return -1 * std::log((double)(count + 1) / (double)(dirIndex.size() + 1));
}
