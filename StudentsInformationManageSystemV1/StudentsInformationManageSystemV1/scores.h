#pragma once
#include<string>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

class scores
{
private:
	int SCyear,term,subjectnum;						//�����꼶��ѧ�ڡ���Ŀ��   1��ʾ��ѧ�ڣ�2��ʾ��ѧ��  
	char subject[20][100];							//��Ŀ����
	double credit[20],study_scores[20];				//��Ŀ��Ӧ��ѧ�ֺͿ��Գɼ�
	double GPA;
									
													//����ӹ��ܺ����������GPA

	void inputformfile(FILE *filename);				//���ļ�����scores
	void outPutToScreen();							//�������Ļ
	double getGPA();								//����GPA��ֵ��GPA,���������ֵ

	friend class student;
	scores(void);
	~scores(void);
};

