#include "MngInput.h"

MngInput::MngInput()
{
	this->Init();
}

void MngInput::Init() {
	//ゲームパッド使用宣言
	InputDevice.CreateGamePad(PAD_MAX);
	//キーボード初期化
	SetKeybordID(-1);
	ResetConfigKey();
	//ゲームパッド初期化
	for (int i = 0; i < PAD_MAX; i++) {
		//PadID指定
		SetPadID(i, i);
		//コンフィグ情報初期化
		ResetConfigButton(i);
	}
}

void MngInput::Update() {
	_keybuf = Keyboard->GetBuffer();
	_keystate = Keyboard->GetState();

	for (int i = 0; i < PAD_MAX; i++) {
		_padbuf[i]   = GamePad(PadPadID[i])->GetBuffer();
		_padstate[i] = GamePad(PadPadID[i])->GetState();
	}
}

bool MngInput::GetPadInputDown(int PadID, int KeyID) {
	return (BOOL)_padbuf[PadID].IsPressed(buttonID[PadPadID[PadID]][KeyID - 1]);
}
bool MngInput::GetPadInput(int PadID, int KeyID) {
	return _padstate[PadID].Buttons[KeyID - 1] != 0;
}

bool MngInput::GetPadandKeybordInputDown(int PadID, int KeyID) {
	if (PadPadID[PadID] == KeyBordPlayerID) {

		if (_keybuf.IsPressed(keybordID[KeyID])) return true;
	}
	return GetPadInputDown(PadID, KeyID);
}

bool MngInput::GetPadandKeybordInput(int PadID, int KeyID) {
	if (PadPadID[PadID] == KeyBordPlayerID) {

		if (_keystate.IsKeyDown(keybordID[KeyID])) return true;
	}
	return  GetPadInput(PadID, KeyID);
}

bool MngInput::GetAxisflag(int PadID)
{
	double pad_x, pad_z;
	pad_x = ((double)(_padstate[PadID].X - Axis_Center)) / ((double)(Axis_Max - Axis_Center));
	pad_z = ((double)(_padstate[PadID].Y - Axis_Center)) / ((double)(Axis_Max - Axis_Center));

	return pad_x == 0.0f && pad_z == 0.0f ? false : true;
}

double MngInput::GetAxisPadAngle(int PadID)
{
	double pad_x = 0.0f, pad_z = 0.0f;

	pad_x = ((double)(_padstate[PadID].X - Axis_Center)) / ((double)(Axis_Max - Axis_Center));
	pad_z = ((double)(_padstate[PadID].Y - Axis_Center)) / ((double)(Axis_Max - Axis_Center));

	return MathHelper_Atan2((double)pad_x, (double)-pad_z);
}

Vector3 MngInput::GetStickVector(int PadID) {
	Vector3 result = Vector3_Zero;

	if ((_padstate[PadID].X - Axis_Center) / (Axis_Max - Axis_Center) < Axis_Center) {
		result += Vector3_Left;
	}
	else {
		if ((_padstate[PadID].X - Axis_Center) / (Axis_Max - Axis_Center) > Axis_Center) {
			result += Vector3_Right;
		}
	}
	if ((_padstate[PadID].Y - Axis_Center) / (Axis_Max - Axis_Center) < Axis_Center)
	{
		result += Vector3_Up;
	}
	else {
		if ((_padstate[PadID].Y - Axis_Center) / (Axis_Max - Axis_Center) > Axis_Center) {
			result += Vector3_Down;
		}
	}

	return result;
}
Vector3 MngInput::GetArrowkeyVector() {
	Vector3 result = Vector3_Zero;

	if (_keystate.IsKeyDown(Keys_Left)) {
		result += Vector3_Left;
	}
	else {
		if (_keystate.IsKeyDown(Keys_Right)) {
			result += Vector3_Right;
		}
	}

	if (_keystate.IsKeyDown(Keys_Up)) {
		result += Vector3_Up;
	}
	else {
		if (_keystate.IsKeyDown(Keys_Down)) {
			result += Vector3_Down;
		}
	}
	return result;
}

Vector3 MngInput::GetStickandArrowkeyVector(int PadID) {
	if (PadPadID[PadID] == KeyBordPlayerID) {
		if (GetArrowkeyVector() != Vector3_Zero) return GetArrowkeyVector();
	}
	return GetStickVector(PadID);
}

//コンフィグ用
void MngInput::SetKeybordID(int PadID) {
	MngInput::KeyBordPlayerID = PadPadID[PadID];
}
void MngInput::SetPadID(int PadID, int newPadID) {
	PadPadID[PadID] = newPadID;
}
void MngInput::SetConfigButtonID(int PadID, int button, int buttonid) {
	buttonID[PadPadID[PadID]][button] = buttonid;
}
void MngInput::SetConfigKeyID(int key, int keyid) {
	keybordID[key] = keyid;
}

//コンフィグリセット用
void MngInput::ResetConfigButton(int PadID) {
	SetConfigButtonID(PadID, 0, GamePad_Button1);
	SetConfigButtonID(PadID, 1, GamePad_Button2);
	SetConfigButtonID(PadID, 2, GamePad_Button3);
	SetConfigButtonID(PadID, 3, GamePad_Button4);
	SetConfigButtonID(PadID, 4, GamePad_Button5);
	SetConfigButtonID(PadID, 5, GamePad_Button6);
	SetConfigButtonID(PadID, 6, GamePad_Button7);
	SetConfigButtonID(PadID, 7, GamePad_Button8);
	SetConfigButtonID(PadID, 8, GamePad_Button9);
	SetConfigButtonID(PadID, 9, GamePad_Button10);
	SetConfigButtonID(PadID, 10, GamePad_Button11);
	SetConfigButtonID(PadID, 11, GamePad_Button12);
	SetConfigButtonID(PadID, 12, GamePad_Button13);
	SetConfigButtonID(PadID, 13, GamePad_Button14);
	SetConfigButtonID(PadID, 14, GamePad_Button15);
	SetConfigButtonID(PadID, 15, GamePad_Button16);
	SetConfigButtonID(PadID, 16, GamePad_Button17);
	SetConfigButtonID(PadID, 17, GamePad_Button18);
	SetConfigButtonID(PadID, 18, GamePad_Button19);
	SetConfigButtonID(PadID, 19, GamePad_Button20);
	SetConfigButtonID(PadID, 20, GamePad_Button21);
	SetConfigButtonID(PadID, 21, GamePad_Button22);
	SetConfigButtonID(PadID, 22, GamePad_Button23);
	SetConfigButtonID(PadID, 23, GamePad_Button24);
	SetConfigButtonID(PadID, 24, GamePad_Button25);
	SetConfigButtonID(PadID, 25, GamePad_Button26);
	SetConfigButtonID(PadID, 26, GamePad_Button27);
	SetConfigButtonID(PadID, 27, GamePad_Button28);
	SetConfigButtonID(PadID, 28, GamePad_Button29);
	SetConfigButtonID(PadID, 29, GamePad_Button30);
	SetConfigButtonID(PadID, 30, GamePad_Button31);
}
void MngInput::ResetConfigKey() {
	SetConfigKeyID(0, Keys_Z);
	SetConfigKeyID(1, Keys_X);
	SetConfigKeyID(2, Keys_C);
}

bool MngInput::GetKeybordInputDown(int KeyID)
{
	if (_keybuf.IsPressed(KeyID)) return true;
	return false;
}

bool MngInput::GetKeybordInput(int KeyID)
{
	if (_keystate.IsKeyDown(KeyID)) return true;
	return false;
}

Vector3 MngInput::GetArrowPadVector(int PadID)
{
	Vector3 result = Vector3(0.0f, 0.0f, 0.0f);
	result.x = ((double)(_padstate[PadID].X - Axis_Center)) / ((double)(Axis_Max - Axis_Center));
	result.z = ((double)(_padstate[PadID].Y - Axis_Center)) / ((double)(Axis_Max - Axis_Center));

	float circle_x, circle_z;
	circle_x =  result.x * Math_Sqrt(1.0f - 0.5f * result.z * result.z);
	circle_z = -result.z * Math_Sqrt(1.0f - 0.5f * result.x * result.x);

	result.x = circle_x;
	result.z = circle_z;

	return Vector3(result);
}

Vector3 MngInput::GetArrowPadVectorNomal(int PadID)
{
	Vector3 result = Vector3(0.0f, 0.0f, 0.0f);

	result.x = ((double)(_padstate[PadID].X - Axis_Center)) / ((double)(Axis_Max - Axis_Center));
	result.z = ((double)(_padstate[PadID].Y - Axis_Center)) / ((double)(Axis_Max - Axis_Center));

	return Vector3(result);
}