/* 目前的代码多为测试用 */



#include "students.h"
#include "passwordcheck.h"
#include "somepieces.h"


students x;										//如果定义在main内部会栈溢出


int main()
{
	system("mode con cols=100 lines=30");		//设定窗口大小
	//passwordcheck("613613613");				//密码验证
	FILE *studenttxt = openfile();				//打开student.txt文件


	x.inputFromFile(studenttxt);
	x.outPutToScreen();

	system("pause");
	
	return 0;
}