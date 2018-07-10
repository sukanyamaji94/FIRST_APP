#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
float a[10],b[10],att;
float eu_dis,c[10],d[10],sum=0.0,min_kwsk,summi=0.0,p,s[10];
float w[10],wd[10],sumwd=0.0;
12
CS-522-Advanced Databases and Data Mining
17203024
int i,j,k;
printf("\n......Distances......");
printf("\nHow many attributes:(atmost 10) ");
scanf("%f",&att);
printf("\nEnter the weight for all attributes:");
for(i=0;i<att;i++)
scanf("%f",&w[i]);
printf("\nEnter the value of attributes for A point:");
for(i=0;i<att;i++)
{
scanf("%f",&a[i]);
}
printf("\nEnter the value of attributes for B point:");
for(i=0;i<att;i++)
{
scanf("%f",&b[i]);
}
printf("\nEnter the value of k for calculating minkowsk distance=");
scanf("%d",&k);
for(i=0;i<att;i++)
{
c[i]=(a[i]-b[i])*(a[i]-b[i]);
s[i]=(a[i]-b[i])>0?(a[i]-b[i]):(-(a[i]-b[i]));
sum=sum+c[i];
}
for(i=0;i<att;i++)
{
wd[i]=w[i]*c[i];
sumwd=sumwd+wd[i];
}
max=s[0];
for(i=0;i<att;i++)
{
d[i]=1;
for(j=0;j<k;j++)
{
d[i]=d[i]*(a[i]-b[i]);
}
printf("%.2f ",d[i]);
summi=(summi+d[i]);
if(s[i]>max)
max=s[i];
}
summi=(summi>0)?summi:(-summi);
eu_dis=sqrt(sum);
p=(1/(float)k);
min_kwsk=pow((summi),p);
printf("\nThe euclidian distance is=%.2f",eu_dis);
printf("\nThe minkowsk distance is %f %.2f",min_kwsk,(summi));
printf("\nThe value of supremam distance is=%.2f",max);
printf("\nThe value of weighted euclidian is %.2f",sumwd);
}
}