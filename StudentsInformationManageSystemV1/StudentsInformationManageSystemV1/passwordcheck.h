/*��Ҷ ���������û�����һ�����룬��֤�Ƿ�Ͳ����ַ�����ȣ��������ʾ������˳�����*/
/*��Ҷ ����ͨ���˺������ò������Э��������˼���bug*/
/*��� 4/22��������Ҳ������BUG*/
/*����getch�����ǻ��崦���û������ַ�����Ϊ�س����˸�������ַ�����������ֱ��password���������Ӧ���ģ�֮��password����ʹ��뺯�����ַ�������ȣ��������ʾ������ȷ���ó���������У�������ʾ�������δ������������*/
/*������20�ַ�����*/

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
	for(int k = 3 ; k >0 ; k--)						//���λ���
	{
		int pass = 1;								//��������ǲ�����ȷ��
		char password[20],ch,ch2;						//password[]���鴢��,ch������������ַ�,ch2����ڶ����ַ�
		int passwordlen = 0;						//�������볤��
		cout<<"please enter your password:";	
	  while(ch = _getch())						//���ѭ��������ȡ�������password����
		{
			
			
			if((ch<0||ch>150)) {ch2=_getch();if(ch2) continue;}		/*����������BUG�����_getch()�ܶ�ȡ�������ɨ���룩����λ�ַ�*/

			if(ch == '\r') break;					//�����س�������ȡ��������һ���ж�������ȷ��
			 if(ch == '\b')							//�����˸�������������볤�ȴ���0�ͼ�1�������"\b \b"��
			{										//����һ��*��
				if(passwordlen > 0)
				{
					passwordlen--;
					cout<<"\b \b";
				}
			}
			else
			{
				password[passwordlen++] = ch;		//���������������ַ��ʹ������飬���³��ȣ������һ��*����Ļ
				cout<<'*';
			 }
		}
	
		if( s.length() != passwordlen )				//������볤���Ƿ���ȷ���������kֵ��ʾ��������ʣ���������
		{											//������ʾ���رճ���
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
		for(int i = 0 ; i < passwordlen ; i++)		//������볤��û���⣬������λ��������Ƿ���ȷ
		{
			if( s[i] != password[i] )
			{
				pass = 0;							//�д�����passΪ0������kֵ��ʾʣ��������������
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
		if(pass == 1)								//û�д�����ʾ��ȷ��������������ѭ�����˳������麯��
		{
			cout<<"\nCorrect Password\n";
			break;
		}
	}
}