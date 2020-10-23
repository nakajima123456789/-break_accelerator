#include "C_DIS.h"
#include <algorithm>


std::list<CDis*> CDis::c_dis_list = {};

void CDis::Init()
{
	c_dis_list.push_back(this);
	tag = "default";
}

 /**
  * @fn
  * @detail 詳細な説明　解放されたときに呼び出し自分の情報をリストから削除する。
  */
void CDis::IsRemove()
{
	auto is_it = c_dis_list.begin();
	while (is_it != c_dis_list.end()) {
		if ((*is_it) != this) {
			is_it++;}
		else {
			is_it = c_dis_list.erase(is_it);
			return;
		}
	}
}

/**
 * @fn
 * @param (std::string _tag) 引数の説明　インスタンス元のタグを指定する
 * @detail 詳細な説明　タグ登録　"default"以外
 */
void CDis::IsTagSet(std::string _tag)
{ 
	ASSERT(_tag != "default" && "default以外にしてください。");
	tag = _tag;
};

/**
 * @fn
 * @param (Vector3 _pos) 引数の説明　インスタンス元のモデルの座標
 * @detail 詳細な説明 座標の登録
 */
void CDis::IsPosition(Vector3 _pos){pos = _pos;}

/**
 * @fn
 * @param (std::string _tag) 引数の説明　タグ登録
 * @return 戻り値の説明　指定されたタグが見つかればTRUE　そうでなければFALSE
 * @detail 詳細な説明　　タグ検索関数
 */
bool CDis::TagSerch(std::string _tag)
{
	bool flag = false;
	for (auto&& h : c_dis_list) {
		if (h->tag == _tag) { flag = true; };
	}
	return flag;
}

/**
 * @fn
 * @param (std::string _tag) 引数の説明　欲しいタグの最小距離を取得する。
 * @return 戻り値の説明　計算した最小距離を返す
 * @detail 詳細な説明　　今まで登録してきたタグの中で最小の値を取得できる関数
 */
float CDis::GetTagDistance(std::string _tag)
{
	ASSERT(TagSerch(_tag) && "tagが存在していない!");

	std::vector<CDis*> C_DIS;
	for (auto&& other : c_dis_list)
	{
		if (other->tag != _tag)          continue;
		if (other->GetThisDis() == this) continue; 
		C_DIS.push_back(other->GetThisDis());
	}

	float tag_min_dis = FLT_MAX;

	if (C_DIS.size() != 0){
		std::vector<float> at_distance;
		for (auto&& other : C_DIS){
			float other_distance = Vector3_Distance(other->pos, this->pos);
			at_distance.push_back(other_distance);
		}
		auto&& min_dis = std::min_element(at_distance.begin(), at_distance.end(), [](float a, float b) {return a < b; });

		tag_min_dis = *min_dis;
	}
	return tag_min_dis == FLT_MAX ? 0.0f : tag_min_dis;
}

