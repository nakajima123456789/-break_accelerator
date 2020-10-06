#pragma once
//------------------------------------------------------------------------------
//	インクルードファイル
//------------------------------------------------------------------------------
#include "../../ESGLib.h"
#include <vector>

//------------------------------------------------------------------------------
//	この関数は２つの座標の距離を調べタグの中で最短の値を取得出来ます。
//------------------------------------------------------------------------------
class CDis
{
private:
	//自分自身を返す
	CDis* GetThisDis(){ return this; };

	static std::list<CDis*> c_dis_list;

	std::string tag;
	Vector3     pos;
public:

	CDis() {};

	virtual ~CDis() { IsRemove(); };

	void  Init();
    //自分自身をリストから削除する。
	void  IsRemove();
	
	/*タグの中で最も小さい値を取得*/
	float GetTagDistance(std::string _tag);

	/*タグを指定*/
	void IsTagSet(std::string _tag);

	/*インスタンス元のモデル座標を登録する*/
	void IsPosition(Vector3 _pos);

	/*指定したタグが存在するか調べる関数*/
	bool TagSerch(std::string _tag);
};