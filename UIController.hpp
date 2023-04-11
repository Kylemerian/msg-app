#ifndef UICONTROLLER_HPP
#define UICONTROLLER_HPP

#include "constants.hpp"
#include "UISignUpPage.hpp"
#include "UISignInPage.hpp"
#include "UIChatPage.hpp"
#include <SFML/Graphics.hpp>

class UIController{
    int page;
    UISignUpPage signup;
    UISignInPage signin;
    UIChatPage chat;
    sf::RenderWindow *window;
public:
    UIController(sf::RenderWindow *wind):
        window(wind),
        signup(wind),
        signin(wind),
        chat(wind),
        page(SIGNINPAGE){};

    void InitUI();

    void DrawUI();

    void EventUI(sf::Event event);
};

#endif
