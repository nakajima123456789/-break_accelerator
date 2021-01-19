#include "Distance.h"

std::list<Distance*> Distance::_c_distance_list = {};

/**
 * @file   C_DIS.cpp
 * @brief  CDistance_クラスソースファイル
 * @author 中島颯一朗
 * @date   2020/10/1
 */

Distance::Distance()
{
	//自分自身の登録
	_c_distance_list.push_back(this);
}

/**
 * @brief 消去(リストから自分を消去する)
 * @param[in] (なし)
 * @return    (なし)
 */
void Distance::IsRemove()
{
	auto is_it = _c_distance_list.begin();
	while (is_it != _c_distance_list.end()) {
		if ((*is_it) != this) {
			is_it++;}
		else {
			//自分自身をリストから削除する。
			is_it = _c_distance_list.erase(is_it);
			return;
		}
	}
}

/**
 * @brief タグ検索
 * @param[in] (_tag) 検索したいタグ
 * @return    (flag) 見つかったらTRUEを返す 
 */
bool Distance::TagSerch(std::string _tag)
{
	bool flag = false;
	for (auto&& h : _c_distance_list) {
		if (h->_tags == _tag) { flag = true; };
	}
	return flag;
}

/**
 * @brief 厳選タグだけを配列に登録する
 * @param[in] (_tag) 厳選したいタグ
 * @return    (_my_oneself_information) 厳選した配列を返す
 */
pair<std::vector<float>, std::vector<Distance*>> Distance::RegistrationOnlyMe(std::string _tags)
{
	std::vector<Distance*> _my_oneself_information;
	for (auto&& f_my_oneself_information : _c_distance_list)
	{
		//指定されていないタグ登録しない
		if (f_my_oneself_information->_tags != _tags)               continue;
		//自分自身も静的配列に入っているので判定しない
		if (f_my_oneself_information->OneselfInformation() == this) continue;

		//指定したタグのみを登録する
		_my_oneself_information.push_back(f_my_oneself_information->OneselfInformation());
	}

	return { DistanceCalculatingArray(_my_oneself_information), _my_oneself_information };
}

/**
 * @brief 厳選タグだけとの距離を計算する
 * @param[in] (cdistance) 厳選したいタグの配列
 * @return    (_after_distance) 厳選したタグとの距離を計算した配列
 */
std::vector<float> Distance::DistanceCalculatingArray(std::vector<Distance*> cdistance)
{
	std::vector<float> _after_distance;
	if (cdistance.size() != 0) {
		for (auto&& fcdistance : cdistance) 
		{
			float other_distance = Vector3_Distance(fcdistance->transform.position, this->transform.position);

			_after_distance.push_back(other_distance);
		}
	}
	return std::vector<float>(_after_distance);
}

/**
 * @brief タグの中で最も小さい距離を計算する
 * @param[in] (_tag) 欲しいタグ
 * @return    (_min_distance) 最小の距離
 */
float Distance::TagMiddleMiniMum(std::string _tag)
{
	//指定されたタグとの距離が格納されている配列
	std::vector<float> _allocated_array;
	_allocated_array = RegistrationOnlyMe(_tag).first;

	float _min_distance = FLT_MAX;

	//配列の中での最小値
	_min_distance = *std::min_element(_allocated_array.begin(), _allocated_array.end(), [](float a, float b)->float {return a < b; });

	return (float)_min_distance;

}

/**
 * @brief タグの中で最も小さい座標を計算する
 * @param[in] (_tag) 欲しいタグ
 * @return    (_min_distance) 最小の座標
 */
Vector3 Distance::TagMiddleNearToPlayerPos(std::string _tag)
{
	std::vector<float> _allocated_array;

	_allocated_array                   = RegistrationOnlyMe(_tag).first;
	std::vector<Distance*> _distance = RegistrationOnlyMe(_tag).second;

	if (_allocated_array.size() == 0) return Vector3(0.0f, 0.0f, 0.0f);

	auto&& min_num   = std::min_element(_allocated_array.begin(), _allocated_array.end(), [](int a, int b) {return a > b;});
	int min_position = std::distance   (_allocated_array.begin(), min_num);

    return  _distance[min_position]->transform.position;
}
