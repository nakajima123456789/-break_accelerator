#include "C_TITLE.h"
#include "../SCENEMANAGER/SceneManager.h"


void C_TITLE::Initialize()
{

}

void C_TITLE::Update()
{
	if (Input.GetKeybordInputDown(Keys_Enter)){SceneManager::ChangeScene(SceneManager::MAIN);}
}

void C_TITLE::Draw2D()
{

}
