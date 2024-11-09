#include<stdio.h>
#include<string.h>

//MAX 8-BIT NUMBER

int BinaryToDecimal(char *binaryNum){
	int decimal;
	int i,base=1;
	for(i=7;i>=0;i--){
		if(binaryNum[i]=='1'){
			decimal+=base;
		}
		base*=2;
	}
	return decimal;
}
void DecimalToBinary(int number){
	int binary[8]={0};
	int i=7;
	if(number==0){
		printf("0");
		return;
	}
	while(number>0 && i>=0){
		binary[i]=number%2;
		number=number/2;
		i--;
	}
	for(i=0;i<8;i++){
		printf("%d",binary[i]);
	}
}
void DecimalToHexadecimal(int number){
	char hexa[3];
	hexa[2]='\0';
	int remainder,j;
	int i=1;
	if(number==0){
		printf("0");
		return;
	}
	while(number>0 && i>=0){
		remainder = number % 16;
		if(remainder<10){
			hexa[i]=remainder+'0';
		}else {
            hexa[i]=(remainder-10)+'A';
		number=number/16;
		i--;
		}
	}
	if(i==0){
        hexa[0]=hexa[1]; 
        hexa[1]='0';     
    }else{
        hexa[0]=hexa[1]; 
        hexa[1]='0';     
    }
    for(j=0;j<2;j++){
        printf("%c",hexa[j]);
    }
}

int HexadecimalToDecimal(char *hexNumber){
    int decimal=0;
    int base=1;
	int i,currentValue; 
	char currentChar;
    int length=strlen(hexNumber); 
    for(i=0;i<length;i++){
        currentChar=hexNumber[length-1-i]; 
        if(currentChar>='0' && currentChar<='9'){
            currentValue=currentChar-'0'; 
        }else if (currentChar>='A' && currentChar<='F') {
            currentValue = currentChar-'A'+10;
        }else{
            printf("Invalid hexadecimal digit: %c\n",currentChar);
            return -1; 
        }
        decimal+=currentValue*base; // Multiply current value by the base
        base*=16;
    }
    return decimal;
}

void BinaryToHexadecimal(char *binaryNum){
	int decimal;
    decimal=BinaryToDecimal(binaryNum);
	DecimalToHexadecimal(decimal);
}

void HexadecimalToBinary(char *hexNumber){
	int decimal;
    decimal=HexadecimalToDecimal(hexNumber);
    if(decimal<0){
        return; 
    }
    DecimalToBinary(decimal);
}

int main(){
	int opt,number;
	char bin[8],hex[2];
	printf("**MAX 8-BITS NUMBER ONLY**");
	printf("Your Options:\n1.BinaryToDecimal(char *binaryNum)\n2.DecimalToBinary(int number)\n3.DecimalToHexadecimal(int number)\n4.HexadecimalToDecimal(char *hexNumber)\n5.BinaryToHexadecimal(char *binaryNum)\n6.HexadecimalToBinary(char *hexNumber)");
	printf("\n\nEnter Option Number: ");
	scanf("%d",&opt);
	switch (opt){
		case 1:
			printf("Enter Binary Value: ");
			scanf(" %c",&bin[8]);
			BinaryToDecimal(bin);
			break;
		case 5:
			printf("Enter Binary Value: ");
			scanf(" %c",&bin[8]);
			BinaryToHexadecimal(bin);
			break;
		case 4:
			printf("Enter Hexadecimal Value: ");
			scanf(" %c",&hex[8]);
			HexadecimalToDecimal(hex);
			break;
		case 6:
			printf("Enter Hexadecimal Value: ");
			scanf(" %c",&hex[8]);
			HexadecimalToBinary(hex);
			break;
		case 2:
			printf("Enter Number: ");
			scanf("%d",&number);
			DecimalToBinary(number);
			break;
		case 3:
			printf("Enter Number: ");
			scanf("%d",&number);
			DecimalToHexadecimal(number);
			break;		
		default:
			("Enter Valid Option Number!");
			break;
	}
	return 0;
}
