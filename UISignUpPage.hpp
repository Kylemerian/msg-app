#ifndef UISIGNUPPAGE_HPP
#define UISIGNUPPAGE_HPP
// #include "FormSFML.h"
#include <SFML/Graphics.hpp>

class UISignUpPage{
    sf::RenderWindow * window;
public:
    UISignUpPage(sf::RenderWindow * wind){}

    void init();

    void draw();
    
    int events(sf::Event event);
};

#endif