#pragma once
#include "Entity.h"
#include "Database\Value.h"

class Attribute : public Entity
{
public:
	Attribute();
	~Attribute();
private:
	Value::eType m_type;
};

