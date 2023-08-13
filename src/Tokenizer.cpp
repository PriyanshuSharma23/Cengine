#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::string &data)
{
    m_Data = data.c_str();
}

Tokenizer::~Tokenizer()
{
}

bool Tokenizer::HasNextToken()
{
    return *m_Data != '\0';
}

bool Tokenizer::m_IsWhitespace(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void Tokenizer::m_TrimLeft()
{
    while (HasNextToken() && m_IsWhitespace(*m_Data))
    {
        m_Data++;
    }
}

const char *Tokenizer::m_Chop(size_t n = 1)
{
    const char *result = m_Data;
    m_Data += n;
    return result;
}

const char *Tokenizer::NextToken()
{
    m_TrimLeft();
    if (!HasNextToken())
    {
        return nullptr;
    }
    const char *result = m_Data;
    if (std::isalpha(*m_Data))
    {
        while (HasNextToken() && std::iswalnum(*m_Data))
        {
            m_Data++;
        }
        return result;
    }

    if (std::isdigit(*m_Data))
    {
        while (HasNextToken() && std::isdigit(*m_Data))
        {
            m_Data++;
        }
        return result;
    }

    return m_Chop(1);
}
