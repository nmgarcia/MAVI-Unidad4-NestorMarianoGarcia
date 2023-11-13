#pragma once
#include "stdafx.h"

using namespace sf;
using namespace std;

class PlayerCrosshair {
	Texture _crossTexture;

public:
	Sprite _crossSprite;
	PlayerCrosshair();
	void Draw(RenderWindow* window);
	void SetPosition(float x, float y);
	Vector2f GetPosition();
};