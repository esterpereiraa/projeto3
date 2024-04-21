#include <stdio.h>

int main(){

    while(1){
        int opcao;
        printf("\nMENU PRINCIPAL\n");
        printf("1 - Criar contato\n");
        printf("2 - Deletar contato\n");
        printf("3 - Listar contato\n");
        printf("4 - Sair");
        printf("Escolha uma opção: ");
        scanf("%d",&opcao);
    switch (opcao)

    {
    case 1:
        printf("Criar contato\n");
        break;
     case 2:
        printf("Deletar contato\n");
        break;
    case 3:
        printf("Deletar contato\n");
        break;
    case 4:
        printf("Sair\n");
        return 0; 


    default:
        printf("OPÇÂO INVALIDA\n\n");
        break;
    }
    }
 
}
