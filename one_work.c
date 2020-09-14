#include<iostream>
using namespace std;

typedef struct Item_set
{
    int item[5];
    int mark=0;
}Item_set;

typedef struct Node{
    Item_set    i[3];
    int total_item=0;
    bool midlle_node = false; //判断是否是空心中继节点
    struct Node *lchild = NULL;
    struct Node *mchild = NULL;
    struct Node *rchild = NULL;
}Node;//增加一个 *Node_p 替换 Node *T试试。

void insert_operation(Node *T,Item_set i)
{

    int d = i.item[i.mark]%3;
    i.mark++;

    if (d == 1)                             //左孩子
    {
        if(T->lchild == NULL)
        {
            Node *p = (Node *)malloc(sizeof(Node));
            p->i[0]=i;
            p->total_item=0;
            p->lchild=NULL;
            p->mchild=NULL;
            p->rchild=NULL;
            p->midlle_node=false;
            p->total_item++;
            T->lchild = p;

        }
        else
        {
            if(T->lchild->total_item < 3)
            {
                 T->lchild->i[T->lchild->total_item]=i;
                 T->lchild->total_item++;
            }
            else
            {
                if(T->lchild->midlle_node!=true)
                {

                    for(int j=0;j<3;j++)
                    {
                        insert_operation(T->lchild,T->lchild->i[j]);
                    }

                      insert_operation(T->lchild,i);
                    //把T处理为空心中继节点。
                    T->midlle_node=true;
                }
                else
                    insert_operation(T->lchild,i);

            }

        }
    }
    if(d ==2)                                   //中间孩子
    {
        if(T->mchild == NULL)
        {
             Node *p = (Node *)malloc(sizeof(Node));
             p->i[0]=i;
             p->total_item=0;
             p->lchild=NULL;
            p->mchild=NULL;
            p->rchild=NULL;
             p->total_item++;
               p->midlle_node=false;
             T->mchild = p;
        }
        else
        {
            if(T->mchild->total_item < 3)
            {
                T->mchild->i[T->mchild->total_item]=i;
                T->mchild->total_item++;
            }
            else
            {
                if(T->midlle_node!=true)
                {
                    for(int j=0;j<3;j++)
                    insert_operation(T->mchild,T->mchild->i[j]);
                    insert_operation(T->mchild,i);
                    //把T处理为空心中继节点。
                    T->midlle_node=true;
                }
                else
                    insert_operation(T->mchild,i);
            }
        }
    }
    if(d==0)                                    //右孩子
    {
        if(T->rchild == NULL)
        {
            Node *p = (Node *)malloc(sizeof(Node));
            p->i[0]=i;
            p->total_item=0;
            p->lchild=NULL;
            p->mchild=NULL;
            p->rchild=NULL;
            p->total_item++;
            p->midlle_node=false;
            T->rchild = p;

        }
        else
        {
            if(T->rchild->total_item < 3)
            {

                 T->rchild->i[T->rchild->total_item]=i;
                 T->rchild->total_item++;
            }
            else
            {

                if(T->rchild->midlle_node!=true)
                {

                    for(int j=0;j<3;j++)
                    {
                        insert_operation(T->rchild,T->rchild->i[j]);
                    }

                      insert_operation(T->rchild,i);
                    //把T处理为空心中继节点。
                    T->midlle_node=true;
                }
                else
                    insert_operation(T->rchild,i);


            }

        }
    }
}
int main()
{
    Item_set a[15];
    a[0].item[0]=1; a[0].item[1]=4;a[0].item[2]=5;  a[1].item[0]=1;a[1].item[1]=2;a[1].item[2]=4;   a[2].item[0]=4;a[2].item[1]=5;a[2].item[2]=7;
    a[3].item[0]=1;a[3].item[1]=2;a[3].item[2]=5;   a[4].item[0]=4;a[4].item[1]=5;a[4].item[2]=8;a[5].item[0]=1;a[5].item[1]=5;a[5].item[2]=9;
    a[6].item[0]=1;a[6].item[1]=3;a[6].item[2]=6;a[7].item[0]=2;a[7].item[1]=3;a[7].item[2]=4;a[8].item[0]=5;a[8].item[1]=6;a[8].item[2]=7;
    a[9].item[0]=3;a[9].item[1]=4; a[9].item[2]=5;a[10].item[0]=3;a[10].item[1]=5;a[10].item[2]=6;a[11].item[0]=3;a[11].item[1]=5;a[11].item[2]=7;
    a[12].item[0]=6;a[12].item[1]=8;a[12].item[2]=9;a[13].item[0]=3;a[13].item[1]=6;a[13].item[2]=7;a[14].item[0]=3;a[14].item[1]=6;a[14].item[2]=8;

    Node *T = (Node *)malloc(sizeof(Node));
    T->rchild=NULL;
    for(int i=0;i<15;i++)
    insert_operation(T,a[i]);


    for(int j =0;j<2;j++)
    cout<<T->rchild->rchild->i[j].item[0]<<T->rchild->rchild->i[j].item[1]<<T->rchild->rchild->i[j].item[2]<<" ";

    return 0;

}
