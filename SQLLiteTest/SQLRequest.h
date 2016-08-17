#pragma once
#include <map>
#include <string>
#include <vector>
#include <memory>
#include "Value.h" 

class SQLRequest
{
public:
	enum class eErrors
	{
		ok = 0,
		internal,
		requestNotFound,
		makeRequest,
		last = 99
	};

	enum eRecusetId
	{
		createTableDbVersion = 0,
		checkTableDbVersion,
		getDbVersion
	};

	static SQLRequest* instance() {
		static auto	m_instance = std::shared_ptr<SQLRequest>(new SQLRequest());

		return m_instance.get();
	}

	std::string operator[](const eRecusetId& idReq)	{
		auto it = m_requests.find(idReq);
		if (it == m_requests.end())
			throw std::exception("Request not found!", static_cast<int>(eErrors::requestNotFound));

		return m_requests[idReq];
	}

	std::string get(const eRecusetId& idReq, const Value::Row& inArgs);
	std::string get(const eRecusetId& idReq) {
		return operator[](idReq);
	};

	virtual ~SQLRequest() {};

private:
	SQLRequest();
	std::map<eRecusetId, std::string> m_requests;
};
