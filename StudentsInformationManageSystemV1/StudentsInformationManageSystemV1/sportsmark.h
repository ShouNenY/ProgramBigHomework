#pragma once
#include <cstdio>
#include <iostream>
using namespace std;
class sportsmark
{
private:
	double SPyear;													//�������
	double pullup,thouthand;										// ��������/��������,/1000m/800m
	double jump,fifty,anteflexion,weight,height,vitalcapacity;		//50m��������Զ����λ��ǰ��������,��ߣ��λ���


	void inputfromfile(FILE *filename);							//���ļ�����					ly�����
	void outputtoscreen();										//�������Ļ					ly�����
	void sportoutputtofile(FILE *filename);						//������ļ�					wyh�����
	void inputfromuser();										//����Ļ����					ly�����

	friend class student;
	friend class students;
	sportsmark(void);
	~sportsmark(void);
};

