#include "Core/Application/Application.h"

int main()
{
	TRUFFLE::Application::Create();
	TRUFFLE::Application::GetInstance().Run();
	TRUFFLE::Application::Destroy();

	return 0;
}
