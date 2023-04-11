all: main

main: client.o UIController.o UISignUpPage.o UISignInPage.o UIChatPage.o
	g++ client.o UIController.o UISignUpPage.o UISignInPage.o UIChatPage.o -o msg-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

client.o: client.cpp
	g++ -c client.cpp

UIController.o: UIController.cpp UIController.hpp
	g++ -c UIController.cpp

UISignUpPage.o: UISignUpPage.cpp UISignUpPage.hpp
	g++ -c UISignUpPage.cpp

UISignInPage.o: UISignInPage.cpp UISignInPage.hpp
	g++ -c UISignInPage.cpp

UIChatPage.o: UIChatPage.cpp UIChatPage.hpp
	g++ -c UIChatPage.cpp	

sockets.o: sockets.cpp sockets.hpp
	g++ -c sockets.cpp

clean:
	rm -rf *.o
