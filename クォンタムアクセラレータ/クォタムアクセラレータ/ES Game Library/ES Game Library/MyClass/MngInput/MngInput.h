#pragma once
#include "../../ESGLib.h"

//◆ボタンの最大数
int const BUTTON_MAX = 31;
//◆ゲームパッドの最大数
int const PAD_MAX = 4;

class MngInput
{
public:
	MngInput();
	virtual ~MngInput() {};

	MngInput(const MngInput&) = delete;
	MngInput& operator=(const MngInput&) = delete;
	MngInput(MngInput&&) = delete;
	MngInput& operator=(MngInput&&) = delete;

	static MngInput& GetInstance()
	{
		static MngInput _input;
		return _input;
	}

	void MngInput::Init();
	void MngInput::Update();

	bool MngInput::GetPadInputDown(int PadID, int KeyID);
	bool MngInput::GetPadInput(int PadID, int KeyID);

	bool MngInput::GetPadandKeybordInputDown(int PadID, int KeyID);
	bool MngInput::GetPadandKeybordInput(int PadID, int KeyID);
	bool MngInput::GetAxisflag(int PadID);

	double MngInput::GetAxisPadAngle(int PadID);

	Vector3 MngInput::GetStickVector(int PadID);
	Vector3 MngInput::GetArrowkeyVector();
	Vector3 MngInput::GetStickandArrowkeyVector(int PadID);

	void MngInput::SetKeybordID(int PadID);
	void MngInput::SetPadID(int PadID, int newPadID);
	void MngInput::SetConfigButtonID(int PadID, int button, int buttonid);
	void MngInput::SetConfigKeyID(int key, int keyid);

	void MngInput::ResetConfigButton(int PadID);
	void MngInput::ResetConfigKey();

	bool MngInput::GetKeybordInputDown(int KeyID);
	bool MngInput::GetKeybordInput(int KeyID);

	Vector3 MngInput::GetArrowPadVector     (int PadID);
	Vector3 MngInput::GetArrowPadVectorNomal(int PadID);

private:
	int PadPadID[PAD_MAX];
	int KeyBordPlayerID;

	BYTE buttonID[PAD_MAX][BUTTON_MAX];
	int  keybordID[BUTTON_MAX];

	GamePadBuffer  _padbuf[PAD_MAX];
	KeyboardBuffer _keybuf;
	GamePadState   _padstate[PAD_MAX];
	KeyboardState  _keystate;
};
#define Input MngInput::GetInstance()