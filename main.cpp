#include <CtrlLib/CtrlLib.h>
using namespace Upp;

struct ExtremeDisc : TopWindow {
    MenuBar menu;
   
    void FileMenu(Bar& bar) {
       bar.Add("Project", [=] { PromptOK(""); });
       bar.Add("Open Project...", [=] { PromptOK(""); });
       bar.Add("Save Project / Save Project As...", [=] { PromptOK(""); });
       bar.Add("Import Files / Folders", [=] { PromptOK(""); });
       bar.Add("Load Disc", [=] { PromptOK(""); });
       bar.Add("Exit", [=] { Exit(); });
   }
   
   void EditMenu(Bar& bar) {
       bar.Add("Add Files...", [=] { PromptOK(""); });
       bar.Add("Add Folder...", [=] { PromptOK(""); });
       bar.Add("Remove Selected", [=] { PromptOK(""); });
       bar.Add("Clear Project", [=] { PromptOK(""); });
       bar.Add("Rename Disc Label", [=] { PromptOK(""); });
       bar.Add("Preferences", [=] { PromptOK(""); });
   }
   
   void ViewMenu(Bar& bar) {
       bar.Add("Project Overview", [=] { PromptOK(""); });
       bar.Add("File List", [=] { PromptOK(""); });
       bar.Add("Burning Progress", [=] { PromptOK(""); });
       bar.Add("Disc Info / Drive Info", [=] { PromptOK(""); });
       bar.Add("Log / Console", [=] { PromptOK(""); });
       bar.Add("Theme / Appearance", [=] { PromptOK(""); });
   }
   
   void BurnMenu(Bar& bar) {
       bar.Add("Start Burn", [=] { PromptOK(""); });
       bar.Add("Burn ISO Image", [=] { PromptOK(""); });
       bar.Add("Create ISO from Project", [=] { PromptOK(""); });
       bar.Add("Verify Disc After Burning", [=] { PromptOK(""); });
       bar.Add("Erase Rewritable Disc", [=] { PromptOK(""); });
       bar.Add("Simulate Burn", [=] { PromptOK(""); });
   }
   
   void ToolsMenu(Bar& bar) {
       bar.Add("Create Audio CD from Tracks", [=] { PromptOK(""); });
       bar.Add("Rip Disc", [=] { PromptOK(""); });
       bar.Add("Copy Disc", [=] { PromptOK(""); });
       bar.Add("Convert Files (e.g. MP3 → WAV)", [=] { PromptOK(""); });
       bar.Add("Disc Info (Capacity, Type, Sessions)", [=] { PromptOK(""); });
       bar.Add("Drive Info (Firmware, Speed Capabillties)", [=] { PromptOK(""); });   
   }
   
   void HelpMenu(Bar& bar) {
       bar.Add("User Manual / Help Contents", [=] { PromptOK(""); });
       bar.Add("Check for Updates", [=] { PromptOK(""); });
       bar.Add("Report a Bug", [=] { PromptOK(""); });
       bar.Add("About", [=] { PromptOK(""); });
   }
   
   void MainMenu(Bar& bar) {
       bar.Sub("File", [=](Bar& bar) { FileMenu(bar); });
       bar.Sub("Edit", [=](Bar& bar) { EditMenu(bar); });
       bar.Sub("View", [=](Bar& bar) { ViewMenu(bar); });
       bar.Sub("Burn", [=](Bar& bar) { BurnMenu(bar); });
       bar.Sub("Tools", [=](Bar& bar) { ToolsMenu(bar); });
       bar.Sub("Help", [=](Bar& bar) { HelpMenu(bar); });
   }
   
   ExtremeDisc() {
       Title("ExtremeDisc").Sizeable().MinimizeBox().MaximizeBox();
       AddFrame(menu);
       menu.Set([=](Bar& bar) { MainMenu(bar); });
   }
   
};
   
GUI_APP_MAIN
{
	ExtremeDisc app;
	app.Run();
}
