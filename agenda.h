#define TOTAL 255
typedef struct {
  char nome[20];
  char sobrenome[20];
  int telefone[15];
  char email[25];
} Contato;

typedef enum {
  OK,
  MAX_CONTATO,
  SEM_CONTATO,
  ARQUIVO_NAO_ENCONTRADO,
  ABRIR,
  ESCREVER,
  FECHAR,
  LER
} RESULTADOS;

typedef RESULTADOS (*funcao)(Contato[], int *);

RESULTADOS criarContato(Contato contatos[], int *ord);
RESULTADOS deletarContato(Contato contatos[], int *ord);
RESULTADOS listarContato(Contato contatos[], int *ord);
RESULTADOS salvarContato(Contato contatos[], int *ord);
RESULTADOS carregarContato(Contato contatos[], int *ord);
void clearBuffer();