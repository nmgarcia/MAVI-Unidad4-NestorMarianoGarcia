#include "PlayerCrosshair.h"
#include "stdafx.h"

PlayerCrosshair::PlayerCrosshair(){
	_crossTexture.loadFromFile("crosshair.png");
	_crossSprite.setTexture(_crossTexture);
	Vector2u size = _crossTexture.getSize();
	_crossSprite.setOrigin(size.x/2.0f, size.y / 2.0f);
}

void PlayerCrosshair::Draw(RenderWindow* window) {
	window->draw(_crossSprite);
}

void PlayerCrosshair::SetPosition(float x, float y) {
	_crossSprite.setPosition(x,y);
}

Vector2f PlayerCrosshair::GetPosition()
{
	return (Vector2f)Mouse::getPosition();
}
