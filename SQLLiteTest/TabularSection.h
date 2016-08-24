#pragma once
#include "Entity.h"
#include "Attribute.h"
#include <vector>

class TabularSection : public Entity
{
public:
	TabularSection();
	~TabularSection();
private:
	std::vector<Attribute> m_vAttributes;
};

