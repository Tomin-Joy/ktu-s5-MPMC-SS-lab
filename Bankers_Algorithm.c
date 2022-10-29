#include<stdio.h>
int main(){
    int i,j,k,n,r,alloc[10][10],max[10][10],avail[10],need[10][10],count,flag,order[10],fla[10];
    printf("Enter no. of processes :- ");
    scanf("%d",&n);
    printf("Enter no. of resources :- ");
    scanf("%d",&r);
    printf("Enter Alocation Matrix :- \n");
    for(i=0;i<n;i++){
        for (j=0;j<r;j++){
            printf("p[%d][%d] :- ",i,j);
            scanf("%d",&alloc[i][j]);
        }
        fla[i]=0;
    }
    printf("Enter Maximum Matrix :- \n");
    for(i=0;i<n;i++){
        for (j=0;j<r;j++){
            printf("p[%d][%d] :- ",i,j);
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the Available Value :- \n");
    for(i=0;i<r;i++){
        scanf("%d",&avail[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    count=0;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            if(fla[i]==0){
                flag=0;
                for(j=0;j<r;j++){
                    if(need[i][j]>avail[j]){
                        flag=1;
                    }
                }
                if(flag==0){
                    order[count]=i;
                    count++;
                    fla[i]=1;
                    for(j=0;j<r;j++){
                        avail[j]=avail[j]+alloc[i][j];
                    }
                }
            }
        }
    }
    flag=0;
    for(i=0;i<n;i++){
        if(fla[i]==0){
            flag=1;
        }
    }
    if(flag==0){
        printf("It is in safe state\n");
        printf("Safe sequence :- ");
        for(i=0;i<count;i++){
            printf("p[%d]  ",order[i]);
        }
    }
    else{
        printf("It is not in safe sequence");
    }
    return 0;
}
