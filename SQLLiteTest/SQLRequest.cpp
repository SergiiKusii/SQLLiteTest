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
		"CREATE TABLE [T_DBVERS](\
		[ID][int] IDENTITY(1, 1) NOT NULL,\
		[MAJOR][int] NULL,\
		[MINOR][int] NULL,\
		[SUBMINOR][int] NULL,\
		[BUILD][int] NULL\
		CONSTRAINT[PK_T_DBVERS_ID] PRIMARY KEY CLUSTERED([ID])\
		);\
		INSERT INTO T_DBVERS(MAJOR, MINOR, SUBMINOR, BUILD) VALUES(1, 0, 0, 1)";
	m_requests[checkTableDbVersion] = "select count(type) from sqlite_master where type='table' and name='T_DBVERS';";
}