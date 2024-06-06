#include <SFML/Graphics.hpp>

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "GAME RPG HOWAK");
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Red);

    //--------------------------------------UPDATE--------------------------------------------------------//
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    //---------------------------------------------UPDATE--------------------------------------------------//

    //-------------------DRAW SECTION-------------------------------------------------------------------//
        
        window.clear(sf::Color::Black);
        window.draw(shape);
        // end the current frame
        window.display();
    //-------------------DRAW SECTION-------------------------------------------------------------------//

    }

    return 0;
}