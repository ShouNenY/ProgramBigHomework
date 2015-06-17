#pragma once
#include "scores.h"
#include "sportsmark.h"
#include "stdio.h"

class student
{
private:
	char name[20],stdnum[20],idnum[20],major[20],home[100],Class[20];	 //姓名，学号，身份证号,专业,籍贯,班级
	int sexi,undergraduate;												 //sex=1表示男，sex=0表示女  undergraduate=1 or 0
	int old, grade, Scorenum, Sportsmarknum;							 //年龄，年级,存储的考试成绩和体侧成绩的次数
	scores Score[8];													 //成绩
	sportsmark Sportsmark[4];											 //体测成绩
	double GPA;

												
																		 //照片、生肖、星座 待添加
																	   	 //各种功能函数
	
	void inputfromfile(FILE *filename);									//输入一个student		ly已完成
	void outputBaseInformatioonToScreen();								//输出基本信息到屏幕		ly已完成
	void outPutScoresToScreen();										//输出成绩到屏幕			ly已完成
	void outPutSportsmarkToScreen();									//输出体测结果到屏幕		ly已完成
	void outputtoscreen();												//输出全部信息到屏幕		ly已完成
	void outputtofile(FILE* filename);									//输出到文件				wyh已完成
	double getGPA(double point);										//从单科分数得到单科绩点	ly已完成
	double GetGPA();													//计算一个学生的总GPA		ly已完成

public:
	friend class students;
	friend bool compareByGPA(student a, student b);
	friend bool compareByStdnum(student a, student b);
	student(void);
	~student(void);
};

