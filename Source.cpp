#include"Game.h"
#include"Textures.h"
#include"Hurdles.h"
#include"Car.h"
int Gameover(RenderWindow& window, Event& e, Textures& T)
{
	window.clear();
	window.draw(T.spGameover);
	while (window.pollEvent(e))
	{
		int count = 0;
		int counter = 1;
		if (counter == 1)
			printf("Try again");
		counter++;
		if (e.key.code == Keyboard::Return)
		{
			count++;
			break;
		}
		else if (e.key.code == Keyboard::Escape)
			window.close();
		return count;
	}
}
int main()
{//object creations and calling default constructor
	Game gObj;
	Hurdles Hobj;
	Car Cobj;
	Textures Tobj;




	RenderWindow window(VideoMode(gObj.getwidth(), gObj.getheight()), "Car Game");
	window.setFramerateLimit(120);
	Tobj.setMainMenu(window.getSize().x, window.getSize().y);


	//for getting car and others



	Cobj.loadTex();
	Tobj.loadTextures();

	//FOR MENU
	Event E;

	while (window.isOpen())
	{
		//polling
		while (window.pollEvent(E))
		{
			switch (E.type)
			{
			case Event::KeyReleased:
				switch (E.key.code)
				{
				case Keyboard::Up:
					Tobj.Moveup(); break;
				case Keyboard::Down:
					Tobj.MoveDown(); break;
				case Keyboard::Return:
					switch (Tobj.getPressedItem())
					{
					case 0:
					{
						cout << "PLAY button Entered\n";
						goto start;
						break;
					}
					case 1:
					{
						cout << "ABOUT button Entered\n";
						gObj.DisplayInfo();
						break;
					}
					case 2:window.close();
					}
					break;
				}
				break;
			case Event::Closed:
				window.close(); break;
			}
		}
		//update

		//render
		window.clear();//clear old frame
		window.draw(Tobj.spritee);//draw picture
		Tobj.draw(window);//draw text
		window.display();//tell window is done drawing
	}

	system("pause");

	//haseeb
start:

	float a = 50, b = 410, x = 300, y = 300;
	float speed = 0, angle = 0;
	float maxSpeed = 3.0;
	float acc = 0.01, dec = 0.02;
	float turnSpeed = 0.08;


	int offsetX = 0, offsetY = 0;

	Event e;

	//game loop

	while (window.isOpen())
	{


		//for closing of window
		Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == Event::Closed)
				window.close();
			if (evnt.key.code == Keyboard::Escape)
				window.close();
		}

		bool Up = 0, Right = 0, Down = 0, Left = 0;
		if (Keyboard::isKeyPressed(Keyboard::Up)) Up = 1;
		if (Keyboard::isKeyPressed(Keyboard::Right)) Right = 1;
		if (Keyboard::isKeyPressed(Keyboard::Down)) Down = 1;
		if (Keyboard::isKeyPressed(Keyboard::Left)) Left = 1;

		if (Up && speed < maxSpeed)
			if (speed < 0)  speed += dec;
			else  speed += acc;
		if (Down && speed > -maxSpeed)
			if (speed > 0) speed -= dec;
			else  speed -= acc;
		if (!Up && !Down)
			if (speed - dec > 0) speed -= dec;
			else if (speed + dec < 0) speed += dec;
			else speed = 0;
		if (Right && speed != 0) angle += turnSpeed * speed / maxSpeed;
		if (Left && speed != 0) angle -= turnSpeed * speed / maxSpeed;
		a += sin(angle) * speed;
		b -= cos(angle) * speed;


		//Draw  Background
		window.clear(Color::Black);
		//drawing hurdles
		window.draw(Hobj.rect());
		window.draw(Hobj.rect1());
		window.draw(Hobj.rect2());
		window.draw(Hobj.rect3());

		window.draw(Hobj.rectangle1());
		window.draw(Hobj.rectangle2());
		window.draw(Hobj.rectangle3());
		window.draw(Hobj.rectangle4());
		window.draw(Hobj.rectangle5());
		window.draw(Hobj.rectangle7());
		window.draw(Hobj.rectangle8());
		window.draw(Hobj.circle1());
		window.draw(Hobj.rectangle91());
		window.draw(Hobj.rectangle10());

		//COLLOSIONS
		//left
		if (Cobj.spcar1.getGlobalBounds().intersects(Hobj.rect().getGlobalBounds()))
		{
			int count = Gameover(window, e, Tobj);
			if (count == 1)
				goto start;

		}
		//Top collosion
		if (Cobj.spcar1.getGlobalBounds().intersects(Hobj.rect1().getGlobalBounds()))
		{
			int count = Gameover(window, e, Tobj);
			if (count == 1)
				goto start;
		}
		//right collosion
		if (Cobj.spcar1.getGlobalBounds().intersects(Hobj.rect2().getGlobalBounds()))
		{
			window.clear();
			int count = Gameover(window, e, Tobj);
			if (count == 1)
				goto start;
		}

		//down collosion

		if (Cobj.spcar1.getGlobalBounds().intersects(Hobj.rect3().getGlobalBounds()))
		{
			int count = Gameover(window, e, Tobj);
			if (count == 1)
				goto start;
		}

		//1st wall
		if ((Cobj.spcar1.getPosition().x) <= 90.f && (Cobj.spcar1.getPosition().x) >= 70.f)
			if ((Cobj.spcar1.getPosition().y) >= 280.f && (Cobj.spcar1.getPosition().y) <= 460.f)
			{
				int count = Gameover(window, e, Tobj);
				if (count == 1)
					goto start;
			}
		//2nd wall
		if (Cobj.spcar1.getPosition().x <= 210.f && Cobj.spcar1.getPosition().x >= 180.f)
			if (Cobj.spcar1.getPosition().y >= 280.f && Cobj.spcar1.getPosition().y <= 400.f)
			{
				int count = Gameover(window, e, Tobj);
				if (count == 1)
					goto start;
			}




		//3rd wall
		if (Cobj.spcar1.getPosition().x <= 550.f && Cobj.spcar1.getPosition().x >= 210.f)
			if (Cobj.spcar1.getPosition().y >= 380.f && Cobj.spcar1.getPosition().y <= 395.f)
			{
				int count = Gameover(window, e, Tobj);
				if (count == 1)
					goto start;
			}
		//4th wall
		if (Cobj.spcar1.getPosition().x <= 620.f && Cobj.spcar1.getPosition().x >= 300.f)
			if (Cobj.spcar1.getPosition().y >= 300.f && Cobj.spcar1.getPosition().y <= 320.f)
			{
				int count = Gameover(window, e, Tobj);
				if (count == 1)
					goto start;
			}
		//5th
		
		//6th
		if (Cobj.spcar1.getPosition().x <= 410.f && Cobj.spcar1.getPosition().x >= 210.f)
			if (Cobj.spcar1.getPosition().y >= 170.f && Cobj.spcar1.getPosition().y <= 190.f)
			{
				int count = Gameover(window, e, Tobj);
				if (count == 1)
					goto start;
			}
		//7th
		if (Cobj.spcar1.getPosition().x <= 430.f && Cobj.spcar1.getPosition().x >= 410.f)
			if (Cobj.spcar1.getPosition().y >= 230.f && Cobj.spcar1.getPosition().y <= 170.f)
			{
				int count = Gameover(window, e, Tobj);
				if (count == 1)
					goto start;
			}
		//8th
		if (Cobj.spcar1.getPosition().x <= 190.f && Cobj.spcar1.getPosition().x >= 20.f)
			if (Cobj.spcar1.getPosition().y >= 180.f && Cobj.spcar1.getPosition().y <= 200.f)
			{
				int count = Gameover(window, e, Tobj);
				if (count == 1)
					goto start;
			}
		//9th
		if (Cobj.spcar1.getPosition().x <= 620.f && Cobj.spcar1.getPosition().x >= 100.f)
			if (Cobj.spcar1.getPosition().y >= 90.f && Cobj.spcar1.getPosition().y <= 110.f)
			{
				int count = Gameover(window, e, Tobj);
				if (count == 1)
					goto start;
			}
		//circle
		if (Cobj.spcar1.getPosition().x <= 520.f && Cobj.spcar1.getPosition().x >= 490.f)
			if (Cobj.spcar1.getPosition().y >= 170.f && Cobj.spcar1.getPosition().y <= 210.f)
			{
				int count = Gameover(window, e, Tobj);
				if (count == 1)
					goto start;
			}
		//For winning
		if (Cobj.spcar1.getPosition().x > 515 && Cobj.spcar1.getPosition().x < 600)
			if (Cobj.spcar1.getPosition().y > 25 && Cobj.spcar1.getPosition().y < 80)
			{
				window.clear(Color::Green);
				window.draw(Tobj.spwin);
				while (window.pollEvent(e))
				{
					if (e.key.code == Keyboard::Return|| e.key.code == Keyboard::R)
						goto level2;
				}
			}

		Cobj.spcar1.setPosition(a, b);
		Cobj.spcar1.setRotation(angle * 180 / 3.14);
		Cobj.spcar1.setColor(Color::Green);
		window.draw(Cobj.spcar1);
		window.display();
	}





level2:
	//2nd level just for random driving
	while (window.isOpen())
	{


		Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == Event::Closed)
				window.close();
			if (evnt.key.code == Keyboard::Escape)
				window.close();
		}
		//movement
		bool Up = 0, Right = 0, Down = 0, Left = 0;
		if (Keyboard::isKeyPressed(Keyboard::Up)) Up = 1;
		if (Keyboard::isKeyPressed(Keyboard::Right)) Right = 1;
		if (Keyboard::isKeyPressed(Keyboard::Down)) Down = 1;
		if (Keyboard::isKeyPressed(Keyboard::Left)) Left = 1;


		if (Up && speed < maxSpeed)
			if (speed < 0)  speed += dec;
			else  speed += acc;

		if (Down && speed > -maxSpeed)
			if (speed > 0) speed -= dec;
			else  speed -= acc;

		if (!Up && !Down)
			if (speed - dec > 0) speed -= dec;
			else if (speed + dec < 0) speed += dec;
			else speed = 0;

		if (Right && speed != 0) angle += turnSpeed * speed / maxSpeed;
		if (Left && speed != 0) angle -= turnSpeed * speed / maxSpeed;


		x += sin(angle) * speed;
		y -= cos(angle) * speed;

		//for making map follow according to the car moving
		if (x > 320) offsetX = x - 320;
		if (y > 240) offsetY = y - 240;





		//Draw  Background
		window.clear(Color::Red);
		Tobj.spBackground2.setPosition(-offsetX, -offsetY);
		window.draw(Tobj.spBackground2);
		//Draw Car

		Cobj.spcar1.setPosition(x - offsetX, y - offsetY);
		Cobj.spcar1.setRotation(angle * 180 / 3.14);
		Cobj.spcar1.setColor(Color::Green);
		window.draw(Cobj.spcar1);
		window.display();

	}//game loop ends 


	system("pause");
	return 0;
}