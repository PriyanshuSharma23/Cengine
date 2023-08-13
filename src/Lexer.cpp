#include "Lexer.hpp"

const char *Lexer::GetLetters() const
{
    return m_Letters;
}

const char *Lexer::NextToken()
{
    m_TrimLeft();
    if (IsTerminated())
    {
        return nullptr;
    }
    const char *token = m_Letters;

    if (std::isalpha(*m_Letters))
    {
        while (!IsTerminated() && std::iswalnum(*m_Letters))
        {
            m_Letters++;
        }
        return token;
    }

    if (std::isdigit(*m_Letters))
    {
        while (!IsTerminated() && std::isdigit(*m_Letters))
        {
            m_Letters++;
        }
        return token;
    }

    m_Letters++;
    return token;
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
