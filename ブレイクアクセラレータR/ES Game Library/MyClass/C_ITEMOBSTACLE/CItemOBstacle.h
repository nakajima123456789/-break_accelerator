#include "../OBSTACLEBASE/ObstacleBase.h"
#include "../OBSEVER/OBSEVER.h"

class CItemObstacle : public ObstacleBase
{
public:
	CItemObstacle() {};
	virtual ~CItemObstacle() {};

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override;

private:

	OBSERVER obsever;

};