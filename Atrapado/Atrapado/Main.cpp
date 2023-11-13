//////Bibliotecas//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

Texture textureCuad,textureCircle;
Sprite sprite;
bool isCircle = false;
bool spacePressed = false;

void setSprite(Texture& t) {
	sprite.setTexture(t);
	sprite.setScale((float)50 / t.getSize().x, (float)50 / t.getSize().x);
}

///Punto de entrada a la aplicación///
int main() {
	
	//Creamos la ventana
	RenderWindow App(VideoMode(800, 600, 32), "Atrapado");
	textureCuad.loadFromFile("cuad_yellow.png");
	textureCircle.loadFromFile("rcircleg.png");
		
	setSprite(textureCuad);

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
			}
		}

		//Verificar movimiento si se presionan las flechas
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			sprite.move(-0.5, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			sprite.move(0.5, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			sprite.move(0, -0.5);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			sprite.move(0, 0.5);
		}

		//Verificar si se presiono la tecla espacio y asegurarse de que solo se presiona una vez
		if (Keyboard::isKeyPressed(Keyboard::Space) && !spacePressed) {
			if (isCircle) {
				setSprite(textureCuad);
			}
			else {
				setSprite(textureCircle);
			}
			
			isCircle = !isCircle;
			spacePressed = true;
		}

		if(evt.type == Event::KeyReleased && evt.key.code == Keyboard::Space && spacePressed) {
			spacePressed = false;  
		}
		
		//Chequeamos los limites de la pantalla
		FloatRect spriteBounds = sprite.getGlobalBounds();
		if (spriteBounds.left < 0) {
			sprite.setPosition(0, sprite.getPosition().y);
		}
		if (spriteBounds.top < 0) {
			sprite.setPosition(sprite.getPosition().x, 0);
		}
		if ((spriteBounds.left + spriteBounds.width) > App.getSize().x) {
			sprite.setPosition(App.getSize().x - spriteBounds.width, sprite.getPosition().y);
		}
		if ((spriteBounds.top + spriteBounds.height) > App.getSize().y ) {
			sprite.setPosition(sprite.getPosition().x, App.getSize().y - spriteBounds.height);
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