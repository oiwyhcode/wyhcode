#include "jy62.h"

int checkSum(char RxBuffer[])    //SUMCRC(数据和校验)
{       static int a = 0;  // 静态全局变量
a++;
if(a>3){
	a=1;
}
        int i;                                //   循环变量
        int sum = 0;
        for(i=0;i<10;i++)
        {
                sum = sum+RxBuffer[i];
        }
        if(RxBuffer[a*11-1] == (char)(sum))
        {
                return 1;                                //     返回1表示数据正确
        }
        else
        {
                return -1;                                // 返回-1表示数据错误
        }
}
