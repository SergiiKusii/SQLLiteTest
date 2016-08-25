#pragma once
#include <string>
class Entity
{
public:
	enum class eErrors : int {
		ok = 300,
		internal,
		last = 399
	};

	enum class Type{
		none,
		field,
		tablePart,
		C_Nomemclature,
		D_Income
	};

	Entity():m_entityType(Type::none){};
	Entity(const std::string& sName, const std::string& sSynonym, const Type& entityType) :
		m_name(sName),
		m_synonym(sSynonym),
		m_entityType(entityType) {};

	std::string getName() {
		return m_name;
	};
	std::string getSynonym() {
		return m_synonym;
	};
	Type getEntityType() {
		return m_entityType;
	};
	virtual ~Entity() {};

protected:
	std::string m_name;
	std::string m_synonym;
	Type m_entityType;

	std::string m_sError;
};

