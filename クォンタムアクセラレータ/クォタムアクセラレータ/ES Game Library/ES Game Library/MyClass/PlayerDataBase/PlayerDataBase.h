#pragma once
#include "../../ESGLib.h"

class IPlayerDataBase
{
public:
	IPlayerDataBase() {};
	virtual ~IPlayerDataBase() {};

	void ResetIPlayerDataBase()
	{
		player_position = Vector3(0.0f, 0.0f, 0.0f);
	}

	static IPlayerDataBase& GetInstance()
	{
		static IPlayerDataBase instance;
		return instance;
	};

	void     SetPlayerPosition(Vector3 position) { player_position = position; };
	Vector3  GetPlayerPosition()           const { return player_position;     };

private:

	Vector3 player_position;

	IPlayerDataBase    (const IPlayerDataBase&) = delete;
	void      operator=(const IPlayerDataBase&) = delete;
};  
#define PlayerDataBase IPlayerDataBase::GetInstance()