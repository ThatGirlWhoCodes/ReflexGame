#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

//Timer class - manages item intervals

class Timer
{
private:
	chrono::steady_clock::time_point start;
	chrono::steady_clock::time_point end;

public:
	void startTimer() {
		start = chrono::steady_clock::now();
	}
	void stopTimer() {
		end = chrono::steady_clock::now();
	}
	double getDuration() const {
		return chrono::duration_cast<chrono::milliseconds>(end - start).count()/1000;
	}

};

