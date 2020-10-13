#pragma once

//�w�b�_�[�t�@�C���ǉ�
#include "../../ESGLib.h"
#include "../C_OBJECT/Object.h"

//�A�C�e���w�b�_�[�t�@�C���ǉ�
#include "../C_OBSTACLE/C_Obstacle.h"

class ObstacleFactory
{
public:
	 ObstacleFactory() {};
	~ObstacleFactory() {};

	/**
	 *  @brief object�𐶐����A���̃C���X�^���X��Ԃ��֐�
	 */
	Object* Create(std::string _type, Vector3 _position);

	/**
	 *  @brief Product���쐬���鏃�����z�֐�
	 *  @param type Product�̎��
	 *  @param name Product�̏��L�҂̖��O
	 */
	virtual Object* CreateProduct(std::string _type, Vector3 _position) = 0;
private:

};

class ObstacleStationeryFactory : public ObstacleFactory
{
public:
	/**
	 * @brief Product���쐬����֐�
	 */
	Object* CreateProduct(std::string _type, Vector3 _position) override;
};
