#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
using namespace std;

//Player class = manages player details

class Player
{
private:
	string name;
	int score;

public:
	Player(const string& name = "Guest") : name(name), score(0) {}

	//getting users name before playing
	string getName() const { return name; }
	void setName(const string& n) { name = n; }
	
	//getting & displaying score before closing
	int getScore() const { return score; }
	void setScore(int s) { score = s; }

};

