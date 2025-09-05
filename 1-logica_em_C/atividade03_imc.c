#include <stdio.h>

float imc(float peso, float altura) {
    /*
    * Recebe um peso, umna altura e calcula o imc do usuário (imc = peso / (altura * altura))
    */
    return (peso / (altura * altura));
}

int main() {
    float peso, altura;
    printf("Digite o peso e a altura com duas casas decimais: \n");
    scanf("%f %f", &peso, &altura);

    float resultado_imc = imc(peso, altura);
    printf("%.2f\n", resultado_imc);

    return 0;
}