#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include "menu.h"
using  namespace std;
using namespace sf;
int pagenumber;
//constants
const int WindowWidth = 640.0f;
const int WindowHeight = 480.0f;
const float ballRedius = 7.0f, ballVelocity = 8.9f;
const float barWidth = 120.0f, barHeight = 20.0f;

//Ball and bar structs
struct Ball
{
    CircleShape shape;
    Vector2f velocity{ 0,0 };
    Ball(float mx, float my) {
        shape.setPosition(mx, my);
        shape.setRadius(ballRedius);
        shape.setOrigin(ballRedius, ballRedius);
    }
    // Control movement of the ball
    void Shoot() {
        shape.move(velocity);
        if (Left() < 15)
        {
            velocity.x = ballVelocity;
        }
        else if (Right() > WindowWidth - 15)
        {
            velocity.x = -ballVelocity;
        }
        if (Top() < 65)
        {
            velocity.y = ballVelocity;
        }
    }
    //Return Positions of ball
    float Left() { return shape.getPosition().x - shape.getRadius(); }
    float Right() { return shape.getPosition().x + shape.getRadius(); }
    float Top() { return shape.getPosition().y - shape.getRadius(); }
};
// The Bar
struct Bar
{
    RectangleShape shape;
    Bar(float mx, float my)
    {
        shape.setPosition(mx, my);
        shape.setSize(Vector2f(barWidth, barHeight));
        shape.setOrigin(barWidth / 2.f, barHeight / 2.f);
        shape.setFillColor(Color(180, 207, 236));
    }
    // Movement of the Bar
    void Movement() {
        if (Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (shape.getPosition().x < 560)
                shape.move(10.0f, 0.0f);
        }
        if (Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (shape.getPosition().x > 80)
                shape.move(-10.0f, 0.0f);
        }
    }
};

int main() {
    //Creating variables of score & lives
    bool is_key_pressed = false;
    int num_of_lives = 3, max_score = -100;

    while (true) ////while loop for the whole program (all windows)
    {

        RenderWindow Menuwindow(sf::VideoMode(640.0, 480.0f), "Brick breaker",Style::Close);
        menu menu(640.0f, 480.0f); //l constructor
        Texture Main_menu;              //menu background
        Main_menu.loadFromFile("menu.png");
        Sprite Main_menu_sprite;
        Main_menu_sprite.setTexture(Main_menu);
        while (Menuwindow.isOpen())
        {
            Event event;
            while (Menuwindow.pollEvent(event)) //events' loop
            {
                if (event.type == sf::Event::Closed) {
                    Menuwindow.close();
                    pagenumber = 1;
                    break;
                }
                if (event.type == sf::Event::KeyReleased) //a bottom on the keyboard has been pressed
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        menu.moveup();
                        break; //break from events' loop (while loop)
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        menu.movedown();
                        break;
                    }
                    //creating new window inside play bottom
                    if (event.key.code == sf::Keyboard::Return) //check if the enter button has been pressed
                    {

                        if (menu.mainmenupressed() == 0) //the user pressed on play
                        {
                            Menuwindow.close(); //menu window
                            pagenumber = 0;
                        }
                        if (menu.mainmenupressed() == 1) //the user pressed on exit
                        {
                            Menuwindow.close();
                            pagenumber = 1; //close whole game
                        }
                    }

                }
            }

            Menuwindow.clear();
            Menuwindow.draw(Main_menu_sprite);
            menu.draw(Menuwindow);
            Menuwindow.display();       //displaying Menu

        }
        //The game
        if (pagenumber == 0)
        {
            //Creating window:
            RenderWindow window(VideoMode(640.0f, 480.0f), "Brick Bricker", Style::Close);  //Rendering the window
            window.setFramerateLimit(30); //Set FPS limit for Better Performance
            Event event;//Declare event for closing window

            //Window borders:
            RectangleShape border1;         //Border at edges of screen
            border1.setSize(Vector2f(620.0f, 460.0f));
            border1.setPosition(Vector2f(10.0f, 10.0f));
            border1.setFillColor(Color::Transparent);
            border1.setOutlineThickness(10);
            border1.setOutlineColor(Color(105, 96, 236));
            RectangleShape border2;                     //line to separate Counters of score&lives from the gameplay
            border2.setSize(Vector2f(640.0, 10.0));
            border2.setPosition(Vector2f(0.0, 50));
            border2.setFillColor(Color(105, 96, 236));

            //Creating textures and sprites
            Texture texture1, texture2, texture3;
            texture1.loadFromFile("Red_Heart.png");
            texture2.loadFromFile("Red_Heart.png");
            texture3.loadFromFile("Red_Heart.png");
            Sprite sprite1(texture1), sprite2(texture2), sprite3(texture3);
            sprite1.setPosition(WindowWidth-52.0f, 12.0f);
            sprite2.setPosition(WindowWidth-97.0f, 12.0f);
            sprite3.setPosition(WindowWidth-142.0f, 12.0f);
            Texture Back_ground;
            Back_ground.loadFromFile("Background.jpg");
            Sprite Background_sprite;
            Background_sprite.setTexture(Back_ground);

            //Importing font:
            Font font;
            font.loadFromFile("pixelmix.ttf");
            //Creating text
            Text text;
            text.setFont(font);
            text.setString("Press space to start the game");
            text.setCharacterSize(15);
            text.setPosition((640.0f / 2) -135, 25.0f);

            //Sounds:
            Music music;   //Game music
            music.openFromFile("music.ogg");
            music.play();
            music.setLoop(true);
            music.setVolume(31);
            SoundBuffer h;   //Buffer for hit sound
            SoundBuffer b;   //Buffer for Bounce sound
            Sound hit;       //hit sound
            Sound bounce;    //bounce sound
            b.loadFromFile("bounce-00.wav");
            h.loadFromFile("explosion-03.wav");
            hit.setBuffer(h); //set buffer for hit
            bounce.setBuffer(b); //set buffer for bounce

            //calling constructors:
            Ball ball{ WindowWidth / 2.0,WindowHeight - 80 };
            Bar bar{ WindowWidth / 2.0 , WindowHeight - 30.0 };

            //Setting Bricks:
            vector<RectangleShape>V;                                        //Bricks vector
            Color clr;                                                      // Variable to change Colour each row
            bool isCollided[36] = { false };                                    //Boolean to check if ball hit the brick
            float x = 30, y = 90;                                               //declaration & initialization coordinates of 1st brick in 1st row
            for (int j = 0; j < 4; ++j) {                                  //Loop to create bricks and save them in the Vector
                switch (j) {                                              //change colour of each row
                    case 0:clr = Color(21, 27, 84); break;
                    case 1:clr = Color(52, 45, 126); break;
                    case 2:clr = Color(0, 65, 194); break;
                    case 3: clr = Color(53, 126, 199);
                }
                for (int i = 0; i < 10; ++i) {
                    RectangleShape b_i;
                    b_i.setSize(Vector2f{ 60, 20 });
                    b_i.setPosition(x, y);
                    b_i.setFillColor(clr);
                    V.push_back(b_i);
                    x += 65;
                    if (i == 8)
                        x += 60;
                }
                y += 30; x = 30;                                                //Reset X-coordinate and move to 2nd row
            }


            //Deceleration of score
            int score = 0;
            Text ScoreText;
            ScoreText.setFont(font);
            ScoreText.setString("Score:");
            stringstream ss,finalscore;

            Text ScorePlayer;
            ss << score;
            ScorePlayer.setString(ss.str());
            ss.str("");
            ScorePlayer.setFont(font);
            ScorePlayer.setPosition({ 140.0f,12.0f });

            ScoreText.setFillColor(Color::White);
            ScoreText.setPosition({ 15.0f ,12.0f });


            while (window.isOpen()) {



                if (Keyboard::isKeyPressed(sf::Keyboard::Space)&&  num_of_lives!=0  &&   score!=360 && ball.velocity.x==0)
                {
                    ball.velocity = { -ballVelocity,ballVelocity };
                    text.setString("");
                    is_key_pressed = true;
                }
                //remove text from screen permanently
                if (is_key_pressed)
                {
                    text.setString("");
                }


                //Bounce sound when ball hit the borders:
                if (ball.shape.getPosition().x<22 || ball.shape.getPosition().x>WindowWidth - 22) {
                   bounce.play();
                }

                //To Close Window:
                while (window.pollEvent(event))
                    if (event.type == Event::Closed) {
                        window.close();
                        break;
                    }

                //Bar And ball collision:
                if (bar.shape.getGlobalBounds().intersects(ball.shape.getGlobalBounds())) {
                    if (bar.shape.getPosition().x > ball.shape.getPosition().x) {      //ball movement when it hit left side of bar
                        ball.velocity.y = -ballVelocity;
                        ball.velocity.x = -ballVelocity;
                        ball.shape.move(ball.velocity);
                        bounce.play();
                    }
                    if (bar.shape.getPosition().x < ball.shape.getPosition().x) {      //ball movement when it hit right side of bar
                        ball.velocity.y = -ballVelocity;
                        ball.velocity.x = ballVelocity;
                        ball.shape.move(ball.velocity);
                        bounce.play();
                    }
                }
                //Check for losing:
                if (ball.shape.getPosition().y > WindowWidth + 3)
                {
                    V.clear();                                                          //Clear bricks vector to draw new one
                    bar.shape.setPosition(WindowWidth / 2.0, WindowHeight - 30);        //Reset bar position
                    ball.shape.setPosition(WindowWidth / 2.0, WindowHeight - 80);       //Reset ball position
                    ball.velocity = { 0,0 };                                            //Reset  ball Velocity
                    //lives
                    num_of_lives--;
                    if (num_of_lives >= 0)                                          //change red heart to grey one in case of losing
                    {
                        if (num_of_lives  == 2)
                        {
                            texture3.loadFromFile("losing heart.png");
                            if (score >= max_score)
                            {
                                max_score = score;
                            }
                        }
                        else if (num_of_lives  == 1)
                        {
                            texture2.loadFromFile("losing heart.png");
                            if (score >= max_score)
                            {
                                max_score = score;
                            }
                        }
                        else if (num_of_lives == 0)
                        {
                            texture1.loadFromFile("losing heart.png");
                            if (score >= max_score)
                            {
                                max_score = score;
                            }
                        }
                        else if(num_of_lives < 0 || score == 360)
                        {
                            goto END;
                        }
                    }
                    ////////////////// final score << score;
                    score = 0;                                                         //Reset the score
                    ss << score;
                    ScorePlayer.setString(ss.str());
                    ss.str("");


                    x = 30; y = 90;                                                        //Recreate bricks
                    for (int j = 0; j < 4; ++j) {
                        switch (j) {
                            case 0:clr = Color(21, 27, 84); break;
                            case 1:clr = Color(52, 45, 126); break;
                            case 2:clr = Color(0, 65, 194); break;
                            case 3: clr = Color(53, 126, 199);
                        }
                        for (int i = 0; i < 10; ++i) {
                            RectangleShape b_i;
                            b_i.setSize(Vector2f{ 60, 20 });
                            b_i.setPosition(x, y);
                            b_i.setFillColor(clr);
                            V.push_back(b_i);
                            x += 65;
                            if (i == 8)
                                x += 60;
                        }
                        y += 30;
                        x = 30;
                    }
                }
                //Drawing each frame:
                window.clear(Color::Black);
                window.draw(Background_sprite);
                //Checking ball position relative to bricks before drawing it:
                for (int i = 0; i < V.size(); ++i) {
                    if (ball.shape.getGlobalBounds().intersects(V[i].getGlobalBounds())) {
                        V.erase(V.begin() + i);                                   //remove the brick that the ball hit
                        score += 10;
                        ss << score;
                        ScorePlayer.setString(ss.str());                          //calculating score
                        ss.str("");
                        hit.play();                                                   //play hit sound
                        isCollided[i] = false;
                        if (ball.shape.getPosition().y > V[i].getPosition().y) {          //change ball direction when hit brick from downside
                            ball.velocity.y = ballVelocity;
                            ball.velocity.x = -ballVelocity;
                        }
                        else {                                                           //change ball direction when hit brick from downside
                            ball.velocity.y = -ballVelocity;
                            ball.velocity.x = -ballVelocity;
                        }
                        ball.shape.move(ball.velocity);
                    }
                    window.draw(V[i]);
                    //draw brick if ball didn't hit it
                    window.draw(ScorePlayer);

                }
                //losing all lives condition
                END:if (num_of_lives == 0)
            {
                //Draw
                window.clear();
                window.draw(border1);
                // The Score
                finalscore << max_score;
                Text game_over, your_score, highest;
                game_over.setFont(font);
                game_over.setString("Game Over :(");
                game_over.setCharacterSize(20);
                game_over.setPosition(WindowWidth/2.0f-60 , WindowHeight - 300);
                game_over.setFillColor(Color::Magenta);
                your_score.setFont(font);
                your_score.setString("Your highest score achieved is: ");
                your_score.setPosition(100.0f , WindowHeight - 250.0f);
                your_score.setCharacterSize(15);
                highest.setFont(font);
                highest.setCharacterSize(15);
                highest.setString(finalscore.str());
                finalscore.str("");
                highest.setPosition(450.0f, WindowHeight - 250.0f);
                window.draw(game_over);
                window.draw(your_score);
                window.draw(highest);
                if (Keyboard::isKeyPressed(Keyboard::Escape))
                    window.close();
            }
                if (score == 360)                   //winning condition
            {
                window.clear();
                ball.velocity={0,0};
                window.draw(border1);
                finalscore << max_score;
                Text you_won, your_score, highest;
                you_won.setFont(font);
                you_won.setString("You Won! Congratulations! :)");
                you_won.setCharacterSize(20);
                you_won.setPosition(WindowWidth / 2.0f - 200, WindowHeight - 300);
                you_won.setFillColor(Color(255, 255, 112));

                window.draw(you_won);
                if (Keyboard::isKeyPressed(Keyboard::Escape))
                    window.close();
            }
       if(num_of_lives!=0&&score!=360){
                window.draw(bar.shape);
                window.draw(ball.shape);
                window.draw(sprite1);
                window.draw(sprite2);
                window.draw(sprite3);
                window.draw(border2);
                window.draw(text);
                window.draw(ScoreText);
            }
                window.draw(border1);
                ball.Shoot();
                bar.Movement();
                window.display();   //Display the frame

            }
            return 0;
        }
        //Ending the Game
        if (pagenumber == 1)
        {
            break;
        }
    }
}