#pragma once

#include<cstdio>
#include<cstdlib>


FILE* openfile()									//打开文件		ly已完成
{
	FILE *studenttxt;	
	studenttxt = fopen("student.dd","a+");
	if(  studenttxt == NULL )
	{
		printf("Open File Error!");
		system("puase");
		exit(1);
	}
	return studenttxt;
}


void printinstructions()							//打印操作提示信息		ly已完成
{
	cout<<"-----------------------------------\n";
	cout << "操作方法——输入数字后按回车确定:\n";
	cout << "输入1添加学生\n";
	cout << "输入2查看单个学生\n";
	cout << "输入3查看所有学生所有信息\n";
	cout << "输入4查看所有学生基本信息\n";
	cout << "输入5查看所有学生成绩\n";
	cout << "输入6查看所有学生体测结果\n";
	cout << "输入7修改单个学生\n";
	cout << "输入8删除单个学生\n";
	cout << "输入9清空所有学生\n";
	
	cout << "输入0退出程序\n";
	cout<<"-----------------------------------\n\n";
}

bool compareByGPA(student a, student b)				//按GPA比较两个学生			ly已完成
{
	return (a.GPA < b.GPA);
}

bool compareByStdnum(student a, student b)				//按学号比较两个学生				ly
{
	if (strcmp(a.stdnum, b.stdnum) == -1)
		return true;
	else
		return false;
}

void printinstructions2()							//打印选择查看所有学生模式时的提示信息		ly已完成
{
	printf("");
}