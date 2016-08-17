#include "stdafx.h"
#include "DataSource.h"
#include "DBSqlite.h"

DataSource::DataSource()
{
	m_pDB = std::shared_ptr<IDataBase>(new DBSqlite());
}


DataSource::~DataSource()
{
}
