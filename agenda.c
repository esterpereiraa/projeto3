#include <stdio.h>
#include <string.h>
#include "agenda.h"

void clearBuffer();

ERROS criarContato(Contato contatos[], int *ord ){
  if (*ord >= TOTAL)
    return MAX_CONTATO;
  printf("Digite o nome: ");
  fgets(contatos[*ord].nome, 10, stdin);
  clearBuffer();
  printf("Digite o sobrenome: ");
  fgets(contatos[*ord].sobrenome,10, stdin);
  clearBuffer();
  printf("Digite o email: ");
  fgets(contatos[*ord].email, 20, stdin);
  printf("Digite o telefone: ");
  scanf("%d", contatos[*ord].telefone);
  
}
ERROS deletarContato(Contato contatos[], int *ord ){
  printf("Deletar contato\n");
}
ERROS listarContato(Contato contatos[], int *ord ){
  printf("listar \n");
}
ERROS salvarContato(Contato contatos[], int *ord ){
  printf("salvando");
}
ERROS carregarContato (Contato contatos[], int *ord ){
  printf("carregando");
}
void clearBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}