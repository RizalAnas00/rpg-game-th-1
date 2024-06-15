#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Skeleton.h"

int main()
{
    //---------------------------------------------INITIALIZE---------------------------------------------//
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1080, 720), "GAME RPG HOWAK", sf::Style::Default,settings);
    
    Player player;
    player.Initialize();

    Skeleton skeleton;
    skeleton.Initialize();

    //---------------------------------------------INITIALIZE---------------------------------------------//

    //----------------------------------------------LOAD--------------------------------------------------//
   
    player.Load();

    skeleton.Load();
     
    //-------------------------------------------------LOAD------------------------------------------------//
    


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
        
        //METHOD CALLING
        skeleton.Update();
        player.Update(skeleton);

    //---------------------------------------------UPDATE--------------------------------------------------//

    //-------------------DRAW SECTION-------------------------------------------------------------------//

        window.clear(sf::Color::Black);

        skeleton.Draw(window);

        player.Draw(window);

        window.display();
    //-------------------DRAW SECTION-------------------------------------------------------------------//

    }

    return 0;
}