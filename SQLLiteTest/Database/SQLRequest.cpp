#include "SQLRequest.h"

#define IN_ARG "?"

std::string SQLRequest::get(const eRecusetId& idReq, const Value::Row& inArgs)
{
	std::string sqlReq = operator[](idReq);

	size_t searchIdx = 0;
	for (auto& value : inArgs)
	{
		std::string val = value.toString();
		searchIdx = sqlReq.find(IN_ARG, searchIdx);

		if (searchIdx == std::string::npos)
			throw std::exception("Incorect count of input args", static_cast<int>(eErrors::makeRequest));

		sqlReq.erase(searchIdx, sizeof(IN_ARG) - 1);
		sqlReq.insert(searchIdx, val);
	}

	return sqlReq;
}

SQLRequest::SQLRequest()
{
	m_requests[createTable] =
		"CREATE TABLE [?](\
		[ID][integer] PRIMARY KEY ASC AUTOINCREMENT\
		? ); ";
	m_requests[createAttribute] = "[?][?] NULL";

	m_requests[createTableDbVersion] =
		"CREATE TABLE [T_DBVERS](\
		[ID][integer] PRIMARY KEY ASC AUTOINCREMENT,\
		[MAJOR][int] NULL,\
		[MINOR][int] NULL,\
		[SUBMINOR][int] NULL,\
		[BUILD][int] NULL\
		);\
		INSERT INTO T_DBVERS(MAJOR, MINOR, SUBMINOR, BUILD) VALUES(1, 0, 0, 1)";

	m_requests[checkTable] = "SELECT COUNT(type) FROM sqlite_master WHERE type='table' and name = ?;";
	m_requests[dropTable] = "DROP TABLE ?;";
	m_requests[getDbVersion] = "SELECT MAJOR, MINOR, SUBMINOR, BUILD FROM T_DBVERS";
}