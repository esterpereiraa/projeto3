#include <stdio.h>
#include "agenda.h"

int main() {
  funcao ct[] = {criarContato, deletarContato, listarContato, salvarContato, carregarContato};
  Contato contatos[TOTAL];
  int ord = 0;
  RESULTADOS resultado = ct[4](contatos, &ord);
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
      resultado = ct[0](contatos, &ord);
      if (resultado == OK)
        printf("\nCONTATO REGISTRADO\n");
        resultado = ct[3](contatos, &ord);
      break;
    case 2:
      resultado = ct[1](contatos, &ord);
      break;
    case 3:
      resultado = ct[2](contatos, &ord);
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
