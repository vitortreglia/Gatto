#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "Teste SFML");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        window.clear();
        window.display();
    }
}