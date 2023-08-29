#include "Lexer.hpp"

size_t Lexer::GetTokenLength(const char *token) const
{
    return GetLetters() - token;
}

const char *Lexer::GetLetters() const
{
    return m_Letters;
}

Lexer::Token Lexer::NextToken()
{
    m_TrimLeft();
    if (IsTerminated())
    {
        return Lexer::Token{.type = END, .value = std::string()};
    }
    const char *token = m_Letters;
    TokenType type;

    if (std::isalpha(*m_Letters))
    {
        type = ALPHANUMERIC;
        while (!IsTerminated() && std::iswalnum(*m_Letters))
        {
            m_Letters++;
        }
    }
    else if (std::isdigit(*m_Letters))
    {
        type = NUMERIC;
        while (!IsTerminated() && std::isdigit(*m_Letters))
        {
            m_Letters++;
        }
    }
    else
    {
        type = SYMBOL;
        m_Letters++;
    }

    return Lexer::Token{.type = type, .value = m_CapitalizeToken(token)};
}

bool Lexer::IsTerminated()
{
    return *m_Letters == 0;
}

void Lexer::m_TrimLeft()
{
    while (!IsTerminated() && *m_Letters == ' ')
    {
        m_Letters++;
    }
}

std::string Lexer::m_CapitalizeToken(const char *token)
{
    auto s = std::string(token, GetTokenLength(token));
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}
