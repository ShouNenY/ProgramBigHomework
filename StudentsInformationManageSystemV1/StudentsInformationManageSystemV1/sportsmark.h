#pragma once
#include <cstdio>
#include <iostream>
using namespace std;
class sportsmark
{
private:
	double SPyear;													//�������
	double pullup,thouthand;										// ��������/��������,/1000m/800m
	double jump,fifty,anteflexion,weight,height,vitalcapacity;	//50m��������Զ����λ��ǰ��������,��ߣ��λ���

																//���ݲ��Խ��ȷ���ɼ��ĺ���

	void inputfromfile(FILE *filename);							//���ļ�����
	void outputtoscreen();										//�������Ļ
	friend class student;
	sportsmark(void);
	~sportsmark(void);
};

