#include <gtkmm.h>
#include "ExtremeDiscWindow.hpp"

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.example.discburner");
    ExtremeDiscWindow window;
    return app->run(window);
}
