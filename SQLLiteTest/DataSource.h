#pragma once
#include "Database\IDataBase.h"
#include <memory>

#include "Database\SQLRequest.h"

class DataSource
{
public:
	static DataSource* instance()	{
		static auto	m_instance = std::shared_ptr<DataSource>(new DataSource());

		return m_instance.get();
	}
	static IDataBase* sGetDB() {
		return instance()->getDB();
	};

	IDataBase* getDB()	{
		return m_pDB.get();
	};

	std::string m_sError;

	virtual ~DataSource();
private:
	DataSource();
	std::shared_ptr<IDataBase> m_pDB;
};

