#include<stdio.h>
#include<math.h>
#include<string.h>



  int main()
  {
      int n,k=0,m,x,y,f=0,z,i,a;
      printf("\nEnter a odd number for primarility check");
      scanf("%d",&n);
      x=n-1;
      while(x!=0)
      {
          if(x%2==0)
          k++;
          x=x/2;


      }
      x=n-1;
      m=x/(pow(2,k));
      printf("\nEnter the value of base:");
      scanf("%d",&a);
      y=(int)(pow(a,m))% n;
      if(y==1||y==n-1)
        printf("\nNumber is prime with high probability");
      else for(i=1;i<k-1;i++)
      {
          z=(int)pow(y,2*i)%n;
          if(z==(n-1)){
            printf("\nNumber is prime with high probability");
            f++;
      }
      }
      if(f!=0)
        printf("\nThis number is composite number");












      return 0;
  }
