#include<iostream>
#include<fstream>
#include<string>
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

void preworks()
{
    Item_set sets[15];
    ifstream afile("c:\\Users\\30931\\Desktop\\sets.txt");
    const int len = 4;
    int j,i;
    char data[len];
    int w=0;
    while(w!=15){
         afile.getline(data,len);


                sets[w].item[0]=(int)data[0]-48;
                sets[w].item[1]=(int)data[1]-48;
                sets[w].item[2]=(int)data[2]-48;

             w++;
    }

    for(j=0;j<15;j++)
    {
        for(i=0;i<3;i++)
          cout<<sets[j].item[i];
        cout<<endl;
    }


}
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
    Item_set sets[15];
    ifstream afile("c:\\Users\\30931\\Desktop\\sets.txt");
    const int len = 4;
    int j,i;
    char data[len];
    int w=0;
    while(w!=15){
         afile.getline(data,len);


                sets[w].item[0]=(int)data[0]-48;
                sets[w].item[1]=(int)data[1]-48;
                sets[w].item[2]=(int)data[2]-48;

             w++;
    }

    Node *T = (Node *)malloc(sizeof(Node));
    T->rchild=NULL;
    for(int i=0;i<15;i++)
    insert_operation(T,sets[i]);
    return 0;

}
