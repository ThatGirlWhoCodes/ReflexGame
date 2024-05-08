// PROG220-FinalProj-RelfexGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "reflexGame.h"
#include "Game.h"
#include "Player.h"
#include "Timer.h"

using namespace std;

int main()
{
	cout << "-----------------------------------------------------Reflex Game-----------------------------------------------------\n";
	this_thread::sleep_for(chrono::seconds(5));


	string playerName;
	cout << "Enter player name: ";
	cin >> playerName;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Welcome " << playerName << " to Reflex Game!" << endl;
	cout << "Loading" << endl;
	this_thread::sleep_for(chrono::seconds(1));

	reflexGame game(playerName);
	game.play();

	return 0;
}