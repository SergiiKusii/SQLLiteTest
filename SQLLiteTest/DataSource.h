#pragma once
#include "IDataBase.h"
#include <memory>

#include "SQLRequest.h"

enum eVersion{
	MAJOR = 1,
	MINOR = 0,
	SUBMINOR = 0,
	BUILD = 1
};

class DataSource
{
public:
	static DataSource* instance()	{
		static auto	m_instance = std::shared_ptr<DataSource>(new DataSource());

		return m_instance.get();
	}

	IDataBase* getDB()	{
		return m_pDB.get();
	};

	void createDB() {
		SQLRequest& req = *SQLRequest::instance();
		m_pDB->exec(req[SQLRequest::createTableDbVersion]);
	};

	void updateDB() {

	};

	bool needCreate() {
		Value::Table table;
		table.addColum(Value::eType::Int);
		m_pDB->exec(SQLRequest::instance()->get(SQLRequest::checkTableDbVersion), table);
		return table[0][0].getInt() != 0;
	};

	bool needUpdate() {
		Value::Table table;
		table.addColum(Value::eType::Int);
		table.addColum(Value::eType::Int);
		table.addColum(Value::eType::Int);
		table.addColum(Value::eType::Int);
		m_pDB->exec(SQLRequest::instance()->get(SQLRequest::getDbVersion), table);

		return !(table[0][0].getInt() == MAJOR && table[0][1].getInt() == MINOR && table[0][2].getInt() == SUBMINOR && table[0][3].getInt() == BUILD);
	};

	virtual ~DataSource();
private:
	DataSource();
	std::shared_ptr<IDataBase> m_pDB;
};

