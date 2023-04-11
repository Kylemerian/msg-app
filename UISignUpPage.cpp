#include "UISignUpPage.hpp"
#include <iostream>
#include "constants.hpp"
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

// extern sf::TcpSocket socket;

void UISignUpPage::init(){

}

void UISignUpPage::draw(){
    logField.setSize(window->getSize().x / 3.f, 30);
    logField.setPosition(window->getSize().x / 3.f, window->getSize().y / 2.f + 30);
    
    passField.setSize(window->getSize().x / 3.f, 30);
    passField.setPosition(window->getSize().x / 3.f, window->getSize().y / 2.f + 100);
    
    nickField.setSize(window->getSize().x / 3.f, 30);
    nickField.setPosition(window->getSize().x / 3.f, window->getSize().y / 2.f - 40);
    
    signUpBtn.setSize(window->getSize().x / 3.f, 50);
	signUpBtn.setPosition({window->getSize().x / 3.f, window->getSize().y / 2.f + 170});
    
    window -> draw(logField);
    window -> draw(passField);
    window -> draw(nickField);
    signUpBtn.drawTo(*window);
}

int UISignUpPage::events(sf::Event event){
    if(event.type == sf::Event::MouseMoved)
        if (signUpBtn.isMouseOver(*window))
            signUpBtn.setBackColor(getBtnColorHover());
        else 
            signUpBtn.setBackColor(getBtnColor());
    
    if(event.type == sf::Event::MouseButtonPressed)
        if (signUpBtn.isMouseOver(*window)) {
            std::cout << "NICK: " << nickField.getText() <<
                " LOGIN: " << logField.getText() <<
                " PASS: " << passField.getText() << "\n";
            logField.setText("");
            passField.setText(""); 
            nickField.setText("");
            
        }
    
    if (event.type == sf::Event::MouseButtonPressed){
        auto pos = sf::Mouse::getPosition(*window);
        logField.setFocus(false);
        passField.setFocus(false);
        nickField.setFocus(false);

        if (logField.contains(sf::Vector2f(pos)))
            logField.setFocus(true);

        if (passField.contains(sf::Vector2f(pos)))
            passField.setFocus(true);

        if (nickField.contains(sf::Vector2f(pos)))
            nickField.setFocus(true);
    }
    else{
        logField.handleInput(event);
        passField.handleInput(event);
        nickField.handleInput(event);
    }

    return SIGNUPPAGE;
}