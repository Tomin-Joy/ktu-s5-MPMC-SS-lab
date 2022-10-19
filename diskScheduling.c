#include<stdio.h>
#include<stdlib.h>
int fcfs(int np,int init,int size, int req[]){
    int i,totalDisk=0;
    for(i=0;i<np;i++){
        totalDisk+=abs(req[i]-init);
        init=req[i];
    }
    return totalDisk;
}
int scan(int np,int init,int size,int req[],int dir){
    int i,temp,totalDisk=0;
    for(i=0;i<np;i++){
        for(int j=0;j<np-i-1;j++){
            if(req[j]>req[j+1]){
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }
    if(!dir)
        totalDisk=(size-init)+(size-req[0]);
    else
        totalDisk=(init+req[np-1]);
    return totalDisk;
}
int c_scan(int np,int init,int size,int req[],int dir){
    int i,temp,point,totalDisk=0;
    for(i=0;i<np;i++){
        for(int j=0;j<np-i-1;j++){
            if(req[j]>req[j+1]){
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }
    point=init;
    for(i=0;i<np;i++){
        if(req[i]>point){
            point=req[i-1];
            break;
        }
    }
    if(!dir)
        totalDisk=(size-init)+(point)+size;
    else
        totalDisk=(init+req[np-1]);
    return totalDisk;
}
int main(){
    int choice,i,init,np,dir,temp,size,req[50];
    do{
        printf("********MENU********\n");
        printf("1. FCFS\n2. SCAN\n3. C-SCAN\n4. EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        if(choice>=1&&choice<=3){
            printf("Enter the number of process : ");
            scanf("%d",&np);
            printf("Enter the request sequence : ");
            for(i=0;i<np;i++)
                scanf("%d",&req[i]);
            printf("Enter the initial disk position : ");
            scanf("%d",&init);
            if(choice!=1){
                printf("Enter disk size : ");
                scanf("%d",&size);
                size-=1;
                printf("Enter direction of head (0 for left to right any other number for right to left) : ");
                scanf("%d",&dir);
            }
        }
        switch (choice){
            case 1: printf("The total disk movement : %d cylinders\n",fcfs(np,init,size,req));break;
            case 2: printf("The total disk movement : %d cylinders\n",scan(np,init,size,req,dir));break;
            case 3: printf("The total disk movement : %d cylinders\n",c_scan(np,init,size,req,dir));break;
            case 4: break;
            default: printf("\nInvalid option selected\n");
        }
    }while(choice!=4);
    return 0;
}