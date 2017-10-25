#pragma once


#include <iostream>

#define ReadElementValue(parent, elementName, value, type) \
{ \
	XMLElement* mpElement = parent->FirstChildElement(elementName); \
	if(mpElement == nullptr) \
	{ \
		std::cout << "Could not find element: " << elementName << '\n'; \
	} \
\
	XMLError queryResult = mpElement->Query##type##Text(&value); \
	if(queryResult != XMLError::XML_SUCCESS) \
	{ \
		std::cout << "Failed to parse element: " << elementName << '\n'; \
	} \
}