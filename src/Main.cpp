#include "window/Window.h"

#include "Settings.h"
#include "fonts/roboto.h"

int main() {
    Settings::font.loadFromMemory(roboto_data, roboto_size);

    Window window;
    window.startRenderLoop();

    return 0;
}