#include "Core/Application.h"

int main()
{
    Core::ApplicationSpecification appSpec;
    appSpec.Name = "OpenGL";
    appSpec.WindowSpec.Width = 1280;
    appSpec.WindowSpec.Height = 720;

    Core::Application app(appSpec);
    app.Run();
}
