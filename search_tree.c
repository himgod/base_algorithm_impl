#include<stdio.h>
#include<stdlib.h>

/*
 * for binary-search tree,any node value,it must be as follows:
 * if y is x's left child,so key[y] <= key[x]
 * if y is x's right child,so key[y] >= key[x]
 *
 */
typedef int data_type;
typedef struct binary_search_tree_node
{
    data_type data;
    struct binary_search_tree_node* left;
    struct binary_search_tree_node* right;
}bst_n,*bst_p;

/*
 * To insert a new node into binary search tree,you have to maintain the property of binary search tree
 *if the root is null, new node is root node.
 *if root node is not null,insert it in the right position.
 */
static bst_p search_bst_for_insert(bst_p* root,data_type data)
{
    bst_p tmp,parent = *root;

    while(parent)
    {
        tmp = parent;

        if( parent->data == data )
        {
            return NULL;
        }

        parent = (parent->data > data)?parent->left:parent->right;
    }
    return tmp;
}

void insert_bst_node(bst_p* root,data_type data)
{
    bst_p new_node = (bst_p)malloc(sizeof(bst_n));

    bst_p tmp;
    if( new_node == NULL )
    {
        fprintf(stderr,"malloc new node's memory  failed\n");
        return;
    }

    new_node->data = data;
    new_node->left = new_node->right = NULL;
    
    if( NULL == *root )
    {
        *root = new_node;
    }
    else
    {
        tmp = search_bst_for_insert(root,data);
        if( NULL == tmp )
        {
            fprintf(stderr,"%d has already exits\n",data); 
            free(new_node);
            return;
        }
       if( tmp->data > data )
       {
            tmp->left = new_node;        
       }
       else
       {
            tmp->right = new_node;
       }
    }


    return;
}
/* nonrecursive
 * delete bst_node
 * if there are no the same elements in bst.
 */
/*void nonrecursive_delete_bst_node(bst_p* root,data_type data)
{
   //find the node that will be deleted     
   bst_p tmp = iterative_tree_search(*root,data); 
   if( NULL == tmp )
   {
        fprintf(stderr,"the node that wanna be deleted does exist\n");
        return;
   }
   if( NULL == tmp->left && NULL == tmp->right )
   {
        if( tmp == *root )
        {
            *root = NULL;
            free(tmp);
        }

        //TODO
   }
}*/
/*
 * recursive 
 */
void recursive_delete_bst_node(bst_p* root,data_type data)
{
    bst_p tmp = *root;
    if( NULL == tmp )
    {
        fprintf(stderr,"can't find data %d\n",data);
        return;
    }

    if( data == tmp->data )
    {
        //it is a leaf node    
        if( tmp->left == NULL && tmp->right == NULL )
        {
            *root = NULL;
            free(tmp);
        }
        else if( tmp->right == NULL )
        {
            //right child is NULL
            *root = tmp->left;
            free(tmp);
        }
        else if( tmp->left == NULL )
        {
            //left child is NULL
            *root = tmp->right;
            free(tmp);
        }   
        else
        {
            // it has both child
            bst_p parent;
            bst_p smallest = tmp->right;
            if( smallest->left == NULL )
            {
                smallest->left = tmp->left;
            }
            else
            {
                //find the smallest node
                while(smallest->left)
                {
                    parent = smallest;
                    smallest = smallest->left;
                }

                parent->left = smallest->right;
                smallest->left = parent->left;
                smallest->right = parent->right;
            }

            *root = smallest;
            free(tmp);
        }
    }
    else if( data > tmp->data )
    {
        recursive_delete_bst_node(&tmp->right,data);
    }
    else
    {
        recursive_delete_bst_node(&tmp->left,data);
    }

    return;

}
/*
 * get the successor of key element in inorder way
 */
/*bst_p tree_successor(bst_p root,data_type data)
{
    //find the data element node
    bst_p tmp = iterative_tree_search(root,data);
    if( tmp == NULL )
    {
        fprintf(stderr,"there is no %d value element exist.\n");
        return NULL;
    }
    if( tmp->right != NULL )
    {
        return tree_minimum(tmp->right);
    }
    //TODO



}*/

/*
 * by inorder way,print all the element by order
 *
 */
void inorder_tree_walk(bst_p root)
{
    bst_n* tmp_node = root;
    if( tmp_node  != NULL )
    {
       inorder_tree_walk(tmp_node->left);
       printf("%d ",tmp_node->data);
       inorder_tree_walk(tmp_node->right);
    }
}

/*
 *by preorder way
 */
void preorder_tree_walk(bst_p root)
{
    bst_n* tmp_node = root;
    if( tmp_node  != NULL )
    {
       printf("%d ",tmp_node->data);
       preorder_tree_walk(tmp_node->left);
       preorder_tree_walk(tmp_node->right);
    }

}
/*
 *by postorder way
 */
void postorder_tree_walk(bst_p root)
{
    bst_n* tmp_node = root;
    if( tmp_node  != NULL )
    {
       postorder_tree_walk(tmp_node->left);
       postorder_tree_walk(tmp_node->right);
       printf("%d ",tmp_node->data);
    }

}

/*
 * recursive implementation
 * search the element x in the binary search tree
 */
bst_p recursive_tree_search(bst_p root,data_type key)
{
    bst_p tmp_node = root;

    if( tmp_node == NULL || key == tmp_node->data )
    {
        return tmp_node;
    }

    if( key < tmp_node->data )
    {
        return recursive_tree_search(tmp_node->left,key);
    }
    else
    {
        return recursive_tree_search(tmp_node->right,key);
    }
}

/*
 * non-recursive implementation,that is iterative's way
 */
bst_p iterative_tree_search(bst_p root,data_type key)
{
    bst_p tmp_node = root;    
    while(tmp_node != NULL && key != tmp_node->data )
    {
        if( key < tmp_node->data )
        {
            tmp_node = tmp_node->left;
        }
        else
        {
            tmp_node = tmp_node->right;
        }
    }

    return tmp_node;
}

//find the maximum element in the binary search tree 
bst_p tree_maximum(bst_p root)
{
    bst_p tmp_node = root;
    while( NULL != tmp_node->right )
    {
        tmp_node = tmp_node->right;
    }

    return tmp_node;
}
//find the minimum element in the binary search tree 
bst_p tree_minimum(bst_p root)
{
    bst_p tmp_node = root;
    while( NULL != tmp_node->left )
    {
        tmp_node = tmp_node->left;
    }

    return tmp_node;
}

int main()
{
    data_type test_data[] = {15,6,18,3,7,17,20,2,4,13,9}; 
    bst_n* root = NULL;
    //bst_p* root; //error
    int i = 0;
    for( i = 0; i < 11; i++ )
    {
        insert_bst_node(&root,test_data[i]);
    }

    printf("inorder:\n");
    inorder_tree_walk(root);
    printf("\n");
    printf("preorder:\n");
    preorder_tree_walk(root);
    printf("\n");
    printf("postorder:\n");
    postorder_tree_walk(root);
    printf("\n");

    recursive_delete_bst_node(&root,3);
    printf("after deleted some element: %d\n",3);
    inorder_tree_walk(root);
    printf("\n");
    return 0;
}
