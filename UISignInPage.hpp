#ifndef UISIGNINPAGE_HPP
#define UISIGNINPAGE_HPP
#include <SFML/Graphics.hpp>

class UISignInPage{
    sf::RenderWindow * window;
public:
    UISignInPage(sf::RenderWindow * wind){}

    void init();

    void draw();
    
    int events(sf::Event event);
};

#endif