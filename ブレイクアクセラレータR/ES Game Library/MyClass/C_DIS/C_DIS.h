#pragma once
//------------------------------------------------------------------------------
//	�C���N���[�h�t�@�C��
//------------------------------------------------------------------------------
#include "../../ESGLib.h"
#include <vector>

//------------------------------------------------------------------------------
//	���̊֐��͂Q�̍��W�̋����𒲂׃^�O�̒��ōŒZ�̒l���擾�o���܂��B
//------------------------------------------------------------------------------
class CDis
{
private:
	//�������g��Ԃ�
	CDis* GetThisDis(){ return this; };

	static std::list<CDis*> c_dis_list;

	std::string tag;
	Vector3     pos;
public:

	CDis() {};

	virtual ~CDis() { IsRemove(); };

	void  Init();
    //�������g�����X�g����폜����B
	void  IsRemove();
	
	/*�^�O�̒��ōł��������l���擾*/
	float GetTagDistance(std::string _tag);

	/*�^�O���w��*/
	void IsTagSet(std::string _tag);

	/*�C���X�^���X���̃��f�����W��o�^����*/
	void IsPosition(Vector3 _pos);

	/*�w�肵���^�O�����݂��邩���ׂ�֐�*/
	bool TagSerch(std::string _tag);
};