#include <iostream>
#include <vector>

using namespace std;

struct tree_node {
    int value;
    tree_node * left = nullptr;
    tree_node * right = nullptr;
};

void arbol_mostrar(
        tree_node * & root )
{
    if( root != nullptr ) {
        arbol_mostrar( root->left );
        cout << root->value << " ";
        arbol_mostrar(root->right);
    }
}

unsigned int arbol_buscar_entre(
        tree_node * &   root,
        const int &     a,
        const int &     b )
{
    unsigned int res = 0;
    if( root != nullptr ) {
        bool value_major_a = root->value > a ;
        bool value_minor_b = root->value < b ;

        if( value_major_a )
            res += arbol_buscar_entre(root->left, a, b);

        if( value_minor_b )
            res += arbol_buscar_entre(root->right, a, b);

        if( value_major_a && value_minor_b )
            res++;
    }
    return res;
}

void arbol_insertar(
        tree_node * &   root,
        const int &     value)
{

    if( root == nullptr) {
        //create node
        root = new tree_node;
        root->value = value;
    }
    else //root != nullptr
    {
        if( value < root->value)
        {
            arbol_insertar(root->left, value);
        } else // value >= root->value
        {
            arbol_insertar(root->right, value);
        }
    }

}

void arbol_liberar(
        tree_node * & root)
{
    if( root != nullptr ) {
        arbol_liberar(root->left);
        arbol_liberar(root->right);
        delete(root);
    }
}

int main()
{
    tree_node * root = nullptr;

    for ( auto value : {5, -1, 0, 3, 6, -22, 5, -101, 6, 22, -14 } ) {
        arbol_insertar(root, value);
    }

    arbol_mostrar(root);
    cout << endl;

    int a = -100;
    int b = 10;

    cout    << "Hay "
            << arbol_buscar_entre(root, a, b)
            << " elementos entre "
            << a << " y " << b
            << endl;

    arbol_liberar(root);
    return 0;
}
