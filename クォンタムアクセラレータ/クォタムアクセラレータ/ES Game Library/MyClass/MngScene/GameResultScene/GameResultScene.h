#pragma once
#include "../SCENEMANAGER/BaseScreen.h"

class GameResultScene : public BaseScene
{
public:

	GameResultScene() {};
	virtual ~GameResultScene() {};

	virtual void Initialize()  override;
	virtual void Update()      override;
	virtual void Draw3D()      override { return; };
	virtual void Draw2D()      override;
	virtual void DrawAlpha3D() override { return; };

private:
	std::vector<int>     ranking_sort;

	void RoadFileCsv   (char* file_name);
	void WritingFileCsv(char* file_name);

	enum RANKING {_1st,_2nd,_3rd, MAX};

	SPRITE  ranking_sprite[RANKING::MAX];
	int     ranking_score [RANKING::MAX];

	std::vector<SPRITE> sprite_list;
	void Add_Sprite(LPCTSTR _sprite_name);

	FONT font;
};