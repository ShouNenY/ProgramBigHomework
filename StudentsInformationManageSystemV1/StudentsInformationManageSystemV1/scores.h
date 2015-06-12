#pragma once
#include<string>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

class scores
{
private:
	int SCyear,term,subjectnum;						//考试年级、学期、科目数   1表示上学期，2表示下学期  
	char subject[20][100];							//科目名称
	double credit[20],study_scores[20];				//科目对应的学分和考试成绩
	double GPA;
									
													//待添加功能函数，如计算GPA

	void inputformfile(FILE *filename);				//从文件输入scores
	void outPutToScreen();							//输出到屏幕
	double getGPA();								//计算GPA后赋值给GPA,并返回这个值

	friend class student;
	scores(void);
	~scores(void);
};

