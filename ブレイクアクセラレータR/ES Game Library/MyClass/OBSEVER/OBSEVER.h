#pragma once
#include "../../ESGLib.h"

// �Փ˔��� �ϑ��� �C���^�[�t�F�[�X�i �ϑ� �� �� ���ۉ��j 
class OBSERVERLISTENER
{
public:
	// ���z �f�X�g���N�^
	virtual ~OBSERVERLISTENER() {}
	// �Փ˔��肵��
	virtual void OnCollision() = 0;
};

// �Փ˔��� �N���X�i �ϑ� �� �� �ʒm ���� ���j
class OBSERVER
{
public:
	// �ϑ��҂̓o�^ 
	void addListener(OBSERVERLISTENER* listener);
	void removeListener(OBSERVERLISTENER* listener);

	// �Փ˔��肵��
	void IsCollision();

private:
	// �ϑ��҂ɒʒm 
	void OnCollisionNotify();

	static std::list<OBSERVERLISTENER*> listeners_;
};