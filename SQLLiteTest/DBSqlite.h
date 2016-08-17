#include "IDataBase.h"
#include "sqlite\sqlite3.h"

class DBSqlite : public IDataBase
{
public:
	DBSqlite();

	void connect(const std::string& connStr);

	bool isConnected();

	bool avaliable();

	void exec(const std::string& sqlReq);

	void exec(const std::string& sqlReq, Value::Table& vOut);

	void close();

	virtual ~DBSqlite();

	static int fillOutTable(void *data, int argc, char **argv, char **azColName);

private:

	sqlite3* m_db;
	//std::string m_sConnectStr;
};
