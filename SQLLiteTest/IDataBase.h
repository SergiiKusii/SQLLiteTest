#pragma once
#include <string>
#include <vector>
#include "Value.h"

class IDataBase
{
public:

	enum class eErrors : int {
		ok = 100,
		internal,
		connect,
		notConnected,
		execute,
		incorrectOutData,
		last = 199
	};

	IDataBase() {};

	virtual void connect(const std::string& connStr) = 0;

	virtual bool isConnected() = 0;

	virtual bool avaliable() = 0;
	
	virtual void exec(const std::string& sqlReq) = 0;
	
	virtual void exec(const std::string& sqlReq, Value::Table& vOut) = 0;
	
	virtual void close() = 0;

	virtual ~IDataBase() {};
};
