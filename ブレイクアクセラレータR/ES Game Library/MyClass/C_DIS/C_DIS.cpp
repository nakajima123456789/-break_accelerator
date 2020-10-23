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
  * @detail �ڍׂȐ����@������ꂽ�Ƃ��ɌĂяo�������̏������X�g����폜����B
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
 * @param (std::string _tag) �����̐����@�C���X�^���X���̃^�O���w�肷��
 * @detail �ڍׂȐ����@�^�O�o�^�@"default"�ȊO
 */
void CDis::IsTagSet(std::string _tag)
{ 
	ASSERT(_tag != "default" && "default�ȊO�ɂ��Ă��������B");
	tag = _tag;
};

/**
 * @fn
 * @param (Vector3 _pos) �����̐����@�C���X�^���X���̃��f���̍��W
 * @detail �ڍׂȐ��� ���W�̓o�^
 */
void CDis::IsPosition(Vector3 _pos){pos = _pos;}

/**
 * @fn
 * @param (std::string _tag) �����̐����@�^�O�o�^
 * @return �߂�l�̐����@�w�肳�ꂽ�^�O���������TRUE�@�����łȂ����FALSE
 * @detail �ڍׂȐ����@�@�^�O�����֐�
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
 * @param (std::string _tag) �����̐����@�~�����^�O�̍ŏ��������擾����B
 * @return �߂�l�̐����@�v�Z�����ŏ�������Ԃ�
 * @detail �ڍׂȐ����@�@���܂œo�^���Ă����^�O�̒��ōŏ��̒l���擾�ł���֐�
 */
float CDis::GetTagDistance(std::string _tag)
{
	ASSERT(TagSerch(_tag) && "tag�����݂��Ă��Ȃ�!");

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

