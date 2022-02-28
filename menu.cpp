#include "menu.h"
#include <SFML/Graphics.hpp>
using namespace sf;
menu::menu(float width, float height)
{
    if (!font.loadFromFile("pixelmix.ttf")) {}
    //Menu background

    //play
    mainmenu[0].setFont(font);
    mainmenu[0].setFillColor(Color(130,202,250));
    mainmenu[0].setString("Play Game");
    mainmenu[0].setCharacterSize(54);
    mainmenu[0].setPosition(Vector2f(480.0f / 2-68 , height /2-30)); //width (x axis) height (y axis)

    //exit
    mainmenu[1].setFont(font);
    mainmenu[1].setFillColor(Color::White);
    mainmenu[1].setString("Exit Game");
    mainmenu[1].setCharacterSize(30);
    mainmenu[1].setPosition(Vector2f(480.0f / 2-10 , height / (Max_main_menu +
                                                                    1) * 2));

    mainmenuselected = 0; //starting with play bottom
}

//function of drawing main menu
void menu::draw(RenderWindow& Menuwindow)
{
    for (int i = 0; i < 2; i++)
    {
        Menuwindow.draw(mainmenu[i]);
    }
}

//move down
void menu::movedown()
{
    if (mainmenuselected + 1 <= Max_main_menu) //check if not on the last item "exit"
    {
        mainmenu[mainmenuselected].setFillColor(Color::White); //change the previous item's color
        mainmenuselected++; //move to the lower item
        if (mainmenuselected == 2)
        {
            mainmenuselected = 0;
        }
        mainmenu[mainmenuselected].setFillColor(Color(130,202,250));//change the new item's color
    }
}

//move up
void menu::moveup()
{
    if (mainmenuselected - 1 >= -1) //check if not on the first item "play"
    {
        mainmenu[mainmenuselected].setFillColor(Color::White);//change the previous item's color
        mainmenuselected--; //move to the upper item
        if (mainmenuselected == -1)
        {
            mainmenuselected = 2;
        }
        mainmenu[mainmenuselected].setFillColor(Color(130,202,250)); //change the new item's color
    }
}