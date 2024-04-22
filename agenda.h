#define TOTAL 255
typedef struct {
  char nome[10];
  char sobrenome[10];
  int telefone[15];
  char email[20];
} Contato;

typedef enum {
  OK,
  MAX_CONTATO,
  SEM_CONTATO,
  ARQUIVO_NAO_ENCONTRADO,
  ABRIR,
  FECHAR,
  LER
} ERROS;

typedef ERROS (*funcao)(Contato[], int *);

ERROS criarContato(Contato contatos[], int *ord);
ERROS deletarContato(Contato contatos[], int *ord);
ERROS listarContato(Contato contatos[], int *ord);
ERROS salvarContato(Contato contatos[], int *ord);
ERROS carregarContato(Contato contatos[], int *ord);
