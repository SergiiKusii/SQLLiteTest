#include "Attribute.h"

void Attribute::setValue(const Value& val)
{
	if (val.hasType(m_value.getType()))
	{
		m_value = val;
	}
	else
	{
		m_sError = "tring to set attribute value with wrong type";
		throw std::exception()//;
	}
}
