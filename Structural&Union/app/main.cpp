#include <stdio.h>
#include<stdlib.h> //该头文件为malloc必须
//using namespace std;

   struct SIMPLE{
   int a;
   char b;
   float c;
   };

   struct SIMPLE x1,x2;

   typedef struct {
   int a;
   char b;
   float c;
   }simple;

   simple member3,member4,y[40];

   struct CPMPLEX{
          float f;
          int a[20];
          long *lp;
          struct SIMPLE s;
          struct SIMPLE sa[10];
          struct SIMPLE *sp;
          };

    struct CPMPLEX comp;

    struct SELF_FRF1{
        int a;
        struct SELF_FRF1 *b;
        int c;
    };

    struct Int_ex{
    int a;
    short b[10];
    SIMPLE c;
    }x={
        10,
        {1,2,3,4,5},
        {25,'x',1.9}
    };

    struct init_ex{
        int a;
        short b[10];
        SIMPLE c;
    }e={
        10,
        {1,2,4,5},
        {1,'X',2.4}
    };

    typedef struct {
        int a;
        short b[2];
    }Ex2;

    typedef struct EX{
        int a;
        char b[3];
        Ex2 c;
        struct EX *d;
    }Ex;

    Ex y2={10,"Hi",{5,{-1,25}},0};

    Ex *px=&y2;
 #if 1
    typedef struct _tagMem_Align
    {
        char  c1;
        short s;
        char c2;
        int i;
    }Mem_Boundary_Aligment;
  #endif // 0
#if 0
  //offset(type,member);
  //offset(struct ALIGN,b);
    #define PRODUCT_SIZE 20
  typedef struct{
    char  product[PRODUCT_SIZE];
    int   quantity;
    float unit_price;
    float total_amoubt;
  }Transaction;

  Transaction trans;

  void print_receipt(Transaction trans)
  {
    printf("%s\n",trans.product);
    printf("%d&%.2f total %.2f\n",trans.quantity,\
           trans.unit_price,trans.total_amoubt);
  }

  //print_receipt(current_trance);

  void print_receipt2(Transaction &trans)
  {
    printf("%s\n",trans->product);
    printf("%d&%.2f total %.2f\n",trans->quantity,\
           trans->unit_price,trans->total_amoubt);

  }
  //print_receipt2(&current_trance);
    #endif // 0
int main()
{

    int size_value1,size_value2;
   int a;
   char b,c,d;
   int e;
   short f,g;
   EX *h;
   a=12;
   b=13;
   c=a+b;
   a=px->a;
   b=px->b[0];
   c=px->b[1];
   d=px->b[2];
   e=px->c.a;
   f=px->c.b[0];
   g=px->c.b[1];
   h=px->d;
    size_value1=sizeof(float);
    size_value2=sizeof(int);
   #if 0
    Mem_Boundary_Aligment.c1='a';
    Mem_Boundary_Aligment.s=12;
    Mem_Boundary_Aligment.c2='b';
    Mem_Boundary_Aligment.i=32;
    #endif

     #if 1
   Mem_Boundary_Aligment MemAligExample={'a',2,'g',21};
   printf("start adress,c1:%p, s:%p,c2:%p, i:%p",
   (unsigned int) (void *)&MemAligExample.c1- (unsigned int) (void *)&MemAligExample,

   (unsigned int) (void *)&MemAligExample.s- (unsigned int) (void *)&MemAligExample,
   (unsigned int) (void *)&MemAligExample.c2- (unsigned int) (void *)&MemAligExample,
   (unsigned int) (void *)&MemAligExample.i- (unsigned int) (void *)&MemAligExample);
    #endif //
     //   {
       //  a++;}
   //(com.sa[4]).c
   //=com.sa[4].c
   //void func(struct COMPLEX *cp）
   // (*cp).f
    //==cp->f;
    //cp->a
    //cp->s

}

