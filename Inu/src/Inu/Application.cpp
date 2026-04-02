#include"inupch.h"

#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Inu {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		INU_TRACE(e);

		while (true);
	}
}