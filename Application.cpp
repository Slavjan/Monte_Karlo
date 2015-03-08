#include "Application.h"

// publice
Application::Application()
{
	Space = 0;
	testing = nullptr;
	control = nullptr;
}


Application::~Application()
{
	delete[] testing;
	delete[] control;
}



// /public

// private
void Application::generateShape()
{
}

// /private

