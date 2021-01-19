#pragma once
#include "../../ESGLib.h"

class MngSprite
{
public:

	MngSprite();
	~MngSprite() {};

	//生成メソッド
	int  MngSprite::CreateSprite(Vector2 size,Color color,Vector3 position);
	int  MngSprite::CreateSpriteFromFile(LPCTSTR file_name,Vector3 position);
	
	int  MngSprite::CreateSpriteFromFileRect(LPCTSTR file_name, Vector3 position);
	int  MngSprite::CreateSpriteFromFileAlpha(LPCTSTR file_name, Vector3 position);

	//フィードアウト
	bool MngSprite::BlackOutTrigger(int slot);

	//描画メソッド
	void MngSprite::DrawSprite();

	void MngSprite::SetRectWH(int slot, const int l, const int t, const int w, const int h) { _sprite_rectwh[slot] = RectWH(l, t, w, h); };

private:

	enum DRAW_TYPE{NOMAL,RECTWH,ALPHA,TYPE_MAX,} type;

	std::vector<std::vector<SPRITE>>  _sprite;
	std::vector<std::vector<Vector3>> _sprite_position;

	std::vector<RectWH>  _sprite_rectwh;
	std::vector<float >  _sprite_alpha;

	float _alpha = 0.0f;
};