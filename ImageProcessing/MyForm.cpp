#include "MyForm.h"

using namespace hw1; 
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �إߥ��󱱨���e�A���ҥ� Windows XP ��ı�ƮĪG
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	// �إߥD�����ð���
	Application::Run(gcnew MyForm());
	return 0;
}