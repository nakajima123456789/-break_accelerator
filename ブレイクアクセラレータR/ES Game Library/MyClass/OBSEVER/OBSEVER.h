#pragma once
#include "../../ESGLib.h"

// �Փ˔��� �ϑ��� �C���^�[�t�F�[�X�i �ϑ� �� �� ���ۉ��j 
class OBSERVERLISTENER
{
public:
	// ���z �f�X�g���N�^
	virtual ~OBSERVERLISTENER() {}
	// �Փ˔��肵��
	virtual void OnCollisionDamage() = 0;
	virtual void OnCollisionClear() = 0;
	virtual void OnCollisionGage() = 0;
	virtual void OnCollisionGate() = 0;

};

// �Փ˔��� �N���X�i �ϑ� �� �� �ʒm ���� ���j
class OBSERVER
{
public:
	// �ϑ��҂̓o�^ 
	void addListener(OBSERVERLISTENER* listener);
	void removeListener(OBSERVERLISTENER* listener);

	// �Փ˔��肵��
	void IsCollisionDamage();

	void IsCollisionClear();
	void IsCollisionGage();
	void IsCollisionGate();


private:
	// �ϑ��҂ɒʒm 

	static std::list<OBSERVERLISTENER*> listeners_;
};