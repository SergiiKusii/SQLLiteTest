#pragma once
#include <string>
#include <tuple>
#include <assert.h> 
#include <vector>

class Value
{
public:
	enum class eErrors : int {
		ok = 200,
		internal = 201,
		columTypeMissmath,
		last = 299
	};

	enum class eType : int {
		Int = 0,
		Double = 1,
		String = 2
	};

	static std::string typeName(const eType& type, const size_t stringSize = 0);

	typedef std::tuple<int, double, std::string> ValueType;

	Value(const eType& type, const ValueType& value) : m_type(type), m_value(value){};

	Value(const eType& type, const std::string& sValue);

	Value(const eType& type, const size_t stringSize = 0) : m_type(type), m_stringSize(stringSize) {};

	Value(const int value) { 
		m_type = eType::Int;
		std::get<0>(m_value) = value; 
	};
	Value(const double& value) {
		m_type = eType::Double;
		std::get<1>(m_value) = value;
	};
	Value(const std::string& value) {
		m_type = eType::String;
		std::get<2>(m_value) = value;
	};

	eType getType()	const{
		return m_type;
	};

	std::string toString() const;

	ValueType getValue(){
		return m_value;
	};

	int getInt() const {
		return std::get<0>(m_value);
	};

	double getDouble() const {
		return std::get<1>(m_value);
	};

	std::string getString() const {
		return std::get<2>(m_value);
	};

	bool hasType(const eType& type) const {
		return static_cast<int>(type) == static_cast<int>(m_type);
	};

	std::string typeName() const {
		return Value::typeName(m_type, m_stringSize);
	}

	virtual ~Value() {};

private:
	ValueType m_value;
	size_t m_stringSize; //0 if max
	eType m_type;

public:
	typedef std::vector<Value> Row;
	struct Colum
	{
		std::string sName;
		eType type;

		Colum(const eType& eColType, const std::string& sColName) : type(eColType), sName(sColName) {};
	};

	class Table
	{
	public:
		Table() {};
		void clear() {
			m_data.clear();
		};
		void addColum(const Colum& col) {
			m_colums.push_back(col);
		};
		void addColum(const eType& type) {
			addColum(Colum(type, ""));
		};
		void pushBack(const Row& row) {
			checkRow(row);
			m_data.push_back(row);
		};
		void removeColum(const size_t idx) {
			//TODO
		};
		size_t columsCount() {
			return m_colums.size();
		};
		size_t count() {
			return m_colums.size();
		};
		Row& operator[](size_t idx) {
			return m_data[idx];
		};
		Colum& getColum(const size_t idx) {
			return m_colums[idx];
		};
	private:
		std::vector<Row> m_data;
		std::vector<Colum> m_colums;

		void checkRow(const Row& row) const{
			bool isError = false;

			if (row.size() != m_colums.size())
				throw std::exception("Row has not added!", static_cast<int>(eErrors::columTypeMissmath));
			else {
				for (size_t idx = 0; idx < row.size(); idx++) {
					if( !row[idx].hasType(m_colums[idx].type))
						throw std::exception("Row has not added!", static_cast<int>(eErrors::columTypeMissmath));
				}
			}
				
		};
	};
};


