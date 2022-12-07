#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int searchSymtab(char label[10]){
    char symbol[10];
    FILE *symtab;
    int value;
    symtab=fopen("symtab.txt","r");
    while(!feof(symtab)){
        fscanf(symtab,"%s%d",symbol,&value);
        if(strcmp(label,symbol)==0){
            return 1;
        }
    }
    fclose(symtab);
    return 0;
}
int searchOptab(char opcode[10]){
    char op[10];
    int value;
    FILE *optab;
    optab=fopen("optab.txt","r");
    while(!feof(optab)){
        fscanf(optab,"%s%d",op,&value);
        if(strcmp(opcode,op)==0){
            return 1;
        }
    }
    fclose(optab);
    return 0;
}
int main(){
    FILE *input,*intermediate,*symtab;
    int length,pgLength;
    char label[20],opcode[20],operand[20];
    int sA,LOCCTR,op;
    input=fopen("input.txt","r");
    intermediate=fopen("intermediate.txt","w");
    symtab=fopen("symtab.txt","w");
    fscanf(input,"%s%s%d",label,opcode,&op);
    if(strcmp(opcode,"START")==0){
        sA=op;
        LOCCTR=op;
        fprintf(intermediate,"\t%s\t\t%s\t\t%d\n",label,opcode,op);
    }
    else{
        LOCCTR=0;
    }
    while(strcmp(opcode,"END")!=0){
        fscanf(input,"%s%s%s",label,opcode,operand);
        fprintf(intermediate,"%d\t\t%s\t\t%s\t\t%s\n",LOCCTR,label,opcode,operand);
        pgLength=LOCCTR-sA;
        if(strcmp(label,"**")!=0){
            if(searchSymtab(label)==0){
                fprintf(symtab,"%s %d\n",label,LOCCTR);
            }
        }
        if(searchOptab(opcode)==1){
            LOCCTR+=3;
        }
        else if(strcmp(opcode,"WORD")==0){
            LOCCTR+=3;
        }
        else if(strcmp(opcode,"RESW")==0){
            op=atoi(operand);
            LOCCTR=LOCCTR+(3*op);
        }
        else if(strcmp(opcode,"RESB")==0){
            op=atoi(operand);
            LOCCTR=LOCCTR+op;
        }
        else if(strcmp(opcode,"BYTE")==0){
            length=strlen(operand)-3;
            LOCCTR=LOCCTR+length;
        }
    }
    fclose(input);
    fclose(intermediate);
    fclose(symtab);
    printf("Program Length = %d",pgLength);
    return 0;
}
