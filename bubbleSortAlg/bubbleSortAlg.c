#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 20


struct stack {
	int top;
	int items[STACKSIZE];
};



void initialize(struct stack* p)
{
	p->top = -1;
}



int empty(struct stack* p)
{
	if (p->top == -1)
		return 1;
	else
		return 0;
}


int pop(struct stack* p)
{
	int pozisyon;
	if (empty(p)) {
		printf("Yigit bos-underflow");
		exit(1); //stdlib.h kütüphanesi gerekli
	}
	pozisyon = p->top;
	p->top--;
	return (p->items[pozisyon]);
}


void push(struct stack* p, int deger)
{
	if (p->top == STACKSIZE - 1) {
		printf("Yigit dolu-overflow");
		exit(1); //stdlib.h kütüphanesi gerekli
	}
	++(p->top);
	p->items[p->top] = deger;
	return;
}
void Goster(struct stack* p) {
	if (empty(p)) {
		printf("Yigit bos.\n");
	}
	else {
		printf("Yigit: ");
		int i = 0;
		for (i = 0; i <= p->top; i++) {
			printf("%d ", p->items[i]);
		}
		printf("\n");
	}
}

void swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void bubbleSort(int arr[], int n) {
	int i, j; // Declare both i and j outside the loop
	for (i = 0; i < n - 1; i++) {
		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
		}
	}
}


void menu() {
	printf("\n");
	printf("***********************************************************\n");
	printf("*Merhaba! Sayilari kucukten buyuge siralamaya hazir misin?*\n");
	printf("*Lutfen yapmak istedigin islemi sec                       *\n");
	printf("***********************************************************\n");
	printf("*                  1.Yeni sayi girisi                     *\n");
	printf("*                  2.Cikis                                *\n");
	printf("***********************************************************\n");
	printf("Secimin nedir:\n");
}



int main() {


	struct stack s;
	initialize(&s);
	int islem, karsilastirma, l, k, z;
	int arr[10];
	int n = sizeof(arr) / sizeof(arr[0]);
	do {
		menu();
		initialize(&s);

		scanf_s("%d", &islem);
		if (islem == 1) {
			printf("Sayilari gir:\n");

			for (l = 0; l < 10; l++) {
				scanf_s("%d", &arr[l]);
				push(&s, arr[l]);
			}
			Goster(&s);

			// Calling bubble sort on array arr
			bubbleSort(arr, n);



			for (z = n - 1; z >= 0; z--) {
				karsilastirma = pop(&s);
				if (karsilastirma == arr[z]) {
					printf("Siralaman dogru\n");
				}
				else {
					printf("Yanlis siralama. Dogru siralama: ");
					for (k = 0; k < n; k++) {
						printf("%d ", arr[k]);
					}
					printf("\n");
					break;
				}
			}

		}
		else if (islem == 2) {
			return 0;
		}
		else {
			printf("Gecersiz secim yaptin:\n");
			islem == 1;
		}

	} while (islem == 1);

	return 0;
}