/* 
題目名稱:作業11
製作:呂家明 
修改/完成日期:2019/4/9
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int award_money(char[]);//兌獎副函式 

int main(void){
	
	char input_number[9];//建立int變數輸入統一發票號碼 
	
	do{
		printf("請輸入統一號碼:");
		gets(input_number);//輸入變數 
		printf("中獎金額%d元\n",award_money(input_number));
	}while(input_number!=NULL);
	
	return 0;
	system("pause");

}
int award_money(char input_number[]){
	
	char first_award[9]="00106725";//特別獎 
	char second_award[9]="90819218";//特獎 
	char thirst_award[3][9]={"13440631","26650552","09775722" };//頭獎 
	char additional_award[2][4]={"809","264"};//六獎 
	int same_number=0;//對中n個號碼 
	int i;//迴圈 
	
	for(i=7;i>=0;i--){
		
		if(first_award[i]==input_number[i]){
			same_number+=1;
		}
		else{
			break;
		}
	}	
	//對特別獎、2-6獎 
	if(same_number>=3){
		
		switch(same_number){
			
			case 8:{
				return 10000000;
				break;
			}
			case 7:{
				return 40000;
				break;
			}
			case 6:{
				return 10000;
				break;
			}
			case 5:{
				return 4000;
				break;
			}
			case 4:{
				return 1000;
				break;
			}
			case 3:{
				return 200;
				break;
			}
					
		}
	}
	
	
	if(strcmp(input_number,second_award)==0){  //特獎
		return 2000000;
	}
	else{
		
		for(i=0;i<3;i++){ //對照頭獎 
			
			if(strcmp(input_number,thirst_award[i])==0){
				return 200000;
				break;
			}
		}
		for(i=0;i<2;i++){ //對照增開六獎 
			
			if(strncmp(&input_number[5],additional_award[i],3)==0){
				return 200;
				break;
			}
		}
		
	
	} 
	return 0;//都沒中，零元 
}
	
	
	

