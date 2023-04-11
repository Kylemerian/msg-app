#ifndef UISIGNUPPAGE_HPP
#define UISIGNUPPAGE_HPP
#include "shapes.hpp"
#include <SFML/Graphics.hpp>
#include "style.hpp"

class UISignUpPage{
    sf::RenderWindow * window;
    TextField logField;
    TextField passField;
    TextField nickField;
    Button signUpBtn;
public:
    UISignUpPage(sf::RenderWindow * wind) : window(wind),
        logField(30, window, false),
        passField(30, window, true),
        nickField(30, window, false),
        signUpBtn("Register", {50, 50}, 15, getBtnColor(), sf::Color::White)
    {

    }

    void init();

    void draw();
    
    int events(sf::Event event);
};

#endif