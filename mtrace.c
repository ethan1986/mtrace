#include <stdio.h>  
#include <stdlib.h>  
#include <string.h> 
#include <mcheck.h> 

int main()
{  
	setenv("MALLOC_TRACE", "output", 1);  /* ��������MALLOC_TRACEΪ��¼�ļ�·��,����ڴ������Ϣ */
	mtrace();  
   
	char * text = (char *)malloc(sizeof(char)*100);  
	memset(text, 0, 100);  
	memcpy(text, "hello,world!", 12);  
   
	printf("%s/n",text);  
	
	unsetenv("MALLOC_TRACE");
	
	return 0;  
} 

/*
mtrace��ԭ���Ǽ�¼ÿһ��malloc-free��ִ�У���ÿһ��malloc������Ӧ��free�������û���ڴ�й¶��
�����κη�malloc/free��r�����������ڴ�й¶���⣬mtrace�������ҳ�����
ʹ�÷�ʽ��mtrace app(��ִ���ļ�����) output(��¼�ļ�)
*/
 
