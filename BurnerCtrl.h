#ifndef _ExtremeDisc_BurnerCtrl_h_
#define _ExtremeDisc_BurnerCtrl_h_

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

class BurnerCtrl : public TopWindow {

public:
    BurnerCtrl();

private:
    FileSel file_selector;
    ArrayCtrl file_list;
    Button add_button, burn_button, clear_button;
    String iso_path;

    void AddFiles();
    void ClearFiles();
    void BurnDisc();
    void RunCommand(const String& cmd);
};

#endif
