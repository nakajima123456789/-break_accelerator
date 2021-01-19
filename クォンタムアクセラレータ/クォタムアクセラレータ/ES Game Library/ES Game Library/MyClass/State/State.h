#pragma once

/**
 * @file   C_STATE.cpp
 * @brief  Stateクラスソースファイル
 * @author 中島颯一朗
 * @date   2020/10/1
 */

class State {
private:
   //経過フレーム
   int time = 0;
public:
   virtual void Update() {}; 

  void     AddTime() { time++; };      //フレーム追加
  int      GetTime() { return time; }; //現在の経過フレーム取得

  bool ChangeExitState(){AddTime(); 
                  return GetTime() >= ExitTime() ? true : false;
  }

  virtual  int  ExitTime() { return 0; };
};
//ステート管理クラス
class StateProcessor {
private:
   State* _state = nullptr; //現在の状態
public:
   StateProcessor::StateProcessor() : _state(nullptr) {
   }
   StateProcessor::~StateProcessor() {	delete _state; }
   void StateProcessor::Update()
   {
	_state->AddTime();
	//ポリモーフィズムによりアルゴリズムの変化
	_state->Update();
   }

   void  StateProcessor::ChangeState(State* state) {
	   //現在のアドレスを解放
	delete _state;
	   //新たなアドレスを取得
	_state = state;
   }

};
