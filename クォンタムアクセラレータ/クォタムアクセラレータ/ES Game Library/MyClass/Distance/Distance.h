#pragma once
//------------------------------------------------------------------------------
//	インクルードファイル
//------------------------------------------------------------------------------
#include "../Object/Object.h"

class Distance : public Object
{
private:

	//関数宣言

	//自分自身を返す
	Distance* OneselfInformation() { return this; }

	pair<std::vector<float>, std::vector<Distance*>> RegistrationOnlyMe(std::string _tags);

         std::vector<float> DistanceCalculatingArray(std::vector<Distance*> cdistance);

	//変数宣言

	static std::list<Distance*> _c_distance_list;

	std::string _tags;

public:

	Distance();
	virtual ~Distance() { IsRemove(); };

	//削除
	void  IsRemove();
	void  Settags(std::string tag) { _tags = tag; };

	//距離取得
	float   TagMiddleMiniMum(std::string _tag);
	Vector3 TagMiddleNearToPlayerPos(std::string _tag);

	//検索
	bool TagSerch(std::string _tag);

};