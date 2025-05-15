#pragma once

#include <gtkmm.h>

class ExtremeDiscWindow : public Gtk::Window {
public:
    DiscBurnerWindow();

protected:
    void on_button_select_clicked();
    void on_button_burn_clicked();

    Gtk::Box vbox_main;
    Gtk::FileChooserButton file_chooser;
    Gtk::Button button_burn, button_select;
    Gtk::Label label_status;

    Glib::ustring selected_path;
};
