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
	if (SCyear == 1) printf("大一");
	else if (SCyear == 2) printf("大二");
	else if (SCyear == 3) printf("大三");
	else if (SCyear == 4) printf("大四");

	if (term == 1) printf("上学期 ");
	else if (term == 2) printf("下学期 ");

	for (int i = 0; i < subjectnum; i++)
	{
		printf("%s ", subject[i]);
		printf("%.1f ", credit[i]);
		printf("%.1f ", study_scores[i]);
	}
	printf("\n");
}

double scores::getGPA()								//计算并返回GPA
{

	return 0.0;
}