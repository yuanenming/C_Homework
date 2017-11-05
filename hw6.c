#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100     //单词的最大长度
#define MAXWORDS 100    //打印的最多单词数

struct linklist{        //行号链表
    int lnum;           //行号
    struct linklist *ptr;//链表指针
};

struct tnode{           //二叉树统计单词
    char *word;          //单词
    int count;           //出现次数
    struct linklist *lines; //行号链表
    struct tnode *left;    //左分支
    struct tnode *right;    //右分支
};

struct tnode *addtreex(struct tnode *,char *,int); //创建子树函数
int getword(char *,int);       //       读取单词函数
void treeprint(struct tnode *); //      字典顺序打印树函数
int getarray(struct tnode *x[100],struct tnode *p );//  获得所有子树函数
void ntreeprint(struct tnode *p[], int n);     //   出现频率打印子树函数
int strcmp_(char *s,char *t);    //忽略大小写字符串比较函数
struct tnode *talloc(void);      //申请子树空间
struct linklist *lalloc(void);   //申请链表空间
void addln(struct tnode*, int); //在已存在子树中加入行号
int getch(void);                //getch函数
void ungetch(int c);            //ungetch函数


int main(int argc, char *argv[])
{
    struct tnode *root;
    char word[MAXWORD];
    int linenum = 1;
    
    root = NULL;
    printf("Please input content end with a '*':\n");
    while (getword(word,MAXWORD) > 0)        //读入新单词
    {if (isalpha(word[0]) )
            root = addtreex(root,word, linenum);//创建子树结构
        else if (word[0] == '\n')    //增加行数
            linenum++;}
    if(argc == 1||(argc == 2 && argv[1][0] == '-' && argv[1][1] == 'a'))
        //默认情况以及“-a”，按照字典顺序输出
        treeprint(root);
    else if(argc == 2 && argv[1][0] == '-' && argv[1][1] == 'f')
        //“-f”，按照出现频率输出
        {struct tnode *p[100];
        int n = getarray(p,root);
            ntreeprint(p,n);}
        return 0;
}



struct tnode *addtreex(struct tnode *p,char *w, int linenum)
{
    int cond;
    
    if(p == NULL){
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->lines = lalloc();
        p->lines->lnum = linenum;
        p->lines->ptr = NULL;
        p->left = p->right = NULL;
    }else if ((cond = strcmp_(w, p->word)) == 0)
              addln(p, linenum);
    else if (cond < 0)
        p->left = addtreex(p->left,w,linenum);
    else
        p->right = addtreex(p->right,w,linenum);
    return p;
}

int strcmp_(char *s,char *t)
{
    int i = 0;
    int tmp1, tmp2;
    while(s[i]!=0&&t[i]!=0)
    {
        if (s[i] >= 97 && s[i] <=122)
           tmp1 = s[i] - 32;
        else tmp1 = s[i];
        if (t[i] >= 97&& t[i] <=122)
            tmp2 = t[i] - 32;
        else tmp2 = t[i];
        
        if (tmp1 == tmp2)
        {
            i++;
        }
        else return tmp1-tmp2;
    }
    return s[i] - t[i];
}

void addln(struct tnode *p, int linenum)
{
    p->count++;
    struct linklist *temp;
    
    temp = p->lines;
    while(temp->ptr != NULL )
        temp = temp->ptr;
    if (temp->lnum != linenum){
        temp->ptr = lalloc();
        temp->ptr->lnum = linenum;
        temp->ptr->ptr = NULL;
    }
}

void treeprint(struct tnode *p)
{
    struct linklist *temp;
    if (p != NULL){
        treeprint(p->left);
        printf("%10s:%4d",p->word,p->count);
        for (temp = p->lines;temp != NULL ; temp = temp->ptr)
            printf("%4d",temp->lnum);
        printf("\n");
        treeprint(p->right);
    }
}



    int ii = 0 ;
int getarray(struct tnode *x[100],struct tnode *p )
{

    if(p != NULL){
        getarray(x,p->left);
        x[ii] = p;
        ii++;
        getarray(x,p->right);
    }
    return ii;
}

void ntreeprint(struct tnode *p[], int n)
{
    struct tnode *ttmp;
    struct linklist *ltmp;
    for(int i = 0;i < n-1; i++)
        for(int j = i+1;j<n;j++)
        {
            if(p[i]->count < p[j]->count)
            {
                ttmp = p[i];
                p[i] = p[j];
                p[j] = ttmp;
            }
        }
    for(int i=0;i<n;i++)
    {
        printf("%10s:%4d",p[i]->word,p[i]->count);
        for (ltmp = p[i]->lines; ltmp != NULL; ltmp = ltmp->ptr)
            printf ("%4d",ltmp->lnum);
        printf("\n");
    }
}
struct linklist *lalloc(void)
{
    return (struct linklist *)malloc(sizeof(struct linklist));
}

struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

int getword(char *word,int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while ((c = getch())==' '||c == '\t')
        ;
    if ( c == '*') return 0;
    if ( c != EOF )
        *w++ = c;
    if ( !isalpha(c) ){
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp>0)?buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch:too many characters\n");
    else
        buf[bufp++] = c;
}

/*
 int noiseword(char *w)
{
    static char *nw[] = {
        "a",
        "an",
        "and",
        "are",
        "in",
        "is",
        "of",
        "or",
        "that",
        "the",
        "this",
        "to"
    };
    int cond, mid;
    int low = 0;
    int high = sizeof(nw) / sizeof(char *) - 1;
    while(low <= high){
        mid = (low + high) /2;
        if ((cond = strcmp_(w, nw[mid]))<0)
            high = mid - 1;
        else if(cond > 0)
            low = mid+1;
        else
            return mid;
    }
    return -1;
} */

