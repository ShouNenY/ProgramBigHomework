#include "students.h"


students::students(void)
{
}


students::~students(void)
{
}


void students::inputFromFile(FILE* filename)
{
	for (int i = 0; i < MAXN; i++)
		Students[i].inputfromfile(filename);
	//Students[0].inputfromfile(filename);
}

void students::outputBaseInformatioonToScreen()								//���������Ϣ����Ļ
{
	printf("\n����ѧ��������Ϣ��\n\n");
	for (int i = 0; i < MAXN; i++)
	{
		if (Students[i].old == -1)
			continue;
		else
			Students[i].outputBaseInformatioonToScreen();
	}
}

void students::outPutScoresToScreen()							//����ɼ�����Ļ		
{
	printf("\n����ѧ�����Գɼ���\n\n");
	for (int p = 0; p < MAXN; p++)
	{
		if (Students[p].old == -1)
			continue;
		else
		{
			//���4�������������������
			for (int i = 0; i < 8; i = i + 2)
			{
				if (Students[p].name[i] == '\0' || Students[p].name[i + 1] == '\0')
				{
					for (int k = 0; k < (8 - i) / 2; k++)
						printf("  ");
					break;
				}
				else
					printf("%c%c", Students[p].name[i], Students[p].name[i + 1]);
			}
			printf("\n");
			Students[p].outPutScoresToScreen();
		}
	}
}

void students::outPutSportsmarkToScreen()						//������������Ļ
{
	printf("\n����ѧ���������\n\n");
	for (int p = 0; p < MAXN; p++)
	{
		if (Students[p].old == -1)
			continue;
		else
		{
			//���4�������������������
			for (int i = 0; i < 8; i = i + 2)
			{
				if (Students[p].name[i] == '\0' || Students[p].name[i + 1] == '\0')
				{
					for (int k = 0; k < (8 - i) / 2; k++)
						printf("  ");
					break;
				}
				else
					printf("%c%c", Students[p].name[i], Students[p].name[i + 1]);
			}
			printf(" ");


			if (Students[p].sexi == 1)
				printf("��\n");
			else if (Students[p].sexi == 0)
				printf("Ů\n");
			Students[p].outPutSportsmarkToScreen();
		}
	}
}

void students::outPutToScreen()									//���������Ϣ����Ļ				ly
{
	printf("\n����ѧ����\n\n");
	for (int i = 0; i < MAXN; i++)
	{
		if (Students[i].old == -1)
			continue;
		else
			Students[i].outputtoscreen();
	}
}

void students::outPutToScreenByStdnum()							//��ѧ���������ѧ����Ϣ				ly
{
	printf("������ѧ�ţ�");
	char stdnum[20];
	scanf("%s", stdnum);
	int i = findStudentByStdnum(stdnum);
	if (i != -1)
		Students[i].outputtoscreen();
	else
		printf("û�д�ѧ����\n");
}

void students::outPutToFile(FILE* filename)					//������ļ�			wyh
{
	filename = fopen("student.dd", "w");
	for (int i = 0; i < MAXN; i++)
	{
		if (Students[i].old == -1)
			continue;
		else
			Students[i].outputtofile(filename);

	}

}

int students::findStudentByStdnum(char stdnum[20])				//��ѧ�Ų��ң������������е��±�  yzy
{
	for (int i = 0; i < MAXN; i++)
	{
		if (strcmp(Students[i].stdnum, stdnum) == 0 && Students[i].old != -1)
			return i;
	}
	return -1;
}

void students::deleteStudentByStdnum()				//��ѧ��ɾ������old��ֵΪ-1��		yzy
{
	printf("������ѧ�ţ�");
	char stdnum[20];
	scanf("%s", stdnum);
	int i = students::findStudentByStdnum(stdnum);
	if (i != -1)
	{
		Students[i].old = -1;
		printf("ɾ���ɹ�\n");
	}
	else printf("��ѧ�Ų�����\n");
}

void students::empty()											//���ѧ��					yzy
{
	printf("�˲��������棬ȷ��Ҫ�����(y/n) ");
	char cmd[20];
	scanf("%s", cmd);
	if (cmd[0] == 'y')
	{
		for (int i = 0; i < MAXN; i++)
		{
			Students[i].old = -1;
		}
		printf("��ճɹ���\n");
	}
	else
		printf("��ȡ�����\n");
}

void students::sortByGPA()										//��Students���鰴GPA����,ʹ����stl��sort����			ly
{
	sort(Students, Students + MAXN, compareByGPA);
	reverse(Students, Students + MAXN);
}

void students::sortByStdnum()									//�����鰴ѧ������					ly
{
	sort(Students, Students + MAXN, compareByStdnum);
}

void students::changeStudentByIndex(int index)								//�ı��±�Ϊindex��ѧ����Ϣ		ly
{
		char choice[10];
		printf("������������");
		scanf("%s", Students[index].name);
		while (1)
		{
			printf("�������Ա�");
			scanf("%s", choice);
			if (strcmp("��", choice) == 0)
			{
				Students[index].sexi = 1;
				break;
			}
			else if (strcmp("Ů", choice) == 0)
			{
				Students[index].sexi = 0;
				break;
			}
		}
		while (1)
		{
			printf("�Ǳ����������о�����");
			scanf("%s", choice);
			if (strcmp(choice, "������") == 0)
			{
				Students[index].undergraduate = 1;
				break;
			}
			else if (strcmp(choice, "�о���") == 0)
			{
				Students[index].undergraduate = 0;
				break;
			}
		}

		printf("������ѧ�ţ�");
		while (scanf("%s", Students[index].stdnum))
		{
			if (findStudentByStdnum(Students[index].stdnum) != -1 && findStudentByStdnum(Students[index].stdnum) != index )
				printf("��ѧ���Ѵ��ڣ����飡");
			else if (strlen(Students[index].stdnum) != 13)
				printf("ѧ�ŵĳ���Ӧ��13λ��");
			else
				break;
		}

		printf("���������֤�ţ�");
		while (scanf("%s", Students[index].idnum))
		{
			if (strlen(Students[index].idnum) == 18)
				break;
			else
				printf("���֤�ŵĳ���Ӧ��18λ��");
		}

		printf("��������ѧ��ݣ�");
		scanf("%d", &Students[index].grade);
		printf("������༶��");
		scanf("%s", Students[index].Class);
		printf("������רҵ��");
		scanf("%s", Students[index].major);
		printf("�����뼮�᣺");
		scanf("%s", Students[index].home);
		printf("���������䣺");
		scanf("%d", &Students[index].old);

		printf("�Ƿ����뿼�Գɼ���(y/n)��");
		while (scanf("%s", choice) == 1 && (choice[0] == 'y' || choice[0] == 'Y'))
		{
			Students[index].Score[Students[index].Scorenum].inputfromuser();
			Students[index].Scorenum++;
			if (Students[index].Scorenum >= 9)
				break;
			printf("�Ƿ�������뿼�Գɼ���(y/n)��");
		}

		printf("�Ƿ��������ɼ���(y/n)��");
		while (scanf("%s", choice) == 1 && (choice[0] == 'y' || choice[0] == 'Y'))
		{
			Students[index].Sportsmark[Students[index].Sportsmarknum].inputfromuser();
			Students[index].Sportsmarknum++;
			if (Students[index].Sportsmarknum >= 5)
				break;
			printf("�Ƿ�����������ɼ���(y/n)��");
		}
		Students[index].GetGPA();
		printf("��ӳɹ���\n\n");
}

void students::changeStudent()											//�޸�ѧ��							ly
{
	printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	char stdnumToBeChanged[20];
	scanf("%s", &stdnumToBeChanged);
	int x = findStudentByStdnum(stdnumToBeChanged);
	if (x != -1)
		changeStudentByIndex(x);
	else
		printf("û�д�ѧ����\n");
}

void students::addStudent()										//���ѧ��							ly
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
	}
	else 
		changeStudentByIndex(blank);
}