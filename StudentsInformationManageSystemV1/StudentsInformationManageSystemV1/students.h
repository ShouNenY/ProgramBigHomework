#include "student.h"

#pragma once
class students
{
private:
	student Students[10000];							

public:
	void inputFromFile(FILE* filename);						//���ļ�����							ly�����
	void outPutToScreen();									//ȫ���������Ļ						ly�����
	void outPutToFile(FILE* filename);						//������ļ�							wyh
	int findStudentByStdnum(char stdnum[20]);				//��ѧ�Ų��ң������������е��±�
	void deleteStudentByStdnum(char stdnum[20]);			//��ѧ��ɾ������old��ֵΪ-1��
	void sortByGPA();										//�����鰴GPA����
	int addStudent();										//���ѧ��


	students(void);
	~students(void);
};

