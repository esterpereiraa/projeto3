#include "agenda.h"
#include <stdio.h>
#include <string.h>

void clearBuffer();

RESULTADOS criarContato(Contato contatos[], int *ord) {
  if (*ord >= TOTAL)
    return MAX_CONTATO;
  clearBuffer();
  printf("Digite o nome: ");
  fgets(contatos[*ord].nome, 20, stdin);
  
  printf("Digite o sobrenome: ");
  fgets(contatos[*ord].sobrenome, 20, stdin);
  
  printf("Digite o email: ");
  fgets(contatos[*ord].email, 25, stdin);

  printf("Digite o telefone: ");
  scanf("%d", contatos[*ord].telefone);
  *ord  += 1;
  return OK;
}
RESULTADOS deletarContato(Contato contatos[], int *ord) { printf("deletar"); }
RESULTADOS listarContato(Contato contatos[], int *ord) {
  if (*ord == 0)
    return SEM_CONTATO;
  for (int i = 0; i < *ord; i++){
    printf("\n======= POSIÇÂO %d ========\n", i+1);
    printf("NOME: %s \n", contatos[i].nome);
    printf("SOBRENOME: %s\n", contatos[i].sobrenome);
    printf("EMAIL: %s\n", contatos[i].email);
    printf("TELEFONE: %d\n", *(contatos[i].telefone));
    printf("==========================\n");
  } return OK;
}
RESULTADOS salvarContato(Contato contatos[], int *ord) {
  FILE *arquivo = fopen("agenda.bin", "wb");
  if (arquivo == NULL)
    return ABRIR;
  int quant = fwrite(contatos, TOTAL, sizeof(Contato), arquivo);
  if (quant == 0)
    return ESCREVER;
  quant = fwrite(ord, sizeof(int), 1, arquivo);
  if (quant == 0)
    return ESCREVER;
  if (fclose(arquivo))
    return FECHAR;
  return OK;
}
RESULTADOS carregarContato(Contato contatos[], int *ord) {
  FILE *arquivo = fopen("agenda.bin", "rb");
  if (arquivo == NULL)
    return ABRIR;
  int quant = fread(contatos, TOTAL, sizeof(Contato), arquivo);
  if (quant == 0)
    return LER;
  quant = fread(ord, sizeof(int), 1, arquivo);
  if (quant == 0)
    return LER;
  if (fclose(arquivo))
    return FECHAR;
  return OK;
}
void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}