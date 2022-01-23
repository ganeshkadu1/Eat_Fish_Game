#include "Fish.h"
#include "Graphics.h"
#include "Graphics.h"

void Fish::Update()
{
	x += vx;
	y += vy;

	const int right = x + width;
	if (x < 0)
	{
		x = 0;
		vx = -vx;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		x = (Graphics::ScreenWidth - 1) - width;
		vx = -vx;
	}

	const int bottom = y + height;
	if (y < 0)
	{
		y = 0;
		vy = -vy;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - 1) - height;
		vy = -vy;
	}

}

bool Fish::IsColliding(int dudex, int dudey, int dudeWidth, int dudeHeight)
{
	const int duderight = dudex + dudeWidth;
	const int dudebottom = dudey + dudeHeight;
	const int fishright = x + width;
	const int fishbottom = y + height;

	return
		duderight >= x &&
		dudex <= fishright &&
		dudebottom >= y &&
		dudey <= fishbottom;
}

