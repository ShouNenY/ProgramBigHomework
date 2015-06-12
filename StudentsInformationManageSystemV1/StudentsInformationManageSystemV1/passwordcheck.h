/*刘叶 创建，让用户输入一个密码，验证是否和参数字符串相等，不相等提示错误后退出程序*/
/*刘叶 测试通过此函数可用并在吴宇航协助下清除了几个bug*/
/*吴宇航 4/22解决方向键也会读入的BUG*/
/*利用getch函数非缓冲处理用户输入字符，分为回车、退格和其他字符三种情况，分别对password数组进行相应更改，之后将password数组和传入函数的字符串的相比，相等则提示密码正确，让程序继续运行，否则提示错误，三次错误后会结束程序*/
/*密码在20字符以内*/

#pragma once
#include<cstdlib>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include <conio.h>

using namespace std;


void passwordcheck(string s)
{
	//cout<<"please don't input character in control field.\n";
	for(int k = 3 ; k >0 ; k--)						//三次机会
	{
		int pass = 1;								//标记密码是不是正确的
		char password[20],ch,ch2;						//password[]数组储存,ch储存读进来的字符,ch2储存第二个字符
		int passwordlen = 0;						//储存密码长度
		cout<<"please enter your password:";	
	  while(ch = _getch())						//这个循环用来读取密码存入password数组
		{
			
			
			if((ch<0||ch>150)) {ch2=_getch();if(ch2) continue;}		/*方向键输入的BUG解决（_getch()能读取方向键的扫描码）有两位字符*/

			if(ch == '\r') break;					//读到回车结束读取，继续下一步判断密码正确性
			 if(ch == '\b')							//读到退格，如果已输入密码长度大于0就减1并且输出"\b \b"来
			{										//消除一个*号
				if(passwordlen > 0)
				{
					passwordlen--;
					cout<<"\b \b";
				}
			}
			else
			{
				password[passwordlen++] = ch;		//读到正常的密码字符就存入数组，更新长度，并输出一个*到屏幕
				cout<<'*';
			 }
		}
	
		if( s.length() != passwordlen )				//检查密码长度是否正确，错误根据k值提示密码错误和剩余输入次数
		{											//或者提示并关闭程序
			pass = 0;
			if(k > 1)
			{
				cout<<"\nPassword Error! "<<k-1<<" chances remained.\n";
				continue;
			}
			else if(k == 1) 
			{
				cout<<"\nPassword Error!\nThe program will be closed.\n";
				system("pause");
				exit(0);
			}
		}
		for(int i = 0 ; i < passwordlen ; i++)		//如果密码长度没问题，继续按位检查密码是否正确
		{
			if( s[i] != password[i] )
			{
				pass = 0;							//有错误标记pass为0，根据k值提示剩余次数或结束程序
				if(k > 1) 
				{
					cout<<"\nPassword Error! "<<k-1<<" chances remained.\n";
					break;
				}
				else if(k == 1)
				{
					cout<<"\nPassword Error! The program will be closed.\n";
					system("pause");
					exit(0);
				}
			}
		}
		if(pass == 1)								//没有错误，提示正确，结束检查密码的循环，退出密码检查函数
		{
			cout<<"\nCorrect Password\n";
			break;
		}
	}
}