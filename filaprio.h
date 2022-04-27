typedef struct filap FilaP;

//fun��o que retorna o �ndice do pai de certo valor cujo �ndice desse valor � ind.
int parent(int ind);

//fun��o que retorna o �ndice do filho esquerdo do valor cujo �ndice desse valor � ind.
int left(int ind);

//fun��o que retorna o �ndice do filho direito do valor cujo �ndice desse valor � ind.
int right(int ind);

//cria uma fila de prioridade vazia.
FilaP* filap_cria();

//devolve o elemento de maior prioridade na fila.
int heap_maximum(FilaP* fp);

//fun��o que faz com que o elemento de maior prioridade seja o primeiro da fila.
void max_heapfy(FilaP* fp, int ind);

//devolve o elemento de maior prioridade e o retira da fila;
int heap_extract_max(FilaP* fp);

//modifica a prioridade de determinado elemento no �ndice ind na fila (apenas se chave for maior).
void heap_increase_key(FilaP* fp, int ind, int chave);

//insere um novo elemento na fila com prioridade chave.
void max_heap_insert(FilaP* fp, int chave);
