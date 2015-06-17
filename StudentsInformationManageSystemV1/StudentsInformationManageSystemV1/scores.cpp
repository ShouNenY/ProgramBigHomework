#include "scores.h"


scores::scores(void)
{
	this->subjectnum = 0;
}


scores::~scores(void)
{
}

void scores::inputformfile(FILE *filename)				//���ļ�����scores
{
	fscanf(filename, "%d%d", &SCyear, &term);
	char x[20];
	while (fscanf(filename, "%s", &x) && strcmp(x, "0") != 0)
	{
		strcpy(subject[subjectnum], x);
		fscanf(filename, "%lf%lf", &study_scores[subjectnum], &credit[subjectnum]);
		subjectnum++;
	}
}

void scores::outPutToScreen()							//�������Ļ
{
	if (SCyear == 1) printf("һ�꼶");
	else if (SCyear == 2) printf("���꼶");
	else if (SCyear == 3) printf("���꼶");
	else if (SCyear == 4) printf("���꼶");

	if (term == 1) printf("��ѧ�� ");
	else if (term == 2) printf("��ѧ�� ");

	for (int i = 0; i < subjectnum; i++)
	{
		printf("%s ", subject[i]);
		printf("%.1fѧ�� ", credit[i]);
		printf("%.1f�� ", study_scores[i]);
	}
	printf("\n");
}

void scores::scoreoutPutToFile(FILE *filename)										//wyh
{
	fprintf(filename, "���� ");
	fprintf(filename, "%d ", SCyear);
	fprintf(filename, "%d ", term);
	for (int i = 0; i < subjectnum; i++)
	{
		fprintf(filename, "%s ", subject[i]);
		fprintf(filename, "%.1f ", study_scores[i]);
		fprintf(filename, "%.1f ", credit[i]);
	}
	fprintf(filename, "0");
	fprintf(filename, "\n");
}

void scores::inputfromuser()											//���ѧ��ʱ���û�����
{
	char choice[20];
	printf("�����뿼���꼶��һ�꼶/���꼶/���꼶/���꼶����");

	while (1)
	{
		scanf("%s", choice);
		if (strcmp(choice, "һ�꼶") == 0)
		{
			SCyear = 1;
			break;
		}
		else if (strcmp(choice, "���꼶") == 0)
		{
			SCyear = 2;
			break;
		}
		else if (strcmp(choice, "���꼶") == 0)
		{
			SCyear = 3;
			break;
		}
		else if (strcmp(choice, "���꼶") == 0)
		{
			SCyear = 4;
			break;
		}
	}

	while (true)
	{
		printf("�����뿼��ѧ�ڣ���ѧ��/��ѧ�ڣ���");
		scanf("%s", choice);
		if (strcmp(choice, "��ѧ��") == 0)
		{
			term = 1;
			break;
		}
		else if (strcmp(choice, "��ѧ��") == 0)
		{
			term = 2;
			break;
		}
	}
	
	do
	{
		printf("�������Ŀ���ƣ�");
		scanf("%s", subject[subjectnum]);
		printf("�������Ŀѧ�֣�");
		scanf("%lf", &credit[subjectnum]);
		printf("�����뿼�Է�����");
		scanf("%lf", &study_scores[subjectnum]);
		subjectnum++;
		if (subjectnum >= 19)
			break;
		printf("�Ƿ��������(y/n)��");
	} while (scanf("%s", choice) == 1 && (choice[0] == 'y' || choice[0] == 'Y'));
}