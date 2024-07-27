#pragma once
#include "DemoApp.h"
#include "Script/Object/Wall.h"

class CameraController;

class IMap
	: public Script
{
public:
	// sprite
	SpriteRenderer2D*		mapSprite;
	Actor*					backGround;
	SpriteRenderer2D*		bgSprite;
	// camere
	Actor*					mainCamera;
	CameraController*		cameraController;
	// spawnPoint
	std::vector<Vector2>	spawnPoint;
	// wall
	std::vector<Actor*>     wallList;

	virtual void			Start();
	virtual void            Update();
	virtual void			OnDestroy() {}

	virtual void            SetSpawnPoint() {}
	void					AddWallObject(Vector2 _pos, Vector2 _size);
};

