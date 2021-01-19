#pragma once
//------------------------------------------------------------------------------
//	�C���N���[�h�t�@�C��
//------------------------------------------------------------------------------
#include "../Object/Object.h"

class Distance : public Object
{
private:

	//�֐��錾

	//�������g��Ԃ�
	Distance* OneselfInformation() { return this; }

	pair<std::vector<float>, std::vector<Distance*>> RegistrationOnlyMe(std::string _tags);

         std::vector<float> DistanceCalculatingArray(std::vector<Distance*> cdistance);

	//�ϐ��錾

	static std::list<Distance*> _c_distance_list;

	std::string _tags;

public:

	Distance();
	virtual ~Distance() { IsRemove(); };

	//�폜
	void  IsRemove();
	void  Settags(std::string tag) { _tags = tag; };

	//�����擾
	float   TagMiddleMiniMum(std::string _tag);
	Vector3 TagMiddleNearToPlayerPos(std::string _tag);

	//����
	bool TagSerch(std::string _tag);

};