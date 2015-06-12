#include "students.h"


students::students(void)
{
}


students::~students(void)
{
}


void students::inputFromFile(FILE* filename)
{
	for (int i = 0; i < 10000; i++)
		Students[i].inputfromfile(filename);
	//Students[0].inputfromfile(filename);
}

void students::outPutToScreen()
{
	for (int i = 0; i < 10000; i++)
	{
		if (Students[i].old == -1)
			break;
		else
			Students[i].outputtoscreen();
	}
	//Students[0].outputtoscreen();
}

void students::outPutToFile(FILE* filename)					//wyh
{

}

int students::findStudentByStdnum(char stdnum[20])				//按学号查找，返回在数组中的下标
{

	return 0;
}
void students::deleteStudentByStdnum(char stdnum[20])				//按学号删除（把old赋值为1）
{

}

void students::sortByGPA()										//将数组按GPA排序,使用stl的sort函数，否则手动写快速排序
{

}

int students::addStudent()										//添加学生,还没完成   ly
{
	int blank = -1;
	//找到第一个old为-1的位置
	for (int i = 0; i < 10000; i++)
		if (Students[i].old == -1)
		{
			blank = i;
			break;
		}
	if (blank == -1)
	{
		printf("存储空间已满");
		return -1;
	}
	else
	{
		printf("请输入姓名：");
		scanf("%s", Students[blank].name);

		printf("添加成功！");
		return 0;
	}
}