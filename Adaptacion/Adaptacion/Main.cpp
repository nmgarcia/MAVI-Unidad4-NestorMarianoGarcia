//////Bibliotecas//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

Texture texture;
Sprite sprite;

///Punto de entrada a la aplicación///
int main() {
	
	//Creamos la ventana
	RenderWindow App(VideoMode(800, 600, 32), "Adaptacion");
	App.setFramerateLimit(60);
	// Loop principal
	while (App.isOpen())
	{
		Event evt;
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
				/////Si se cerro la ventana//////
				case Event::Closed:
					App.close();
					break;

				case Event::Resized:
					// Limitar el tamaño de la ventana
					Vector2u newSize = App.getSize();
					newSize.x = max(100u, min(newSize.x, 1000u));
					newSize.y = max(100u, min(newSize.y, 1000u));
					App.setSize(newSize);
					break;
			}
		}

		// Limpiamos la ventana
		App.clear();
		//Dibujamos la escena
		//App.draw(sprite);
		// Mostramos la ventana
		App.display();
	}
	return 0;
}