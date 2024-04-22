#include "agenda.h"
#include <stdio.h>
#include <string.h>

void clearBuffer();

RESULTADOS criarContato(Contato contatos[], int *ord) {
  if (*ord >= TOTAL)
    return MAX_CONTATO;
  printf("Digite o nome: ");
  fgets(contatos[*ord].nome, 10, stdin);
  clearBuffer();

  printf("Digite o sobrenome: ");
  fgets(contatos[*ord].sobrenome, 10, stdin);

  printf("Digite o email: ");
  fgets(contatos[*ord].email, 20, stdin);

  printf("Digite o telefone: ");
  scanf("%d", contatos[*ord].telefone);
  *ord = *ord + 1;
  return OK;
}
RESULTADOS deletarContato(Contato contatos[], int *ord) { printf("deletar"); }
RESULTADOS listarContato(Contato contatos[], int *ord) {
  printf("listar");
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