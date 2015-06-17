#pragma once
#include "student.h"
#include <algorithm>

#define MAXN 10000

class students
{
private:
	student Students[MAXN];							

public:
	void inputFromFile(FILE* filename);						//从文件输入							ly完成
	void outPutToScreen();									//全部输出到屏幕						ly完成
	void outPutToScreenByStdnum();							//按学号输出单个学生信息				ly完成
	void outputBaseInformatioonToScreen();					//输出基本信息到屏幕					ly完成
	void outPutScoresToScreen();							//输出成绩到屏幕						ly完成
	void outPutSportsmarkToScreen();						//输出体测结果到屏幕					ly完成
	void outPutToFile(FILE* filename);						//输出到文件							wyh完成
	int findStudentByStdnum(char stdnum[20]);				//按学号查找，返回在数组中的下标		yzy完成
	void deleteStudentByStdnum();							//按学号删除（把old赋值为-1）			yzy完成
	void empty();											//清空学生							yzy完成
	void sortByGPA();										//将数组按GPA排序					ly完成
	void sortByStdnum();									//将数组按学号排序					ly完成
	void changeStudentByIndex(int index);					//改变下标为index的学生信息			ly完成
	void changeStudent();									//修改学生							ly完成
	void addStudent();										//添加学生							ly完成
	students(void);
	~students(void);


	friend bool compareByGPA(student, student);				//使用stl::sort时的第三个参数
	friend bool compareByStdnum(student, student);			//使用stl::sort时的第三个参数
};

