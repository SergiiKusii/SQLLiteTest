#include "Designer.h"



Designer::Designer()
{
	auto cat = Catalog("T_NOMENCLATURE", "Nomenclature", Entity::Type::C_Nomemclature);

	m_vCatalogs.push_back(cat);
}


Designer::~Designer()
{
}
