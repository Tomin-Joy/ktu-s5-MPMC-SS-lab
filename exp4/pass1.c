#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int searchOpcode(char opcode[]){
	FILE *optab;
	char op[10];
	optab = fopen("optab.txt","r");
	while(!feof(optab)){
		fscanf(optab,"%s",op);
		if(!strcmp(op,opcode)){
			return 1;
		}
	}
	return 0;
}
int main(){
	FILE *in,*out,*sym;
	int sA,locctr,op;
	char label[10],opcode[10],operand[10];
	in = fopen("input.txt","r");
	out = fopen("intermediate.txt","w");
	sym = fopen("symtab.txt","w");
	if(!feof(in)){
		fscanf(in,"%s%s%d",label,opcode,&op);
		if(!strcmp(opcode,"START")){
			sA=op;
			locctr=op;
			fprintf(out,"%s %s %s %d\n"," - ",label,opcode,op);
			
		}
		else{
			locctr=0;
			sA=0;
		}
	}
	while(!feof(in)){
		
		fscanf(in,"%s%s%s",label,opcode,operand);
		
		fprintf(out,"%d %s %s %s\n",locctr,label,opcode,operand);
		if(!strcmp(label,"**")){
			if(!strcmp(opcode,"END")){
				break;
				}
			locctr+=3;
			
		}else{
			if(searchOpcode(opcode)){
				locctr+=3;
			}
			else if(!strcmp(opcode,"WORD")){
				fprintf(sym,"%s %d\n",label,locctr);
				locctr+=3;
				
			}
			else if(!strcmp(opcode,"RESW")){
				fprintf(sym,"%s %d\n",label,locctr);
				op=	atoi(operand);
				op*=3;
				locctr+=op;
				
			}
			else if(!strcmp(opcode,"BYTE")){
				fprintf(sym,"%s %d\n",label,locctr);
				locctr+=(strlen(operand)-3);
			}
			
			else{
				printf("opcode error");
			}
		}
		
	}
	printf("length = %d\n",locctr-sA);
	return 0;
			
}
