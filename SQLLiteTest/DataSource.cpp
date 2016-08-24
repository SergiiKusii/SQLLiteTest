#include "DataSource.h"
#include "Database\DBSqlite.h"

DataSource::DataSource()
{
	m_pDB = std::shared_ptr<IDataBase>(new DBSqlite());
}


DataSource::~DataSource()
{
}
