#include "DigitalClockObserver.h"
#include "ClockTimer.h"
#include <iostream>
#include <string>
using namespace std;

DigitalClockObserver::DigitalClockObserver(){
};
DigitalClockObserver::DigitalClockObserver(ClockTimer* s){
  //Upon instantiation, attaches itself to a ClockTimer
  _subject = s;
  _subject->Attach(this);
};
DigitalClockObserver::~DigitalClockObserver(){
  //Upon destruction, detaches itself from its ClockTimer      
  _subject->Detach(this);
};
void DigitalClockObserver::Update(){
  display();
}; 
void DigitalClockObserver::display(){
	cout << constructDisplayString() << endl;
};
string DigitalClockObserver::constructDisplayString(){
	string toDisplay; 
	toDisplay = std::to_string(_subject->getSecond()) + " seconds ";
	return (toDisplay); 
}
