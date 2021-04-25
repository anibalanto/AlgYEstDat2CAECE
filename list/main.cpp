#include <iostream>
#include <vector>

using namespace std;


struct list_node_t {
    int value;
    list_node_t *next;
};




list_node_t * & lista_buscar_menor( list_node_t * & list, list_node_t * & menor ) {
    if( list != nullptr && menor != nullptr ) {
        if( menor->value < list->value) {
            return lista_buscar_menor( list->next, menor);
        }
        // menor->value >= list->value
        return lista_buscar_menor( list->next, list);
    }
    return menor;
}

void lista_ordenar(list_node_t * & list) {
    list_node_t * & ref_menor = lista_buscar_menor(list, list);
    if( ref_menor   != nullptr &&
        list    != nullptr ) {
        if( list != ref_menor ) {
            list_node_t * menor_next_aux = (* ref_menor).next; //[1] //null
            //list_node_t * first_list_aux = list; //[1.2]
            (* ref_menor).next = list; //[2]
            list = ref_menor; //[3]
            //first_list_aux->next = menor_next_aux; //[4.1]
            ref_menor = menor_next_aux ;   //[4.0]
            //list -> (10 [dir&])-> (-3 [dir])->(5 [dir])...
            //        (10 [DIR&])-> (5 [dir])
        }
        lista_ordenar( list->next );
    }
}

//////


list_node_t * lista_crear(std::vector<int> &values) {

    if( ! values.empty() ) {
        list_node_t * list = new list_node_t;
        auto first = values.begin();        //se toma el primer elemento
        list->value = *first;               //se le da el primer elemento al value del nodo actual
        values.erase(first);                //se elimona el primer elemento
        list->next = lista_crear(values);
        return list;
    }
    return nullptr;
}

void lista_liberar(list_node_t * list) {

    if( list != nullptr ) {
        lista_liberar(list->next);
        delete(list);
    }
}

void mostrar_recursivo(list_node_t * list) {
    if( list != nullptr ) {
        std::cout << list->value << " " ;
        mostrar_recursivo(list->next);
    }
}

void mostrar(list_node_t * list) {
    mostrar_recursivo(list);
    std::cout << "\n";
}

/*void mult_2_int(int value) {
    value = value * 2;
}


void mult_2_int_ptr(int *value) {
    *value = *value * 2;
}

void mult_2_int_ref(int &value) {
    value = value * 2;
}

void crear_primero(list_node_t ** ptr) {
    *ptr = new list_node_t;
}

void crear_primero_ref(list_node_t * & ptr) {
    ptr = new list_node_t;
}*/

int main()
{

    /*int a =5;

    //para lenguaje C y C++
    mult_2_int(a); //a = a * 2 ; no genera modificacion

    mult_2_int_ptr(&a);

    //C++ agrega referencias

    mult_2_int_ref(a);

    list_node_t * ptr;
    //modificar un punter C y C++
    crear_primero(&ptr);

    //modificar un puntero con ref C++
    crear_primero_ref(ptr);

    free(ptr);*/


    std::vector<int> values = { 3, 9, -1, 1, 7  };

    list_node_t * list = lista_crear(values);

    mostrar(list);

    lista_ordenar(list);

    mostrar(list);

    lista_liberar(list);

    return 0;
}







//////ptr a ptr
/*ptr_list_node_t * lista_buscar_menor( ptr_list_node_t * list, ptr_list_node_t * menor ) {
    if (list != nullptr ) {
        if( (* list )   != nullptr) {

            if (       menor    != nullptr &&
                    (* menor)   != nullptr ) {

                if( (* menor)->value < (* list)->value) {
                    return lista_buscar_menor( &( (*list)->next ) , menor);
                }
            }

            return lista_buscar_menor( &( (*list)->next ), list);
        }
    }
    return menor;
}

void lista_ordenar(ptr_list_node_t * list) {
    ptr_list_node_t *menor = lista_buscar_menor(list, nullptr);
    if ( menor   != nullptr &&
         *menor  != nullptr &&
         list    != nullptr ) {
        if( list != menor ) {
            ptr_list_node_t aux = (** menor).next; //[A]
            (** menor).next = * list;
            * list = * menor;
            * menor = aux ;

        }
        lista_ordenar( &(*list)->next );

    }
}*/


////referencias
