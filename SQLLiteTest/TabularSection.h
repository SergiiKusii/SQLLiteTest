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

class TabularSectionsHolder
{
public:
	TabularSectionsHolder() {};
	virtual ~TabularSectionsHolder() {};
	
	void addTabularSection(const TabularSection& tableSec) {
		//TODO check  There is  such an TabularSection
		m_vTabularSections.push_back(tableSec);
	};

protected:
	std::vector<TabularSection> m_vTabularSections;
};