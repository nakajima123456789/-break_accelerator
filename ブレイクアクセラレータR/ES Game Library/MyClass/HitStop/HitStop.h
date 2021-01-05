
#pragma once
#include "../C_OBJECT/Object.h"

//�q�b�g�X�g�b�v
class HitStop : public Object {
private:
   //�q�b�g�X�g�b�v�c�莞��
   int _count = 0;
   //�~�߂�Ώ�
   Object* p_taget;
public:
   //������
   void HitStop::Init();
   //�X�V
   void HitStop::Update();
   //�q�b�g�X�g�b�v�l�ݒ�
   void HitStop::SetStopCount(int damage);
   //�q�b�g�X�g�b�v����
   bool HitStop::IsStop();
   //�Ώێw��
   void HitStop::SetTaget(Object* taget) 
   {
	p_taget = taget;
   };
};