#ifndef UISIGNINPAGE_HPP
#define UISIGNINPAGE_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include "shapes.hpp"
#include "style.hpp"

class UISignInPage{
    sf::RenderWindow * window;
    TextField logField;
    TextField passField;
    Button signInBtn;
    Button signUpBtn;
public:
    UISignInPage(sf::RenderWindow * wind) : window(wind),
        logField(80, window, 0),
        passField(80, window, 1),
        signInBtn("Sign In", {50, 50}, 15, getBtnColor(), sf::Color::White),
        signUpBtn("Create account", {50, 50}, 15, getBGColor(), sf::Color::White)
    {

    }

    void init();

    void draw();
    
    int events(sf::Event event);
};

#endif