#include "student.h"
#include "scores.h"
#include "sportsmark.h"


//构造函数，创建对象时将三个变量初始化
student::student(void)
{
	old = -1;
	Scorenum = 0;
	Sportsmarknum = 0;
}


student::~student(void)
{
}

																			//输入一个student			ly
void student::inputfromfile(FILE *filename)
{
	fscanf(filename, "%s", name);
	fscanf(filename, "%s", stdnum);
	fscanf(filename, "%s", idnum);
	fscanf(filename, "%d", &grade);
	fscanf(filename, "%s", Class);
	fscanf(filename, "%s%d%d%s%d", major, &sexi, &undergraduate, home, &old);
	char is_end[5];
	while ( fscanf(filename, "%s", &is_end) && (strcmp("体测", is_end) == 0 || strcmp(is_end, "考试") == 0) )
	{
		if (strcmp("体测", is_end) == 0)
			Sportsmark[Sportsmarknum++].inputfromfile(filename);
		else if (strcmp(is_end, "考试") == 0)
			Score[Scorenum++].inputformfile(filename);
	}
	GetGPA();
}

void student::outputBaseInformatioonToScreen()								//输出基本信息到屏幕			ly
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
	printf("GPA: %.3f ", GPA);
	printf("\n");
}

void student::outPutScoresToScreen()										//输出成绩到屏幕			ly
{
	for (int i = 0; i < Scorenum; i++)
	{
		Score[i].outPutToScreen();
	}
}

void student::outPutSportsmarkToScreen()									//输出体测结果到屏幕			ly
{
	for (int i = 0; i < Sportsmarknum; i++)
	{
		Sportsmark[i].outputtoscreen();
	}
}

void student::outputtoscreen()												//输出所有信息到屏幕			ly
{
	outputBaseInformatioonToScreen();
	outPutScoresToScreen();
	outPutSportsmarkToScreen();
	printf("\n");
}


double student::getGPA(double point)										//从单科分数得到单科绩点		ly
{
	if (point >= 90.0) return 4.0;
	else if (85.0 <= point && point < 90.0) return 3.7;
	else if (82.0 <= point && point < 85.0) return 3.3;
	else if (78.0 <= point && point < 82.0) return 3.0;
	else if (75.0 <= point && point < 78.0) return 2.7;
	else if (72.0 <= point && point < 75.0) return 2.3;
	else if (68.0 <= point && point < 72.0) return 2.0;
	else if (64.0 <= point && point < 68.0) return 1.5;
	else if (60.0 <= point && point < 64.0) return 1.0;
	else if (point < 60.0) return 0.0;
}

double student::GetGPA()														//计算一个学生的总GPA		ly
{
	double sumGPA = 0.0, sumcredit = 0.0;
	for (int i = 0; i < Scorenum; i++)
	{
		for (int k = 0; k < Score[i].subjectnum; k++)
		{
			sumGPA += getGPA(Score[i].study_scores[k]) * Score[i].credit[k];
			sumcredit += Score[i].credit[k];
		}
	}
	if (sumcredit != 0.0)
		GPA = sumGPA / sumcredit;
	else
		GPA = 0.0;
	return GPA;
}

void student::outputtofile(FILE* filename)										//输出到文件 wyh
{
	for (int i = 0; i < 8; i = i + 2)
	{
		if (name[i] == '\0' || name[i + 1] == '\0')
		{

			break;
		}
		else
			fprintf(filename, "%c%c", name[i], name[i + 1]);
	}
	fprintf(filename, " ");
	fprintf(filename, "%s %s ", stdnum, idnum);
	fprintf(filename, "%d %s %s ", grade, Class, major);
	fprintf(filename, "%d ", sexi);
	fprintf(filename, "%d ", undergraduate);
	fprintf(filename, "%-12s ", home);
	fprintf(filename, "%d", old);
	fprintf(filename, "\n");

	for (int i = 0; i < Sportsmarknum; i++)
	{
		Sportsmark[i].sportoutputtofile(filename);
	}
	for (int i = 0; i < Scorenum; i++)
	{
		Score[i].scoreoutPutToFile(filename);
	}
	fprintf(filename, "0");
	fprintf(filename, "\n");
}