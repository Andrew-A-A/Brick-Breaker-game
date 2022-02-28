#include <SFML\Graphics.hpp> //for using sf in line 9 (drawing of window)
#define Max_main_menu 2
class menu
{
public: //variables will be called main.cpp
    menu(float width, float height); //(constructor) treated like a fun (fun def.)

    void draw(sf::RenderWindow& Menuwindow); //functions
    void moveup();
    void movedown();

    int mainmenupressed() ////check which blue word is pressed
    {
        return mainmenuselected;
    }

private: //variables won't be calls in main.cpp
    int mainmenuselected; //index for buttons
    sf::Font font;
    sf::Text mainmenu[Max_main_menu]; //array of text , with size 2 (max num of buttons)

};
//menu.h is for the header of fun (def.) + variables which will be used
//menu.cpp is for the implementation of functions