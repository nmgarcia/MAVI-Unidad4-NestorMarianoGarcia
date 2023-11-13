//////Bibliotecas//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "main.h"
#include <vector>

using namespace sf;
using namespace std;

Texture texture;
Sprite sprite1,sprite2,sprite3,sprite4;
float height, width;
Vector2i screenSize;
Vector2f offset;
bool isDragging = false;
vector<Sprite> sprites;
int index = -1;


///Punto de entrada a la aplicación///
int main() {
	
	screenSize.x =800;
	screenSize.y =600;

	texture.loadFromFile("rcircle.png");
	sprite1.setTexture(texture);
	sprite2.setTexture(texture);
	sprite3.setTexture(texture);
	sprite4.setTexture(texture);

	height = (float)texture.getSize().y;
	width = (float)texture.getSize().x;

	sprite2.setPosition(screenSize.x - width, 0);
	sprite3.setPosition(0,screenSize.y-height);
	sprite4.setPosition(screenSize.x - width,screenSize.y - height);

	sprites.push_back(sprite1);
	sprites.push_back(sprite2);
	sprites.push_back(sprite3);
	sprites.push_back(sprite4);

	//Creamos la ventana
	RenderWindow App(VideoMode(800, 600, 32),"Sniper^4");
		
	Event evt;
	// Loop principal
	while (App.isOpen())
	{
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
				/////Si se cerro la ventana//////
				case Event::Closed:
					App.close();
					break;
			}
			
			if (Keyboard::isKeyPressed(Keyboard::Escape) == true)
				App.close();

			if (evt.type == Event::MouseButtonPressed && evt.mouseButton.button == Mouse::Left)
			{
				for (int i = 0; i < sprites.size(); i++)
				{
					if (sprites[i].getGlobalBounds().contains(evt.mouseButton.x, evt.mouseButton.y))
					{
						isDragging = true;
						index = i;

						offset = sprites[i].getPosition() - Vector2f(evt.mouseButton.x, evt.mouseButton.y);
					}
				}				
			}

			if (isDragging && evt.type == Event::MouseButtonReleased && evt.mouseButton.button == Mouse::Left)
			{
				isDragging = false;
				index = -1;
			}

			if (evt.type == Event::MouseMoved && isDragging && index != -1)
			{
				// Actualiza la posición del objeto mientras lo arrastras
				sprites[index].setPosition(evt.mouseMove.x + offset.x, evt.mouseMove.y + offset.y);
			}
		}
		
		// Limpiamos la ventana
		App.clear();
		//Dibujamos
		App.draw(sprites[0]);
		App.draw(sprites[1]);
		App.draw(sprites[2]);
		App.draw(sprites[3]);
		// Mostramos la ventana
		App.display();
	}
	return 0;
}