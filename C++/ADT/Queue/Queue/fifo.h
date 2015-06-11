#include "simulator.h"
#include <string>
#include <fstream>

class fifo : public simulator
{
private:
	int currentTime;
	event curEvent;
	int endOfCurEvent;
	int latency;
	queue<event> waitingQueue;
public:
	fifo(int seconds_per_page);
	void serviceWaitingQueue(ofstream& strm);
	void simulator::simulate(string file);
};