#pragma once
#include "../../ESGLib.h"
#include "../SharedMethod/SharedMethod.h"

class IUiDataBase : public SharedMethod
{
public:
	IUiDataBase() {};
	virtual ~IUiDataBase() {};

	void ResetIUiDataBase(){
		item_size = 0;
	}

	static IUiDataBase& GetInstance()
	{
		static IUiDataBase instance;
		return instance;
	};

	void  SetItemSize(int itemsize) { 
		item_size += itemsize; 
		item_size  = this->clamp(item_size, 1, 9);
	};
	int   GetItemSize()       const { return item_size;     };

	void  SetTimerSize(int itemsize) { timer = itemsize; };
	int   GetTimerSize()       const  { return timer; };

private:

	int item_size;
	int timer;

	IUiDataBase(const IUiDataBase&)    = delete;
	void operator=(const IUiDataBase&) = delete;
};  
#define UiDataBase IUiDataBase::GetInstance()