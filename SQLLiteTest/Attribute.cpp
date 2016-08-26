#include "Attribute.h"

void Attribute::setValue(const Value& val)
{
	if (val.hasType(m_value.getType()))
	{
		m_value = val;
	}
	else
	{
		m_sError = "tring to set attribute [" + m_name + "] with type [" + Value::typeName(m_value.getType()) +"] value with type [" + Value::typeName(val.getType()) + "]";
		throw std::exception(m_sError.c_str(), static_cast<int>(eErrors::wrongAttributeType));
	}
}
