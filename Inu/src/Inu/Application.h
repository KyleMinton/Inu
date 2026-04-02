#pragma once
#include"../inupch.h"

#include"Core.h"
#include "Events/Event.h"
namespace Inu {

	class INU_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();

}
