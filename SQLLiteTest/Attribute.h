#pragma once
#include "Entity.h"
#include "Database\Value.h"

class Attribute : public Entity
{
public:
	Attribute(const Value::eType& type) : m_value(Value(type)) {};
	Attribute(const std::string& sName, const std::string& sSynonym, const Value::eType& type) : 
		Entity(sName, sSynonym, Entity::eType::attribute), 
		m_value(Value(type)) {};

	void setValue(const Value& val);

	Value getValue() {
		return m_value;
	}

	~Attribute() {};
private:
	Attribute() : m_value(Value::eType::Int) {};

	Value m_value;
};

