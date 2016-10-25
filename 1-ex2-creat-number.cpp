#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include<string.h>

int main(void)
{
	long int n = pow(3,13);
	long int i;
	int j;
	
	FILE *fp;  
	if ((fp = fopen("F:\\PB14011025-project1\\ex2\\input\\input_strings.txt.txt", "wb")) == NULL)  
	{  
   	 exit(0);  
	} 
	for(i = 0;i < n; i++)
	{
		int num;
		num=1+rand()%65535;
	    fseek(fp, 0, SEEK_END); 
		fprintf(fp,"%d\n",num);
	 } 
	 fclose(fp);
}
