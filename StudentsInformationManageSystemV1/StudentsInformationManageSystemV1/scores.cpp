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
	if (SCyear == 1) printf("��һ");
	else if (SCyear == 2) printf("���");
	else if (SCyear == 3) printf("����");
	else if (SCyear == 4) printf("����");

	if (term == 1) printf("��ѧ�� ");
	else if (term == 2) printf("��ѧ�� ");

	for (int i = 0; i < subjectnum; i++)
	{
		printf("%s ", subject[i]);
		printf("%.1f ", credit[i]);
		printf("%.1f ", study_scores[i]);
	}
	printf("\n");
}

double scores::getGPA()								//���㲢����GPA
{

	return 0.0;
}