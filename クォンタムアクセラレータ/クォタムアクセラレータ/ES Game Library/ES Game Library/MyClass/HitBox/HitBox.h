#pragma once

#include "../Object/Object.h"

class HitBox : public Object
{
public:
	//�f�X�g���N�^
	HitBox::HitBox();

	virtual HitBox::~HitBox();

	virtual void HitBox::Init()   override;
	virtual void HitBox::Update() override { return; };
	virtual void HitBox::Draw3D() override;

	void HitBox::OnReMove();

	//���g��Ԃ�
	HitBox* HitBox::GetThisHitBox() { return this; };
	HitBox* HitBox::GetOtherHitBox(std::string other_tag);

	void SetHitBoxPosition(Vector3 _position) { _model->SetPosition(_position); };

	//�Փ˂��Ă���HitBox�̃��X�g���擾
	std::list<HitBox*> HitBox::HitHitBoxlist();

	void    Settags(std::string tags);

	bool HitBox::IsHitObjects(std::string tags);

private:
	//�S�Ă�HitBox���i�[���Ă������X�g
	static std::list<HitBox*> _HitBox_list;

	//����p�̃��f��
	MODEL       _model = nullptr;
	std::string _tag;

	//�Փ˔���֐�
	bool HitBox::IsHit(HitBox* other);

protected:

};
