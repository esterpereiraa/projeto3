#define TOTAL 255
typedef struct{
    char nome[10];
    char sobrnome[10];
    char telefone[15];
    char email[20];
} Contato;

typedef enum{OK, MAX_CONTATO, SEM_CONTATO, ARQUIVO_NAO_ENCONTRADO, ABRIR, FECHAR, LER} ERROS;

typedef ERROS(*funcao)(Contato[], int*);

ERROS criar(Contato contatos[], int *ord );
ERROS deletar(Contato contatos[], int *ord );
ERROS listar(Contato contatos[], int *ord );
ERROS salvar(Contato contatos[], int *ord );
ERROS carregar(Contato contatos[], int *ord );

