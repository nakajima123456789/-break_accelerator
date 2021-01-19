#pragma once
#include "../Object/Object.h"

#include "../SharedMethod/SharedMethod.h"
#include "../UiDataBase/UiDataBase.h"

class Time : public Object, SharedMethod
{
public:
	virtual void Init()        override;
	virtual void Update()      override;
	virtual void Draw3D()      override { return; };

	virtual void DrawAlpha3D() override { return; };
	virtual void Draw2D()      override;

	bool IsTimer ()  const { return timer <= 0; };
	void AddTimer(int num) { timer += num; };

private:
	FONT  font ;
	int   timer;
	const int MAX_TIME = 30;
};
