#include<stdio.h>

int n, b; 

int multRec(int a, int b) {
	if(a == 0 || b == 0) {
		return 0;
	}
	if(b == 1) {
		return a;
	}
	return a + multRec(a, b - 1);
}

int main(){
  printf("Digite um numero:");
   scanf("%d",&n);
  printf("Digite outro numero:");
   scanf("%d",&b);
   printf("Resultado: %d\n", multRec(n, b));
   return 0;
}