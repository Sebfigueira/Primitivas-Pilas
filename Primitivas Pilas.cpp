#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
};

void menu();
void push(Node *&, int);
void pop(Node *&, int&);
bool isVoid(Node *);
void top(Node *);
void print_pila(Node *);

Node *Pila = NULL;

int main(){
    int option, value;
    do{
        cout<<"\n\tMENU\n";
        cout<<"1. Insertar una pila\n";
        cout<<"2. Eliminar una pila\n";
        cout<<"3. Determinar si la pila esta vacia\n";
        cout<<"4. Mostrar el valor de la cabeza de la pila\n";
        cout<<"5. Mostrar la pila entera\n";
        cout<<"6. Salir\n";
        cout<<"\n";
        cin>>option;

        switch(option){
            case 1: cout<<"Escriba el dato que desea agregar\n";
                    cin>>value;
                    push(Pila,value);
                    break;

            case 2: cout<<"Eliminando pila\n";
                    pop(Pila,value);
                    break;

            case 3: if(isVoid(Pila)==false){
                    cout<<"La pila tiene elementos\n";
                    }
                    else{
                        cout<<"La pila no tiene elementos\n";
                    }
                    break;

            case 4: cout<<"El tope de la pila es: \n";
                    top(Pila);
                    break;

            case 5: print_pila(Pila);
                    break;
        }
    }while(option!=6);
}

void push(Node *&Pila, int n){
    Node *new_node = new Node;
    new_node -> value = n;
    new_node -> next = Pila;
    Pila = new_node;
}

void pop(Node *&Pila, int &n){
    Node *aux1 = Pila;
    n = aux1 -> value;
    Pila = aux1 -> next;
    delete aux1;
}

bool isVoid(Node *Pila){
    if(Pila){
        return false;
    }
    return true;
}

void top(Node *Pila){
    if(!isVoid(Pila)){
        cout<<Pila -> value;
    }
}

void print_pila(Node *Pila){
    Node *aux1 = Pila;
    while (aux1 != NULL){
        cout<<aux1 -> value<<"->";
        aux1 = aux1 -> next;
    }
}