#include "student.h"
#include "scores.h"
#include "sportsmark.h"

int student::sumstudent = 0;

//构造函数，创建对象时将三个变量初始化
student::student(void)
{
	old = -1;
	Scorenum = 0;
	Sportsmarknum = 0;
	sumstudent++;;
}


student::~student(void)
{
	sumstudent--;
}

//输入一个student，调用了sore和sportmark下的单个输入函数
void student::inputfromfile(FILE *filename)
{
	fscanf(filename, "%s%s%s%d%s", &name, &stdnum, &idnum, &grade, &Class);
	fscanf(filename, "%s%d%d%s%d", &major, &sexi, &undergraduate, &home, &old);
	char is_end[5];
	while ( fscanf(filename, "%s", &is_end) && (strcmp("体测", is_end) == 0 || strcmp(is_end, "考试") == 0) )
	{
		if (strcmp("体测", is_end) == 0)
			Sportsmark[Sportsmarknum++].inputfromfile(filename);
		else if (strcmp(is_end, "考试") == 0)
			Score[Scorenum++].inputformfile(filename);
	}
}

void student::outputBaseInformatioonToScreen()
{
	//输出4个字姓名，超出不输出
	for (int i = 0; i < 8; i = i + 2)
	{
		if (name[i] == '\0' || name[i + 1] == '\0')
		{
			for (int k = 0; k < (8 - i) / 2; k++)
				printf("  ");
			break;
		}
		else 
			printf("%c%c", name[i], name[i + 1]);
	}
	printf(" ");


	if (sexi == 1)
		printf("男 ");
	else if (sexi == 0)
		printf("女 ");

	printf("%d ", old);
	printf("%d %-4s %s ", grade, Class, major);
	
	if (undergraduate == 1)
		printf("本科生 ");
	else if (undergraduate == 0)
		printf("研究生 ");

	printf("%-12s ", home);
	printf("%s %s ", stdnum, idnum);
	printf("\n");
}

void student::outputtoscreen()
{
	outputBaseInformatioonToScreen();
	for (int i = 0; i < Scorenum; i++)
	{
		Score[i].outPutToScreen();
	}
	for (int i = 0; i < Sportsmarknum; i++)
	{
		Sportsmark[i].outputtoscreen();
	}
	printf("\n");
}

void student::outputtofile(FILE* filename)			//wyh
{

}