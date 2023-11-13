#pragma once
#include "stdafx.h"

using namespace sf;
using namespace std;

class Enemy
{
	Texture _enemyTexture;
	bool _isAlive;
	bool _isVisible;
	Clock _clock;
	float _visibleTime;
	float _invisibleTime;

	Vector2f RandomPosition(int x, int y);
public:
	Sprite _enemySprite;
	Enemy();
	bool IsAlive();
	bool IsActive();
	bool CheckCollision(float x, float y);
	void Kill();
	void Draw(RenderWindow* window);
	void Update(RenderWindow* window);
};

