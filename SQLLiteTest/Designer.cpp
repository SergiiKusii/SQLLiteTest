#include "Designer.h"
#include "Database\IDataBase.h"
#include "Database\SQLRequest.h"
#include "DataSource.h"

#define T_DBVERSION "T_DB_VERSION"

Designer::Designer()
{
	auto cat = Catalog("T_NOMENCLATURE", "Nomenclature", Entity::eType::C_Nomemclature);
		cat.addAttribute(Attribute("NAME", "Name", Value::eType::String));
		cat.addAttribute(Attribute("Code", "Code", Value::eType::String));
	m_vCatalogs.push_back(cat);
}

void Designer::createDB() {
	DataSource::sGetDB()->exec(SQLRequest::sGet(SQLRequest::createTableDbVersion));

	//create T_DB_VERSION maybe T_MAIN {ID (1 - VERSION), Value (string), Type (1 - int, 2 - string)}

	//create catalogs

	//create documents

	//create registers

};

void Designer::updateDB() {
	// check fields in db and add new if not exists PRAGMA table_info('T_DBVERS');

};

bool Designer::needCreate() {
	Value::Table table;
	table.addColum(Value::eType::Int);
	Value::Row row;
	row.push_back(Value(T_DBVERSION));
	DataSource::instance()->getDB()->exec(SQLRequest::instance()->get(SQLRequest::checkTable, row), table);
	return table[0][0].getInt() == 0;
};

bool Designer::needUpdate() {
	Value::Table table;
	table.addColum(Value::eType::Int);
	table.addColum(Value::eType::Int);
	table.addColum(Value::eType::Int);
	table.addColum(Value::eType::Int);
	DataSource::instance()->getDB()->exec(SQLRequest::instance()->get(SQLRequest::getDbVersion), table);

	return !(table[0][0].getInt() == MAJOR && table[0][1].getInt() == MINOR && table[0][2].getInt() == SUBMINOR && table[0][3].getInt() == BUILD);
};