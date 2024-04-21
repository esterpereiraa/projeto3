#include "agenda.h"
#include <stdio.h>

int main() {
  funcao ct[] = {criar, deletar, listar, salvar, carregar};
  Contato contatos[TOTAL];
  int ord = 0;
  ERROS erro = ct[4](contatos, &ord);
  while (1) {
    int opcao;
    printf("\nMENU PRINCIPAL\n");
    printf("1 - Criar contato\n");
    printf("2 - Deletar contato\n");
    printf("3 - Listar contato\n");
    printf("4 - Sair");
    printf("\nEscolha uma opção: ");
    scanf("%d", &opcao);
    switch (opcao)

    {
    case 1:
     erro = ct [0](contatos, &ord);
      break;
    case 2:
      erro = ct[1](contatos, &ord);
      break;
    case 3:
     erro = ct [2](contatos, &ord);
      break;
    case 4:
      printf("Sair\n");
      return 0;

    default:
      printf("OPÇÂO INVALIDA\n\n");
      break;
    }
  }
  return 0;
}
