#pragma once
#include "Entity.h"
#include "Attribute.h"
#include "TabularSection.h"
#include <vector>
#include <memory>

class Catalog : public Entity
{
public:
	Catalog();
	~Catalog();

private:
	std::vector<Attribute> m_vAttributes;
	std::vector<TabularSection> m_vTabularSections;

	std::shared_ptr<Catalog> m_pParent;
	std::shared_ptr<Catalog> m_pOwner;
};

