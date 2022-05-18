#include <iostream>
#include <gtkmm.h>

#include "ui/MainWindow.h"

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "com.github.asuka1975.HyperWorld-Markup-Language-Engine");
    hwml_engine::ui::MainWindow win;

    return app->run(win);
}