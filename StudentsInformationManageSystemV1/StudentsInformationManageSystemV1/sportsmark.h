#pragma once
#include <cstdio>
#include <iostream>
using namespace std;
class sportsmark
{
private:
	double SPyear;													//测试年份
	double pullup,thouthand;										// 引体向上/仰卧起坐,/1000m/800m
	double jump,fifty,anteflexion,weight,height,vitalcapacity;	//50m、立定跳远，坐位体前屈，体重,身高，肺活量

																//根据测试结果确定成绩的函数

	void inputfromfile(FILE *filename);							//从文件输入
	void outputtoscreen();										//输出到屏幕
	friend class student;
	sportsmark(void);
	~sportsmark(void);
};

