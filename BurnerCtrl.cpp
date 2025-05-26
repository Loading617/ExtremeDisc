#include "BurnerCtrl.h"

BurnerCtrl::BurnerCtrl() {
    Title("ExtremeDisc").Sizeable();

    Add(file_list.SizePos());
    file_list.AddColumn("Files to Burn");

    Add(add_button.LeftPosZ(10, 80).BottomPosZ(10, 25));
    add_button.SetLabel("Add Files");
    add_button << [=] { AddFiles(); };

    Add(clear_button.LeftPosZ(100, 80).BottomPosZ(10, 25));
    clear_button.SetLabel("Clear");
    clear_button << [=] { ClearFiles(); };

    Add(burn_button.RightPosZ(10, 80).BottomPosZ(10, 25));
    burn_button.SetLabel("Burn");
    burn_button << [=] { BurnDisc(); };
}

void BurnerCtrl::AddFiles() {
    if(file_selector.ExecuteOpen()) {
        for (const auto& f : file_selector.GetFiles())
            file_list.Add(f);
    }
}

void BurnerCtrl::ClearFiles() {
    file_list.Clear();
}

void BurnerCtrl::BurnDisc() {
    if(file_list.GetCount() == 0) {
        PromptOK("No files selected.");
        return;
    }

    // Temporary ISO path
    String iso_path = GetTempFileName() + ".iso";

    // Create ISO command
    String mkisofs_cmd = "mkisofs -o " + iso_path;
    for(int i = 0; i < file_list.GetCount(); i++) {
        mkisofs_cmd << " \"" << file_list.Get(i, 0) << "\"";
    }

    RunCommand(mkisofs_cmd);

    // Burn to disc
    String burn_cmd = "cdrecord -v dev=/dev/cdrom " + iso_path;
    RunCommand(burn_cmd);

    PromptOK("Burn process completed.");
}

void BurnerCtrl::RunCommand(const String& cmd) {
    String output = Sys(cmd);
    PromptOK("Command executed:\n" + cmd + "\n\nOutput:\n" + output);
}
