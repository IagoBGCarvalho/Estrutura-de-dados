#include <stdio.h>
#include <stdlib.h>

int IMC(double peso, double altura){
    double IMC = (peso / (altura * altura));
    return IMC;
}

int main(){
    double p, a;

    printf("Digite o peso: ");
    scanf("%lf", &p);

    printf("Digite a altura: ");
    scanf("%lf", &a);

    double resultado_imc = IMC(p, a);
    printf("O resultado do IMC foi: %.2lf\n", resultado_imc);
    
    return 0;
}