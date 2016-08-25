#pragma once
#include "Entity.h"
#include "Database\Value.h"

class Attribute : public Entity
{
public:
	Attribute() {};
	Attribute(const Value::eType& type) : m_value(Value(type)) {};

	void setValue(const Value& val);

	~Attribute() {};
private:
	Value m_value;
};

