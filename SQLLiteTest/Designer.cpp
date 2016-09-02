#include "Designer.h"
#include "Database\IDataBase.h"
#include "Database\SQLRequest.h"
#include "DataSource.h"

#define T_CONFIG "T_CONFIG"

Designer::Designer()
{
	m_config = Catalog(T_CONFIG, "Config", Entity::eType::C_Config);
		m_config.addAttribute(Attribute("Value", "Value", Attribute::eType::String, 256));
	auto cat = Catalog("T_NOMENCLATURE", "Nomenclature", Entity::eType::C_Nomemclature);
		cat.addAttribute(Attribute("NAME", "Name", Attribute::eType::String, 100));
		cat.addAttribute(Attribute("CODE", "Code", Attribute::eType::String, 11));
		auto tabSec = TabularSection("CODE", "Code", cat);
		tabSec.addAttribute(Attribute("Nomenclature", "Nomenclature", Attribute::eType::Catalog, Entity::eType::C_Nomemclature));
	m_vCatalogs.push_back(cat);
}

std::string Designer::getAtttributeTxt(const Attribute& attr)
{
	return SQLRequest::sGet(SQLRequest::createAttribute, Value::Row({ Value(attr.getName()),  Value(attr.getSqlType()) }));
}

void Designer::createTabularSection(const TabularSection& tsec)
{

}

void Designer::createCatalog(const Catalog& cat) {
	std::string sql;
	//create attribute
	auto& attributes = cat.getAttributes();
	for (auto& attr : attributes) {
		sql += ", " + getAtttributeTxt(attr);
	}
	//create table, idx and attribute
	sql = SQLRequest::sGet(SQLRequest::createTable, Value::Row({ Value(cat.getName()),  sql }));
	DataSource::sGetDB()->exec(sql);

	//create tabular section
	auto& tsections = cat.getTabularSections();
	for (auto& tsec : tsections) {
		createTabularSection(tsec);
	}
}

void Designer::createDB() {
	//create T_DB_VERSION maybe T_MAIN {ID (1 - VERSION), Value (string), Type (1 - int, 2 - string)}
	createCatalog(m_config);

	//create catalogs
	for (auto& cat : m_vCatalogs) {
		createCatalog(cat);
	}
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
	row.push_back(Value(T_CONFIG));
	DataSource::instance()->getDB()->exec(SQLRequest::sGet(SQLRequest::checkTable, row), table);
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