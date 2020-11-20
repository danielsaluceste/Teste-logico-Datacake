#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 9

struct node {
    char *value;            
    struct node *p_left;
    struct node *p_right;
};

typedef int (*Compare)(const char *, const char *);

void insert(char* key, struct node** leaf, Compare cmp)
{
    int res;
    if( *leaf == NULL ) {
        *leaf = (struct node*) malloc( sizeof( struct node ) );
        (*leaf)->value = malloc( strlen (key) +1 );   
        strcpy ((*leaf)->value, key);               
        (*leaf)->p_left = NULL;
        (*leaf)->p_right = NULL;
    } else {
        res = cmp (key, (*leaf)->value);
        if( res < 0)
            insert( key, &(*leaf)->p_left, cmp);
        else if( res > 0)
            insert( key, &(*leaf)->p_right, cmp);
        else                                       
            printf ("Key '%s' ja existe na arvore\n", key);
    }
}

int CmpStr(const char *a, const char *b)
{
    return (strcmp (a, b));  
}

char *input( void )
{
    static char line[MAXLEN+1];    
    printf("Digite uma string : ");
    fgets( line, sizeof line, stdin );
    return ( strtok(line, "\n" ));  
}

void in_order(struct node *root)
{
    if( root != NULL ) {
        in_order(root->p_left);
        printf("   %s\n", root->value); 
        in_order(root->p_right);
    }
}

void search(char* key, struct node* leaf, Compare cmp) 
{
    int res;
    if( leaf != NULL ) {
        res = cmp(key, leaf->value);
        if( res < 0)
            search( key, leaf->p_left, cmp);
        else if( res > 0)
            search( key, leaf->p_right, cmp);
        else
            printf("\n'%s' encontrado!\n", key); 
    }
    else printf("\nNao encontrado\n");
    return;
}

void delete_tree(struct node** leaf)
{
    if( *leaf != NULL ) {
        delete_tree(&(*leaf)->p_left);
        delete_tree(&(*leaf)->p_right);
        free( (*leaf)->value );     
        free( (*leaf) );
    }
}

void menu()
{
    printf("\nPressione 'i' para inserir um elemento\n");
    printf("Pressione 'b' para buscar por um elemento\n");
    printf("Pressione 'p' para imprimir a arvore in-ordem\n");
    printf("Pressione 'f' para destruir a arvore\n");
    printf("Pressione 's' para sair\n");
}

int main()
{
    struct node *p_root = NULL;
    char *value;
    char option = 'x';

    while( option != 's' ) {
        menu();

        option = getch();     

        if( option == 'i') {
            value = input();
            printf ("Inserindo %s\n", value);
            insert(value,  &p_root, (Compare)CmpStr);
        }
        else if( option == 'b' ) {
            value = input();
            search(value, p_root, (Compare)CmpStr); 
        }
        else if( option == 'p' ) {
            in_order(p_root);
        }
        else if( option == 'f' ) {
            delete_tree(&p_root);
            printf("Arvore destruida");
            p_root = NULL;
        }
        else if( option == 's' ) {
            printf("Saindo...");
        }
    }
	return 0;
}
