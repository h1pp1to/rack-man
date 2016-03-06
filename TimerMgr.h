#pragma once

#include <map>
using std::map;

//Base Class
class TimerMgr
{
public:
	virtual void OnTick(int Id, int times) = 0;
};

class TickMgr
{
private:
	struct client
	{
		TimerMgr* clientClass;
		int currentTick;
		int tickPeriod;
		int nTimes;
		
		client(){}
		client(TimerMgr* derived, int period) :
			clientClass(derived), tickPeriod(period), 
			nTimes(0), currentTick(0) {}
	};

	map<int, client> m_ClientContainer;

	TickMgr() = default;
	TickMgr(const TickMgr&) = delete;
	TickMgr& operator=(const TickMgr&) = delete;
	~TickMgr(){}

public:
	static TickMgr& Instance()
	{
		static TickMgr *Instance = new TickMgr;
		return *Instance;
	}

	void StartTimer(TimerMgr* clientClass, int id, int tickPeriod);
	void StopTimer(int id);
	bool IsClientAcive(int id);

	void Process();
};



