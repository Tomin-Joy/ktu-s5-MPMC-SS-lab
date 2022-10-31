//PROGRAM TO IMPLEMENT PAGE REPLACEMENT ALGORITHM
#include<stdio.h>

//Function to implement FIFO
void fifo(int n,int no,int pages[]){
	int i,j,frame[10],k,avail,count=0;
	for(i=0;i<no;i++)
		frame[i]=-1;
	j=0;
	printf("Reference \t Page Frame \n");
	for(i=1;i<=n;i++){
		printf("%d\t\t",pages[i]);
	avail=0;
	for(k=0;k<no;k++)
		if(frame[k]==pages[i])
			avail=1;
		if(avail==0){
			frame[j]=pages[i];
			j=(j+1)%no;
			count++;
			for(k=0;k<no;k++)
				printf("%d\t",frame[k]);
		}
		printf("\n");
	}
}

//Function to implement LRU
void lru(int n,int nf,int pages[]){
	int i,j,k,flag,pag,count,result[10],flagP[10];
	count=0;
	pag=0;
	for(i=0;i<nf;i++){
		result[i]=pages[i];
		count++;
	}
	printf("\nReference \t Page frame\n");
	for(i=0;i<nf;i++){
		printf("%d\t\t",pages[i]);
		for(j=0;j<=i;j++)
			printf("%d   ",result[j]);
		printf("\n");
	}
	for(i=nf;i<n;i++){
		flag=0;
		for(j=0;j<nf;j++){
			flagP[j]=0;
			if(result[j]==pages[i]){
				flag=1;break;
			}
		}
		if(flag==0){
			for(j=i;j>i-nf;j--){
				for(k=0;k<nf;k++){
					if(pages[j]==result[k]){
						flagP[k]=1;break;
					}
				}
			}
			for(j=0;j<nf;j++){
				if(flagP[j]==0){
					result[j]=pages[i];
					count++;break;
				}
			}
		}
		printf("%d\t\t",pages[i]);
		for(j=0;j<nf;j++){
			printf("%d   ",result[j]);
		}
		printf("\n");
	}
	printf("\nPage fault = %d\n",count);
}
void print(int frameNo,int frame[]){
	for(int j=0;j<frameNo;j++)
		printf("%d\t",frame[j]);
	printf("\n");
}
	

//Function to implement LFU
void lfu(int n,int frameNo,int page[]){
	int i,j,k,frame[10],move=0,flag,count=0,count1[10]={0},repIndex,leastCount;
	for(i=0;i<n;i++)
		frame[i]=-1;
	printf("\nReference\t Page Frame\n");
	for(i=0;i<n;i++){
		printf("%d\t\t",page[i]);
		flag=0;
		for(j=0;j<frameNo;j++){
			if(page[i]==frame[j]){
				flag=1;
				count1[j]++;
				printf("No replacement \n");
				break;
			}
		}
		if(flag==0&&count<frameNo){
			frame[move]=page[i];
			count1[move]=1;
			move=(move+1)%frameNo;
			count++;
			print(frameNo,frame);
		}
		else if(flag==0){
			repIndex=0;
			leastCount=count1[0];
			for(j=1;j<frameNo;j++){
				if(count1[j]<leastCount){
					repIndex=j;
					leastCount=count1[j];
				}
			}
			frame[repIndex]=page[i];
			count1[repIndex]=1;
			count++;
			print(frameNo,frame);
		}
	}
	printf("Number of page faults is : %d\n",count);
}
void main(){
	int option,n,nf,pages[50]; 
	do{
		printf("\n*********** MENU **********");
		printf("\n1. FIF0\n2. LRU \n3. LFU\n4. EXIT\n");
		printf("\nSelect an option : ");
		scanf("%d",&option);
		printf("Enter the number of pages : ");
		scanf("%d",&n);
		printf("Enter the reference string : ");
		for(int i=1;i<=n;i++){
			scanf("%d",&pages[i]);
		}
		printf("Enter the no. of frames:");
		scanf("%d",&nf);
		switch(option){
			case 1:fifo(n,nf,pages);break;
			case 2:lru(n,nf,pages);break;
			case 3:lfu(n,nf,pages);break;
			case 4:break;
			default : printf("\nInvalid option selected\n");
		}
	}while(option!=4);
}
