#include <iostream>
#include <string>

using namespace std;

struct node 
{
    int key;
    string data;
    struct node* parent_node;
    struct node* left_node;
    struct node* right_node;
    int height;
};

class avl_tree
{
    public: 
        node* root = NULL;

        int height (node*);
        void cleanup(node*);
        void display(node*, int);

        node* insert(node*, int, string);
        node* remove(node*, int);
        node* search(node*, int);

        node* single_left_rotation(node*);
        node* single_right_rotation(node*);
        node* double_left_rotation(node*);
        node* double_right_rotation(node*);
};

int main() 
{
    avl_tree avl;
    int choice, key;
    string data;
    node* found = NULL;

    while (true)
    {   
        choice = key = 0;
        data = "";
        found = NULL;

        cout << "-----------------------------------" << endl;
        cout << "                AVL                " << endl;
        cout << "-----------------------------------" << endl;
        cout << "  1 - Inserir elemento na arvore" << endl;
        cout << "  2 - Remover elemento na arvore" << endl;
        cout << "  3 - Buscar elemento na arvore" << endl;
        cout << "  4 - Mostrar a arvore" << endl;
        cout << "  5 - Encerrar o programa" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Digite o valor da chave que deseja inserir: ";
            cin >> key;
            cout << endl << "Digite o valor que deseja guardar nesse nó: ";
            
            cin.ignore();
            getline(cin, data);

            avl.root = avl.insert(avl.root, key, data);

            break;
        
        case 2:
            cout << "Digite a chave que deseja remover: ";
            cin >> key;

            avl.root = avl.remove(avl.root ,key);

            break;

        case 3:
            cout << "Digite a chave que deseja buscar: ";
            cin >> key;

            found = avl.search(avl.root, key);
            if (found == NULL)
            {
                cout << "O nó não foi encontrado" << endl;
            }
            else
            {
                cout << "O nó " << key << " guardava o valor " << found->data << "."; 
            }

            break;

        case 4:
            cout << "--------------Direita--------------" << endl;
            avl.display(avl.root, 1);
            cout << endl << endl << "--------------Esquerda-------------" << endl;
            break;

        case 5:
            avl.cleanup(avl.root);
            return 0;

        default:
            cout << "Opcao invalida" << endl;
            break;
        }
    }
}


int avl_tree::height(node* tree_node)
{
    return (tree_node == NULL ? -1 : tree_node->height);
}

void avl_tree::display(node* tree_node, int level)
{
    if (tree_node != NULL)
    {
        display(tree_node->right_node, level + 1);

        cout << endl;

        if (tree_node == root) 
        {
            cout << "Root -> ";
        }

        for (int i = 0; i < level && tree_node != root; i++)
        {
            cout<<"        ";
        }
        
        cout << tree_node->key;

        display(tree_node->left_node, level + 1);
    }
}

// Liberar memória dinamicamente alocada com o operador new
void avl_tree::cleanup(node* tree_node) 
{
    if (tree_node == NULL)
    {
        return;
    }

    cleanup(tree_node->left_node);
    cleanup(tree_node->right_node);

    delete tree_node;
}

node* avl_tree::insert(node* tree_node, int key, string data)
{
    if (tree_node == NULL) 
    {
        tree_node = new node();

        tree_node->key = key;
        tree_node->data = data;
        tree_node->height = 0;
        tree_node->left_node = tree_node->right_node = NULL;
    }
    else if (key < tree_node->key)
    {
        tree_node->left_node = insert(tree_node->left_node, key, data);
        tree_node->left_node->parent_node = tree_node;
    }
    else
    {
        tree_node->right_node = insert(tree_node->right_node, key, data);
        tree_node->right_node->parent_node = tree_node;
    }

    int left_height = height(tree_node->left_node);
    int right_height = height(tree_node->right_node);

    tree_node->height = (left_height >= right_height ? left_height : right_height) + 1;

    return tree_node;
}

node* avl_tree::remove(node* ,int key)
{
    //TODO
    return NULL;
}

node* avl_tree::search(node* tree_node, int key)
{
    if (tree_node == NULL)
    {
        return NULL;
    }
    else if (tree_node->key == key)
    {
        return tree_node;
    }
    else if (key > tree_node->key)
    {
        return search(tree_node->right_node, key);
    }
    else 
    {
        return search(tree_node->left_node, key);
    }
}

node* avl_tree::single_left_rotation(node*)
{
    //TODO
    return NULL;
}

node* avl_tree::single_right_rotation(node*)
{
    //TODO
    return NULL;
}

node* avl_tree::double_left_rotation(node*)
{
    //TODO
    return NULL;
}

node* avl_tree::double_right_rotation(node*)
{
    //TODO
    return NULL;
}

