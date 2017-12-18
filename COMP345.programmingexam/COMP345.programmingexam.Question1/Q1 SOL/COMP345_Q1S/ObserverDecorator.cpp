#include"ObserverDecorator.h"
#include"Subject.h"
#include<iostream>
using namespace std;

ObserverDecorator::ObserverDecorator(DigitalClockObserver* ob)
{
	dCO = ob;
}
void ObserverDecorator::Update()
{
	dCO->Update();
}

MinutesDecorator::MinutesDecorator(DigitalClockObserver* ob) :ObserverDecorator(ob)
{
	_subject =ob->_subject;
	_subject->Attach(this);
}

void MinutesDecorator::Update()
{
	cout << _subject->getMinute() << " minutes ";
}

HoursDecorator::HoursDecorator(DigitalClockObserver* ob) :ObserverDecorator(ob)
{
	_subject = (ob->_subject);
	_subject->Attach(this);
}

void HoursDecorator::Update()
{
	cout << _subject->getHour() << " hours \n";
}