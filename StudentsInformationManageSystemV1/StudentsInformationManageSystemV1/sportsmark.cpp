#include "sportsmark.h"


sportsmark::sportsmark(void)
{
}


sportsmark::~sportsmark(void)
{
}

void sportsmark::inputfromfile(FILE *filename)				//���ļ�����
{
	fscanf(filename, "%lf%lf%lf%lf", &SPyear, &height, &weight, &vitalcapacity);
	fscanf(filename, "%lf%lf%lf%lf%lf", &pullup, &anteflexion, &thouthand, &jump, &fifty);
}

void sportsmark::outputtoscreen()							//�������Ļ
{
	printf("�������%.f ", SPyear);
	printf("���%.f ", height);
	printf("����%.f ", weight);
	printf("�λ���%.f ", vitalcapacity);
	printf("��������%.f ", pullup);
	printf("��λ��ǰ��%.f ", anteflexion);
	printf("1000��%.f ", thouthand);
	printf("��Զ%.f ", jump);
	printf("50��%.f ", fifty);
	printf("\n");
}