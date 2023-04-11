#ifndef UICHATPAGE_HPP
#define UICHATPAGE_HPP
#include "constants.hpp"
#include <SFML/Graphics.hpp>

class UIChatPage{
    sf::RenderWindow * window;
public:
    UIChatPage(sf::RenderWindow * wind) : window(wind){
        
    }

    void init();

    void draw();
    
    int events(sf::Event event);
};

#endif  