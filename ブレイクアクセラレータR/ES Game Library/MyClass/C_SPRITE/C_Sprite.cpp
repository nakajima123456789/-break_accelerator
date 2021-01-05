#include "C_Sprite.h"

/**
 * @file   Sprite.cpp
 * @brief  Sprite�N���X�\�[�X�t�@�C��
 * @author �����D��N
 * @date   2020/10/1
 */
SpriteManager::SpriteManager()
{
	_sprite.         resize(DRAW_TYPE::TYPE_MAX);
	_sprite_position.resize(DRAW_TYPE::TYPE_MAX);
}
/**
  * @brief �摜���쐬����()
  * @param[in] (size)�@�摜�T�C�Y
  * @param[in] (color) �F
  * @param[in] (position) ���W
  * @return    �X���b�g�ԍ�
  */
int SpriteManager::CreateSprite(Vector2 size, Color color, Vector3 position)
{
	SPRITE sprite = GraphicsDevice.CreateSprite((UINT)size.x, (UINT)size.y, PixelFormat_RGBX8888);
	sprite->ColorFill(nullptr, color);

	this->_sprite         [DRAW_TYPE::ALPHA].push_back(sprite);
	this->_sprite_position[DRAW_TYPE::ALPHA].push_back(position);

	this->_sprite_alpha.push_back(0.0f);

	return (this->_sprite [DRAW_TYPE::ALPHA].size() - 1);
}
/**
 * @brief �摜�̓ǂݍ���()
 * @param[in] (file_name)�@�摜�̖��O
 * @param[in] (position)�@ �摜�̍��W
 * @return     �X���b�g�ԍ�
 */
int SpriteManager::CreateSpriteFromFile(LPCTSTR file_name, Vector3 position)
{
	SPRITE sprite = GraphicsDevice.CreateSpriteFromFile(file_name);
	IDirect3DTexture9* texture = *sprite;

	ASSERT(texture != nullptr && "�摜��������Ȃ�!");

	this->_sprite         [DRAW_TYPE::NOMAL].push_back(sprite);
	this->_sprite_position[DRAW_TYPE::NOMAL].push_back(position);

	return (this->_sprite [DRAW_TYPE::NOMAL].size() - 1);
}

int SpriteManager::CreateSpriteFromFileRect(LPCTSTR file_name, Vector3 position)
{
	SPRITE sprite = GraphicsDevice.CreateSpriteFromFile(file_name);
	IDirect3DTexture9* texture = *sprite;

	ASSERT(texture != nullptr && "�摜��������Ȃ�!");

	this->_sprite         [DRAW_TYPE::RECTWH].push_back(sprite);
	this->_sprite_position[DRAW_TYPE::RECTWH].push_back(position);

	this->_sprite_rectwh.push_back(RectWH(0, 0, 0, 0));

	return (this->_sprite[DRAW_TYPE::RECTWH].size() - 1);
}

int SpriteManager::CreateSpriteFromFileAlpha(LPCTSTR file_name, Vector3 position)
{
	SPRITE sprite = GraphicsDevice.CreateSpriteFromFile(file_name);
	IDirect3DTexture9* texture = *sprite;

	ASSERT(texture != nullptr && "�摜��������Ȃ�!");

	this->_sprite[DRAW_TYPE::ALPHA].push_back(sprite);
	this->_sprite_position[DRAW_TYPE::ALPHA].push_back(position);

	this->_sprite_alpha.push_back(0);

	return (this->_sprite[DRAW_TYPE::ALPHA].size() - 1);
}

/**
 * @brief �摜�s�����x���グ��
 * @param[in] (slot)�@ �X���b�g�ԍ�
 * @return  �s�����x���ő�l�ɂȂ�����TRUE
 */
bool SpriteManager::BlackOutTrigger(int slot)
{
	ASSERT(slot <= _sprite.size() && "�X���b�g�ԍ����݂��܂���B");
	this->_sprite_alpha[slot] += 0.05f;

	if (this->_sprite_alpha[slot] >= 1.0f){
		this->_sprite_alpha[slot]  = 1.0f;
		return true;
	}
	return false;
}

/**
 *@brief �摜�̕`��@�`��͈͎w��</brief>
 */
void SpriteManager::DrawSprite()
{
	for (int i = 0; i < _sprite.size(); i++)
	{
		for (int j = 0; j < _sprite[i].size(); j++)
		{
			switch (i)
			{
			case SpriteManager::NOMAL:
				SpriteBatch.Draw(*this->_sprite[i][j], this->_sprite_position[i][j]);
				break;
			case SpriteManager::RECTWH:
				SpriteBatch.Draw(*this->_sprite[i][j], this->_sprite_position[i][j], this->_sprite_rectwh[j]);
				break;
			case SpriteManager::ALPHA:
				SpriteBatch.Draw(*this->_sprite[i][j], this->_sprite_position[i][j], this->_sprite_alpha[j]);
				break;
			}
		}
	}
};


