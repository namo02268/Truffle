#include "Core/Application/Application.h"

int main() {
	OPENGL_TEST::Application::Create();
	OPENGL_TEST::Application::GetInstance().Run();
	OPENGL_TEST::Application::Destroy();

  return 0;
}
