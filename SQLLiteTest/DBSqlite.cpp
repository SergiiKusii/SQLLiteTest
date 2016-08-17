#include "DBSqlite.h"
#include <string>

DBSqlite::DBSqlite()
{
	m_db = nullptr;
}


DBSqlite::~DBSqlite()
{
}


void DBSqlite::connect(const std::string& connStr)
{
	int iRes = sqlite3_open(connStr.c_str(), &m_db);
	
	if (iRes != SQLITE_OK) {
		std::string sError;
		sError = "Can't open database: \n" 
			+ std::string(sqlite3_errmsg(m_db)) 
			+ "\n Responce code: \n"
			+ std::to_string(iRes);

		m_db = nullptr;

		throw std::exception(sError.c_str(), static_cast<int>(eErrors::connect));
	}
}

bool DBSqlite::isConnected()
{
	return m_db != nullptr;
}

bool DBSqlite::avaliable()
{
	return false;
}

void DBSqlite::exec(const std::string& sqlReq)
{
	Value::Table table;
	exec(sqlReq, table);
}

int DBSqlite::fillOutTable(void *data, int argc, char **argv, char **azColName) {
	
	if (data == nullptr)
		return 0;
	
	Value::Table* pTable = static_cast<Value::Table*>(data);
	size_t colCount = pTable->columsCount();
	if (colCount != static_cast<size_t>(argc))
		throw std::exception("The table does not match the request!", static_cast<int>(eErrors::incorrectOutData));

	Value::Row row;
	for (size_t i = 0; i < colCount; i++) {
		row.push_back(Value(pTable->getColum(i).type, argv[i]));
		//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	pTable->pushBack(row);

	return 0;
}

void DBSqlite::exec(const std::string& sqlReq, Value::Table& vOut)
{
	char *pszErrMsg = 0;

	if (!isConnected())
		throw std::exception("No connect to sqlite database!", static_cast<int>(eErrors::notConnected));

	vOut.clear();

	int iRes = sqlite3_exec(m_db, sqlReq.c_str(), fillOutTable, &vOut, &pszErrMsg);

	if (iRes != SQLITE_OK) {
		std::string sError = "SQL error: " + std::string(pszErrMsg) 
			+ "\n Response code: " + std::to_string(iRes);
		sqlite3_free(pszErrMsg);

		throw std::exception(sError.c_str(), static_cast<int>(eErrors::execute));
	}
}

void DBSqlite::close()
{
	if (m_db)
		sqlite3_close(m_db);
}