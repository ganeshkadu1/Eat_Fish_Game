#pragma once
class Dude
{
public:
	int x = 200;
	int y = 200;
	int vx= 1;
	int vy= 1;
	bool inhibitUp = false;
	bool inhibitDown = false;
	bool inhibitLeft = false;
	bool inhibitRight = false;
	static constexpr int width = 20;
	static constexpr int height = 20;
public:
	void Update();
};

