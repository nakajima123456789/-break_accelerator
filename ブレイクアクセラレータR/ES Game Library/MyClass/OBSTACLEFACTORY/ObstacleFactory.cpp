#include "ObstacleFactory.h"


Object* ObstacleFactory::Create(std::string _type, Vector3 _position)
{
	Object* object = CreateProduct(_type, _position);
	return object;
}

Object* ObstacleStationeryFactory::CreateProduct(std::string _type, Vector3 _position)
{
	//if (_type == "�Ǐ�Q��") { return new CObstacle(_position); }
	//ASSERT(FALSE && !"�A�C�e���̖��O���Ⴄ!");
	return nullptr;
}