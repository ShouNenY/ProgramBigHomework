#pragma once

#include<cstdio>
#include<cstdlib>


FILE* openfile()									//���ļ�		ly�����
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


void printinstructions()							//��ӡ������ʾ��Ϣ		ly�����
{
	cout<<"-----------------------------------\n";
	cout << "�������������������ֺ󰴻س�ȷ��:\n";
	cout << "����1���ѧ��\n";
	cout << "����2�鿴����ѧ��\n";
	cout << "����3�鿴����ѧ��������Ϣ\n";
	cout << "����4�鿴����ѧ��������Ϣ\n";
	cout << "����5�鿴����ѧ���ɼ�\n";
	cout << "����6�鿴����ѧ�������\n";
	cout << "����7�޸ĵ���ѧ��\n";
	cout << "����8ɾ������ѧ��\n";
	cout << "����9�������ѧ��\n";
	
	cout << "����0�˳�����\n";
	cout<<"-----------------------------------\n\n";
}

bool compareByGPA(student a, student b)				//��GPA�Ƚ�����ѧ��			ly�����
{
	return (a.GPA < b.GPA);
}

bool compareByStdnum(student a, student b)				//��ѧ�űȽ�����ѧ��				ly
{
	if (strcmp(a.stdnum, b.stdnum) == -1)
		return true;
	else
		return false;
}

void printinstructions2()							//��ӡѡ��鿴����ѧ��ģʽʱ����ʾ��Ϣ		ly�����
{
	printf("");
}