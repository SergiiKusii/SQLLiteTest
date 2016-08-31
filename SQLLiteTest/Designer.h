#pragma once

#include "Catalog.h"
#include <vector>

enum eVersion {
	MAJOR = 1,
	MINOR = 0,
	SUBMINOR = 0,
	BUILD = 1
};

//singelton
class Designer
{
public:
	enum class eErrors : int {
		ok = 400,
		internal,
		last = 499
	};

	~Designer() {};
	static Designer* instance() {
		static auto	m_instance = std::shared_ptr<Designer>(new Designer());

		return m_instance.get();
	}

	void createDB();
	void updateDB();
	bool needCreate();
	bool needUpdate();

private:
	std::vector<Catalog> m_vCatalogs;
	Catalog m_config;
	Designer();
	static void createCatalog(const Catalog& cat);
	static std::string getAtttributeTxt(const Attribute& attr);
	static void createTabularSection(const TabularSection& tsec);
};

