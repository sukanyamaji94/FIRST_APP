#include<stdio.h>
#include<math.h>
#include<string.h>
int mulv(int a,int mod){
int val=a,mliv;
//printf("\nEnter the value :");
//scanf("%d",&val);
//printf("\nEnter the modulus value");
//scanf("%d",&mod);
int a1,a2,a3,b1,b2,b3,t1,t2,t3,q;
a1=1;
a2=0;
a3=mod;
b1=0;
b2=1;
b3=val;
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
       if(b3==1)
        mliv=b2>0?b2:(mod+b2);
    return mliv;

    if(b3==0)
        return 0;

}

int main()
{
   int e,n,d,m,c,p,q,totient,m1=0,c1,i,g;
   printf("\n.........RSA CRYPTOSYSTEM........\n");
    printf("\n\tEnter the public key of alice p,q,e");
    scanf("%d%d%d",&p,&q,&e);
    n=p*q;
    totient=(p-1)*(q-1);
    d=mulv(e,totient);
    //printf("%d",d);
    printf("\n\tEnter the message=");
    scanf("%d",&m);
    c=(int)pow(m,e)%n;
     printf("\n\tThe ciphertext is %d\n",c);
     printf("\n\tEnter the message for decryption=");
    scanf("%d",&c1);

        g=d/2;
        m1=c1;
        c1=1;
        for(i=0;i<g;i++)
        {
            c1=(c1*(int)pow(m1,2))%n;
            //printf("  %d",m1);
        }
        if(d%2!=0){

        c1=(c1*m1)%n;

    }
    //m1=()(pow(c1,d))%n;
    printf("\n\tThe plaintext is %d\n",c1);
    return 0;
}
