#pragma once
#include "Entity.h"
#include "Attribute.h"
#include "TabularSection.h"
#include <vector>
#include <string>
#include <memory>

class Catalog : public Entity , public AttributesHolder, public TabularSectionsHolder
{
public:
	Catalog();
	Catalog(const std::string& sName, const std::string& sSynonym, const eType& entityType) :
		Entity(sName, sSynonym, entityType) {};
	~Catalog();

private:
	std::shared_ptr<Catalog> m_pParent;
	std::shared_ptr<Catalog> m_pOwner;
};

