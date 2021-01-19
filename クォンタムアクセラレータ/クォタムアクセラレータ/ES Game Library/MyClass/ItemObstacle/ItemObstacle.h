#include "../OBSTACLEBASE/ObstacleBase.h"

class ItemObstacle : public ObstacleBase
{
public:
	ItemObstacle() {};
	virtual ~ItemObstacle() {};

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override;

private:

};