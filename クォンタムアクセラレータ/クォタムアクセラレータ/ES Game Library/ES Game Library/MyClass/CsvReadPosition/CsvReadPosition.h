#pragma once

#include "../CsvPositionDataBase/CsvPositionDataBase.h"

class CsvReadPosition
{
public:

	CsvReadPosition();
   ~CsvReadPosition() {};

private:

	std::vector<cstring>  mapdata;

	void SetCsvPositionDataBase();

	//�v���C���[�̃f�[�^�x�[�X
	std::unique_ptr<CsvPositionDataBases>   csv_position_database;

protected:
	
};