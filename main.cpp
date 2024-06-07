#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "GAME RPG HOWAK");
    
    //----------------------------------------------LOAD--------------------------------------------------//

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("GameTrial/Assets/Player/Texture/male_ss.png"))
    {
        std::cout<< "Image Loaded SUCCESSFULLY" << std::endl;
        playerSprite.setTexture(playerTexture);
        
        //X, Y, w, h
        int XIndex = 0;
        int YIndex = 0;

        playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        playerSprite.setScale(sf::Vector2f(2, 2));
    }
    else {
        std::cout << "Failed to Load Image" << std::endl;
    }

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

        sf::Vector2f currPosition = playerSprite.getPosition();
        float speed = 0.08f; // Kecepatan default

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
            speed += 0.08f; // Kecepatan saat Shift ditekan
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp))
            playerSprite.setPosition(currPosition + sf::Vector2f(0, -speed));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown))
            playerSprite.setPosition(currPosition + sf::Vector2f(0, speed));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
            playerSprite.setPosition(currPosition + sf::Vector2f(-speed, 0));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::End))
            playerSprite.setPosition(currPosition + sf::Vector2f(speed, 0));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            playerSprite.setPosition(sf::Vector2f(400, 300));


    //---------------------------------------------UPDATE--------------------------------------------------//

    //-------------------DRAW SECTION-------------------------------------------------------------------//
        
        window.clear(sf::Color::Black);

        window.draw(playerSprite);

        window.display();
    //-------------------DRAW SECTION-------------------------------------------------------------------//

    }

    return 0;
}