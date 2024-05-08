#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <thread>

#include "Game.h"
#include "Player.h"
#include "Timer.h"

using namespace std;


/// <summary>
/// Reflex game class derives from game
/// </summary>

class reflexGame : public Game
{
private:
	Player player;
	Timer timer;
	//list of random words for game
	vector<string> words = { "unicorn", "adventure", "sun", "flamingo", "box", "bubble", "treasure"};

public:
	reflexGame(const string& playerName) : player(playerName) {}

	void play() override {

		//introduction and instructions
		cout << "Instructions: Type the word shown as quickly as you can after it appears." << endl;
		cout << "You will have 2-3 seconds to respond once the word is displayed." << endl;
		cout << "Type 'exit' to leave at any time." << endl;
		this_thread::sleep_for(chrono::seconds(1));
		cout << "Are you ready to start ? (type 'yes' to start)." << endl;

		//capturing input from user before starting the game, if they reply 'no' then the game will quit
		string readyResponse;
		cin >> readyResponse;
		
		if (readyResponse == "yes" || readyResponse == "y")
		{
			//game loop starts here
			while (true)
			{
				//random number generator
				random_device rd;
				mt19937 gen(rd());
				//between 5 and 10 seconds
				uniform_int_distribution<> dis(5, 10);
				//index selection
				uniform_int_distribution<> word_index(0, words.size() - 1);

				//random delay generator
				int delay = dis(gen);
				cout << "Get ready... Waiting for " << delay << " seconds!\n";
				this_thread::sleep_for(chrono::seconds(delay));

				//random word is selected from words list
				string selectedWord = words[word_index(gen)];
				cout << "Type this word: " << selectedWord << endl;

				//timer starts 
				timer.startTimer(); 
				string userInput;
				//console gets user input 
				cin >> userInput;
				//timer stops and records user time
				timer.stopTimer();

				//check if user would like to exit game
				if (userInput == "exit")
				{
					cout << "Exiting game... Final Score: " << player.getScore() << endl;
					//end of game loop if user leaves
					break;
				}
				//how long it took to respond 
				double responseTime = timer.getDuration();
				if (userInput == selectedWord && responseTime <= 3)
				{
					cout << "Success! You responded in " << responseTime << " seconds. Congratulations, you are freaky fast!" << endl;
					player.setScore(player.getScore() + 1);
				}
				else
				{
					cout << "Oh no... You failed. Either the wrong input or slow response (Time: " << responseTime << " seconds)." << endl;
				}
			}
		}
		else
		{
			cout << "Game preparing to exit... Come back when you are ready.";
		}
	}
};

