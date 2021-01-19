#pragma once
#include "../../ESGLib.h"

// �Փ˔��� �ϑ��� �C���^�[�t�F�[�X�i �ϑ� �� �� ���ۉ��j 
class Observerlistener
{
public:
	// ���z �f�X�g���N�^
	virtual ~Observerlistener() {}
	// �Փ˔��肵��
	virtual void OnCollision(int collsionType)     = 0;
};

// �Փ˔��� �N���X�i �ϑ� �� �� �ʒm ���� ���j
class Observer
{
public:
	// �ϑ��҂̓o�^ 
	void addListener   (Observerlistener* listener);
	void removeListener(Observerlistener* listener);

	// �Փ˔��肵��
	void IsCollision(int collsionType);

private:

	static std::list<Observerlistener*> listeners_;
};