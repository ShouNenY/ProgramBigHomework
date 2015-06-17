#pragma once
#include <cstdio>
#include <iostream>
using namespace std;
class sportsmark
{
private:
	double SPyear;													//测试年份
	double pullup,thouthand;										// 引体向上/仰卧起坐,/1000m/800m
	double jump,fifty,anteflexion,weight,height,vitalcapacity;		//50m、立定跳远，坐位体前屈，体重,身高，肺活量


	void inputfromfile(FILE *filename);							//从文件输入					ly已完成
	void outputtoscreen();										//输出到屏幕					ly已完成
	void sportoutputtofile(FILE *filename);						//输出到文件					wyh已完成
	void inputfromuser();										//从屏幕输入					ly已完成

	friend class student;
	friend class students;
	sportsmark(void);
	~sportsmark(void);
};

