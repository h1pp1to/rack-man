#include "TimerMgr.h"

void TickMgr::StartTimer(TimerMgr* clientClass, int id, int tickPeriod)
{
	//TODO - Same id - error handler
	m_ClientContainer[id] = client(clientClass, tickPeriod);
}

void TickMgr::StopTimer(int id)
{
	m_ClientContainer.erase(id);
}

bool TickMgr::IsClientAcive(int id)
{
	return (m_ClientContainer.find(id) != m_ClientContainer.end());
}

void TickMgr::Process()
{
	for (auto &it : m_ClientContainer)
	{
		if (++(it.second.currentTick) == it.second.tickPeriod)
		{
			it.second.clientClass->OnTick(it.first, ++(it.second.nTimes));
			it.second.currentTick = 0;
		}
	}
}