#pragma once
#include "Entity.h"
#include "Attribute.h"
#include "TabularSection.h"
#include <vector>
#include <string>
#include <memory>

class Catalog : public Entity
{
public:
	Catalog();
	Catalog(const std::string& sName, const std::string& sSynonym, const eType& entityType) :
		Entity(sName, sSynonym, entityType) {};
	~Catalog();

	void addAttribute(const Attribute& attr) {
		//TODO check  There is  such an attribute
		m_vAttributes.push_back(attr);
	};

	void addTabularSection(const TabularSection& tableSec) {
		//TODO check  There is  such an TabularSection
		m_vTabularSections.push_back(tableSec);
	};



private:

	std::vector<Attribute> m_vAttributes;
	std::vector<TabularSection> m_vTabularSections;

	std::shared_ptr<Catalog> m_pParent;
	std::shared_ptr<Catalog> m_pOwner;
};

