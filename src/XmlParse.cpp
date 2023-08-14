#include "XmlParse.hpp"
#include <ostream>

class ParseError {};

std::string XmlParse::GetText(char *buffer)
{
    using namespace rapidxml;
    xml_document<> doc;

    doc.parse<0>(buffer);

    // get all text nodes in the XHTML document
    xml_node<> *node = doc.first_node();
    std::string text;

    if (!node) {
        throw ParseError();
    }

    PopulateText(text, node);

    return text;
}

void XmlParse::PopulateText(std::string &text, rapidxml::xml_node<> *node)
{
    if (node->type() == rapidxml::node_data)
    {
        text.append(node->value());
    }
    else
    {
        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            PopulateText(text, child);
        }
    }
}
