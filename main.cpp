#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "Skeleton.h"

int main()
{
    //---------------------------------------------INITIALIZE---------------------------------------------//
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1080, 720), "GAME RPG HOWAK", sf::Style::Default,settings);
    window.setFramerateLimit(240);

    Player player;
    player.Initialize();

    Skeleton skeleton;
    skeleton.Initialize();

    sf::Clock clock;

    sf::Text FrameRateText;
    sf::Font font;

    //---------------------------------------------INITIALIZE---------------------------------------------//

    //----------------------------------------------LOAD--------------------------------------------------//
   
    if (font.loadFromFile("GameTrial/Assets/fonts/OldSansBlack.ttf"))
    {
        std::cout << "FONT LOADED" << std::endl;
        FrameRateText.setFont(font);
    }

    player.Load();

    skeleton.Load();
     
    //-------------------------------------------------LOAD------------------------------------------------//
    


    //--------------------------------------UPDATE--------------------------------------------------------//
    while (window.isOpen())
    {
        //clock----
        sf::Time deltaTimeTimer = clock.restart();
        double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0f;
        int rslt = 1000.0f / deltaTime;

        FrameRateText.setCharacterSize(14);

        // Update the FPS string
        std::string fpsString = "FPS : \n" + std::to_string(rslt);
        FrameRateText.setString(fpsString);


        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        //METHOD CALLING
        skeleton.Update(deltaTime);
        player.Update(deltaTime, skeleton);

    //---------------------------------------------UPDATE--------------------------------------------------//

    //-------------------DRAW SECTION-------------------------------------------------------------------//

        window.clear(sf::Color::Black);

        skeleton.Draw(window);

        player.Draw(window);

        window.draw(FrameRateText);
        window.display();
    //-------------------DRAW SECTION-------------------------------------------------------------------//

    }

    return 0;
}