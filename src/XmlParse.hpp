#ifndef RADIXXML_HPP__
#define RADIXXML_HPP__

// RapidXml http://rapidxml.sourceforge.net/
#include <iostream>

#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_utils.hpp"

class XmlParse
{
public:
    static std::string GetText(char *buffer);

private:
    static void PopulateText(std::string &text, rapidxml::xml_node<> *node);
};

#endif // RADIXXML_HPP__
