#include "MyForm.h"
#include "Functions.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Practice::MyForm form;
	Application::Run(% form);
}
System::Void Practice::MyForm::Step_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ str;
	str += textBox1->Text->ToString();
	std::string temp = Stos(str);
	std::ofstream File(FILE, std::ios::out);
	File << temp;
	textBox1->Clear();
	File.close();
}
