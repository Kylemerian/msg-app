#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>
#include "constants.hpp"
#include "UIController.hpp"
#include "style.hpp"

using namespace std;

int main(int argc, char ** argv){
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Chat");
    
    window.setFramerateLimit(100);
    sf::View view = window.getDefaultView();
    // window.setVerticalSyncEnabled(true);
    // while (socket.connect("0", stoi(argv[1])) != sf::Socket::Done){
    //     std::cout << "Didn't connect to server\n";
    //     window.clear(sf::Color(14, 22, 33));
    //     window.display();
    //     sf::sleep(sf::seconds(1));
    // }
    UIController UI(&window);
    UI.InitUI();
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::Resized){
                // if(window.getSize().y < 400)
                //     window.setSize({window.getSize().x, 400});
                // if(window.getSize().x < 600)
                //     window.setSize({600, window.getSize().y});
                // if(event.size.height > 768)
                //     window.setSize({window.getSize().x, 768});
                // if(event.size.width > 1024)
                //     window.setSize({1024, window.getSize().y});
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }

            UI.EventUI(event);
        }
        window.clear(getBGColor());
        UI.DrawUI();
        window.display();
    }
    return 0;
}