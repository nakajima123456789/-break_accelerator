#pragma once

#include "../Object/Object.h"

class Stage : public Object
{
public:

	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override;

	virtual void DrawAlpha3D() override;
	virtual void Draw2D()      override;

private:

	void AddModelParametor(LPCTSTR _filename, int scene, Vector3 position);

	std::vector<MODEL> model;
	std::vector<std::vector<Vector3>> model_position;
	std::vector<int>                  model_scene;

protected:

};