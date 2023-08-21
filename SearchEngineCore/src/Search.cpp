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
        std::cout << "Size after indexing " << m_ActiveDir.size() << std::endl;
    }
    catch (Indexer::IndexError &error)
    {
        throw;
    }
}

void Search::SearchQuery(const char *query)
{
    std::cout << m_ActiveDir.size() << std::endl;
    for (auto &pair : m_ActiveDir)
    {

        double tfidf = _tf(query, pair.second) * _idf(query, m_ActiveDir);
        if (tfidf != 0)
        {
            std::cout << "File: " << pair.first << std::endl;
            std::cout << "TF-IDF for " << query << " is " << tfidf << std::endl;
        }
    }
}

double Search::_tf(const char *term, TermFreq &doc)
{
    return (double)doc[term] / (double)doc.size();
}

double Search::_idf(const char *term, TermIndex &dirIndex)
{
    size_t count = 0;
    for (auto &pair : dirIndex)
    {
        count += pair.second[term];
    }

    return (double)(count + 1) / (double)(dirIndex.size());
}