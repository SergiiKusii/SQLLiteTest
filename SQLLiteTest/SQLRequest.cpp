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

		sqlReq.replace(searchIdx, val.size(), val);
	}

	return sqlReq;
}

SQLRequest::SQLRequest()
{
	m_requests[createTableDbVersion] =
		"drop table T_DBVERS; CREATE TABLE [T_DBVERS](\
		[ID][int] PRIMARY KEY ASC NOT NULL AUTOINCREMENT,\
		[MAJOR][int] NULL,\
		[MINOR][int] NULL,\
		[SUBMINOR][int] NULL,\
		[BUILD][int] NULL\
		);\
		CREATE UNIQUE INDEX [PK_T_DBVERS_ID] ON T_DBVERS(ID);\
		INSERT INTO T_DBVERS(MAJOR, MINOR, SUBMINOR, BUILD) VALUES(1, 0, 0, 1)";
	m_requests[checkTableDbVersion] = "select count(type) from sqlite_master where type='table' and name='T_DBVERS';";
	m_requests[getDbVersion] = "SELECT MAJOR, MINOR, SUBMINOR, BUILD FROM T_DBVERS";
}