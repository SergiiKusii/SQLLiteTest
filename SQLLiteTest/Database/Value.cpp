#include "Value.h"

std::string Value::toString() const
{
	std::string sVal;

	switch (m_type)
	{
	case eType::Int:
		sVal = std::to_string(std::get<0>(m_value));
		break;
	case eType::Double:
		sVal = std::to_string(std::get<1>(m_value));
		break;
	case eType::String:
		sVal = std::get<2>(m_value);
		break;
	default:
		break;
	}

	return sVal;
}

Value::Value(const eType& type, const std::string& sValue)
{
	m_type = type;
	
	switch (m_type)
	{
	case eType::Int:
		std::get<0>(m_value) = std::stoi(sValue);
		break;
	case eType::Double:
		std::get<1>(m_value) = std::stod(sValue);
		break;
	case eType::String:
		std::get<2>(m_value) = sValue;
		break;
	default:
		break;
	}
}

std::string Value::typeName(const eType& type)
{
	std::string str;

	switch (type)
	{
	case eType::Int:
		str = "int";
		break;
	case eType::Double:
		str = "double";
		break;
	case eType::String:
		str = "string";
		break;
	default:
		str = "none";
		break;
	}

	return str;
}
