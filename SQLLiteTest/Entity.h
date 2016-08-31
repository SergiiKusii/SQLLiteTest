#pragma once
#include <string>
class Entity
{
public:
	enum class eErrors : int {
		ok = 300,
		internal,
		wrongAttributeType,
		last = 399
	};

	enum class eType{
		none,
		attribute,
		tabularSection,
		C_Config,
		C_Nomemclature,
		D_Income
	};

	Entity():m_entityType(eType::none){};
	Entity(const std::string& sName, const std::string& sSynonym, const eType& entityType) :
		m_name(sName),
		m_synonym(sSynonym),
		m_entityType(entityType) {};

	std::string getName() const{
		return m_name;
	};
	std::string getSynonym() const{
		return m_synonym;
	};
	eType getEntityType() const{
		return m_entityType;
	};

	bool operator==(const Entity& ent){
		return m_name.compare(ent.m_name) == 0
			&& m_entityType == ent.m_entityType;
	}
	virtual ~Entity() {};

protected:
	std::string m_name;
	std::string m_synonym;
	eType m_entityType;

	std::string m_sError;
};

