/*********************************************************************
* ��Ȩ���� (C)2017, ileyun.org
* 
* �ļ����ƣ� //main.c
* �ļ���ʶ�� // 
* ����ժҪ�� // main����
* ����˵���� // ������
* ��ǰ�汾�� // v1.1
* ��    �ߣ� // ��������<345340585@qq.com>
* ������ڣ� // 2017/08/29
* 
* �޸�����        �汾��     �޸���	      �޸�����
* ---------------------------------------------------------------
* 2017/08/29	     V1.1	   *************************************/
#include "main.h"

int a = 0;
int main()
{
	initStatusLed();
    turnOn(); 
    while(a){
        turnOff();
    }
	return 0;
}
void initPwrLed(){
	GPIOL_CONFIG1= 0x11<<8;
	GPIOL_CONFIG1|= 0x11<<0;
}
void initStatusLed(){
	GPIOA_CONFIG2= 0x77<<16;
	GPIOA_CONFIG2|= 0x77<<8;
	GPIOA_CONFIG2|= 0x17<<0;
}
void turnOn(){
	GPIOA_DATA = 1<<17; 
	GPIOL_DATA = 0xFFF;
}
void turnOff(){
	 
	GPIOA_DATA = 0<<17; 
	GPIOL_DATA = 0x0;
}

