#include "fifo.h"
#include <fstream>

fifo::fifo(int seconds_per_page) : simulator(seconds_per_page)
{
	currentTime = 0;
	latency = 0;
}

void fifo::serviceWaitingQueue(ofstream& fileOut)
{
	curEvent = waitingQueue.front();
	endOfCurEvent = seconds_per_page * curEvent.getjob().getnumpages() + currentTime;
	fileOut << "\tServicing: " << curEvent.getjob() << " at " << currentTime << " seconds\n";
	latency = latency + currentTime - curEvent.arrival_time();
	waitingQueue.pop();
}

void fifo::simulate(string file)
{
	loadworkload(file);
	int totalJobs = workload.size();
	ofstream fileOut(file + ".out");
	fileOut << "FIFO Simulator\n\n";
	bool curEventExist = false;
	while (true)
	{
		while (!workload.empty() && workload.front().arrival_time() == currentTime)
		{
			fileOut << "\tArriving: " << workload.front().getjob() << " at " << currentTime << " seconds\n";
			waitingQueue.push(workload.front());
			workload.pop();
		}

		if (curEventExist == true)
		{
			if (endOfCurEvent == currentTime)
			{
				if (!waitingQueue.empty())
					serviceWaitingQueue(fileOut);
				else
					curEventExist = false;
			}
		}
		else
		{
			if (!waitingQueue.empty())
			{
				serviceWaitingQueue(fileOut);
				curEventExist = true;
			}
		}

		if (waitingQueue.empty() && workload.empty())
			break;

		++currentTime;
	}

	fileOut << "\n\tTotal jobs: " << totalJobs << endl;
	fileOut << "\tAggregate latency: " << latency << " seconds\n";
	fileOut << "\tMean latency: " << (double)latency / totalJobs << " seconds\n";
	fileOut.close();
}