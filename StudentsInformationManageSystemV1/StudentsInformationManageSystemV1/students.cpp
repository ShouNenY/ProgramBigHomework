#include "students.h"


students::students(void)
{
}


students::~students(void)
{
}


void students::inputFromFile(FILE* filename)
{
	for (int i = 0; i < 10000; i++)
		Students[i].inputfromfile(filename);
	//Students[0].inputfromfile(filename);
}

void students::outPutToScreen()
{
	for (int i = 0; i < 10000; i++)
	{
		if (Students[i].old == -1)
			break;
		else
			Students[i].outputtoscreen();
	}
	//Students[0].outputtoscreen();
}

void students::outPutToFile(FILE* filename)					//wyh
{

}

int students::findStudentByStdnum(char stdnum[20])				//��ѧ�Ų��ң������������е��±�
{

	return 0;
}
void students::deleteStudentByStdnum(char stdnum[20])				//��ѧ��ɾ������old��ֵΪ1��
{

}

void students::sortByGPA()										//�����鰴GPA����,ʹ��stl��sort�����������ֶ�д��������
{

}

int students::addStudent()										//���ѧ��,��û���   ly
{
	int blank = -1;
	//�ҵ���һ��oldΪ-1��λ��
	for (int i = 0; i < 10000; i++)
		if (Students[i].old == -1)
		{
			blank = i;
			break;
		}
	if (blank == -1)
	{
		printf("�洢�ռ�����");
		return -1;
	}
	else
	{
		printf("������������");
		scanf("%s", Students[blank].name);

		printf("��ӳɹ���");
		return 0;
	}
}