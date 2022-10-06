#include<stdio.h>
struct cpuScheduling{
	int no;
	int burst;
	int burstCopy;
	int priority;
	int turnAround;
	int waiting;
}p[10],temp;
void print(int n){
	int i;
	printf("\nProc\tbur\tturn\twait\n");
	for(i=0;i<n;i++){
		printf("p[%d]\t%d\t%d\t%d\n",p[i].no,p[i].burst,p[i].turnAround,p[i].waiting);
	}
}
void avgTWCalc(int n,int flag){
	if(flag){
		printf("\nGantt Chart\n");
		printf("0");
		for(int i=0;i<n;i++){
			printf("[%d]  %d  ",p[i].no,p[i].turnAround);
		}
		printf("\n");
		print(n);
	}
	float totalTurn=0,totalWait=0,avgT,avgW;
	for(int i=0;i<n;i++){
		totalTurn+=p[i].turnAround;
		totalWait+=p[i].waiting;
	}
	avgT=totalTurn/n;
	avgW=totalWait/n;
	printf("Average Turnaround Time = %.2f \n",avgT);
	printf("Average Waiting Time = %.2f \n",avgW);
}
void fcfs(int n){
	int i,com=0;
	float totalTurn=0,totalWait=0,avgT,avgW;
	for(i=0;i<n;i++){
		com=com+p[i].burst;
		p[i].turnAround=com;
		p[i].waiting=com-p[i].burst;
	}
	avgTWCalc(n,1);
}
void sjf(int n){
	int i,j,com=0;
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(p[j].burst>p[j+1].burst){
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	for(i=0;i<n;i++){
		com=com+p[i].burst;
		p[i].turnAround=com;
		p[i].waiting=com-p[i].burst;
	}
	avgTWCalc(n,1);
}
void priority(int n){
	int i,j,com=0;
	printf("Enter the Priority\n");
	for(i=0;i<n;i++){
		printf("p[%d] :- ",i);
		scanf("%d",&p[i].priority);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(p[j].priority>p[j+1].priority){
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	for(i=0;i<n;i++){
		com=com+p[i].burst;
		p[i].turnAround=com;
		p[i].waiting=com-p[i].burst;
	}
	avgTWCalc(n,1);
}
void roundRobin(int n){
	int i,quanta,totalBurst=0,com;
	printf("Enter the Time Quanta :- ");
	scanf("%d",&quanta);
	com=0;
	for(i=0;i<n;i++){
		totalBurst+=p[i].burst;
	}
	printf("Gatt chart :- \n 0   ");
	while(com<totalBurst){
		for(i=0;i<n;i++){
			if(p[i].burstCopy>0){
				if(p[i].burstCopy<=quanta){
					com+=p[i].burstCopy;
					p[i].burstCopy=0;
					p[i].turnAround=com;
					p[i].waiting=com-p[i].burst;
				}
				else{
					com+=quanta;
					p[i].burstCopy-=quanta;
				}
				printf("p[%d]  %d   ",i,com);
			}
		}
	}
	print(n);
	avgTWCalc(n,0);
}
int main(){
	int i,j,n,option;
	do{
        printf("*************** MENU *************");
		printf("\nPlease choose your option\n");
		printf("1.FCFS\n2.SJF\n3.PRIORITY\n4.RoundRobin\n5.Exit\n");
		scanf("%d",&option);
        if(option!=5){
            printf("Enter no. of process :- ");
            scanf("%d",&n);
            printf("Enter the burst Time\n");
            for(i=0;i<n;i++){
                printf("p[%d] :- ",i);
                scanf("%d",&p[i].burst);
                p[i].burstCopy=p[i].burst;
                p[i].no=i;
            }
            for(i=0;i<n;i++){
                for(j=0;j<n-1-i;j++){
                    if(p[j].no>p[j+1].no){
                        temp = p[j];
                        p[j] = p[j+1];
                        p[j+1] = temp;
                    }
                }
            }
        }
		switch(option){
			case 1:fcfs(n);break;
			case 2:sjf(n);break;
			case 3:priority(n);break;
			case 4:roundRobin(n);break;
			case 5:break;
			default:printf("Enter a valid option");
		}
	}while(option!=5);
	return 0;
}