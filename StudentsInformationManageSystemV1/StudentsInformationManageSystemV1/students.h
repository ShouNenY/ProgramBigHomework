#pragma once
#include "student.h"
#include <algorithm>

#define MAXN 10000

class students
{
private:
	student Students[MAXN];							

public:
	void inputFromFile(FILE* filename);						//���ļ�����							ly���
	void outPutToScreen();									//ȫ���������Ļ						ly���
	void outPutToScreenByStdnum();							//��ѧ���������ѧ����Ϣ				ly���
	void outputBaseInformatioonToScreen();					//���������Ϣ����Ļ					ly���
	void outPutScoresToScreen();							//����ɼ�����Ļ						ly���
	void outPutSportsmarkToScreen();						//������������Ļ					ly���
	void outPutToFile(FILE* filename);						//������ļ�							wyh���
	int findStudentByStdnum(char stdnum[20]);				//��ѧ�Ų��ң������������е��±�		yzy���
	void deleteStudentByStdnum();							//��ѧ��ɾ������old��ֵΪ-1��			yzy���
	void empty();											//���ѧ��							yzy���
	void sortByGPA();										//�����鰴GPA����					ly���
	void sortByStdnum();									//�����鰴ѧ������					ly���
	void changeStudentByIndex(int index);					//�ı��±�Ϊindex��ѧ����Ϣ			ly���
	void changeStudent();									//�޸�ѧ��							ly���
	void addStudent();										//���ѧ��							ly���
	students(void);
	~students(void);


	friend bool compareByGPA(student, student);				//ʹ��stl::sortʱ�ĵ���������
	friend bool compareByStdnum(student, student);			//ʹ��stl::sortʱ�ĵ���������
};

