#include "CBrockObstacle.h"

#include "../C_CAMERA/C_CAMERA.h"

CBrockObstacle::CBrockObstacle(std::vector<Vector3> _obstacle_pos)
{
	obstacle_pos = _obstacle_pos;
}

void CBrockObstacle::Init()
{
	this->obstacle_model = GraphicsDevice.CreateModelFromFile(_T("model3D//‰ü’ù”Å_//hako_P.X"));

	this->obstacle_model->SetMaterial(this->SetMaterial(Color(1.f, 1.f, 1.f)));

	IsHitObjectsInit("Item_Hitbox");

	shader = GraphicsDevice.CreateEffectFromFile(_T("FX/ShaderTest.hlsl"));
    SPRITE texture = GraphicsDevice.CreateSpriteFromFile(_T("model3D//‰ü’ù”Å_//hako_P.png"));
	shader->SetTexture("modelTex", *texture);

	SPRITE texture1 = GraphicsDevice.CreateSpriteFromFile(_T("model3D//‰ü’ù”Å_//hako_P.png"));
	shader->SetTexture("modelTex1", *texture1);
}

void CBrockObstacle::Update()
{


	
}

void CBrockObstacle::Draw3D()
{
	
}

void CBrockObstacle::DrawAlpha3D()
{
	auto&& obstacle_it = this->obstacle_pos.begin();
	while (obstacle_it != this->obstacle_pos.end()) {

		this->transform.position = *obstacle_it;

		if (DistanceTrigger(90.0f))
		{
			this->obstacle_model->SetPosition(this->transform.position);
			this->obstacle_model->SetRotation(this->transform.rotation);
			this->obstacle_model->SetScale(this->transform.scale);

			Matrix world = obstacle_model->GetWorldMatrix();
			shader->SetParameter("wvp", world * CCamera_::camera.GetViewProjectionMatrix());

			GraphicsDevice.BeginAlphaBlend();
			GraphicsDevice.SetRenderState(CullMode_None);
			this->obstacle_model->Draw(shader);
			GraphicsDevice.SetRenderState(CullMode_CullCounterClockwiseFace);
			GraphicsDevice.EndAlphaBlend();

		}

		if (RemoveModelDistance(-20))
		{
			obstacle_it = this->obstacle_pos.erase(obstacle_it);
			continue;
		}

		if (this->CollsionTrigger())
		{
			observer.IsCollisionDamage();
		}

		obstacle_it++;
	}
}
