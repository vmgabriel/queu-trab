#include <stdio.h>
#include <iostream>

using namespace std;

struct Nodo
{
    int elem;
    Nodo * sig;
};

class ListaDinamica
{
protected:
    Nodo * cabeza;

    //Metodos
public:
    ListaDinamica()
    {
        cabeza=NULL;
    }

    void agregar(int);
    void mostrar();
    void eliminar();
    void eliminar(int);
    Nodo * buscar(int);
    void ordenar();
    void insertar();
    bool vacio();
};

bool ListaDinamica::vacio()
{
    return cabeza==NULL;
}

void ListaDinamica::agregar(int elem)
{
    Nodo *nuevo=new Nodo();
    (*nuevo).elem=elem;
    (*nuevo).sig=cabeza;
    cabeza=nuevo;
}

void ListaDinamica::mostrar()
{
    Nodo *p=cabeza;
    while(p != NULL)
    {
	    std::cout<<p->elem<<" ";
	    std::cout<<p->sig<<std::endl;
	    p=p->sig;
    }
    std::cout<<std::endl;
}

Nodo * ListaDinamica::buscar(int valor)
{
    Nodo * p = cabeza;
    bool encontro=false;
    while (p && !encontro)
	if (p->elem==valor)
	    encontro=true;
	else
	    p=p->sig;
    return p;
}

class Cola:public ListaDinamica
{
private:
    Nodo *fin;
public:
    Cola()
    {
        cabeza=fin=NULL;
    }
    void agregar(int);
    int eliminar();
};

void Cola::agregar(int elem)
{
    Nodo *p =new Nodo();
    p->elem=elem;
    p->sig=NULL;
    if (cabeza==NULL)
    {
        cabeza=p;
        fin=cabeza;
    }
    else
    {
        fin->sig=p;
        fin=p;
    }
}

int Cola::eliminar()
{
    int elemento = cabeza->elem;
    Nodo *p=cabeza;
    cabeza=cabeza->sig;
    delete p;
    return elemento;
}



char menu()
{
    char opcion;
    std::cout<<"Menu"<<std::endl;
    std::cout<<"(A)gregar"<<std::endl;
    std::cout<<"(E)liminar"<<std::endl;
    std::cout<<"(M)ostrar"<<std::endl;
    std::cout<<"(B)uscar"<<std::endl;
    std::cout<<"(O)rdenar"<<std::endl;
    std::cout<<"(S)alir"<<std::endl;
    std::cout<<"Escoja una opcion: ";
    std::cin>>opcion;
    return opcion;
}

int main()
{
    Cola cola;
    char opcion='q';
    int elem;
    while(opcion != 's' && opcion != 'S')
    {
	    opcion=menu();
	    switch(opcion)
	    {
	        case('A'):
	        case('a'):
	        {
	            std::cout<<"Digite el elemento: ";
	            std::cin>>elem;
	            cola.agregar(elem);
	        }
	        break;
	        case('M'):
	        case('m'):
	        {
	            cola.mostrar();
	        }
	        break;
	        case('B'):
	        case('b'):
	        {
	            std::cout<<"Ingrese el valor a buscar: ";
	            std::cin>>elem;
	            if (cola.buscar(elem) != NULL)
	            {
		        std::cout<<"Elemento encontrado"<<std::endl;
	            }
	            else
	            {
		        std::cout<<"Elemento No Emcontrado"<<std::endl;
	            }
	        }
	        break;
	        case('E'):
	        case('e'):
	        {
	            if (cola.vacio())
	            {
	                std::cout<<"Cola Vacia"<<std::endl;
	            }
	            else
	            {
	                std::cout<<"Elemento "<<cola.eliminar()<<" Eliminado"<<std::endl;
	            }
	        }
	        break;
	    }
    }
    return 0;
}


