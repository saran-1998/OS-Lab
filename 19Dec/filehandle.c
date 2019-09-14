#include<stdio.h>
int main()
{
	FILE *fp;
	int a,b;
	fp = fopen("inp.txt","r");
	fscanf(fp,"%d%d",&a,&b);
	int sum = a+b;
	fclose(fp);
	fp = fopen("output.txt","w");
	fprintf(fp,"Sum = %d",sum);
	fclose(fp);
	return 0;
}
