#include <SFML/Graphics.hpp>

using namespace sf;
int main() {
    
    ContextSettings settings;
    settings.antialiasingLevel = 50;
    
    sf::RenderWindow window (sf::VideoMode(1074, 758), "Mila's Project");
    
    while (window.isOpen())
    {
        sf::Event event;
        
        // handle all events
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    
                    break;
            }
        }
        
        // Background color
        window.clear(Color(153, 204, 255, 0));
        
        // Background photo
        Texture texture;
        texture.loadFromFile("texture.jpeg", IntRect(0,0,320,320));
        Sprite sprite(texture);
        window.draw(sprite);
        
        // Circle photo
        Texture texture2;
        texture2.loadFromFile("math.jpg", IntRect(0, 0, 1074, 758));
        Sprite sprite2(texture2);
        sprite2.setOrigin(537.f, 329.f);
        sprite2.setColor(Color(255, 0, 127, 120));
        sprite2.rotate(-10.f);
        sprite2.move(500, 300);
        window.draw(sprite2);
        
        
        // Circle
        CircleShape circle(50.f);
        circle.setFillColor(Color(102, 255, 102, 70));
        circle.setOutlineThickness(20.f);
        circle.setOutlineColor(Color(255, 255, 255));
        circle.move(320 - 50, 240 - 50);
        window.draw(circle);
        
        // Square
        CircleShape square(60.f, 4);
        square.setPosition(320, 240);
        square.setFillColor(Color::Red);
        window.draw(square);
        
        // Convex
        ConvexShape convex;
        convex.setPointCount(5);
        convex.setPoint(0, Vector2f(0.f, 0.f));
        convex.setPoint(1, Vector2f(150.f, 10.f));
        convex.setPoint(2, Vector2f(120.f, 90.f));
        convex.setPoint(3, Vector2f(30.f, 100.f));
        convex.setPoint(4, Vector2f(5.f, 50.f));
        convex.setFillColor(Color::Black);
        convex.move(10, 150);
        window.draw(convex);
        
        // Rectangle
        RectangleShape rectangle(Vector2f(70.f, 100.f));
        rectangle.move(320, 50);
        rectangle.setFillColor(Color(255, 159, 54));
        rectangle.rotate(45.f);
        window.draw(rectangle);
        
        // Line
        Vertex line[] =
        {
            Vertex(Vector2f(390.f, 10.f)),  // x
            Vertex(Vector2f(20.f,20.f))    // y
        };
        line->color = Color::Red;
        window.draw(line, 2, Lines);
        
        // drawing all
        window.display();
    }
}
