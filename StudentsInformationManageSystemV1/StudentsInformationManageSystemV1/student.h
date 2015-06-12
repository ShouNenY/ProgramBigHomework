#pragma once
#include "scores.h"
#include "sportsmark.h"
#include "stdio.h"

class student
{
private:
	static int sumstudent;												 //学生总人数
	char name[20],stdnum[20],idnum[20],major[20],home[100],Class[20];	 //姓名，学号，身份证号,专业,籍贯,班级
	int sexi,undergraduate;												 //sex=1表示男，sex=0表示女  undergraduate=1 or 0
	int old, grade, Scorenum, Sportsmarknum;							 //年龄，年级,存储的考试成绩和体侧成绩的次数
	scores Score[8];													 //成绩
	sportsmark Sportsmark[4];											 //体测成绩

												
																		 //照片、生肖、星座 待添加
																	   	 //各种功能函数
	
	void inputfromfile(FILE *filename);									//输入一个student，调用了sore和sportmark下的单个输入函数
	void outputBaseInformatioonToScreen();								//输出基本信息到屏幕		已完成
	void outputtoscreen();												//输出全部信息到屏幕		已完成
	void outputtofile(FILE* filename);									//输出到文件				wyh

	friend class students;
	student(void);
	~student(void);
};

