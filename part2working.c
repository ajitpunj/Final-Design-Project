#include <stdio.h>
#include <time.h>

volatile int * ready = (int *) 0xFF200050;
volatile int * sdram2hpsdata1 = (int *) 0xFF200040;
volatile int * sdram2hpsdata2 = (int *) 0xFF200030;
volatile int * istart = (int *) 0xFF200020;
volatile int * hps2vgadata1 = (int *) 0xFF200010;
volatile int * hps2vgadata2 = (int *) 0xFF200000;
volatile int * ddr3 = (int *) 0x00100000;
volatile int * sdramstart = (int *) 0xFF200080;
volatile int * fifowe = (int *) 0xFF200090;
volatile int * greyparameter = (int *) 0xFF2000b0;
volatile int * binary = (int *) 0xFF2000a0;
volatile int * sdramclock = (int *) 0xFF200070;
volatile int * vgabinary = (int *) 0xFF2000c0;
volatile int * vgaclock = (int *) 0xFF2000d0;
volatile int * vgaread = (int *) 0xFF2000e0;

int main(void)
{

//do{
//printf("\nEnter 1 to start:\n");
//scanf("%d", &start);
//}while(start != 1);


int start;
//int graph[480][640];//fixed indexes
int i = 0;
int m,n;
int count = 0;





	*(istart) = 1;
	*(fifowe) = 1;
	*(greyparameter) = 170;
	*(ready) = 0;

	do{
		printf("\nEnter1");
		scanf("%d", &start);
	}while(start != 1);
    
    
    while (*(vgaread)!=0) {
        //wait
    }
    //after this while loop, the read has been asserted low, now capture image
		
		
		
		*(fifowe) = 0;
		//for(i = 0; i < 1000; i++){}
		*(ready) = 1;
		//printf("\nTest");
		for(i  = 0;i < 480*640; i++){
		*(sdramclock) = 0;
		//for(i = 0; i < 100; i++){}
		ddr3[i] = *(binary);
	
		//graphtemp[count] = *(binary);
		//printf("%d",graphtemp[count]);
		count++;
		//for(i = 0; i < 100; i++){}
		*(sdramclock) = 1;
		}
	
//printf("\nTest");
		i = 0;
		for(m  = 0;m < 480; m++){
			for(n  = 0;n < 640; n++){
				if(ddr3[i]==1023){
				//if(graphtemp[i]==1023){
				//printf("%d",one);
				//graph[n][m] = 1;
				 graph[m][n] = 1;
				}
				if(ddr3[i]==0){
				//if(graphtemp[i]==0){
				//printf("%d",zero);
				graph[m][n] = 0;
				}				
				i++;
				printf("%d",graph[m][n]);
			}
				printf("\n");
			}



	/*	*(ready) = 0;
		i = 0;
		while(1){
		while(*(ready)){
		if(i == 307200){
		break; 
		}
		if(*(vgaclock)){
		*(vgabinary)  = graphtemp[i];
		*(vgaclock) = 0;
		i++;
		}
		}
		}*/

	
		/*for(m  = 0;m < 10; m++){
			for(n  = 0;n < 640; n++){
	
				printf("%d",graph[n][m]);
			}
				printf("\n");
			}*/

	return 0;
}
