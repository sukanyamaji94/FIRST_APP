
#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int main()
{

     int s0[4][4]={{01,00,11,10},
                 {11,10,01,00},
                 {00,10,01,11},
                 {11,01,11,10}},
        s1[4][4]={{00,01,10,11},
                {10,00,01,11},
                {11,01,00,11},
                {10,01,00,11}},
        p10[]={3,5,2,7,4,10,1,9,8,6},
        p8[]={6,3,7,4,8,5,10,9},
        p4[]={2,4,3,1},
        ep[]={4,1,2,3,2,3,4,1},
        ip[]={2,6,3,1,4,8,5,7},
        ipiv[]={4,1,3,5,7,2,8,6};

        int fpt[8],temp3[4],key[10],pt[8],ct[8],i,temp[10],key1[8],key2[8],tem,j,rpt[4],lpt[4],temp1[8],index[4],r,l0pt[4],r0pt[4],l2pt[4],r2pt[4];
       printf("\n.......Implementation of Simplified-DES.........\n");
        printf("\n\tEnter the key:");
        for(i=0;i<10;i++)
            scanf("%d",&key[i]);
       printf("\n\tEnter the plaintext:");
        for(i=0;i<8;i++)
            scanf("%d",&pt[i]);

            //Rearrange by p10
            for(i=0;i<10;i++)
            {   j=p10[i]-1;
                temp[i]=key[j];
              // printf("%d ",temp[i]);

            }
            for(i=0;i<10;i++)
            {
                key[i]=temp[i];
               // printf("%d  ",key[i]);
            }


           // left shift
            tem=key[0];
            for(i=0;i<4;i++)
            {

                key[i]=key[i+1];
            }
            key[4]=tem;
            tem=key[5];
            for(i=5;i<9;i++)
            {
                key[i]=key[i+1];
            }
            key[9]=tem;
            for(i=0;i<10;i++)
              // printf("%d  ",key[i]);


        //Rearrange by p8
        for(i=0;i<10;i++)
            {
                j=p8[i]-1;
                temp[i]=key[j];
                //printf("%d  ",temp[i]);


            }
            //printf("\nKey 1  ");
            for(i=0;i<8;i++)
            {
                key1[i]=temp[i];
              //printf("%d  ",key1[i]);
            }

            //left shift again to get key2
                   tem=key[0];
            for(i=0;i<4;i++)
            {

                key[i]=key[i+1];
            }
            key[4]=tem;
            tem=key[5];
            for(i=5;i<9;i++)
            {
                key[i]=key[i+1];
            }
            key[9]=tem;
            tem=key[0];
            for(i=0;i<4;i++)
            {

                key[i]=key[i+1];
            }
            key[4]=tem;
            tem=key[5];
            for(i=5;i<9;i++)
            {
                key[i]=key[i+1];
            }
            key[9]=tem;
          //  for(i=0;i<10;i++)
            //    printf("%d  ",key[i]);

            //rearrange by p8

            for(i=0;i<10;i++)
            {
                temp[i]=key[p8[i]-1];

            }
            //printf("\nKey 2  ");
            for(i=0;i<8;i++)
            {
                key2[i]=temp[i];
              //printf("%d  ",key2[i]);
            }
//End of key generation


			//printf("\nAfter initial permutation:");
            for(i=0;i<8;i++)
            {
                temp[i]=pt[ip[i]-1];
              //printf("%d  ",temp[i]);
            }


            //printf("\nthe left half:");
            for(i=0;i<4;i++)
            {
                l0pt[i]=temp[i];
              //printf("  %d  ",l0pt[i]);
            }


            //printf("\nright half:  ");
            for(i=0;i<4;i++)
            {
                r0pt[i]=temp[i+4];
              //printf(" %d  ",r0pt[i]);

            }


            //printf("\nAfter EP  ");
         	for(i=0;i<8;i++)
            {
                j=ep[i]-1;
                temp[i]=r0pt[j];

    		//printf("%d ",temp[i]);
            }

            //printf("\nafter xor with key1:");
            for(i=0;i<8;i++)
            {
            	if(key1[i]==temp[i])
				{

           			 temp1[i]=0;
        			}
        		else
        		temp1[i]=1;
        		//printf("  %d",temp1[i]);

			}
			 //printf("\nthe left half:");
            for(i=0;i<4;i++)
            {
                lpt[i]=temp1[i];
              //printf("  %d  ",lpt[i]);
            }


            //printf("\nright half:  ");
            for(i=0;i<4;i++)
            {
                rpt[i]=temp1[i+4];
              //printf(" %d  ",rpt[i]);

            }

			if(lpt[0]==0&&lpt[3]==0)
			index[0]=0;
			else if(lpt[0]==0&&lpt[3]==1)
			index[0]=1;
			else if(lpt[0]==1&&lpt[3]==0)
			index[0]=2;
			else if(lpt[0]==1&&lpt[3]==1)
			index[0]=3;

			if(lpt[1]==0&&lpt[2]==0)
			index[1]=0;
			else if(lpt[1]==0&&lpt[2]==1)
			index[1]=1;
			else if(lpt[1]==1&&lpt[2]==0)
			index[1]=2;
			else if(lpt[1]==1&&lpt[2]==1)
			index[1]=3;


            if(rpt[0]==0&&rpt[3]==0)
			index[2]=0;
			else if(rpt[0]==0&&rpt[3]==1)
			index[2]=1;
			else if(rpt[0]==1&&rpt[3]==0)
			index[2]=2;
			else if(rpt[0]==1&&rpt[3]==1)
			index[2]=3;

			if(rpt[1]==0&&rpt[2]==0)
			index[3]=0;
			else if(rpt[1]==0&&rpt[2]==1)
			index[3]=1;
			else if(rpt[1]==1&&rpt[2]==0)
			index[3]=2;
			else if(rpt[1]==1&&rpt[2]==1)
			index[3]=3;

			int llpt=s0[index[0]][index[1]];
			//int rlpt=s[index[1]][index[2]];
			int rrpt=s1[index[2]][index[3]];
			//printf("\n %d  %d",llpt,rrpt);

			for(i=1;i>=0;i--){
                r=llpt%10;
                pt[i]=r;
                llpt=llpt/10;

			}

			for(i=3;i>=2;i--){
                r=rrpt%10;
                pt[i]=r;
                rrpt=rrpt/10;
			}
			//for(i=0;i<4;i++)
              //  printf("%d  ",pt[i]);
			//printf("\nAfter p4::");
			for(i=0;i<4;i++){
               // printf("\n %d",pt[i]);
               temp[i]=pt[p4[i]-1];


              //  printf("   %d",temp[i]);
                //printf("   %d",l0pt[i]);

			}
			//printf("\nAfter xor with left half::");
			 for(i=0;i<4;i++)
            {
            	if(l0pt[i]==temp[i])
				{

           			 temp1[i]=0;
        			}
        		else
        		temp1[i]=1;
        		//printf("  %d",temp1[i]);

			}
			for(i=0;i<4;i++)
                temp3[i]=temp1[i];

			//printf("\nAfter EP  ");
         	for(i=0;i<8;i++)
            {
                j=ep[i]-1;
                temp[i]=temp1[j];

    		//printf("%d ",temp[i]);
            }
            //printf("\nXor with k2::  ");

            for(i=0;i<8;i++)
            {
            	if(key2[i]==temp[i])
				{

           			 temp1[i]=0;
        			}
        		else
        		temp1[i]=1;
        		//printf("  %d",temp1[i]);

			}

			//printf("\nthe left half 2:");
            for(i=0;i<4;i++)
            {
                l2pt[i]=temp1[i];
              //printf("  %d  ",l2pt[i]);
            }


            //printf("\nright half 2:  ");
            for(i=0;i<4;i++)
            {
                r2pt[i]=temp1[i+4];
              //printf(" %d  ",r2pt[i]);

            }

			if(l2pt[0]==0&&l2pt[3]==0)
			index[0]=0;
			else if(l2pt[0]==0&&l2pt[3]==1)
			index[0]=1;
			else if(l2pt[0]==1&&l2pt[3]==0)
			index[0]=2;
			else if(l2pt[0]==1&&l2pt[3]==1)
			index[0]=3;

			if(l2pt[1]==0&&l2pt[2]==0)
			index[1]=0;
			else if(l2pt[1]==0&&l2pt[2]==1)
			index[1]=1;
			else if(l2pt[1]==1&&l2pt[2]==0)
			index[1]=2;
			else if(l2pt[1]==1&&l2pt[2]==1)
			index[1]=3;


            if(r2pt[0]==0&&r2pt[3]==0)
			index[2]=0;
			else if(r2pt[0]==0&&r2pt[3]==1)
			index[2]=1;
			else if(r2pt[0]==1&&r2pt[3]==0)
			index[2]=2;
			else if(r2pt[0]==1&&r2pt[3]==1)
			index[2]=3;

			if(r2pt[1]==0&&r2pt[2]==0)
			index[3]=0;
			else if(r2pt[1]==0&&r2pt[2]==1)
			index[3]=1;
			else if(r2pt[1]==1&&r2pt[2]==0)
			index[3]=2;
			else if(r2pt[1]==1&&r2pt[2]==1)
			index[3]=3;

			int llpt2=s0[index[0]][index[1]];
			//int rlpt=s[index[1]][index[2]];
			int rrpt2=s1[index[2]][index[3]];
			//printf("\n %d  %d",llpt2,rrpt2);

			for(i=1;i>=0;i--){
                r=llpt2%10;
                pt[i]=r;
                llpt2=llpt2/10;

			}

			for(i=3;i>=2;i--){
                r=rrpt2%10;
                pt[i]=r;
                rrpt2=rrpt2/10;
			}
//for(i=0;i<4;i++)
  //              printf("%d  ",pt[i]);
			//printf("\nAfter p4::");
			for(i=0;i<4;i++){
               // printf("\n %d",pt[i]);
               temp[i]=pt[p4[i]-1];


              //  printf("   %d",temp[i]);
              //  printf("   %d",r0pt[i]);

			}
            //printf("\nAfter xor with left half::");
			 for(i=0;i<4;i++)
            {
            	if(r0pt[i]==temp[i])
				{

           			 temp1[i]=0;
        			}
        		else
        		temp1[i]=1;
        		//printf("  %d",temp1[i]);

			}
			for(i=0;i<4;i++)
            {
                pt[i]=temp1[i];
            }
            for(i=0;i<4;i++)
            {
                pt[i+4]=temp3[i];
            }
            printf("\n\tCipher text is:  ");
            for(i=0;i<8;i++)

            {
                temp[i]=pt[ipiv[i]-1];
              printf("%d  ",temp[i]);
            }
            printf("\n\n");
    return 0;
}
