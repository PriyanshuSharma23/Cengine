#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <cwctype>
#include <string>

class Lexer
{

  public:
    enum TokenType
    {
        ALPHANUMERIC,
        NUMERIC,
        SYMBOL,
        END,
    };
    struct Token
    {
        TokenType type;
        std::string value;
    };

  private:
    const char *m_Letters;

  public:
    Lexer(const char *input) : m_Letters(input)
    {
    }

    const char *GetLetters() const;

    Token NextToken();

    bool IsTerminated();

    size_t GetTokenLength(const char *token) const;

  private:
    void m_TrimLeft();
    std::string m_CapitalizeToken(const char *token);
};

#endif // TOKENIZER_HPP
