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
	printf("���%.fcm ", height);
	printf("����%.fkg ", weight);
	printf("�λ���%.fml ", vitalcapacity);
	printf("��������%.f�� ", pullup);
	printf("��λ��ǰ��%.fcm ", anteflexion);
	printf("1000��%.fs ", thouthand);
	printf("��Զ%.2fm ", jump);
	printf("50��%.1fs ", fifty);
	printf("\n");
}

void sportsmark::sportoutputtofile(FILE *filename)
{
	fprintf(filename, "��� ");
	fprintf(filename, "%.0f ", SPyear);
	fprintf(filename, "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f", height, weight, vitalcapacity, pullup, anteflexion, thouthand, jump, fifty);

	fprintf(filename, "\n");

}

void sportsmark::inputfromuser()							//���ѧ��ʱ���û�����
{
		printf("�����������ݣ�");
		scanf("%lf", &SPyear);
		printf("�����������������");
		scanf("%lf", &height);
		printf("����������ǧ������");
		scanf("%lf", &weight);
		printf("������λ�����������");
		scanf("%lf", &vitalcapacity);
		printf("��������������/��������������");
		scanf("%lf", &pullup);
		printf("��������λ��ǰ����������");
		scanf("%lf", &anteflexion);
		printf("������1000��/800��������");
		scanf("%lf", &thouthand);
		printf("��������Զ������");
		scanf("%lf", &jump);
		printf("������50��������");
		scanf("%lf", &fifty);
}