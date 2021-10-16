#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
int main()
{
    RenderWindow window(VideoMode(1280, 720), "berserk!!!!!!!!!!");
    window.setVerticalSyncEnabled(true);

    Font font;
    font.loadFromFile("fonts/arial.ttf");
    Text text;
    text.setFont(font);


    Image img1;
    img1.loadFromFile("img/behelitggg.png");
    img1.createMaskFromColor(Color(255, 255, 255));
    Texture texture1;
    texture1.loadFromImage(img1);
    Sprite sprite1(texture1, IntRect(0, 0, 828, 623));
    sprite1.scale(0.2, 0.2);
    sprite1.setPosition(0, 0);
    double yh = rand() % 690, x1 = rand() % 1100;
    sprite1.setOrigin(414, 311);

    Image img;
    img.loadFromFile("img/griffithggg.png");
    img.createMaskFromColor(Color(255, 255, 255));
    Texture texture;
    texture.loadFromImage(img);
    Sprite sprite(texture, IntRect(0, 0, 1280, 963));
    sprite.scale(0.17, 0.17);
    double x = 600, y = 360;
    sprite.setOrigin(640, 481);

    srand(time(NULL));
    double speed = 10;
    int score = 0;
    Transform transform;
    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            x -= speed;
            std::cout << x << " " << y << std::endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            y -= speed;
            std::cout << x << " " << y << std::endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            y += speed;
            std::cout << x << " " << y << std::endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            x += speed;

            std::cout << x << " " << y << std::endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {

        }

        if ((x1 - x < 60 && x1 - x > -60) && (yh - y < 60 && yh - y > -60)) {
            x1 = rand() % 1100;
            yh = rand() % 690;
            while ((x1 - x < 60 && x1 - x > -60) && (yh - y < 60 && yh - y > -60)) {
                x1 = rand() % 1100;
                yh = rand() % 690;
            }
            std::cout << "contact" << std::endl;
            score++;
            text.setString(std::to_string(score));
        }

        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (y > 720) y = 720;
        if (x > 1280)x = 1280;
        sprite.setPosition(x, y);
        sprite1.setPosition(x1, yh);
        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.draw(sprite1);
        window.display();
    }

    return 0;
}