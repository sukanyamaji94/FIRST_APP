#include <stdio.h>
#include <stdint.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int l,i,j,m,pl,s[256],t[256],k[256],key[256];
    unsigned int p[256],k1[256],a,temp;
    int c[256];
    printf("\n......Implementation of RC4 cryptosydtem.......\n");
    printf("\n\tEnter the length of state vector=");
    scanf("%d",&l);
    printf("\n\tEnter the length of key=");
    scanf("%d",&j);
    printf("\n\tEnter the key");
    for(i=0;i<j;i++)
    scanf("%d",&key[i]);
    printf("\nEnter the plaintext, length of plaintext=");
    scanf("%d",&pl);
    for(i=0;i<pl;i++)
        scanf("%d",&p[i]);
//for(i=0;i<pl;i++)
  //      printf("%d",p[i]);

    for(i=0;i<l;i++)
    {
        s[i]=i;
        k[i]=i%j;
    }
    m=0;
    for(i=0;i<l;i++)
    {

        m=(m+s[i]+k[i])%l;
        swap(&s[i],&s[m]);
    }
   i=0, j=0;
   int v=0;
  while(v<5)
  {
      i=(i+1)%8;
      j=(j+s[i])%8;
      temp=s[i];
      s[i]=s[j];
      s[j]=temp;
      k1[v]=s[(s[i]+s[j])%8];
      c[v]=k1[v]^p[v];
     // printf("%d\t",k1[v]);
              v++;
  }
    printf("\n\tciphertext is=");
    for(i=0;i<5;i++){
       // c[i]=(unsigned int)p[i]^(unsigned int)k1[i];
          printf("%d  ",c[i]);


    }
    printf("\n\n");






    return 0;
}
