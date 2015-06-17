#include "sportsmark.h"


sportsmark::sportsmark(void)
{
}


sportsmark::~sportsmark(void)
{
}

void sportsmark::inputfromfile(FILE *filename)				//从文件输入
{
	fscanf(filename, "%lf%lf%lf%lf", &SPyear, &height, &weight, &vitalcapacity);
	fscanf(filename, "%lf%lf%lf%lf%lf", &pullup, &anteflexion, &thouthand, &jump, &fifty);
}

void sportsmark::outputtoscreen()							//输出到屏幕
{
	printf("测试年份%.f ", SPyear);
	printf("身高%.fcm ", height);
	printf("体重%.fkg ", weight);
	printf("肺活量%.fml ", vitalcapacity);
	printf("引体向上%.f个 ", pullup);
	printf("座位体前屈%.fcm ", anteflexion);
	printf("1000米%.fs ", thouthand);
	printf("跳远%.2fm ", jump);
	printf("50米%.1fs ", fifty);
	printf("\n");
}

void sportsmark::sportoutputtofile(FILE *filename)
{
	fprintf(filename, "体测 ");
	fprintf(filename, "%.0f ", SPyear);
	fprintf(filename, "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f", height, weight, vitalcapacity, pullup, anteflexion, thouthand, jump, fifty);

	fprintf(filename, "\n");

}

void sportsmark::inputfromuser()							//添加学生时由用户输入
{
		printf("请输入体测年份：");
		scanf("%lf", &SPyear);
		printf("请输入身高厘米数：");
		scanf("%lf", &height);
		printf("请输入体重千克数：");
		scanf("%lf", &weight);
		printf("请输入肺活量毫升数：");
		scanf("%lf", &vitalcapacity);
		printf("请输入引体向上/仰卧起坐个数：");
		scanf("%lf", &pullup);
		printf("请输入坐位体前屈厘米数：");
		scanf("%lf", &anteflexion);
		printf("请输入1000米/800米秒数：");
		scanf("%lf", &thouthand);
		printf("请输入跳远米数：");
		scanf("%lf", &jump);
		printf("请输入50米秒数：");
		scanf("%lf", &fifty);
}