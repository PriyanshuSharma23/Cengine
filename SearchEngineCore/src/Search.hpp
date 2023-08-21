#ifndef SEARCH_HPP__
#define SEARCH_HPP__

#include "unordered_map"

#include "Indexer.hpp"

class Search
{
  private:
    static Search *m_Instance;
    TermIndex m_ActiveDir;
    Search()
    {
    }

  public:
    Search(const Search &other) = delete;
    static Search *GetInstance();
    void SetActiveDir(const char *absoluteDirPath);
    void SearchQuery(const char *query);

  private:
    double _tf(const char *term, TermFreq &doc);
    double _idf(const char *term, TermIndex &dirIndex);
};
#endif // SEARCH_HPP__