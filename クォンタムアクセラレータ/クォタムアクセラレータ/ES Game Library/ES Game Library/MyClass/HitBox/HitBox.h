#pragma once

#include "../Object/Object.h"

class HitBox : public Object
{
public:
	//デストラクタ
	HitBox::HitBox();

	virtual HitBox::~HitBox();

	virtual void HitBox::Init()   override;
	virtual void HitBox::Update() override { return; };
	virtual void HitBox::Draw3D() override;

	void HitBox::OnReMove();

	//自身を返す
	HitBox* HitBox::GetThisHitBox() { return this; };
	HitBox* HitBox::GetOtherHitBox(std::string other_tag);

	void SetHitBoxPosition(Vector3 _position) { _model->SetPosition(_position); };

	//衝突しているHitBoxのリストを取得
	std::list<HitBox*> HitBox::HitHitBoxlist();

	void    Settags(std::string tags);

	bool HitBox::IsHitObjects(std::string tags);

private:
	//全てのHitBoxを格納しておくリスト
	static std::list<HitBox*> _HitBox_list;

	//判定用のモデル
	MODEL       _model = nullptr;
	std::string _tag;

	//衝突判定関数
	bool HitBox::IsHit(HitBox* other);

protected:

};
