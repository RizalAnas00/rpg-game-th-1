#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f NormalizedVector(sf::Vector2f vector)
{
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    sf::Vector2f normalizedVector;

    normalizedVector.x = vector.x / m;
    normalizedVector.y = vector.y / m;

    return normalizedVector;

}

int main()
{
    //INITIALIZE----------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1080, 720), "GAME RPG HOWAK", sf::Style::Default,settings);
    
    //----------------------------------------------LOAD--------------------------------------------------//
   
    //Bullets
    std::vector<sf::RectangleShape> AllBullets;

    float bulletSpeed = 1.5f;

    //enemy chars
    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite;

    if (skeletonTexture.loadFromFile("GameTrial/Assets/Enemy/Skeleton/Texture/skeleton_spritesheet.png"))
    {
        std::cout << "ENEMY LOADED SUCCESSFULLY" << std::endl;
        skeletonSprite.setTexture(skeletonTexture);

        //X, Y, w, h
        int XIndex = 0;
        int YIndex = 0;

        skeletonSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        skeletonSprite.setScale(sf::Vector2f(2, 2));

        skeletonSprite.setPosition(sf::Vector2f(500, 500));
    }
    else {
        std::cout << "Failed to Load Image" << std::endl;
    }

    //Player Chars
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
        float speed = 0.4f; // Kecepatan default

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
            speed += 0.2f; // Kecepatan saat Shift ditekan
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
            playerSprite.setPosition(sf::Vector2f(540, 360));

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            AllBullets.push_back(sf::RectangleShape(sf::Vector2f(30, 15)));

            //bullets postion
            int i = AllBullets.size() - 1;
            AllBullets[i].setPosition(playerSprite.getPosition());
            
            //Use This if u want the bullets dont follow the enemy
            //sf::Vector2f bulletDirection (move this outside loop window) = skeletonSprite.getPosition() - AllBullets[i].getPosition();
            //bulletDirection = NormalizedVector(bulletDirection);

        }

        for (size_t i = 0; i < AllBullets.size(); i++) 
        {
            sf::Vector2f bulletDirection = skeletonSprite.getPosition() - AllBullets[i].getPosition();
            bulletDirection = NormalizedVector(bulletDirection);
            AllBullets[i].setPosition(AllBullets[i].getPosition() + bulletDirection * bulletSpeed);

        }
    //---------------------------------------------UPDATE--------------------------------------------------//

    //-------------------DRAW SECTION-------------------------------------------------------------------//
        
        window.clear(sf::Color::Black);

        window.draw(skeletonSprite);

        for (size_t i = 0; i < AllBullets.size(); i++) {
            window.draw(AllBullets[i]);
        }

        window.draw(playerSprite);

        window.display();
    //-------------------DRAW SECTION-------------------------------------------------------------------//

    }

    return 0;
}