#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <cwctype>

class Tokenizer
{
private:
    const char *m_Data;

public:
    Tokenizer(std::string &data);
    ~Tokenizer();

    const char *NextToken();
    bool HasNextToken();
    const char *GetToken() const { return m_Data; }

private:
    bool m_IsWhitespace(char c);
    void m_TrimLeft();
    const char *m_Chop(size_t n);
};

#endif // TOKENIZER_HPP
