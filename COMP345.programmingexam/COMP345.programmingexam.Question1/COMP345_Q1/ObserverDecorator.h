#include "DigitalClockObserver.h"
class ObserverDecorator : public DigitalClockObserver
{

public:
	DigitalClockObserver* dCO;
	ObserverDecorator();
	ObserverDecorator(DigitalClockObserver* ob);
	virtual void Update();
};

class MinutesDecorator : public ObserverDecorator
{
public:
	MinutesDecorator(DigitalClockObserver* ob);
	void Update();
};

class HoursDecorator : public ObserverDecorator
{
public:
	HoursDecorator(DigitalClockObserver* ob);
	void Update();
};