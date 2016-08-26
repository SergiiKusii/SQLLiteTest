#include "Designer.h"



Designer::Designer()
{
	auto cat = Catalog("T_NOMENCLATURE", "Nomenclature", Entity::eType::C_Nomemclature);
		cat.addAttribute(Attribute("NAME", "Name", Value::eType::String));
		cat.addAttribute(Attribute("Code", "Code", Value::eType::String));
	m_vCatalogs.push_back(cat);
}


Designer::~Designer()
{
}
