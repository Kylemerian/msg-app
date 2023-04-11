#include "UISignInPage.hpp"
#include <iostream>
#include "constants.hpp"
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "shapes.hpp"


void UISignInPage::init(){
    signInBtn.setBold();

    signUpBtn.setCharSize(9);
}

void UISignInPage::draw(){
    logField.setSize(window->getSize().x / 3.f, 30);
    logField.setPosition(window->getSize().x / 3.f, window->getSize().y / 2.f - 40);

    passField.setSize(window->getSize().x / 3.f, 30);
    passField.setPosition(window->getSize().x / 3.f, window->getSize().y / 2.f + 30);

    signInBtn.setSize(window->getSize().x / 3.f, 50);
    signInBtn.setPosition({window->getSize().x / 3.f, window->getSize().y / 2.f + 110});

    signUpBtn.setSize(window->getSize().x / 3.f, 12);
    signUpBtn.setPosition({window->getSize().x / 3.f, window->getSize().y / 2.f + 80});

    window->draw(logField);
    window->draw(passField);
    signInBtn.drawTo(*window);
    signUpBtn.drawTo(*window);
}

int UISignInPage::events(sf::Event event){
    if(event.type == sf::Event::MouseMoved){
        if (signInBtn.isMouseOver(*window))
            signInBtn.setBackColor(getBtnColorHover());
        else 
            signInBtn.setBackColor(getBtnColor());

    }

    if(event.type == sf::Event::MouseButtonPressed){
        if (signInBtn.isMouseOver(*window)) {
            std::cout << "LOGIN: " << logField.getText() <<
                " PASS: " << passField.getText() << "\n";
            logField.setText("");
            passField.setText(""); 
            
        }
        else if(signUpBtn.isMouseOver(*window))
            return SIGNUPPAGE;
    }

    if (event.type == sf::Event::MouseButtonPressed){
        auto pos = sf::Mouse::getPosition(*window);
        logField.setFocus(false);
        passField.setFocus(false);

        if (logField.contains(sf::Vector2f(pos)))
            logField.setFocus(true);

        if (passField.contains(sf::Vector2f(pos)))
            passField.setFocus(true);
    }
    else{
        logField.handleInput(event);
        passField.handleInput(event);
    }
    return SIGNINPAGE;
}