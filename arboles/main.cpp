#include <iostream>
#include <vector>

using namespace std;

struct tree_node {
    int value;
    tree_node * left = nullptr;
    tree_node * right = nullptr;
};

using ptr_tree_node = tree_node *;

void arbol_mostrar( const ptr_tree_node & root ) {
    if( root != nullptr ) {
        arbol_mostrar( root->left );
        cout << root->value << " ";
        arbol_mostrar(root->right);
    }
}

unsigned int arbol_buscar_entre(const ptr_tree_node & root, const int & a, const int & b) {
    if( root != nullptr ) {
        bool value_major_a = root->value > a ;
        bool value_minor_b = root->value < b ;
        unsigned int res = ( value_major_a && value_minor_b )? 1 : 0;//( a < root->value && root->value < b ) ? 1 : 0;
        if( value_major_a )
            res += arbol_buscar_entre(root->left, a, b);
        if ( value_minor_b )
            res += arbol_buscar_entre(root->right, a, b);

        return res ;
    }
    return 0;
}

ptr_tree_node arbol_insertar( ptr_tree_node & root, const int & value) {

    if( root == nullptr) {
        //create node
        root = new tree_node;
        root->value = value;
        return root;
    }
    // root != nullptr
    if( value < root->value)
        return arbol_insertar(root->left, value);
    // value >= root->value
    return arbol_insertar(root->right, value);
}

int main()
{
    ptr_tree_node root = nullptr;

    for ( auto value : {5, -1 , 3, 6, 8, -22, 5, 6 , 8, 11, 22, -14 } ) {
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

    return 0;
}
