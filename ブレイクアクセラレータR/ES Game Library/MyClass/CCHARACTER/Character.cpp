#include "Character.h"

/**
 * @file   Character.cpp
 * @brief  �L�����N�^�����N���X�\�[�X�t�@�C��
 * @author �����D��N
 * @date   2020/10/1
 */

 /**
  * @brief �ݒ�(�F�̐ݒ�)
  * @param[in] (color)�F�̐ݒ�
  * @return    (mtrl) �ݒ肵���F
  */
Material ModelBase::SetMaterial(Color color)
{
	Material mtrl;

	ASSERT(color <= Color(1.0f, 1.0f, 1.0f) && "�F��1.0f����");

	mtrl.Diffuse  = color;
	mtrl.Ambient  = color;
	mtrl.Specular = color;
	mtrl.Emissive = color;
	mtrl.Power = 1.0f;

	return mtrl;
}

/**
 * @brief ���f���ݒ�(�A�j���[�V�������f���̓ǂݍ��݁A�}�e���A���̐ݒ�)
 * @param[in] (model_filename) �A�j���[�V�������f���̃t�@�C���l�[��
 * @return    (�Ȃ�)
 */
void AnimationModel::SetModel(LPCTSTR model_filename)
{
	_animation_model = GraphicsDevice.CreateAnimationModelFromFile(model_filename);
	_animation_model->SetMaterial(SetMaterial(Color(1.0f, 1.0f, 1.0f)));

	ASSERT(_animation_model != nullptr && "�A�j���[�V�������f���������Ă��܂���B");
}

/**
 * @brief �V�F�[�_�[�̐ݒ�(�V�F�[�_�[�̓ǂݍ���)
 * @param[in] (model_filename)���f���̃e�N�X�`��
 * @return    (�Ȃ�)
 */
void AnimationModel::SetShader(LPCTSTR model_filename)
{
	_shader.reset(new CShaderAnimation);

	SPRITE sprite = GraphicsDevice.CreateSpriteFromFile(model_filename);
	IDirect3DTexture9* texture = *sprite;

	ASSERT(texture != nullptr && "�摜��������Ȃ�!");

	_shader->ShaderInitialize(model_filename, _T("FX/Light.hlsl"));
}

/**
 * @brief �Đ����x(�A�j���[�V�������f���̍Đ��t���[���̐ݒ�)
 * @param[in] (animation_speed)�@�Đ����x	
 * @return    (�Ȃ�)
 */
void AnimationModel::SetAdvanceTime(int generating_time, int animation_speed)
{
	_generating_time = generating_time;
	_animation_speed = animation_speed;
}


/**
 * @brief �`��(�V�F�[�_�[��K�p������Ԃ̕`��)
 * @param[in] (alpha)�@�s�����x
 * @return    (�Ȃ�)
 */
void AnimationModel::DrawShader(float alpha)
{
	//�A�j���[�V�������f�������f����
	_shader->IsModelPass(_animation_model);

	float _alpha = alpha;

	EFFECT shader = _shader->ShaderDraw(_alpha, _animation_model->GetPosition());

	//�A�j���[�V�������f���Đ�
	_animation_model->AdvanceTime((_generating_time / _animation_speed));
	_animation_model->Draw(shader);
}

/**
 * @brief �`��(���ʂ̕`��)
 * @return    (�Ȃ�)
 */
void AnimationModel::Draw()
{
	_animation_model->AdvanceTime((_generating_time / _animation_speed));
	_animation_model->Draw();
}

/**
 * @brief �`��(�e��K�p������Ԃ̕`��)
 * @param[in] (�Ȃ�)
 * @return    (�Ȃ�)
 */
void AnimationModel::DrawShadow()
{
	GraphicsDevice.BeginShadowRendering();
	Matrix mat;

	mat = Create_Shadow(Light_Directional, Vector3_Zero, GetPosition(), Vector3(0.0f, 0.1f, 0.0f), Vector3_Up);

	_animation_model->DrawShadow(mat, /*�e�̔Z�x*/0.75f);

	GraphicsDevice.EndShadowRendering();

	_animation_model->AdvanceTime((_generating_time / _animation_speed));
	_animation_model->Draw();
}


/**
 * @brief�@�؂�ւ�(�A�j���[�V�����؂�ւ�)
 * @param[in] (new_state)�@�Đ��������A�j���[�V�����̃g���b�N
 * @return    (�Ȃ�)
 */
void AnimationModel::SetPlayerState(int new_state)
{
	if (_player_state == new_state) { return; }
	else {
		_animation_model->SetTrackEnable(_player_state, FALSE);
		_animation_model->SetTrackEnable(new_state, TRUE);
		_animation_model->SetTrackPosition(new_state, 0);
		_player_state = new_state;
	}
}

/**
 * @brief �e�̐���
 * @param[in] (light_type)�@���C�g�̃^�C�v
 * @param[in] (light)     �@���C�g�̏��
 * @param[in] (pos)     �@  �v���C���[�̍��W
 * @param[in] (shadowoffset)�e�̔Z�x
 * @return    (maT)         �ݒ肵���e�̏��
 */
inline Matrix AnimationModel::Create_Shadow(const D3DLIGHTTYPE light_type, const Vector3& light, const Vector3& pos, const Vector3& shadow_offset, const Vector3& normal)
{
	D3DXVECTOR4   Light;
	Light = D3DXVECTOR4(light + Vector3(0, 1500000, 150000) - pos, 0.0f);
	::D3DXVec4Normalize(&Light, &Light);

	D3DXPLANE     Plane;
	::D3DXPlaneFromPointNormal(&Plane, &(pos + shadow_offset), &normal);

	D3DXMATRIX   matT;
	::D3DXMatrixShadow(&matT, &Light, &Plane);

	return matT;
}

Model::Model()
{
	_iplayer_data.reset(new IPlayerData);
}

/**
 * @brief�@���f���̐ݒ�(���f���̓ǂݍ���)
 * @param[in] (model_filename)�@���f���̃t�@�C���l�[��
 * @return    (�Ȃ�)
 */
void Model::SetModel(LPCTSTR model_filename)
{
	_model = GraphicsDevice.CreateModelFromFile(model_filename);
	_model->SetMaterial(SetMaterial(Color(1.0f, 1.0f, 1.0f)));

	ASSERT(_model != nullptr && "���f����������܂���B");
}

/**
 * @brief�@�V�F�[�_�[�̐ݒ�(�V�F�[�_�[�Ƀe�N�X�`���̓ǂݍ���)
 * @param[in] (model_filename)�@���f���̃e�N�X�`��
 * @return    (�Ȃ�)
 */
void Model::SetShader(LPCTSTR model_filename)
{
	_shader.reset(new CShaderModel());

	_shader->ShaderInitialize(model_filename, _T("FX/Light.hlsl"));
}

/**
 * @brief�@�`��(���f���̕`��)
 * @param[in] (�Ȃ�)
 * @return    (�Ȃ�)
 */
void Model::Draw()
{
	_model->Draw();
}
/// <brief>�V�F�[�_�[��K�p�ł̕`��</brief>
/// <param  alpha>���f���̕s�����x</param>
/// <returns>���l</returns>
void Model::DrawShader(float alpha)
{
	ASSERT(alpha >= 0.0f && alpha <= 1.0f && "alpha�l��1����");

	_shader->IsModelPass(_model);

	EFFECT shader = _shader->ShaderDraw(alpha, _iplayer_data->GetPlayerPosition("player"));

	_model->Draw(shader);
}

/**
 * @brief�@�X�|�b�g���C�g�͈̔�
 * @param[in] (�Ȃ�)
 * @return    (�Ȃ�)
 */
void Model::Attenuation(float attenuation)
{
	ASSERT(attenuation <= 1.0f && "���C�g�̌�����1.0�����̒l�ɂ��Ă�������");

	_shader->SetAttenuation(attenuation);

}

