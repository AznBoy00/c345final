#include "ClockTimer.h"
#include "DigitalClockObserver.h"
#include <iostream>
#include"ObserverDecorator.h"
using namespace std;

int main() {
	//Create a ClockTimer to be observed
	ClockTimer *timer = new ClockTimer;

	//Create a DigitalClock that is connected to the ClockTimer  
	DigitalClockObserver *digitalClock = new DigitalClockObserver(timer);
	digitalClock = new MinutesDecorator(digitalClock);
	digitalClock = new HoursDecorator(digitalClock);

	//Advancing the ClockTimer updates the DigitalClock
	//as Tick() calls Update() after it changed its state
	int secs;
	cout << "Enter number of seconds to count: ";
	cin >> secs;
	timer->start(secs);

	int j;  cin >> j;

	return 0;
}
