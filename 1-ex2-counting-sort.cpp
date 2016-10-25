#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include<windows.h>

double t[6];
int num[1594323];

int B[1594323];
long int C[65536];

void CountingSort(int a[],int m)
{
	long int n;
	n = pow(3,m);
	long int i,j;
	
	LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
	
	for(i = 0;i <65536;i++)
		C[i] = 0;
	for(j = 0;j < n;j++)
		C[a[j]] = C[a[j]] + 1;
	for(i = 1;i < 65536;i++)
		C[i] = C[i] +C[i-1];
	for(j=n-1;j>=0;j--)
	{
		B[C[a[j]]-1]=a[j];
		C[a[j]]=C[a[j]]-1;
	}
	
	QueryPerformanceCounter(&t2);
    FILE *fp;  

	switch (m){
	
		case 3:if ((fp = fopen("F:\\PB14011025-project1\\ex2\\output\\counting-sort\\result_3.txt", "wb")) == NULL) exit(0);
		  t[0] = (t2.QuadPart - t1.QuadPart)*1.0/tc.QuadPart; break;
		case 5:if ((fp = fopen("F:\\PB14011025-project1\\ex2\\output\\counting-sort\\result_5.txt", "wb")) == NULL)  exit(0);
		 t[1] = (t2.QuadPart - t1.QuadPart)*1.0/tc.QuadPart;  break;
		case 7:if ((fp = fopen("F:\\PB14011025-project1\\ex2\\output\\counting-sort\\result_7.txt", "wb")) == NULL)  exit(0);
		 t[2] = (t2.QuadPart - t1.QuadPart)*1.0/tc.QuadPart;  break;
		case 9:if ((fp = fopen("F:\\PB14011025-project1\\ex2\\output\\counting-sort\\result_9.txt", "wb")) == NULL)  exit(0); 
		 t[3] = (t2.QuadPart - t1.QuadPart)*1.0/tc.QuadPart; break;
		case 11:if ((fp = fopen("F:\\PB14011025-project1\\ex2\\output\\counting-sort\\result_11.txt", "wb")) == NULL)  exit(0);
		 t[4] = (t2.QuadPart - t1.QuadPart)*1.0/tc.QuadPart;  break;
		case 13:if ((fp = fopen("F:\\PB14011025-project1\\ex2\\output\\counting-sort\\result_13.txt", "wb")) == NULL)  exit(0); 
		 t[5] = (t2.QuadPart - t1.QuadPart)*1.0/tc.QuadPart; break;
		default:break;
	} 
	
	for(i = 0;i < n; i++)
	{
	    fseek(fp, 0, SEEK_END); 
		fprintf(fp,"%d\n",B[i]);
	 } 
	 fclose(fp);
}

int main(void)
{
	 FILE *fp1;  

	int n;	
	long int n1;

	for(n =3;n<14; n=n+2)
	{
		
			if ((fp1 = fopen("F:\\PB14011025-project1\\ex2\\input\\input_strings.txt", "rb")) == NULL)  
	       {  
   	           exit(0);  
	       } 
		n1 = pow(3,n);
		
		long int k = 0;
		while(!feof(fp1) && k < n1)
		{
			fscanf(fp1,"%d",&num[k]);
			//printf("%d\n",num[k]);
			k++;
		}
		fclose(fp1);
		CountingSort(num,n);
	}
	FILE *fp2;
		if ((fp2 = fopen("F:\\PB14011025-project1\\ex2\\output\\counting-sort\\time.txt", "wb")) == NULL) exit(0);
		int k;
		for(k = 0; k<6; k++)
		{
			fseek(fp2, 0, SEEK_END); 
		fprintf(fp2,"%f",t[k]);
		fprintf(fp2,"%c",'\n');
		}
		fclose (fp2);
		
}
