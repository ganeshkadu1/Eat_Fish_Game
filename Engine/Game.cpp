/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDist(0, 770);
	std::uniform_int_distribution<int> yDist(0, 470);

	fish0.x= xDist(rng);
	fish0.y= yDist(rng);
	fish1.x= xDist(rng);
	fish1.y= yDist(rng);
	fish2.x= xDist(rng);
	fish2.y= yDist(rng);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (dude.inhibitRight)
		{

		}
		else {
			dude.vx += 1;
			dude.inhibitRight = true;
		}
	}
	else
	{
		dude.inhibitRight = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (dude.inhibitLeft)
		{

		}
		else {
			dude.vx -= 1;
			dude.inhibitLeft = true;
		}
	}
	else
	{
		dude.inhibitLeft = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (dude.inhibitUp)
		{

		}
		else {
			dude.vy -= 1;
			dude.inhibitUp = true;
		}
	}
	else
	{
		dude.inhibitUp = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (dude.inhibitDown)
		{

		}
		else {
			dude.vy += 1;
			dude.inhibitDown = true;
		}
	}
	else
	{
		dude.inhibitDown = false;
	}


	if (fish0.IsColliding(dude.x, dude.y, Dude::width, Dude::height))
	{
		fish0.isEatean = true;
	}
	if (fish1.IsColliding(dude.x, dude.y, Dude::width, Dude::height))
	{
		fish1.isEatean = true;
	}
	if (fish2.IsColliding(dude.x, dude.y, Dude::width, Dude::height))
	{
		fish2.isEatean = true;
	}

	dude.Update();

	fish0.Update();
	fish1.Update();
	fish2.Update();

}

void Game::DrawFace(int x, int y)
{
	gfx.PutPixel(7 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(8 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(9 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(10 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 3 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 3 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 4 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 4 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(13 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 6 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 6 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 6 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(3 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(3 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(14 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(15 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(13 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 10 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 10 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 11 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 11 + y, 20, 14, 18);
	gfx.PutPixel(8 + x, 11 + y, 18, 11, 14);
	gfx.PutPixel(9 + x, 11 + y, 18, 12, 14);
	gfx.PutPixel(10 + x, 11 + y, 18, 12, 14);
	gfx.PutPixel(11 + x, 11 + y, 21, 13, 16);
	gfx.PutPixel(12 + x, 11 + y, 24, 11, 15);
	gfx.PutPixel(13 + x, 11 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 11 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 12 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 12 + y, 23, 9, 23);
	gfx.PutPixel(7 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(9 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(10 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(11 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(12 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(13 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(14 + x, 12 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 12 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(9 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(10 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(11 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(12 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(13 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(14 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(6 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(9 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(10 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(11 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(12 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(13 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(14 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 15 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(6 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(9 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(10 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(11 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(12 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(13 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(14 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 15 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 16 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(6 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(9 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(10 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(11 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(12 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(13 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(14 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 16 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(8 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(9 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(10 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(13 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(8 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(9 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(10 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 19 + y, 0, 0, 0);

}

void Game::DrawFish(int x, int y)
{
	gfx.PutPixel(9 + x, 0 + y, 105, 61, 184);
	gfx.PutPixel(10 + x, 0 + y, 105, 61, 184);
	gfx.PutPixel(7 + x, 1 + y, 105, 60, 185);
	gfx.PutPixel(8 + x, 1 + y, 102, 58, 183);
	gfx.PutPixel(9 + x, 1 + y, 104, 59, 184);
	gfx.PutPixel(10 + x, 1 + y, 109, 65, 185);
	gfx.PutPixel(11 + x, 1 + y, 102, 57, 182);
	gfx.PutPixel(12 + x, 1 + y, 101, 56, 183);
	gfx.PutPixel(6 + x, 2 + y, 103, 56, 179);
	gfx.PutPixel(7 + x, 2 + y, 102, 57, 183);
	gfx.PutPixel(8 + x, 2 + y, 113, 71, 188);
	gfx.PutPixel(9 + x, 2 + y, 112, 69, 187);
	gfx.PutPixel(10 + x, 2 + y, 126, 87, 194);
	gfx.PutPixel(11 + x, 2 + y, 106, 63, 184);
	gfx.PutPixel(12 + x, 2 + y, 103, 58, 182);
	gfx.PutPixel(13 + x, 2 + y, 105, 61, 184);
	gfx.PutPixel(3 + x, 3 + y, 105, 61, 184);
	gfx.PutPixel(6 + x, 3 + y, 102, 57, 182);
	gfx.PutPixel(7 + x, 3 + y, 109, 67, 186);
	gfx.PutPixel(8 + x, 3 + y, 103, 58, 183);
	gfx.PutPixel(9 + x, 3 + y, 113, 71, 189);
	gfx.PutPixel(10 + x, 3 + y, 109, 65, 185);
	gfx.PutPixel(11 + x, 3 + y, 108, 64, 186);
	gfx.PutPixel(12 + x, 3 + y, 121, 81, 191);
	gfx.PutPixel(13 + x, 3 + y, 103, 58, 182);
	gfx.PutPixel(16 + x, 3 + y, 97, 60, 182);
	gfx.PutPixel(3 + x, 4 + y, 101, 56, 183);
	gfx.PutPixel(6 + x, 4 + y, 102, 58, 182);
	gfx.PutPixel(7 + x, 4 + y, 103, 58, 183);
	gfx.PutPixel(8 + x, 4 + y, 103, 58, 183);
	gfx.PutPixel(9 + x, 4 + y, 131, 95, 196);
	gfx.PutPixel(10 + x, 4 + y, 105, 60, 184);
	gfx.PutPixel(11 + x, 4 + y, 108, 64, 185);
	gfx.PutPixel(12 + x, 4 + y, 111, 67, 187);
	gfx.PutPixel(13 + x, 4 + y, 103, 58, 182);
	gfx.PutPixel(16 + x, 4 + y, 101, 57, 184);
	gfx.PutPixel(3 + x, 5 + y, 103, 57, 182);
	gfx.PutPixel(6 + x, 5 + y, 103, 58, 182);
	gfx.PutPixel(7 + x, 5 + y, 103, 58, 183);
	gfx.PutPixel(8 + x, 5 + y, 103, 58, 183);
	gfx.PutPixel(9 + x, 5 + y, 103, 58, 183);
	gfx.PutPixel(10 + x, 5 + y, 103, 58, 183);
	gfx.PutPixel(11 + x, 5 + y, 103, 58, 183);
	gfx.PutPixel(12 + x, 5 + y, 109, 65, 185);
	gfx.PutPixel(13 + x, 5 + y, 103, 57, 182);
	gfx.PutPixel(16 + x, 5 + y, 102, 57, 182);
	gfx.PutPixel(17 + x, 5 + y, 127, 63, 191);
	gfx.PutPixel(3 + x, 6 + y, 103, 57, 182);
	gfx.PutPixel(4 + x, 6 + y, 101, 58, 182);
	gfx.PutPixel(6 + x, 6 + y, 96, 56, 177);
	gfx.PutPixel(7 + x, 6 + y, 80, 47, 161);
	gfx.PutPixel(8 + x, 6 + y, 103, 58, 183);
	gfx.PutPixel(9 + x, 6 + y, 103, 58, 183);
	gfx.PutPixel(10 + x, 6 + y, 103, 58, 183);
	gfx.PutPixel(11 + x, 6 + y, 99, 56, 180);
	gfx.PutPixel(12 + x, 6 + y, 81, 47, 162);
	gfx.PutPixel(13 + x, 6 + y, 102, 59, 183);
	gfx.PutPixel(15 + x, 6 + y, 100, 54, 182);
	gfx.PutPixel(16 + x, 6 + y, 103, 57, 182);
	gfx.PutPixel(3 + x, 7 + y, 103, 60, 182);
	gfx.PutPixel(4 + x, 7 + y, 102, 57, 183);
	gfx.PutPixel(6 + x, 7 + y, 136, 97, 154);
	gfx.PutPixel(7 + x, 7 + y, 150, 127, 107);
	gfx.PutPixel(8 + x, 7 + y, 77, 45, 160);
	gfx.PutPixel(9 + x, 7 + y, 102, 58, 182);
	gfx.PutPixel(10 + x, 7 + y, 98, 55, 179);
	gfx.PutPixel(11 + x, 7 + y, 69, 40, 155);
	gfx.PutPixel(12 + x, 7 + y, 179, 158, 91);
	gfx.PutPixel(13 + x, 7 + y, 121, 79, 168);
	gfx.PutPixel(15 + x, 7 + y, 102, 58, 182);
	gfx.PutPixel(16 + x, 7 + y, 102, 58, 183);
	gfx.PutPixel(3 + x, 8 + y, 103, 58, 183);
	gfx.PutPixel(4 + x, 8 + y, 103, 58, 182);
	gfx.PutPixel(6 + x, 8 + y, 137, 99, 153);
	gfx.PutPixel(7 + x, 8 + y, 203, 189, 66);
	gfx.PutPixel(8 + x, 8 + y, 137, 110, 125);
	gfx.PutPixel(9 + x, 8 + y, 94, 53, 177);
	gfx.PutPixel(10 + x, 8 + y, 86, 49, 171);
	gfx.PutPixel(11 + x, 8 + y, 175, 151, 102);
	gfx.PutPixel(12 + x, 8 + y, 213, 194, 72);
	gfx.PutPixel(13 + x, 8 + y, 117, 77, 169);
	gfx.PutPixel(15 + x, 8 + y, 102, 58, 183);
	gfx.PutPixel(16 + x, 8 + y, 103, 58, 183);
	gfx.PutPixel(2 + x, 9 + y, 127, 63, 191);
	gfx.PutPixel(3 + x, 9 + y, 102, 58, 182);
	gfx.PutPixel(4 + x, 9 + y, 101, 58, 182);
	gfx.PutPixel(6 + x, 9 + y, 101, 54, 182);
	gfx.PutPixel(7 + x, 9 + y, 103, 58, 183);
	gfx.PutPixel(8 + x, 9 + y, 103, 58, 183);
	gfx.PutPixel(9 + x, 9 + y, 103, 58, 183);
	gfx.PutPixel(10 + x, 9 + y, 103, 58, 183);
	gfx.PutPixel(11 + x, 9 + y, 103, 58, 183);
	gfx.PutPixel(12 + x, 9 + y, 103, 58, 183);
	gfx.PutPixel(13 + x, 9 + y, 102, 55, 182);
	gfx.PutPixel(15 + x, 9 + y, 102, 58, 183);
	gfx.PutPixel(16 + x, 9 + y, 103, 57, 183);
	gfx.PutPixel(17 + x, 9 + y, 95, 63, 191);
	gfx.PutPixel(2 + x, 10 + y, 104, 58, 183);
	gfx.PutPixel(3 + x, 10 + y, 102, 58, 183);
	gfx.PutPixel(4 + x, 10 + y, 95, 63, 175);
	gfx.PutPixel(6 + x, 10 + y, 100, 61, 185);
	gfx.PutPixel(7 + x, 10 + y, 103, 58, 183);
	gfx.PutPixel(8 + x, 10 + y, 103, 58, 183);
	gfx.PutPixel(9 + x, 10 + y, 103, 58, 183);
	gfx.PutPixel(10 + x, 10 + y, 103, 58, 183);
	gfx.PutPixel(11 + x, 10 + y, 103, 58, 183);
	gfx.PutPixel(12 + x, 10 + y, 103, 58, 183);
	gfx.PutPixel(13 + x, 10 + y, 101, 56, 183);
	gfx.PutPixel(15 + x, 10 + y, 98, 58, 176);
	gfx.PutPixel(16 + x, 10 + y, 103, 58, 182);
	gfx.PutPixel(17 + x, 10 + y, 101, 58, 183);
	gfx.PutPixel(2 + x, 11 + y, 103, 58, 182);
	gfx.PutPixel(3 + x, 11 + y, 103, 58, 183);
	gfx.PutPixel(6 + x, 11 + y, 0, 0, 255);
	gfx.PutPixel(7 + x, 11 + y, 103, 58, 183);
	gfx.PutPixel(8 + x, 11 + y, 103, 58, 183);
	gfx.PutPixel(9 + x, 11 + y, 103, 58, 183);
	gfx.PutPixel(10 + x, 11 + y, 103, 58, 183);
	gfx.PutPixel(11 + x, 11 + y, 103, 58, 183);
	gfx.PutPixel(12 + x, 11 + y, 102, 57, 182);
	gfx.PutPixel(13 + x, 11 + y, 109, 72, 182);
	gfx.PutPixel(16 + x, 11 + y, 102, 57, 183);
	gfx.PutPixel(17 + x, 11 + y, 102, 58, 182);
	gfx.PutPixel(2 + x, 12 + y, 103, 57, 183);
	gfx.PutPixel(3 + x, 12 + y, 102, 57, 183);
	gfx.PutPixel(4 + x, 12 + y, 92, 46, 185);
	gfx.PutPixel(6 + x, 12 + y, 0, 0, 255);
	gfx.PutPixel(7 + x, 12 + y, 102, 58, 182);
	gfx.PutPixel(8 + x, 12 + y, 103, 58, 183);
	gfx.PutPixel(9 + x, 12 + y, 103, 58, 183);
	gfx.PutPixel(10 + x, 12 + y, 103, 58, 183);
	gfx.PutPixel(11 + x, 12 + y, 103, 58, 183);
	gfx.PutPixel(12 + x, 12 + y, 103, 58, 182);
	gfx.PutPixel(13 + x, 12 + y, 85, 85, 170);
	gfx.PutPixel(15 + x, 12 + y, 95, 63, 191);
	gfx.PutPixel(16 + x, 12 + y, 102, 58, 183);
	gfx.PutPixel(17 + x, 12 + y, 102, 57, 182);
	gfx.PutPixel(2 + x, 13 + y, 104, 58, 183);
	gfx.PutPixel(3 + x, 13 + y, 103, 58, 183);
	gfx.PutPixel(4 + x, 13 + y, 102, 58, 183);
	gfx.PutPixel(5 + x, 13 + y, 101, 58, 182);
	gfx.PutPixel(6 + x, 13 + y, 103, 58, 182);
	gfx.PutPixel(7 + x, 13 + y, 103, 58, 183);
	gfx.PutPixel(8 + x, 13 + y, 103, 58, 183);
	gfx.PutPixel(9 + x, 13 + y, 97, 54, 178);
	gfx.PutPixel(10 + x, 13 + y, 97, 55, 179);
	gfx.PutPixel(11 + x, 13 + y, 103, 58, 183);
	gfx.PutPixel(12 + x, 13 + y, 103, 58, 183);
	gfx.PutPixel(13 + x, 13 + y, 103, 58, 182);
	gfx.PutPixel(14 + x, 13 + y, 103, 58, 183);
	gfx.PutPixel(15 + x, 13 + y, 103, 58, 183);
	gfx.PutPixel(16 + x, 13 + y, 103, 58, 183);
	gfx.PutPixel(17 + x, 13 + y, 105, 60, 182);
	gfx.PutPixel(2 + x, 14 + y, 225, 120, 165);
	gfx.PutPixel(3 + x, 14 + y, 153, 82, 180);
	gfx.PutPixel(4 + x, 14 + y, 102, 58, 183);
	gfx.PutPixel(5 + x, 14 + y, 103, 58, 183);
	gfx.PutPixel(6 + x, 14 + y, 103, 58, 183);
	gfx.PutPixel(7 + x, 14 + y, 122, 67, 182);
	gfx.PutPixel(8 + x, 14 + y, 103, 58, 183);
	gfx.PutPixel(9 + x, 14 + y, 81, 46, 169);
	gfx.PutPixel(10 + x, 14 + y, 82, 46, 169);
	gfx.PutPixel(11 + x, 14 + y, 103, 58, 183);
	gfx.PutPixel(12 + x, 14 + y, 123, 67, 181);
	gfx.PutPixel(13 + x, 14 + y, 103, 58, 183);
	gfx.PutPixel(14 + x, 14 + y, 103, 58, 183);
	gfx.PutPixel(15 + x, 14 + y, 103, 58, 183);
	gfx.PutPixel(16 + x, 14 + y, 141, 76, 179);
	gfx.PutPixel(17 + x, 14 + y, 199, 110, 177);
	gfx.PutPixel(3 + x, 15 + y, 254, 131, 169);
	gfx.PutPixel(4 + x, 15 + y, 234, 118, 170);
	gfx.PutPixel(5 + x, 15 + y, 223, 113, 174);
	gfx.PutPixel(6 + x, 15 + y, 243, 121, 172);
	gfx.PutPixel(7 + x, 15 + y, 232, 117, 172);
	gfx.PutPixel(8 + x, 15 + y, 103, 58, 183);
	gfx.PutPixel(9 + x, 15 + y, 68, 37, 159);
	gfx.PutPixel(10 + x, 15 + y, 66, 36, 157);
	gfx.PutPixel(11 + x, 15 + y, 103, 58, 183);
	gfx.PutPixel(12 + x, 15 + y, 223, 113, 172);
	gfx.PutPixel(13 + x, 15 + y, 241, 121, 172);
	gfx.PutPixel(14 + x, 15 + y, 222, 113, 173);
	gfx.PutPixel(15 + x, 15 + y, 223, 113, 172);
	gfx.PutPixel(16 + x, 15 + y, 254, 132, 173);
	gfx.PutPixel(7 + x, 16 + y, 102, 57, 183);
	gfx.PutPixel(8 + x, 16 + y, 93, 53, 176);
	gfx.PutPixel(9 + x, 16 + y, 68, 38, 158);
	gfx.PutPixel(10 + x, 16 + y, 63, 36, 155);
	gfx.PutPixel(11 + x, 16 + y, 96, 54, 178);
	gfx.PutPixel(12 + x, 16 + y, 102, 58, 183);
	gfx.PutPixel(6 + x, 17 + y, 103, 58, 182);
	gfx.PutPixel(7 + x, 17 + y, 100, 56, 181);
	gfx.PutPixel(8 + x, 17 + y, 71, 40, 162);
	gfx.PutPixel(9 + x, 17 + y, 85, 51, 153);
	gfx.PutPixel(10 + x, 17 + y, 56, 28, 155);
	gfx.PutPixel(11 + x, 17 + y, 70, 39, 161);
	gfx.PutPixel(12 + x, 17 + y, 101, 56, 181);
	gfx.PutPixel(13 + x, 17 + y, 103, 56, 182);
	gfx.PutPixel(3 + x, 18 + y, 127, 0, 127);
	gfx.PutPixel(4 + x, 18 + y, 104, 59, 182);
	gfx.PutPixel(5 + x, 18 + y, 102, 57, 183);
	gfx.PutPixel(6 + x, 18 + y, 99, 55, 180);
	gfx.PutPixel(7 + x, 18 + y, 85, 47, 171);
	gfx.PutPixel(8 + x, 18 + y, 51, 51, 153);
	gfx.PutPixel(11 + x, 18 + y, 72, 36, 145);
	gfx.PutPixel(12 + x, 18 + y, 84, 46, 170);
	gfx.PutPixel(13 + x, 18 + y, 102, 58, 183);
	gfx.PutPixel(14 + x, 18 + y, 103, 57, 183);
	gfx.PutPixel(15 + x, 18 + y, 102, 59, 182);
	gfx.PutPixel(16 + x, 18 + y, 85, 85, 170);

}


void Game::ComposeFrame()
{
	DrawFace(dude.x, dude.y);
	if (!fish0.isEatean)
	{
		DrawFish(fish0.x, fish0.y);
	}

	if (!fish1.isEatean)
	{
		DrawFish(fish1.x, fish1.y);
	}

	if (!fish2.isEatean)
	{
		DrawFish(fish2.x, fish2.y);
	}
}
