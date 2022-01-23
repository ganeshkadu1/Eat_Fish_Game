#pragma once
class Fish
{
public:
	int x;
	int y;
	int vx= 1;
	int vy= 1;
	static constexpr int width = 20;
	static constexpr int height = 20;
	bool isEatean = false;

public:
	void Update();
	bool IsColliding(int dudex, int dudey, int dudeWidth, int dudeHeight);
};

