#include <stdio.h>
#include <stdlib.h>

typedef struct dataNode {
	int id;
}DataNode;

typedef struct node{
	DataNode data;
	struct node *next;
}Node;

typedef struct list {
	int size;
	Node *head;
}List;

typedef struct array{
	struct list *prox;
}Array;

List *createList();
void push(List *list, DataNode data);
void printList(List *list);
void pop(List *list);
Node *atPos(List *list, int index);
void erase(List *list, int index);
void deleteEnd(List *list);


//cria lista vazia
List *createList(){
	List *list = (List*) malloc(sizeof(List));

	list->size = 0;
	list->head = NULL;


	return list;
}
//insere no início
void push(List *list, DataNode data){
	Node *node = (Node*) malloc(sizeof(Node));

	node->data = data;
	node->next = list->head;
	list->head = node;
	list->size++;
	
}
//mostra lista
void printList(List *list){

	if(list->size == 0){
		printf("Lista vazia\n");
		return;
	}

	Node *pointer = list->head;

	while (pointer !=NULL){
		printf("%d ", pointer->data.id);
		pointer = pointer->next;
	}
	printf("\n");
}

//deleta começo
void pop(List *list){
	if(!(list->size == 0)){
		Node *pointer = list->head;
		list->head = pointer->next;
		free(pointer);
		list->size--;
	}
}
//qual a pos
Node *atPos(List *list, int index){
	if(index >=0 && index < list->size){
		Node *node = list->head;
		int i;
		for(i = 0; i < index; i++){
			node = node->next;
		}
		return node;

	} else {
		printf("Indice inválido\n");
		return NULL;
	}

}
//deleta atpos
void erase(List *list, int index){
	if(index == 0){
		pop(list);
	}else{
		Node *current = atPos(list, index);
		if(current != NULL){
			Node *previous = atPos(list, index-1);
			previous->next = current->next;
			free (current);
			list->size--;
		} else{
			printf("Índice inválido\n");
		}
	}
}
//deleta fim
void deleteEnd(List *list){
	Node *pointerLast = list->head;
	Node *pointer = list->head;
		while(pointer->next != NULL){
			if(pointerLast == pointer){
				pointer = pointer->next;
			} else{
				pointer = pointer->next;
				pointerLast = pointerLast->next;
			}
		}
		pointerLast->next = NULL;
		free(pointer);
}

int main(){

	List *L1, *L2, *L3;
	List *array[10];
    DataNode data;

    L1 = createList();
    L2 = createList();
    L3 = createList();

    for(int i = 0; i<10; i++){
    	array[i] = createList();
    }



    printf("Lista 1: ");
    data.id = 5;
    push(array[0], data);
    data.id = 6;
    push(array[0], data);
    data.id = 7;
    push(array[0], data);
    data.id = 8;
    push(array[0], data);
    printList(array[0]);

    printf("Lista 2: ");
    data.id = 10;
    push(array[1], data);
    data.id = 11;
    push(array[1], data);
    data.id = 12;
    push(array[1], data);
    printList(array[1]);

}