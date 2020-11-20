#include "../OBSTACLEBASE/ObstacleBase.h"
#include "../OBSEVER/OBSEVER.h"

class CItemObstacle : public ObstacleBase
{
public:
	CItemObstacle(std::vector<Vector3> _obstacle_pos);
	virtual ~CItemObstacle() {};

	inline virtual void Init()        override;
	inline virtual void Update()      override;
	inline virtual void Draw3D()      override;

private:

	OBSERVER obsever;

};