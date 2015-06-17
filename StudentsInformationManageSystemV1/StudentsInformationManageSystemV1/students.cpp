#include "students.h"


students::students(void)
{
}


students::~students(void)
{
}


void students::inputFromFile(FILE* filename)
{
	for (int i = 0; i < MAXN; i++)
		Students[i].inputfromfile(filename);
	//Students[0].inputfromfile(filename);
}

void students::outputBaseInformatioonToScreen()								//输出基本信息到屏幕
{
	printf("\n所有学生基本信息：\n\n");
	for (int i = 0; i < MAXN; i++)
	{
		if (Students[i].old == -1)
			continue;
		else
			Students[i].outputBaseInformatioonToScreen();
	}
}

void students::outPutScoresToScreen()							//输出成绩到屏幕		
{
	printf("\n所有学生考试成绩：\n\n");
	for (int p = 0; p < MAXN; p++)
	{
		if (Students[p].old == -1)
			continue;
		else
		{
			//输出4个字姓名，超出不输出
			for (int i = 0; i < 8; i = i + 2)
			{
				if (Students[p].name[i] == '\0' || Students[p].name[i + 1] == '\0')
				{
					for (int k = 0; k < (8 - i) / 2; k++)
						printf("  ");
					break;
				}
				else
					printf("%c%c", Students[p].name[i], Students[p].name[i + 1]);
			}
			printf("\n");
			Students[p].outPutScoresToScreen();
		}
	}
}

void students::outPutSportsmarkToScreen()						//输出体测结果到屏幕
{
	printf("\n所有学生体测结果：\n\n");
	for (int p = 0; p < MAXN; p++)
	{
		if (Students[p].old == -1)
			continue;
		else
		{
			//输出4个字姓名，超出不输出
			for (int i = 0; i < 8; i = i + 2)
			{
				if (Students[p].name[i] == '\0' || Students[p].name[i + 1] == '\0')
				{
					for (int k = 0; k < (8 - i) / 2; k++)
						printf("  ");
					break;
				}
				else
					printf("%c%c", Students[p].name[i], Students[p].name[i + 1]);
			}
			printf(" ");


			if (Students[p].sexi == 1)
				printf("男\n");
			else if (Students[p].sexi == 0)
				printf("女\n");
			Students[p].outPutSportsmarkToScreen();
		}
	}
}

void students::outPutToScreen()									//输出所有信息到屏幕				ly
{
	printf("\n所有学生：\n\n");
	for (int i = 0; i < MAXN; i++)
	{
		if (Students[i].old == -1)
			continue;
		else
			Students[i].outputtoscreen();
	}
}

void students::outPutToScreenByStdnum()							//按学号输出单个学生信息				ly
{
	printf("请输入学号：");
	char stdnum[20];
	scanf("%s", stdnum);
	int i = findStudentByStdnum(stdnum);
	if (i != -1)
		Students[i].outputtoscreen();
	else
		printf("没有此学生！\n");
}

void students::outPutToFile(FILE* filename)					//输出到文件			wyh
{
	filename = fopen("student.dd", "w");
	for (int i = 0; i < MAXN; i++)
	{
		if (Students[i].old == -1)
			continue;
		else
			Students[i].outputtofile(filename);

	}

}

int students::findStudentByStdnum(char stdnum[20])				//按学号查找，返回在数组中的下标  yzy
{
	for (int i = 0; i < MAXN; i++)
	{
		if (strcmp(Students[i].stdnum, stdnum) == 0 && Students[i].old != -1)
			return i;
	}
	return -1;
}

void students::deleteStudentByStdnum()				//按学号删除（把old赋值为-1）		yzy
{
	printf("请输入学号：");
	char stdnum[20];
	scanf("%s", stdnum);
	int i = students::findStudentByStdnum(stdnum);
	if (i != -1)
	{
		Students[i].old = -1;
		printf("删除成功\n");
	}
	else printf("该学号不存在\n");
}

void students::empty()											//清空学生					yzy
{
	printf("此操作不可逆，确认要清空吗？(y/n) ");
	char cmd[20];
	scanf("%s", cmd);
	if (cmd[0] == 'y')
	{
		for (int i = 0; i < MAXN; i++)
		{
			Students[i].old = -1;
		}
		printf("清空成功！\n");
	}
	else
		printf("已取消清空\n");
}

void students::sortByGPA()										//将Students数组按GPA排序,使用了stl的sort函数			ly
{
	sort(Students, Students + MAXN, compareByGPA);
	reverse(Students, Students + MAXN);
}

void students::sortByStdnum()									//将数组按学号排序					ly
{
	sort(Students, Students + MAXN, compareByStdnum);
}

void students::changeStudentByIndex(int index)								//改变下标为index的学生信息		ly
{
		char choice[10];
		printf("请输入姓名：");
		scanf("%s", Students[index].name);
		while (1)
		{
			printf("请输入性别：");
			scanf("%s", choice);
			if (strcmp("男", choice) == 0)
			{
				Students[index].sexi = 1;
				break;
			}
			else if (strcmp("女", choice) == 0)
			{
				Students[index].sexi = 0;
				break;
			}
		}
		while (1)
		{
			printf("是本科生还是研究生：");
			scanf("%s", choice);
			if (strcmp(choice, "本科生") == 0)
			{
				Students[index].undergraduate = 1;
				break;
			}
			else if (strcmp(choice, "研究生") == 0)
			{
				Students[index].undergraduate = 0;
				break;
			}
		}

		printf("请输入学号：");
		while (scanf("%s", Students[index].stdnum))
		{
			if (findStudentByStdnum(Students[index].stdnum) != -1 && findStudentByStdnum(Students[index].stdnum) != index )
				printf("该学号已存在，请检查！");
			else if (strlen(Students[index].stdnum) != 13)
				printf("学号的长度应是13位！");
			else
				break;
		}

		printf("请输入身份证号：");
		while (scanf("%s", Students[index].idnum))
		{
			if (strlen(Students[index].idnum) == 18)
				break;
			else
				printf("身份证号的长度应是18位！");
		}

		printf("请输入入学年份：");
		scanf("%d", &Students[index].grade);
		printf("请输入班级：");
		scanf("%s", Students[index].Class);
		printf("请输入专业：");
		scanf("%s", Students[index].major);
		printf("请输入籍贯：");
		scanf("%s", Students[index].home);
		printf("请输入年龄：");
		scanf("%d", &Students[index].old);

		printf("是否输入考试成绩？(y/n)：");
		while (scanf("%s", choice) == 1 && (choice[0] == 'y' || choice[0] == 'Y'))
		{
			Students[index].Score[Students[index].Scorenum].inputfromuser();
			Students[index].Scorenum++;
			if (Students[index].Scorenum >= 9)
				break;
			printf("是否继续输入考试成绩？(y/n)：");
		}

		printf("是否输入体测成绩？(y/n)：");
		while (scanf("%s", choice) == 1 && (choice[0] == 'y' || choice[0] == 'Y'))
		{
			Students[index].Sportsmark[Students[index].Sportsmarknum].inputfromuser();
			Students[index].Sportsmarknum++;
			if (Students[index].Sportsmarknum >= 5)
				break;
			printf("是否继续输入体测成绩？(y/n)：");
		}
		Students[index].GetGPA();
		printf("添加成功！\n\n");
}

void students::changeStudent()											//修改学生							ly
{
	printf("请输入要修改的学生的学号：");
	char stdnumToBeChanged[20];
	scanf("%s", &stdnumToBeChanged);
	int x = findStudentByStdnum(stdnumToBeChanged);
	if (x != -1)
		changeStudentByIndex(x);
	else
		printf("没有此学生！\n");
}

void students::addStudent()										//添加学生							ly
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
	}
	else 
		changeStudentByIndex(blank);
}