#include "ExtremeDiscWindow.hpp"
#include <iostream>
#include <cstdlib>

ExtremeDiscWindow::ExtremeDiscWindow()
: file_chooser("Select ISO File"),
  button_burn("Burn Disc"),
  button_select("Choose File") {
    set_title("ExtremeDisc");
    set_default_size(400, 150);

    vbox_main.set_orientation(Gtk::ORIENTATION_VERTICAL);
    add(vbox_main);

    vbox_main.pack_start(file_chooser, Gtk::PACK_SHRINK);
    vbox_main.pack_start(button_burn, Gtk::PACK_SHRINK);
    vbox_main.pack_start(label_status, Gtk::PACK_SHRINK);

    button_burn.signal_clicked().connect(sigc::mem_fun(*this, &ExtremeDiscWindow::on_button_burn_clicked));
    file_chooser.signal_file_set().connect(sigc::mem_fun(*this, &ExtremeDiscWindow::on_button_select_clicked));

    show_all_children();
}

void ExtremeDiscWindow::on_button_select_clicked() {
    selected_path = file_chooser.get_filename();
    label_status.set_text("Selected: " + selected_path);
}

void ExtremeDiscWindow::on_button_burn_clicked() {
    if (selected_path.empty()) {
        label_status.set_text("Please select a file first.");
        return;
    }

    label_status.set_text("Burning...");
    std::string cmd = "wodim -v dev=/dev/cdrw " + selected_path;
    int result = std::system(cmd.c_str());

    if (result == 0)
        label_status.set_text("Burn completed successfully.");
    else
        label_status.set_text("Burn failed. Check the console.");
}
