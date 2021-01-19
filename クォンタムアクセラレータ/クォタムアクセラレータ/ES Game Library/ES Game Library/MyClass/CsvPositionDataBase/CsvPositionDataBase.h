#pragma once
#include "../../ESGLib.h"

class  ICsvPositionDataBase;
struct PositionParam;
class  CsvPositionDataBases;

struct PositionParam {
	std::vector<Vector3>  _position;
};

class ICsvPositionDataBase
{
public:
	friend class CsvPositionDataBases;

	ICsvPositionDataBase() {};
	virtual ~ICsvPositionDataBase() {};

	static ICsvPositionDataBase& Instance() {
		static ICsvPositionDataBase instance;
		return instance;
	};

	void CreateParametor(char name) { _map_params.emplace(name, _map_param); }
	std::map<char, PositionParam> _map_params;
private:
	ICsvPositionDataBase(const ICsvPositionDataBase&) = delete;
	void      operator=(const ICsvPositionDataBase&) = delete;

	PositionParam                 _map_param;
};


class CsvPositionDataBases
{
public:
	CsvPositionDataBases() {};
	virtual ~CsvPositionDataBases() {};

	static CsvPositionDataBases& GetInstance()
	{
		static CsvPositionDataBases instance;
		return instance;
	};

	void SetCsvPosition(char name, Vector3 position){
		if (ICsvPositionDataBase::Instance()._map_params.count(name) == 0)
			ASSERT("連想配列の存在しません。");

		ICsvPositionDataBase::Instance()._map_params[name]._position.push_back(position);
	}

	std::vector<Vector3>& GetCsvPosition(char name){
		if (ICsvPositionDataBase::Instance()._map_params.count(name) == 0)
			ASSERT("連想配列の存在しません。");

		return ICsvPositionDataBase::Instance()._map_params[name]._position;
	}
private:
	CsvPositionDataBases(const CsvPositionDataBases&) = delete;
	void      operator=(const CsvPositionDataBases&) = delete;
};
#define CsvPoitionDataBase CsvPositionDataBases::GetInstance()