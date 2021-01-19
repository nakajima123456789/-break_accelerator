#pragma once

/**
 * @file   C_STATE.cpp
 * @brief  State�N���X�\�[�X�t�@�C��
 * @author �����D��N
 * @date   2020/10/1
 */

class State {
private:
   //�o�߃t���[��
   int time = 0;
public:
   virtual void Update() {}; 

  void     AddTime() { time++; };      //�t���[���ǉ�
  int      GetTime() { return time; }; //���݂̌o�߃t���[���擾

  bool ChangeExitState(){AddTime(); 
                  return GetTime() >= ExitTime() ? true : false;
  }

  virtual  int  ExitTime() { return 0; };
};
//�X�e�[�g�Ǘ��N���X
class StateProcessor {
private:
   State* _state = nullptr; //���݂̏��
public:
   StateProcessor::StateProcessor() : _state(nullptr) {
   }
   StateProcessor::~StateProcessor() {	delete _state; }
   void StateProcessor::Update()
   {
	_state->AddTime();
	//�|�����[�t�B�Y���ɂ��A���S���Y���̕ω�
	_state->Update();
   }

   void  StateProcessor::ChangeState(State* state) {
	   //���݂̃A�h���X�����
	delete _state;
	   //�V���ȃA�h���X���擾
	_state = state;
   }

};
