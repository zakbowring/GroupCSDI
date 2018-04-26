#include "EntryForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GroupCSDI::EntryForm form;
	Application::Run(%form);
	//This is a GitHub Repo Test....Ignore this comment.
	//testing
}