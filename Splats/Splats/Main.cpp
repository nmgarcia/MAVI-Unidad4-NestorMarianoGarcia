//////Bibliotecas//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;
Sprite sprite;
string color;
Texture texture;

///Punto de entrada a la aplicación///
int main() {

	//Creamos la ventana
	RenderWindow App(VideoMode(800, 600, 32), "Splats");

	// Loop principal
	while (App.isOpen())
	{
		Event evt;
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
				case Event::Closed:
					App.close();
					break;

				case Event::MouseButtonPressed:
					if (evt.mouseButton.button == Mouse::Left)
						color = "rcircle.png";
					if(evt.mouseButton.button == Mouse::Right)
						color = "rcircleb.png";

					texture.loadFromFile(color);
					sprite.setTexture(texture);
					sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
					sprite.setPosition(evt.mouseButton.x, evt.mouseButton.y);										
					break;
			}
		}

		
		//Dibujamos la escena
		App.draw(sprite);
				
		// Mostramos la ventana
		App.display();
	}
	return 0;
}