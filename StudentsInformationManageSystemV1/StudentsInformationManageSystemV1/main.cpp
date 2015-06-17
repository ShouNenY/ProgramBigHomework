#include "students.h"
#include "passwordcheck.h"
#include "somepieces.h"


students x;										//如果定义在main内部会栈溢出


int main()
{
	system("mode con cols=120");				//设定窗口大小
	//passwordcheck("613613613");				//密码验证
	FILE *studenttxt = openfile();				//打开student.txt文件
	x.inputFromFile(studenttxt);				//txt储存信息读入内存
	printinstructions();						//打印操作提示信息


	char cmd[100];								//接受模式选择命令
	while (scanf("%s", cmd))
	{
		if (strcmp(cmd, "0") == 0) break;
		else if (strcmp(cmd, "1") == 0)			//添加学生，添加完学生立刻更新txt以防信息丢失
		{
			x.addStudent();
				x.outPutToFile(studenttxt);			
		}
		else if (strcmp(cmd, "2") == 0)			//查看单个学生
		{
			x.outPutToScreenByStdnum();
		}
		else if (strcmp(cmd, "3") == 0)			//输出所有学生所有信息到屏幕
		{
			printf("按照什么顺序排序？\n");
			printf(("0——默认顺序 1——按学号排序 2——GPA顺序\n"));
			int flag;
			scanf("%d", &flag);
			if (flag == 1)
				x.sortByStdnum();
			else if (flag == 2)
				x.sortByGPA();
			x.outPutToScreen();
		}
		else if (strcmp(cmd, "4") == 0)			//输出基本信息到屏幕
		{
			printf("按照什么顺序排序？\n");
			printf(("0——默认顺序 1——按学号排序 2——GPA顺序\n"));
			int flag;
			scanf("%d", &flag);
			if (flag == 1)
				x.sortByStdnum();
			else if (flag == 2)
				x.sortByGPA();
			x.outputBaseInformatioonToScreen();
		}
		else if (strcmp(cmd, "5") == 0)			//输出成绩到屏幕
		{
			printf("按照什么顺序排序？\n");
			printf(("0——默认顺序 1——按学号排序 2——GPA顺序\n"));
			int flag;
			scanf("%d", &flag);
			if (flag == 1)
				x.sortByStdnum();
			else if (flag == 2)
				x.sortByGPA();
			x.outPutScoresToScreen();
		}
		else if (strcmp(cmd, "6") == 0)			//输出体测结果到屏幕
		{
			printf("按照什么顺序排序？\n");
			printf(("0——默认顺序 1——按学号排序 2——GPA顺序\n"));
			int flag;
			scanf("%d", &flag);
			if (flag == 1)
				x.sortByStdnum();
			else if (flag == 2)
				x.sortByGPA();
			x.outPutSportsmarkToScreen();
		}
		else if (strcmp(cmd, "7") == 0)			//改
		{
			x.changeStudent();
		}
		else if (strcmp(cmd, "8") == 0)			//删
		{
			x.deleteStudentByStdnum();
		}
		else if (strcmp(cmd, "9") == 0)			//清空
		{
			x.empty();
		}

		system("PAUSE");
		printf("\n");
		printinstructions();					//每次做完一个操作都再输出一次提示信息
	}
	
	x.outPutToFile(studenttxt);					//输出到文件保存信息
	fclose(studenttxt);							//关闭文件
	return 0;
}