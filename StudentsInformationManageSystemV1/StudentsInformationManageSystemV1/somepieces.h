#include<cstdio>
#include<cstdlib>

//打开文件
FILE* openfile()						
{
	FILE *studenttxt;	
	studenttxt = fopen("student.txt","a+");
	if(  studenttxt == NULL )
	{
		printf("Open File Error!");
		system("puase");
		exit(1);
	}
	return studenttxt;
}

//输出操作提示信息
void	printinstructions(){
	cout<<"-----------------------------------\n";
	cout<<"输入数字后按回车确定:\n";
	cout<<"输入1添加学生\n";
	cout<<"输入2查看所有学生\n";
	cout<<"输入3按学号查找学生\n";
	cout<<"输入4添加学生\n";
	cout<<"输入0退出程序\n";
	cout<<"-----------------------------------\n";
}