#pragma once
#include "../../ESGLib.h"
#include "../C_OBJECT/Object.h"

class HitBox : public Object 
{
public:
	//�f�X�g���N�^
	HitBox::HitBox() {};

	virtual HitBox::~HitBox();

	virtual void HitBox::Init()   override;
	virtual void HitBox::Update() override { return; };
	virtual void HitBox::Draw3D() override;

	void HitBox::OnReMove();

	void HitBox::SetScale(Vector3 scale) { _model->SetScale(scale); };

	//���g��Ԃ�
	HitBox* HitBox::GetThisHitBox() { return this; };

	//�Փ˂��Ă���HitBox�̃��X�g���擾
	std::list<HitBox*> HitBox::HitHitBoxlist();

	void    Settags(std::string tags);

	HitBox* HitBox::Get_Tag_HitBox(std::string tag);
	MODEL   HitBox::GetModel()   { return _model; };

	bool HitBox::IsHitObjects(std::string tags);

	bool _flag = false;

private:
	//�S�Ă�HitBox���i�[���Ă������X�g
	static std::list<HitBox*> _HitBox_list;

	//����p�̃��f��
	MODEL _model = nullptr;
	std::string _tag;

	//�Փ˔���֐�
	bool HitBox::IsHit(HitBox* other);

protected:
	
};