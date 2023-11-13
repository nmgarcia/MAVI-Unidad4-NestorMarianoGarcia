//////Bibliotecas//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;

Texture texture;
Sprite sprite;

///Punto de entrada a la aplicación///
int main() {
	Event evt;
	texture.loadFromFile("crosshair.png");
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);

	//Creamos la ventana
	RenderWindow App(VideoMode(800, 600, 32), "Crosshair");
	sprite.setPosition(App.getSize().x / 2.0f, App.getSize().y / 2.0f);
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
		}
		// Limpiamos la ventana
		App.clear();
		//Dibujamos la escena
		App.draw(sprite);
		// Mostramos la ventana
		App.display();
	}
	return 0;
}