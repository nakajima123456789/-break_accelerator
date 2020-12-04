#pragma once
#include "../../ESGLib.h"
#include "../C_INPUT/C_INPUT.h"
#include "../C_PLAYER/C_PLAYER.h"
#include "../C_OBJECT/Object.h"
int const BUTTON_MAX = 31;

class C_INPUT
{
private:
	C_INPUT();
	virtual ~C_INPUT();

	C_INPUT(const C_INPUT&) = delete;
	C_INPUT& operator=(const C_INPUT&) = delete;
	C_INPUT(C_INPUT&&) = delete;
	C_INPUT& operator=(C_INPUT&&) = delete;

public:
	inline static GamePadState  GetGamePadState()  { return GamePad(0)->GetState();  }
	inline static GamePadBuffer GetGamePadBuffer() { return GamePad(0)->GetBuffer(); }

	inline static KeyboardState  GetKeyState()     { return Keyboard->GetState();  }
	inline static KeyboardBuffer GetKeyBuffer()    { return Keyboard->GetBuffer(); }

	bool C_INPUT::KeyBoardButtomState(DWORD _key_buttom);

	bool C_INPUT::KeyBoardButtomBuffer(DWORD _key_buttom);

	static C_INPUT& GetInstance()
	{
		static C_INPUT c_input;
		return c_input;
	}
	Vector3 GetArrowkeyVector();
	Vector3 GetArrowpadVector();
	Vector3 GetArrowpadVectorNomalize();

	bool    GetPadInputDown(int KeyID);
	bool    GetPadInput(int KeyID);    
	bool    GetKeyInputDown(int keyID);

	double  AxisStateX();
	double  AxisStateY();

	int    DirectionAxisStateX();

	bool    AxisFlag();

	void    BufferButtomSetInit(int button, int buttonid);
	void    BufferButtomInit();

	float   PadKeyAngle();

private:
	BYTE buttom_manager[BUTTON_MAX];
	float angle = 0;
	MODEL player_model;
	Vector3 position = Vector3_Zero;
};

#define Input C_INPUT::GetInstance()





