#pragma once
#include "scores.h"
#include "sportsmark.h"
#include "stdio.h"

class student
{
private:
	char name[20],stdnum[20],idnum[20],major[20],home[100],Class[20];	 //������ѧ�ţ����֤��,רҵ,����,�༶
	int sexi,undergraduate;												 //sex=1��ʾ�У�sex=0��ʾŮ  undergraduate=1 or 0
	int old, grade, Scorenum, Sportsmarknum;							 //���䣬�꼶,�洢�Ŀ��Գɼ������ɼ��Ĵ���
	scores Score[8];													 //�ɼ�
	sportsmark Sportsmark[4];											 //���ɼ�
	double GPA;

												
																		 //��Ƭ����Ф������ �����
																	   	 //���ֹ��ܺ���
	
	void inputfromfile(FILE *filename);									//����һ��student		ly�����
	void outputBaseInformatioonToScreen();								//���������Ϣ����Ļ		ly�����
	void outPutScoresToScreen();										//����ɼ�����Ļ			ly�����
	void outPutSportsmarkToScreen();									//������������Ļ		ly�����
	void outputtoscreen();												//���ȫ����Ϣ����Ļ		ly�����
	void outputtofile(FILE* filename);									//������ļ�				wyh�����
	double getGPA(double point);										//�ӵ��Ʒ����õ����Ƽ���	ly�����
	double GetGPA();													//����һ��ѧ������GPA		ly�����

public:
	friend class students;
	friend bool compareByGPA(student a, student b);
	friend bool compareByStdnum(student a, student b);
	student(void);
	~student(void);
};

