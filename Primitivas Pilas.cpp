#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
};

void menu();
void push(Node *&, int);
int pop(Node *&);
bool isVoid(Node *);
int top(Node *);
void print_pila(Node *);
void impares_pares(Node*&);
void push_par(Node*&, int);

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
        cout<<"6. Cambiar los pares por los impares\n";
        cout<<"7. Salir\n";
        cout<<"\n";
        cin>>option;

        switch(option){
            case 1: cout<<"Escriba el dato que desea agregar\n";
                    cin>>value;
                    push(Pila,value);
                    break;

            case 2: cout<<"Eliminando pila\n";
                    pop(Pila);
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
                    cout<<Pila -> value;
                    break;

            case 5: print_pila(Pila);
                    break;

            case 6: impares_pares(Pila);
                    break;
        }
    }while(option!=7);
}

void push(Node *&Pila, int n){
    Node *new_node = new Node;
    new_node -> value = n;
    new_node -> next = Pila;
    Pila = new_node;
}

int pop(Node *&Pila){
    Node *aux1 = Pila;
    int n = aux1 -> value;
    Pila = aux1 -> next;
    delete aux1;
    return n;
}

bool isVoid(Node *Pila){
    if(Pila){
        return false;
    }
    return true;
}

int top(Node *Pila){
    if(!isVoid(Pila)){
        return Pila -> value;
    }
    return -1;
}

void print_pila(Node *Pila){
    Node *aux1 = Pila;
    while (aux1 != NULL){
        cout<<aux1 -> value<<"->";
        aux1 = aux1 -> next;
    }
}

//------------------------------------------------------------
void impares_pares(Node *&Pila){
    if(!isVoid(Pila)){
        int value = pop(Pila);
        impares_pares(Pila);
        if((value % 2) != 0){
            push(Pila,value);
        }
        else{
            push_par(Pila, value);
        }
    }
}

void push_par(Node *&Pila, int value){
    if(!isVoid(Pila) && (top(Pila)%2) != 0){
        int topvalue = pop(Pila);
        push_par(Pila,value);
        push(Pila,topvalue);
    }
    else{
        push(Pila,value);
    }
}
//----------------------------------------------------------