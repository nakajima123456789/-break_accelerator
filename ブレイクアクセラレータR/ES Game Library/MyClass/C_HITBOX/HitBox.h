#pragma once
#include "../../ESGLib.h"
#include <functional>

using std::string;

class HitBox {
public:
	//デストラクタ
	HitBox::HitBox(std::string tag);

	virtual HitBox::~HitBox();

	//初期化
	virtual void HitBox::Init();

	//描画
	virtual void HitBox::Draw3D();
	virtual void HitBox::DrawAlpha3D();

	//パラメータを設定
	virtual void HitBox::SetHitBox();

	//消去時に呼ばれる処理
	void HitBox::OnReMove();

	void SetHitBoxScale(float sca);	
	void SetHitBoxScale(Vector3 sca);

	void SetHitBoxPosition(Vector3 pos);

	//自身を返す
	HitBox* HitBox::GetThisHitBox() { return this; };

	//衝突しているHitBoxのリストを取得
	std::list<HitBox*> HitBox::HitHitBoxlist();

	void    Settags(std::string tags);
	void    SetColor(Vector3 colors);
	void    HitBoxMove(Vector3 move);

	Vector3 GetHitBoxPosition()const { return _model->GetPosition(); };

	HitBox* HitBox::TypeRayRange(std::string tag, Vector3 position, Vector3 angle, float& range);
	HitBox* HitBox::Get_Tag_HitBox(std::string tag);
	MODEL   HitBox::Get_Tag_Model() const { return _model; };
	bool    HitBox::Tag_Sarch(string _tag);

	bool HitBox::IsHitObjects(std::string tags);

	string _tag;
private:
	//全てのHitBoxを格納しておくリスト
	static std::list<HitBox*> _HitBox_list;

	//判定用のモデル
	MODEL _model = nullptr;

	Vector3 position;
	Vector3    scale;

	Vector3 color = Vector3(1.0f, 0.0f, 0.0f);

	//衝突判定関数
	bool HitBox::IsHit(HitBox* other);


protected:
	
};