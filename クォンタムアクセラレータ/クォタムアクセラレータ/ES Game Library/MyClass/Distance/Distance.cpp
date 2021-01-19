#include "Distance.h"

std::list<Distance*> Distance::_c_distance_list = {};

/**
 * @file   C_DIS.cpp
 * @brief  CDistance_�N���X�\�[�X�t�@�C��
 * @author �����D��N
 * @date   2020/10/1
 */

Distance::Distance()
{
	//�������g�̓o�^
	_c_distance_list.push_back(this);
}

/**
 * @brief ����(���X�g���玩������������)
 * @param[in] (�Ȃ�)
 * @return    (�Ȃ�)
 */
void Distance::IsRemove()
{
	auto is_it = _c_distance_list.begin();
	while (is_it != _c_distance_list.end()) {
		if ((*is_it) != this) {
			is_it++;}
		else {
			//�������g�����X�g����폜����B
			is_it = _c_distance_list.erase(is_it);
			return;
		}
	}
}

/**
 * @brief �^�O����
 * @param[in] (_tag) �����������^�O
 * @return    (flag) ����������TRUE��Ԃ� 
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
 * @brief ���I�^�O������z��ɓo�^����
 * @param[in] (_tag) ���I�������^�O
 * @return    (_my_oneself_information) ���I�����z���Ԃ�
 */
pair<std::vector<float>, std::vector<Distance*>> Distance::RegistrationOnlyMe(std::string _tags)
{
	std::vector<Distance*> _my_oneself_information;
	for (auto&& f_my_oneself_information : _c_distance_list)
	{
		//�w�肳��Ă��Ȃ��^�O�o�^���Ȃ�
		if (f_my_oneself_information->_tags != _tags)               continue;
		//�������g���ÓI�z��ɓ����Ă���̂Ŕ��肵�Ȃ�
		if (f_my_oneself_information->OneselfInformation() == this) continue;

		//�w�肵���^�O�݂̂�o�^����
		_my_oneself_information.push_back(f_my_oneself_information->OneselfInformation());
	}

	return { DistanceCalculatingArray(_my_oneself_information), _my_oneself_information };
}

/**
 * @brief ���I�^�O�����Ƃ̋������v�Z����
 * @param[in] (cdistance) ���I�������^�O�̔z��
 * @return    (_after_distance) ���I�����^�O�Ƃ̋������v�Z�����z��
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
 * @brief �^�O�̒��ōł��������������v�Z����
 * @param[in] (_tag) �~�����^�O
 * @return    (_min_distance) �ŏ��̋���
 */
float Distance::TagMiddleMiniMum(std::string _tag)
{
	//�w�肳�ꂽ�^�O�Ƃ̋������i�[����Ă���z��
	std::vector<float> _allocated_array;
	_allocated_array = RegistrationOnlyMe(_tag).first;

	float _min_distance = FLT_MAX;

	//�z��̒��ł̍ŏ��l
	_min_distance = *std::min_element(_allocated_array.begin(), _allocated_array.end(), [](float a, float b)->float {return a < b; });

	return (float)_min_distance;

}

/**
 * @brief �^�O�̒��ōł����������W���v�Z����
 * @param[in] (_tag) �~�����^�O
 * @return    (_min_distance) �ŏ��̍��W
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
