#pragma once
#include "../../../ESGLib.h"
#include "../../MngInput/MngInput.h"

class BaseScene {
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw3D() = 0;
	virtual void Draw2D() = 0;
	virtual void DrawAlpha3D() = 0;

	virtual void DrawEnd() {};

	BaseScene() {};
	virtual ~BaseScene()
	{
		MediaManager.  ReleaseAllMedia();
		GraphicsDevice.ReleaseAllRenderTargets();
		GraphicsDevice.ReleaseAllStateBlocks();
		GraphicsDevice.ReleaseAllFonts();
		GraphicsDevice.ReleaseAllSprites();
		GraphicsDevice.ReleaseAllVertexBuffers();
		GraphicsDevice.ReleaseAllEffects();
		GraphicsDevice.ReleaseAllModels();
		GraphicsDevice.ReleaseAllAnimationModels();
		SoundDevice.ReleaseAllMusics();
		SoundDevice.ReleaseAllSounds();
	};
};
