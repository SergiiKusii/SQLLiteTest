#pragma once
#include "Entity.h"
#include "Database\Value.h"

class Attribute : public Entity
{
public:
	enum class eType : int {
		Int = 0,
		Double = 1,
		String = 2,
		Catalog = 3,
		Document = 4
	};

	Attribute(const std::string& sName, const std::string& sSynonym, const eType& type, const size_t stringSize = 0) :
		Entity(sName, sSynonym, Entity::eType::attribute),
		m_type(type),
		m_refType(Entity::eType::none),
		m_value(Value(Value::eType::Int, stringSize)) {
		
		switch (m_type)
		{
		case eType::Double:
			m_value.setNewType(Value::eType::Double);
			break;
		case eType::String:
			m_value.setNewType(Value::eType::String);
			break;
		case eType::Int: //by default
			break;
		default: //referense to catalog or document
			throw std::exception("Create attribute: Not specified type of reference!");
			break;
		}
	};

	Attribute(const std::string& sName, const std::string& sSynonym, const eType& type, const Entity::eType& refType) :
		Entity(sName, sSynonym, Entity::eType::attribute),
		m_type(type),
		m_refType(refType),
		m_value(Value(Value::eType::Int)) {

		switch (m_type)
		{
		case eType::Catalog:
		case eType::Document:
			break;
		default: //referense to catalog or document
			throw std::exception("Create attribute: Specified wrong type for reference!");
			break;
		}
	};

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

	eType m_type;
	Value m_value;
	Entity::eType m_refType;
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
