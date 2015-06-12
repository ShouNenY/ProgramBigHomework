#include "student.h"

#pragma once
class students
{
private:
	student Students[10000];							

public:
	void inputFromFile(FILE* filename);						//从文件输入							ly已完成
	void outPutToScreen();									//全部输出到屏幕						ly已完成
	void outPutToFile(FILE* filename);						//输出到文件							wyh
	int findStudentByStdnum(char stdnum[20]);				//按学号查找，返回在数组中的下标
	void deleteStudentByStdnum(char stdnum[20]);			//按学号删除（把old赋值为-1）
	void sortByGPA();										//将数组按GPA排序
	int addStudent();										//添加学生


	students(void);
	~students(void);
};

