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
	printf("身高%.f ", height);
	printf("体重%.f ", weight);
	printf("肺活量%.f ", vitalcapacity);
	printf("引体向上%.f ", pullup);
	printf("座位体前屈%.f ", anteflexion);
	printf("1000米%.f ", thouthand);
	printf("跳远%.f ", jump);
	printf("50米%.f ", fifty);
	printf("\n");
}