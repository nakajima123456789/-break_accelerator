#include "C_TITLE.h"
#include "../SCENEMANAGER/SceneManager.h"
#include "../../C_INPUT/C_INPUT.h"
#include <algorithm>


void C_TITLE::Initialize()
{

}

void C_TITLE::Update()
{
	if (Input.GetKeyInputDown(Keys_Enter)){SceneManager::ChangeScene(SceneManager::MAIN);}
}

void C_TITLE::Draw2D()
{

}
