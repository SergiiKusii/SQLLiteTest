#pragma once
#include "Entity.h"
#include "Attribute.h"
#include <vector>

class TabularSectionsHolder;

class TabularSection : public Entity, public AttributesHolder
{
public:
	TabularSection(const std::string& sName, const std::string& sSynonym, TabularSectionsHolder& parent) :
		Entity(sName, sSynonym, eType::tabularSection),
		m_parent(parent) {
		m_parent.addTabularSection(*this);
	};

	const TabularSectionsHolder& getParent() const{
		return m_parent;
	}

	~TabularSection();
private:
	TabularSectionsHolder& m_parent;
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

	const std::vector<TabularSection>& getTabularSections() const {
		return m_vTabularSections;
	};

protected:
	std::vector<TabularSection> m_vTabularSections;
};