#include <stdio.h>

void listarNotas(float notas[], int quantidade);
float calculaMedia(float notas[], int quantidade);
float maiorNota(float notas[], int quantidade);
float menorNota(float notas[], int quantidade);
void alunoAprovado(float notas[], int quantidade);

int main(){
    float notas[10];
    int quantidade = 0;
    int opcao;

    do{
        printf("\n=====Sistemas de notas=====\n");
        printf("1 - Cadastrar nota\n");
        printf("2 - Listar notas\n");
        printf("3 - Maior nota\n");  
        printf("4 - Menor nota\n");
        printf("5 - Alunos aprovadas e Reprovados\n");
        printf("6 - Média da turma\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                if( quantidade < 10){
                    printf("Digite a nota: ");
                    scanf("%f", &notas[quantidade]);
                    quantidade++;
                }else{
                    printf("Limite atingido\n");
                }
                break;



            case 2:
                listarNotas(notas, quantidade);
            break;



            case 3:    
            printf("Maior nota: %.2f\n", maiorNota(notas, quantidade));
            break;
            
            
            
            case 4:
            printf("Menor nota: %.2f\n", menorNota(notas,quantidade));
            break;

            
            
            case 5:
            alunoAprovado(notas, quantidade);
            break;


            case 6:
            printf("Média: %.2f\n", calculaMedia(notas, quantidade));
            break;
            

        }

    }while (opcao != 0);
    {
        return 0;
    }
    
}  // final da chave main


//modulos

void listarNotas(float notas[], int quantidade){
    for(int i = 0; i < quantidade; i++){
        printf("%.1f\n", notas[i]);
    }
}

float maiorNota(float notas[], int quantidade){
    float maior = notas[0];  
    for(int i = 1; i < quantidade; i++){
        if(notas[i] > maior){
            maior = notas[i];
        }
    }
    return maior;
}

float menorNota(float notas[], int quantidade){
    float menor = notas[0];
    for(int i = 1; i < quantidade; i++){
        if(notas[i] < menor){
            menor = notas[i];
        }
    }
    return menor;
}

void alunoAprovado(float notas[], int quantidade){
    int aprovados = 0;
    int reprovados = 0;

    for(int i = 0; i < quantidade; i++){
        if(notas[i] >= 60){
            printf("Aluno %d (%.1f): Aprovado\n", i + 1, notas[i]);
            aprovados++;
        } else {
            printf("Aluno %d (%.1f): Reprovado\n", i + 1, notas[i]);
            reprovados++;
        }
    }
    printf("\nTotal aprovados:  %d\n", aprovados);
    printf("Total reprovados: %d\n", reprovados);
}

float calculaMedia(float notas[], int quantidade){
    float soma = 0;
        for(int i = 0; i < quantidade; i++){
            soma += notas[i];
        }
        return soma / quantidade;
}