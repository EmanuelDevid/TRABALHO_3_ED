typedef struct filap FilaP;

//função que retorna o índice do pai de certo valor cujo índice desse valor é ind.
int parent(int ind);

//função que retorna o índice do filho esquerdo do valor cujo índice desse valor é ind.
int left(int ind);

//função que retorna o índice do filho direito do valor cujo índice desse valor é ind.
int right(int ind);

//cria uma fila de prioridade vazia.
FilaP* filap_cria();

//devolve o elemento de maior prioridade na fila.
int heap_maximum(FilaP* fp);

//função que faz com que o elemento de maior prioridade seja o primeiro da fila.
void max_heapfy(FilaP* fp, int ind);

//devolve o elemento de maior prioridade e o retira da fila;
int heap_extract_max(FilaP* fp);

//modifica a prioridade de determinado elemento no índice ind na fila (apenas se chave for maior).
void heap_increase_key(FilaP* fp, int ind, int chave);

//insere um novo elemento na fila com prioridade chave.
void max_heap_insert(FilaP* fp, int chave);
