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

	Attribute(const std::string& sName, const std::string& sSynonym, const Value::eType& type, const size_t stringSize) :
		Entity(sName, sSynonym, Entity::eType::attribute),
		m_value(Value(type, stringSize)) {};

	void setValue(const Value& val);

	Value getValue() const{
		return m_value;
	}

	std::string getSqlType() const{
		return m_value.typeName();
	};

	~Attribute() {};
private:
	Attribute() : m_value(Value::eType::Int) {};

	Value m_value;
};

class AttributesHolder
{
public:
	AttributesHolder() {};
	virtual ~AttributesHolder() {};

	const std::vector<Attribute>& getAttributes() const {
		return m_vAttributes;
	}

	void addAttribute(const Attribute& attr) {
		//TODO check  There is  such an attribute
		m_vAttributes.push_back(attr);
	};

protected:

	std::vector<Attribute> m_vAttributes;

};
