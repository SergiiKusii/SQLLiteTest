#pragma once

#include "Catalog.h"
#include <vector>

//singelton
class Designer
{
public:
	~Designer();
	static Designer* instance() {
		static auto	m_instance = std::shared_ptr<Designer>(new Designer());

		return m_instance.get();
	}

private:
	std::vector<Catalog> m_vCatalogs;
	Designer();
};

