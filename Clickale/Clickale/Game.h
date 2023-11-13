#pragma once
#include "stdafx.h"
#include "PlayerCrosshair.h"
#include "Enemy.h"

using namespace sf;
using namespace std;

class Game {
	RenderWindow* _window;
	Texture _backgroundTexture;
	Sprite _backgroundSprite;
	PlayerCrosshair* _playerCrosshair;	
	Enemy* _enemys;
	int _enemysAmount;
	int _points;
	Text _pointsText;
	Text _winText;
	Font _font;
	void SetBackground();
	void UpdatePoints();
	void Shoot();

public:
	Game();
	void Loop();
	void ProcessEvents();
	void Update();
	void Draw();
	void SetUI();
	~Game();

};