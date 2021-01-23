typedef struct dicio *Dicio;

Dicio dicioCriar(void);

void dicioDestruir(Dicio);

void dicioInserir(Dicio, const char *chave, const char *value);

const char *dicioBuscar(Dicio, const char *chave);

void dicioDeletar(Dicio, const char *chave);

void dicioImprimir(Dicio d);
