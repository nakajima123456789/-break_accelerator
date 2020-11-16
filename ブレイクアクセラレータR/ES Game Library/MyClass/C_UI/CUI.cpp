#include "CUI.h"

CUI::CUI()
{
	//自分をリストに登録
	observer.addListener(this);
}

CUI::~CUI()
{
	//自分をリストから削除
	observer.removeListener(this);
}

void CUI::Init()
{
	auto&& AddSprite = [this](LPCTSTR _filename) { sprite.push_back(GraphicsDevice.CreateSpriteFromFile(_filename));};
	
	auto&& AddSpritePos = [this](unsigned int id, Vector3 pos) {sprite_position[id].push_back(pos); };

	AddSprite(_T("UI/FWゲージ/FW_base.png"));
	AddSprite(_T("UI/FWゲージ/FW_base2.png"));
	

	sprite_position.resize(SPRITE_MAX);

	AddSpritePos(FW,   Vector3(320, 0, 0));
	AddSpritePos(FW2,  Vector3(320, 0, 0));
	
	
	FW_S = GraphicsDevice.CreateSpriteFromFile(_T("UI/FWゲージ/FW_S.png"));


	gia = GraphicsDevice.CreateSpriteFromFile(_T("UI/gear/タテギアゲージ2.png"));
	gia2 = GraphicsDevice.CreateSpriteFromFile(_T("UI/gear/タテギアゲージ4.png"));
	
	_hit_ef = GraphicsDevice.CreateSprite(1280, 720, PixelFormat_RGBX8888);
	_hit_ef->ColorFill(nullptr, Color(255, 0, 0));

	fw_S = 0;
	nobi = 100.0f;
	gage= Color(255,255, 255);
}

void CUI::Update()
{
	
	if (nobi <= 68) {
		gage = Color(0, 255,0);
	}
	if (nobi <= 37) {
		gage = Color(255, 255, 0);
	}
	
}

//PLAYERとENEMYとが衝突したら呼ばれる関数
void CUI::OnCollisionDamage()
{
	fw_S  += 20;
	

	_damage_collsion_flag = true;
}

void CUI::OnCollisionClear()
{
	fw_S  -= 10;
	nobi -= 16.0f;
}

void CUI::OnCollisionGage()
{
	nobi -= 32.0f;
	
}

void CUI::Draw2D()
{

	for (int y = 0; y < sprite_position.size(); y++)
	{
		for (int x = 0; x < sprite_position[y].size(); x++)
		{
			SpriteBatch.Draw(*sprite[y], sprite_position[y][x]);
		}
	}

	fw_S = clamp(fw_S, 0, 540);
	SpriteBatch.Draw(*FW_S, Vector3(320.0f, 0.0f, 0.0f), Rect(0, 0, fw_S, 50), 1.f, Vector3_Zero, Vector3(0, 0, 0),1);
	
	if (_damage_collsion_flag)
	{
		fiedout_alpha -= 0.05f;
		SpriteBatch.Draw(*_hit_ef, Vector3(0.0f, 0.0f, 0.0f), fiedout_alpha);
		if (fiedout_alpha <= 0.0f)
		{
			fiedout_alpha = 1.0f;
			_damage_collsion_flag = false;
		}
	}

	SpriteBatch.Draw(*gia2, Vector3(1000.0f, 0.0f, 0.0f), Rect(0, 0, 35, 132),Color(gage));
	SpriteBatch.Draw(*gia, Vector3(1000.0f, nobi, 0.0f), Rect(0, nobi, 35, 132), Color(gage));

}

double CUI::clamp(double x, double low, double high)
{
	ASSERT(low <= high && "最小値 <= 最大値");
	return min(max(x, low), high);
}
