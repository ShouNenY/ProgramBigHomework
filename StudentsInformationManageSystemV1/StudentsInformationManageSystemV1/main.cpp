#include "students.h"
#include "passwordcheck.h"
#include "somepieces.h"


students x;										//���������main�ڲ���ջ���


int main()
{
	system("mode con cols=120");				//�趨���ڴ�С
	//passwordcheck("613613613");				//������֤
	FILE *studenttxt = openfile();				//��student.txt�ļ�
	x.inputFromFile(studenttxt);				//txt������Ϣ�����ڴ�
	printinstructions();						//��ӡ������ʾ��Ϣ


	char cmd[100];								//����ģʽѡ������
	while (scanf("%s", cmd))
	{
		if (strcmp(cmd, "0") == 0) break;
		else if (strcmp(cmd, "1") == 0)			//���ѧ���������ѧ�����̸���txt�Է���Ϣ��ʧ
		{
			x.addStudent();
				x.outPutToFile(studenttxt);			
		}
		else if (strcmp(cmd, "2") == 0)			//�鿴����ѧ��
		{
			x.outPutToScreenByStdnum();
		}
		else if (strcmp(cmd, "3") == 0)			//�������ѧ��������Ϣ����Ļ
		{
			printf("����ʲô˳������\n");
			printf(("0����Ĭ��˳�� 1������ѧ������ 2����GPA˳��\n"));
			int flag;
			scanf("%d", &flag);
			if (flag == 1)
				x.sortByStdnum();
			else if (flag == 2)
				x.sortByGPA();
			x.outPutToScreen();
		}
		else if (strcmp(cmd, "4") == 0)			//���������Ϣ����Ļ
		{
			printf("����ʲô˳������\n");
			printf(("0����Ĭ��˳�� 1������ѧ������ 2����GPA˳��\n"));
			int flag;
			scanf("%d", &flag);
			if (flag == 1)
				x.sortByStdnum();
			else if (flag == 2)
				x.sortByGPA();
			x.outputBaseInformatioonToScreen();
		}
		else if (strcmp(cmd, "5") == 0)			//����ɼ�����Ļ
		{
			printf("����ʲô˳������\n");
			printf(("0����Ĭ��˳�� 1������ѧ������ 2����GPA˳��\n"));
			int flag;
			scanf("%d", &flag);
			if (flag == 1)
				x.sortByStdnum();
			else if (flag == 2)
				x.sortByGPA();
			x.outPutScoresToScreen();
		}
		else if (strcmp(cmd, "6") == 0)			//������������Ļ
		{
			printf("����ʲô˳������\n");
			printf(("0����Ĭ��˳�� 1������ѧ������ 2����GPA˳��\n"));
			int flag;
			scanf("%d", &flag);
			if (flag == 1)
				x.sortByStdnum();
			else if (flag == 2)
				x.sortByGPA();
			x.outPutSportsmarkToScreen();
		}
		else if (strcmp(cmd, "7") == 0)			//��
		{
			x.changeStudent();
		}
		else if (strcmp(cmd, "8") == 0)			//ɾ
		{
			x.deleteStudentByStdnum();
		}
		else if (strcmp(cmd, "9") == 0)			//���
		{
			x.empty();
		}

		system("PAUSE");
		printf("\n");
		printinstructions();					//ÿ������һ�������������һ����ʾ��Ϣ
	}
	
	x.outPutToFile(studenttxt);					//������ļ�������Ϣ
	fclose(studenttxt);							//�ر��ļ�
	return 0;
}