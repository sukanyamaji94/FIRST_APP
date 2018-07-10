#include<stdio.h>
#include<string.h>
int multi_invr(int a){

int mliv, mod=26;

int a1,a2,a3,b1,b2,b3,t1,t2,t3,q;
a1=1;
a2=0;
a3=mod;
b1=0;
b2=1;
b3=a;
while(b3>0&&b3!=1)
{
    q=a3/b3;
    t1=a1-(q*b1);
    t2=a2-(q*b2);
    t3=a3-(q*b3);
    a1=b1;
    a2=b2;
    a3=b3;
    b1=t1;
    b2=t2;
    b3=t3;


}
mliv=b2>0?b2:(mod+b2);
return mliv;
}

int gcd(int x, int y){
while(x!=y){
    if(x>y)
        return gcd(x,x-y);
    else
        return gcd(y-x,y);
}

return x;
}


  int main()
  {
        char msg[10],cip[10],plt[10],msg1[10];
        int i,j,m,k,c,a, a1[10],muliv,en[10],ain,dec[10],b=26,a2[10];
        int mod=26;
        printf("\nEnter the msg");
        gets(msg);
        puts(msg);

        //integer representation of charector
        for(i=0;i<10;i++){
            a1[i]=msg[i]-97;

        printf("%d   ",a1[i]);

        }


        printf("\nEnter the value of a,k");
        scanf("%d%d",&a,&k);

        //Encryption
        for(i=0;i<10;i++)
        {
            en[i]=(a1[i]*a)+k;
            if(en[i]>26)
                en[i]=en[i]%26;
            cip[i]=en[i]+97;
        }
        //decryption


        for(i=0;i<4;i++)
        printf("%c  ",cip[i]);
        printf("\n");


        printf("\nEnter msg for depryption:");
        for(i=0;i<4;i++)
            scanf("%c",&msg1[i]);

        for(i=0;i<10;i++){
            a2[i]=msg1[i];
            printf("%c\t",msg1[i]);
        }
            ain=multi_invr(a);
        for(i=0;i<10;i++){
            dec[i]=((a2[i]-k)*ain)%26;
        }
        for(i=0;i<4;i++)
        {

            plt[i]=dec[i]+97;
            printf("%c  ",plt[i]);
        }
        return 0;

  }
