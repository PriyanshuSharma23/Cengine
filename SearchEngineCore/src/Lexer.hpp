#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <cwctype>

class Lexer
{
private:
    const char *m_Letters;

public:
    Lexer(const char *input) : m_Letters(input) {}

    const char *GetLetters() const;
    const char *NextToken();
    bool IsTerminated();
    size_t GetTokenLength(const char *token) const { return GetLetters() - token; }

private:
    void m_TrimLeft();
};

#endif // TOKENIZER_HPP
