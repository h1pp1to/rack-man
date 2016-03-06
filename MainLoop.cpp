#include "MainLoop.h"


MainLoop::MainLoop(){}
MainLoop::~MainLoop(){}


void MainLoop::Process()
{
	TickMgr::Instance().Process();
}