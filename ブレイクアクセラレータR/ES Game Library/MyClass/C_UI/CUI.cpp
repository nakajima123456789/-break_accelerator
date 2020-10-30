#include "CUI.h"

CUI::CUI()
{
	//���������X�g�ɓo�^
	observer.addListener(this);
	
}

CUI::~CUI()
{
	//���������X�g����폜
	observer.removeListener(this);
	
}

void CUI::Init()
{
	auto&& AddSprite = [this](LPCTSTR _filename) { sprite.push_back(GraphicsDevice.CreateSpriteFromFile(_filename));};
	
	auto&& AddSpritePos = [this](unsigned int id, Vector3 pos) {sprite_position[id].push_back(pos); };

	AddSprite(_T("UI/FW�Q�[�W/FW_base.png"));
	AddSprite(_T("UI/FW�Q�[�W/FW_base2.png"));
	

	sprite_position.resize(SPRITE_MAX);

	AddSpritePos(FW,   Vector3(320, 0, 0));
	AddSpritePos(FW2,  Vector3(320, 0, 0));
	
	
	FW_S = GraphicsDevice.CreateSpriteFromFile(_T("UI/FW�Q�[�W/FW_S.png"));
	
	fw_S = 0;
	
}

void CUI::Update()
{
	
	
	fw_S +=0.5f;

}

//PLAYER��ENEMY�Ƃ��Փ˂�����Ă΂��֐�
void CUI::OnCollision()
{
	fw_S  -= 20;
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
	SpriteBatch.Draw(*FW_S, Vector3(320.0f, 0.0f, 0.0f), Rect(0, 0, fw_S, 50), 1.f, Vector3_Zero, Vector3(0, 0, 0), 1);

}

double CUI::clamp(double x, double low, double high)
{
	ASSERT(low <= high && "�ŏ��l <= �ő�l");
	return min(max(x, low), high);
}
