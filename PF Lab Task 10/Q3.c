#include<stdio.h>
#include<string.h>

struct Car{
	char make[20];
	char model[20];
	int year,price,mileage;
};
struct Car car_details[10];
int numCars=0;

void addCar(){
	if(numCars>=10){
		printf("Cannot add more cars!\n\n");
		return;
	}
	struct Car newCar;
	printf("Enter car make: \n");
	getchar();
	fgets(newCar.make,20,stdin);
	printf("Enter car model: \n");
//	getchar();
	fgets(newCar.model,20,stdin);
	printf("Enter car year: ");
	scanf("%d",&newCar.year);
	printf("Enter car mileage: ");
	scanf("%d",&newCar.mileage);
	printf("Enter car price: ");
	scanf("%d",&newCar.price);
	
	car_details[numCars]=newCar;
	numCars++;
	printf("Car added!\n\n");
}

void displayCar(){
	int i;
	if(numCars==0){
		printf("No cars to display!\n\n");
		return;
	}
	for(i=0;i<numCars;i++){
		printf("Car %d:\n",i+1);
		printf("Car Make: %s\n",car_details[i].make);
		printf("Car Model: %s\n",car_details[i].model);
		printf("Car Year: %d\n",car_details[i].year);
		printf("Car Mileage: %d\n",car_details[i].mileage);
		printf("Car Price: %d\n\n",car_details[i].price);
	}
}

void search(){
	char carModel[20];
	int i;
	printf("Enter Model of Car to be searched: ");
	getchar();
	fgets(carModel,20,stdin);
	for(i=0;i<numCars;i++){
		if(strcmp(carModel,car_details[i].model)==0){
			printf("Car %d:\n",i+1);
			printf("Car Make: %s\n",car_details[i].make);
			printf("Car Model: %s\n",car_details[i].model);
			printf("Car Year: %d\n",car_details[i].year);
			printf("Car Mileage: %d\n",car_details[i].mileage);
			printf("Car Price: %d\n\n",car_details[i].price);
			return;
		}
	}printf("Car not found!\n\n");
}

int main(){
	int n;
	do{
	printf("1) Add Car to dealership. \n");
	printf("2) Display the Cars in the dealership. \n");
	printf("3) Search Car in the dealership. \n");
	printf("4) Exit. \n\n");
	printf("Enter Choice: ");
	scanf("%d",&n);
	switch(n){
		case 1:
			addCar();
			break;
		case 2:
			displayCar();
			break;
		case 3:
			search();
			break;
		case 4:
			printf("Exiting Program...");
			return 0;
		default:
			printf("Enter valid option!");
			break;
		}
	}while(n!=4);
	return 0;
}
