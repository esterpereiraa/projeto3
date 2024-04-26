#define TOTAL 255
typedef struct {
  char nome[20]; 
  char sobrenome[20];
  int telefone[15]; 
  char email[25];
} Contato; // struct para armazenar os contatos

typedef enum {
  OK,
  MAX_CONTATO,
  SEM_CONTATO,
  ARQUIVO_NAO_ENCONTRADO,
  ABRIR,
  ESCREVER,
  FECHAR,
  LER
} RESULTADOS; // enum para retornar os resultados das funções
typedef RESULTADOS (*funcao)(Contato[], int *);

// funções
RESULTADOS criarContato(Contato contatos[], int *ord);
RESULTADOS deletarContato(Contato contatos[], int *ord);
RESULTADOS listarContato(Contato contatos[], int *ord);
RESULTADOS salvarContato(Contato contatos[], int *ord);
RESULTADOS carregarContato(Contato contatos[], int *ord);
void clearBuffer();