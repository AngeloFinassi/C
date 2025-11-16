#include <stdio.h>
#include <stdlib.h>

// ------------------ STRUCT ------------------
typedef struct Node {
    int valor;
    struct Node *next;
} Node;

// ------------------ CRIAR NÓ ------------------
Node* criaNo(int valor) {
    Node *novo = malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = NULL;
    return novo;
}

// ------------------ INSERIR NO INÍCIO ------------------
void inserirInicio(Node **head, int valor) {
    Node *novo = criaNo(valor);
    novo->next = *head;
    *head = novo;
}

// ------------------ INSERIR NO FIM ------------------
void inserirFim(Node **head, int valor) {
    Node *novo = criaNo(valor);

    if (*head == NULL) {
        *head = novo;
        return;
    }

    Node *aux = *head;
    while (aux->next != NULL)
        aux = aux->next;

    aux->next = novo;
}

// ------------------ INSERIR NA POSIÇÃO ------------------
void inserirPos(Node **head, int valor, int pos) {
    if (pos == 0) {
        inserirInicio(head, valor);
        return;
    }

    Node *aux = *head;
    int count = 0;

    while (aux != NULL && count < pos - 1) {
        aux = aux->next;
        count++;
    }

    if (aux == NULL) {
        printf("Posição inválida.\n");
        return;
    }

    Node *novo = criaNo(valor);
    novo->next = aux->next;
    aux->next = novo;
}

// ------------------ REMOVER INÍCIO ------------------
void removerInicio(Node **head) {
    if (*head == NULL) return;

    Node *temp = *head;
    *head = temp->next;
    free(temp);
}

// ------------------ REMOVER FIM ------------------
void removerFim(Node **head) {
    if (*head == NULL) return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node *aux = *head;
    while (aux->next->next != NULL)
        aux = aux->next;

    free(aux->next);
    aux->next = NULL;
}

// ------------------ REMOVER VALOR ------------------
void removerValor(Node **head, int valor) {
    if (*head == NULL) return;

    // valor está na cabeça
    if ((*head)->valor == valor) {
        removerInicio(head);
        return;
    }

    Node *aux = *head;

    while (aux->next != NULL && aux->next->valor != valor)
        aux = aux->next;

    if (aux->next == NULL) {
        printf("Valor não encontrado.\n");
        return;
    }

    Node *temp = aux->next;
    aux->next = temp->next;
    free(temp);
}

// ------------------ BUSCAR ------------------
Node* buscar(Node *head, int valor) {
    while (head != NULL) {
        if (head->valor == valor)
            return head;
        head = head->next;
    }
    return NULL;
}

// ------------------ IMPRIMIR ------------------
void imprimir(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->valor);
        head = head->next;
    }
    printf("NULL\n");
}

// ------------------ LIBERAR ------------------
void liberarLista(Node **head) {
    Node *aux;
    while (*head != NULL) {
        aux = *head;
        *head = (*head)->next;
        free(aux);
    }
}

// ------------------ MAIN ------------------
int main() {
    Node *lista = NULL;

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 5);
    inserirFim(&lista, 20);
    inserirFim(&lista, 30);
    inserirPos(&lista, 15, 2);

    imprimir(lista);  // 5 -> 10 -> 15 -> 20 -> 30 -> NULL

    removerInicio(&lista);
    imprimir(lista);

    removerFim(&lista);
    imprimir(lista);

    removerValor(&lista, 15);
    imprimir(lista);

    Node *achado = buscar(lista, 20);
    if (achado) printf("Encontrado: %d\n", achado->valor);

    liberarLista(&lista);
    return 0;
}
