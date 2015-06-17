#include "scores.h"


scores::scores(void)
{
	this->subjectnum = 0;
}


scores::~scores(void)
{
}

void scores::inputformfile(FILE *filename)				//从文件输入scores
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

void scores::outPutToScreen()							//输出到屏幕
{
	if (SCyear == 1) printf("一年级");
	else if (SCyear == 2) printf("二年级");
	else if (SCyear == 3) printf("三年级");
	else if (SCyear == 4) printf("四年级");

	if (term == 1) printf("上学期 ");
	else if (term == 2) printf("下学期 ");

	for (int i = 0; i < subjectnum; i++)
	{
		printf("%s ", subject[i]);
		printf("%.1f学分 ", credit[i]);
		printf("%.1f分 ", study_scores[i]);
	}
	printf("\n");
}

void scores::scoreoutPutToFile(FILE *filename)										//wyh
{
	fprintf(filename, "考试 ");
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

void scores::inputfromuser()											//添加学生时由用户输入
{
	char choice[20];
	printf("请输入考试年级（一年级/二年级/三年级/四年级）：");

	while (1)
	{
		scanf("%s", choice);
		if (strcmp(choice, "一年级") == 0)
		{
			SCyear = 1;
			break;
		}
		else if (strcmp(choice, "二年级") == 0)
		{
			SCyear = 2;
			break;
		}
		else if (strcmp(choice, "三年级") == 0)
		{
			SCyear = 3;
			break;
		}
		else if (strcmp(choice, "四年级") == 0)
		{
			SCyear = 4;
			break;
		}
	}

	while (true)
	{
		printf("请输入考试学期（上学期/下学期）：");
		scanf("%s", choice);
		if (strcmp(choice, "上学期") == 0)
		{
			term = 1;
			break;
		}
		else if (strcmp(choice, "下学期") == 0)
		{
			term = 2;
			break;
		}
	}
	
	do
	{
		printf("请输入科目名称：");
		scanf("%s", subject[subjectnum]);
		printf("请输入科目学分：");
		scanf("%lf", &credit[subjectnum]);
		printf("请输入考试分数：");
		scanf("%lf", &study_scores[subjectnum]);
		subjectnum++;
		if (subjectnum >= 19)
			break;
		printf("是否继续输入(y/n)：");
	} while (scanf("%s", choice) == 1 && (choice[0] == 'y' || choice[0] == 'Y'));
}