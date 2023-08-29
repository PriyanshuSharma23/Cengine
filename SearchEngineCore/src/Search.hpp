#ifndef SEARCH_HPP__
#define SEARCH_HPP__

#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <utility>
#include <vector>

#include "Indexer.hpp"
#include "Lexer.hpp"

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
    double _tf(const char *token, TermFreq &doc);
    double _idf(const char *token, TermIndex &dirIndex);
};
#endif // SEARCH_HPP__