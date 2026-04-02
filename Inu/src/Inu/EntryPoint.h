#pragma once

#ifdef INU_PLATFORM_WINDOWS

extern Inu::Application* Inu::CreateApplication();

int main(int argc, char** argv)
{
	Inu::Log::Init();
	INU_CORE_WARN("Initialized Log!");
	int a = 5;
	INU_INFO("Hello! Var={0}", a);

	auto app = Inu::CreateApplication();
	app->Run();
	delete app;
}

#endif