#pragma once
#include "scores.h"
#include "sportsmark.h"
#include "stdio.h"

class student
{
private:
	static int sumstudent;												 //ѧ��������
	char name[20],stdnum[20],idnum[20],major[20],home[100],Class[20];	 //������ѧ�ţ����֤��,רҵ,����,�༶
	int sexi,undergraduate;												 //sex=1��ʾ�У�sex=0��ʾŮ  undergraduate=1 or 0
	int old, grade, Scorenum, Sportsmarknum;							 //���䣬�꼶,�洢�Ŀ��Գɼ������ɼ��Ĵ���
	scores Score[8];													 //�ɼ�
	sportsmark Sportsmark[4];											 //���ɼ�

												
																		 //��Ƭ����Ф������ �����
																	   	 //���ֹ��ܺ���
	
	void inputfromfile(FILE *filename);									//����һ��student��������sore��sportmark�µĵ������뺯��
	void outputBaseInformatioonToScreen();								//���������Ϣ����Ļ		�����
	void outputtoscreen();												//���ȫ����Ϣ����Ļ		�����
	void outputtofile(FILE* filename);									//������ļ�				wyh

	friend class students;
	student(void);
	~student(void);
};

