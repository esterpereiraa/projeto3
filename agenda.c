#include "agenda.h"
#include <stdio.h>
#include <string.h>

void clearBuffer();
//criar contato
RESULTADOS criarContato(Contato contatos[], int *ord) {
  if (*ord >= TOTAL)
    return MAX_CONTATO;
  
  clearBuffer();//limpar o buffer
  printf("Digite o nome: ");
  fgets(contatos[*ord].nome, 20, stdin);

  printf("Digite o sobrenome: ");
  fgets(contatos[*ord].sobrenome, 20, stdin);

  printf("Digite o email: ");
  fgets(contatos[*ord].email, 25, stdin);

  printf("Digite o telefone: ");
  scanf("%d", contatos[*ord].telefone);
  *ord += 1;
  return OK;
}
// deletar contato
RESULTADOS deletarContato(Contato contatos[], int *ord) {
  if (*ord == 0)
    return SEM_CONTATO;
  int cont_removido; //contador para remover o contato
  printf("Digite o telefone que deseja deletar: ");
  scanf("%d", &cont_removido);
  //percorre o vetor e procura o contato a ser removido
  for (int i = cont_removido; i < *ord; i++) {
    strcpy(contatos[i].nome, contatos[i + 1].nome);
    strcpy(contatos[i].sobrenome, contatos[i + 1].sobrenome);
    strcpy(contatos[i].email, contatos[i + 1].email);
    contatos[i].telefone, contatos[i + 1].telefone;
  }
  
  (*ord)--;// assegurar que o contador seja atualizado
  return OK;
}
RESULTADOS listarContato(Contato contatos[], int *ord) {
  if (*ord == 0)
    return SEM_CONTATO;
  //percorre o vetor e imprime os contatos
  for (int i = 0; i < *ord; i++) {
    printf("\n======= CONTATO %d ========\n", i + 1);
    printf("NOME: %s \n", contatos[i].nome);
    printf("SOBRENOME: %s\n", contatos[i].sobrenome);
    printf("EMAIL: %s\n", contatos[i].email);
    printf("TELEFONE: %d\n", *(contatos[i].telefone)); // imrpime o telefone
    printf("==========================\n");
  }
  return OK;
}
// salvar contato
RESULTADOS salvarContato(Contato contatos[], int *ord) {
  FILE *arquivo = fopen("agenda.bin", "wb");// abrir arquivo para escrita
  if (arquivo == NULL)
    return ABRIR;
  int quant = fwrite(contatos, TOTAL, sizeof(Contato), arquivo); // escrever no arquivo
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