#include "CEffekseer_.h"
#include <algorithm>


CEffekseer_::CEffekseer_()
{
	Effekseer.Attach(GraphicsDevice);
	effekseer.clear();
	effekseer.reserve(4);
}

CEffekseer_::~CEffekseer_()
{
	effekseer.clear();
}

/**
 * @fn
 * @param (TCHAR* filename) �����̐����@EFFEKSEER�̃t�@�C���l�[����o�^����
 * @return �߂�l�̐����@�X���b�g�ԍ���Ԃ���Ɏw��ł���
 * @detail �ڍׂȐ����@�@�G�t�F�N�g�f�[�^�̓o�^
 */
int CEffekseer_::LoadEffekseer(TCHAR* filename)
{
	EFFEKSEER _effekseer;
	_effekseer = Effekseer.CreateEffectFromFile(filename);

	effekseer.push_back(_effekseer);

	return effekseer.size() - 1;
}

EFFEKSEER CEffekseer_::GetEffekseer(int _number)
{
    return effekseer[_number];
}

/**
 * @fn
 * @param (int _number) �����̐����@LoadEffekseer�̖߂�l�������邱�ƂŔC�ӂ̃G�t�F�N�g�ɃA�N�Z�X�ł���
 * @detail �ڍׂȐ����@�傫���ƍĐ����W�����߂�B
 */
int CEffekseer_::PlayEffekseer(int& _number,Vector3& _pos)
{
    int id = effekseer[_number]->Play(_pos);

	effekseer[_number]->SetPosition(id, _pos);
	effekseer[_number]->SetScale(id,  0.08f);

	return effekseer.size() - 1;
}

void CEffekseer_::Update()
{
	Effekseer.Update();
}

void CEffekseer_::Draw(CAMERA& _camera)
{
	Effekseer.SetCamera(_camera);
	Effekseer.Draw();
}


