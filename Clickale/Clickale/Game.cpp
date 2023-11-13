#include "stdafx.h"
#include "Game.h"
#include <iostream>

Game::Game() {
	_window = new RenderWindow(VideoMode(800, 600, 32), "Clickale");
	_window->setMouseCursorVisible(false);
	_enemysAmount = 5;
	_enemys = new Enemy[_enemysAmount];	
	_playerCrosshair = new PlayerCrosshair();	
	_points = 0;

	SetUI();	

	UpdatePoints();

	SetBackground();
}

void Game::Loop() {
	// Main Loop
	while (_window->isOpen())
	{
		ProcessEvents();
		Update();		
		Draw();		
	}
}

//Buffered
void Game::ProcessEvents() {
	Event evt;
	while (_window->pollEvent(evt)) {

		switch (evt.type)
		{
			case Event::Closed:
				_window->close();
				break;
			case Event::MouseButtonPressed:
				if (evt.mouseButton.button == Mouse::Button::Left) {
					Shoot();
				}
				break;
		}
	}

}

//Unbuffered
void Game::Update() {
	//Update crosshair position
	Vector2i mousePosition = Mouse::getPosition(*_window);
	_playerCrosshair->SetPosition(mousePosition.x,mousePosition.y);

	for (int i = 0; i < _enemysAmount; i++)
	{
		_enemys[i].Update(_window);
		
	}
}

void Game::Draw() {
	// Clear Window
	_window->clear();
	//Draw Scene
	_window->draw(_backgroundSprite);	

	for (int i = 0; i < _enemysAmount; i++) {
		if (_enemys[i].IsActive()) {
			_enemys[i].Draw(_window);
		}
	}
	
	_playerCrosshair->Draw(_window);

	if (_points < _enemysAmount) {
		_window->draw(_pointsText);
	}	
	else {
		_window->draw(_winText);
	}
	
	// Display Window
	_window->display();
	
}

void Game::SetBackground() {
	_backgroundTexture.loadFromFile("fondo.jpg");
	_backgroundSprite.setTexture(_backgroundTexture);
	float scaleX=_window->getSize().x / (float)_backgroundTexture.getSize().x;
	float scaleY= _window->getSize().y / (float)_backgroundTexture.getSize().y;

	_backgroundSprite.setScale(scaleX,scaleY);
}

void Game::UpdatePoints()
{
	_pointsText.setString("Pts: " + to_string(_points));
}

void Game::Shoot() {
	//Check collisions
	Vector2f crossHairPosition = _playerCrosshair->GetPosition();
	for (int i = 0; i < _enemysAmount; i++)
	{
		if (_enemys[i].IsActive()) {			
			if (_enemys[i].CheckCollision(crossHairPosition.x, crossHairPosition.y) ){
				cout << "i: " << i << " position: " << _enemys[i]._enemySprite.getPosition().x << " - " << _enemys[i]._enemySprite.getPosition().y << endl;
				_enemys[i].Kill();
				_points++;
				UpdatePoints();
				break;
			}

		}
	}
}

void Game::SetUI() {
	_font.loadFromFile("arial.ttf");
	_pointsText.setPosition(0.0f, 0.0f);
	_pointsText.setCharacterSize(50.0f);
	_pointsText.setFont(_font);

	_winText.setPosition(400.0f, 300.0f);
	_winText.setCharacterSize(50.0f);
	_winText.setFont(_font);
	_winText.setString("You\nwin!");
}

Game::~Game()
{
	delete _window;
	delete _playerCrosshair;
	//delete _enemys;
}