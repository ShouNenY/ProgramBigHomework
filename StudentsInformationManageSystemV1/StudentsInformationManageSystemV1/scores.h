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
									
													//����ӹ��ܺ����������GPA

	void inputformfile(FILE *filename);				//���ļ�����scores				ly�����
	void outPutToScreen();							//�������Ļ						ly�����
	void scoreoutPutToFile(FILE *filename);			//������ļ�						wyh�����
	void inputfromuser();							//���ѧ��ʱ���û�����			ly�����

	friend class student;
	friend class students;
	scores(void);
	~scores(void);
};

