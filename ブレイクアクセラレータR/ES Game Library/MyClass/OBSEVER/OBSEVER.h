#pragma once
#include "../../ESGLib.h"
#include "../../EnumManager.h"

// �Փ˔��� �ϑ��� �C���^�[�t�F�[�X�i �ϑ� �� �� ���ۉ��j 
class OBSERVERLISTENER
{
public:
	// ���z �f�X�g���N�^
	virtual ~OBSERVERLISTENER() {}
	// �Փ˔��肵��
	virtual void OnCollisionDamage()    {};
	virtual void OnCollisionClear()     {};
	virtual void OnCollisionEffekseer(PLAYER::PLAYEREFFEKSEERTYPE player_effekseer_type) {};
};

// �Փ˔��� �N���X�i �ϑ� �� �� �ʒm ���� ���j
class OBSERVER
{
public:
	// �ϑ��҂̓o�^ 
	void addListener   (OBSERVERLISTENER* listener);
	void removeListener(OBSERVERLISTENER* listener);

	// �Փ˔��肵��
	void IsCollisionDamage();
	void IsCollisionClear();
	void IsCollisionEffekseer(PLAYER::PLAYEREFFEKSEERTYPE player_effekseer_type);
private:
	// �ϑ��҂ɒʒm 

	static std::list<OBSERVERLISTENER*> listeners_;
};