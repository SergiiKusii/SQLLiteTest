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
	Catalog(const std::string& sName, const std::string& sSynonym, const Type& entityType) :
		Entity(sName, sSynonym, entityType) {};
	~Catalog();

	std::vector<Attribute> m_vAttributes;
	std::vector<TabularSection> m_vTabularSections;

private:

	std::shared_ptr<Catalog> m_pParent;
	std::shared_ptr<Catalog> m_pOwner;
};

