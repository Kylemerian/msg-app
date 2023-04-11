#include "UIController.hpp"
#include <iostream>

void UIController::InitUI(){
    signup.init();
    signin.init();
    chat.init();
}

void UIController::DrawUI(){
    switch (page)
    {
    case SIGNUPPAGE:
        signup.draw();
        break;
    
    case SIGNINPAGE:
        signin.draw();
        break;
    
    case CHATPAGE:
        chat.draw();
        break;

    default:
        break;
    }
}

void UIController::EventUI(sf::Event event){
    switch (page)
    {
    case SIGNUPPAGE:
        page = signup.events(event);
        break;
    
    case SIGNINPAGE:
        page = signin.events(event);
        break;

    case CHATPAGE:
        page = chat.events(event);
        break;

    default:
        break;
    }
}