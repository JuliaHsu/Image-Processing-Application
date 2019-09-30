#include "MyForm.h"

using namespace hw1; 
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// 建立任何控制項之前，先啟用 Windows XP 視覺化效果
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	// 建立主視窗並執行
	Application::Run(gcnew MyForm());
	return 0;
}