#include "Enemy.h"
#include "stdafx.h"


Enemy::Enemy() {
	_enemyTexture.loadFromFile("et.png");
	_enemySprite.setTexture(_enemyTexture);
	_enemySprite.setScale(0.07f,0.07f);
	_isAlive = true;
	_isVisible = false;
	_visibleTime = 2.0f;
	_invisibleTime = 1.0f;
}

Vector2f Enemy::RandomPosition(int x, int y)
{
	Vector2f random((float)(rand() % x), (float)(rand() % y));
	return random;
}


bool Enemy::IsAlive() {
	return _isAlive;
}

bool Enemy::IsActive() {
	return _isAlive && _isVisible;
}

bool Enemy::CheckCollision(float x, float y) {
	FloatRect bounds = _enemySprite.getLocalBounds();
	bool check = bounds.contains(x, y);
	return check;
}

void Enemy::Kill()
{
	_isVisible = false;
	_isAlive = false;
}

void Enemy::Draw(RenderWindow* window) {
	window->draw(_enemySprite);
}

void Enemy::Update(RenderWindow* window) {
	if (!_isAlive) {
		return;
	}

	if (!IsActive()) {
		//Probability to set active
		if (_clock.getElapsedTime().asSeconds() > _visibleTime) {
			_clock.restart();
			if (rand() % 100 < 50) {
				_isVisible = true;
				FloatRect max = _enemySprite.getGlobalBounds();
				_enemySprite.setPosition(RandomPosition(window->getSize().x - (max.width/2), window->getSize().y - (max.height / 2)));
			}
		}
	}
	else {
		if (_clock.getElapsedTime().asSeconds() > _visibleTime) {
			_isVisible = false;
			_clock.restart();
		}
	}
	
}
