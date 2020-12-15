#pragma once
#include "../../ESGLib.h"
#include "../C_SHADER/C_SHADER.h"
#include "../CPLAYERDATA/CPlayerData.h"

//�L�����N�^�[�����N���X

class ModelBase
{
protected:
	Material SetMaterial(Color color);

	virtual void SetModel(LPCTSTR model_filename)    = 0;
	virtual void SetShader(LPCTSTR model_filename)   = 0;
	virtual void SetMove(Vector3  move_position)     = 0;
	virtual void SetPosition(Vector3 position)       = 0;
	virtual void SetRotation(Vector3 rotation)       = 0;
	virtual void SetScale(float character_scale)     = 0;
	virtual void SetDirection(Quaternion quaternion) = 0;
};

class AnimationModel : public ModelBase
{
public:
	//�A�j���[�V�����̃p�����[�^�̐ݒ�֐�

	virtual void SetModel(LPCTSTR model_filename)    override;
	virtual void SetShader(LPCTSTR model_filename)   override;
	virtual void SetMove(Vector3  move_position)     override { _animation_model->Move(move_position);   };
	virtual void SetPosition(Vector3 position)       override { _animation_model->SetPosition(position); };
	virtual void SetRotation(Vector3 rotation)       override { _animation_model->SetRotation(rotation); };
	virtual void SetScale(float character_scale)     override { _animation_model->SetScale(character_scale); };
	virtual void SetDirection(Quaternion quaternion) override { _animation_model->SetDirection(quaternion); };

	void SetPlayerState(int new_state);
	void SetAdvanceTime(int generating_time, int animation_speed);

	void SetMateriaI(Color color)           { _animation_model->SetMaterial(SetMaterial(color)); };

	ANIMATIONMODEL GetAnimationModel() { return _animation_model; };

	//�A�j���[�V�����̃p�����[�^���擾

	Vector3 GetFrontVector() const { return _animation_model->GetFrontVector(); };
	Vector3 GetPosition()    const { return _animation_model->GetPosition();    };

	Quaternion GetDirectionQuaternion() const { return  _animation_model->GetDirectionQuaternion(); };


	//�`��^�C�v�I���@�e�ƃV�F�[�_�[�ƕ��ʂ̂R�@�����ɓK�p���ł��Ȃ�
	void DrawShader(float alpha);
	void Draw();
	void DrawShadow();

	int GetPlayerState() const { return _player_state; };

	//�e�̕`��
	Matrix Create_Shadow(const D3DLIGHTTYPE light_type, const Vector3& light, const Vector3& pos, const Vector3& shadow_offset, const Vector3& normal);

	ANIMATIONMODEL _animation_model = nullptr;
private:

	//�֐���`

	//�ϐ���`

	int     _player_state    = 0;

	double  _generating_time = 1.0f;
	double  _animation_speed = 60.0f;

	//�N���X�C���X�^���X�̒�`
	std::unique_ptr <CShaderManager> _shader;
};

class Model : public ModelBase
{
public:

	Model();

	//�A�j���[�V�����̃p�����[�^�̐ݒ�֐�
	virtual void SetModel(LPCTSTR model_filename)    override;

	virtual void SetShader(LPCTSTR model_filename)	 override;
	virtual void SetMove(Vector3  move_position)     override { _model->Move(move_position); };
	virtual void SetPosition(Vector3 position)       override { _model->SetPosition(position); };
	virtual void SetRotation(Vector3 rotation)       override { _model->SetRotation(rotation); };
	virtual void SetScale(float character_scale)     override { _model->SetScale(character_scale); };
	virtual void SetDirection(Quaternion quaternion) override { _model->SetDirection(quaternion); };

	MODEL GetModel() const { return _model; };

	float GetRadius() {float model = _model->GetOBB().Radius.x;};

	void Attenuation(float attenuation);

	void Model::SetModelData(MODEL Model) { _model = Model; 	_model->SetMaterial(SetMaterial(Color(1.0f, 1.0f, 1.0f)));};

	//�A�j���[�V�����̃p�����[�^���擾

	//�`��^�C�v�I���@�Î~�������f���Ȃ̂ŕ��ʕ`�悾��
	void Draw();
	void DrawShader(float alpha);

    void SetModels(MODEL model);

private:

	//�֐���`

	//�ϐ���`

	MODEL _model = nullptr;

	//�N���X�C���X�^���X�̒�`
	std::unique_ptr <CShaderManager>  _shader;
	std::unique_ptr<IPlayerData>      _iplayer_data;

};