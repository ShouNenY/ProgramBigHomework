#include<cstdio>
#include<cstdlib>

//���ļ�
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

//���������ʾ��Ϣ
void	printinstructions(){
	cout<<"-----------------------------------\n";
	cout<<"�������ֺ󰴻س�ȷ��:\n";
	cout<<"����1���ѧ��\n";
	cout<<"����2�鿴����ѧ��\n";
	cout<<"����3��ѧ�Ų���ѧ��\n";
	cout<<"����4���ѧ��\n";
	cout<<"����0�˳�����\n";
	cout<<"-----------------------------------\n";
}