/* Ŀǰ�Ĵ����Ϊ������ */



#include "students.h"
#include "passwordcheck.h"
#include "somepieces.h"


students x;										//���������main�ڲ���ջ���


int main()
{
	system("mode con cols=100 lines=30");		//�趨���ڴ�С
	//passwordcheck("613613613");				//������֤
	FILE *studenttxt = openfile();				//��student.txt�ļ�


	x.inputFromFile(studenttxt);
	x.outPutToScreen();

	system("pause");
	
	return 0;
}