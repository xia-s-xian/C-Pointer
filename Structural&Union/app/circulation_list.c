#include <stdio.h>


#define BUFFER_NUM  5
#define BUFFER_SIZE 60
unsigned int buffer[BUFFER_NUM][BUFFER_SIZE];


typedef struct criculate_list_s
{
    void *buf_in; //��ǰ���������ַ
    void *buf_out;//��ǰ���������ַ
    int   num;    //��Ч���ݸ���
}criculate_list_t;

void fun_array();
void add_criculate(void *buf,criculate_list_t *list);
void init_list(void);
criculate_list_t *criculate_list;
int get_buf_num(void*pointer);

int main()
{
    int buffer_in[60]={1,2,3};
    int buffer_out[60];
    printf("size = %d\r\n",sizeof(criculate_list_t));

    init_list();
    for(int i=0;i<11;i++)
    {
        add_criculate(buffer_in,criculate_list);
        //printf("data=%x\r\n",criculate_list->buf_in);
        add_criculate(buffer_in,criculate_list);
       // printf("data=%x\r\n",criculate_list->buf_in);
        printf("buffer in\r\n");
        printf("buffer list1=%d\r\n",buffer[0][0]);
        printf("buffer list2=%d\r\n",buffer[1][0]);
        printf("buffer list1=%d\r\n",buffer[2][0]);
        printf("buffer list2=%d\r\n",buffer[3][0]);
        printf("buffer list1=%d\r\n",buffer[4][0]);
        get_criculate(buffer_out,criculate_list);
        //get_criculate(buffer_out,criculate_list);
        printf("buffer out\r\n");
        printf("buffer list1=%d\r\n",buffer[0][0]);
        printf("buffer list2=%d\r\n",buffer[1][0]);
        printf("buffer list1=%d\r\n",buffer[2][0]);
        printf("buffer list2=%d\r\n",buffer[3][0]);
        printf("buffer list1=%d\r\n",buffer[4][0]);
    }
    //fun_array();
    return 1;
}

void init_list(void)
{
    criculate_list = malloc(sizeof(criculate_list_t));
    criculate_list->num = 0;
    criculate_list->buf_in = buffer[0];
    criculate_list->buf_out = buffer[0];
}

void add_criculate(void *buf,criculate_list_t *list)
{
    static int num=0;

    if(list->num == 0 &&(list->buf_in == list->buf_out))
        list->buf_in= list->buf_out;
    else
        list->buf_in = buffer[num];

    memcpy(list->buf_in,buf,BUFFER_SIZE);
    num=get_buf_num(list->buf_in);
    num++;
    //limit all buffer
    if(list->num<BUFFER_NUM)
        list->num++;

    //criculate the buffer
    if(num == BUFFER_NUM)
        num=0;

    //change the pointer of buffer out
    if(list->buf_in == list->buf_out&&list->num== BUFFER_NUM)
    {
        list->buf_out = buffer[num];
    }
    printf("num=%x\r\n",list->num);
    printf("list->buf_in=%x\r\n",list->buf_in);
    printf("list->buf_out=%x\r\n",list->buf_out);
 //   for(int i=0;i<num;i++)
  //      printf("buff=%d%d%d",(unsigned int*)*(list->buf_in));
}

void get_criculate(void *buf,criculate_list_t *list)
{
    int num;
    if(list->num>0)
    {
        memcpy(buf,list->buf_out,BUFFER_SIZE);
        memset(list->buf_out,0,BUFFER_SIZE);
        list->num--;
        num = get_buf_num(list->buf_out);
        if((num<5)&&(list->num>0))
        {
            num++;
            if(num<=4)
                list->buf_out = buffer[num];
            if(num==5)
                list->buf_out = buffer[0];
        }

        //  list->buf_out = buffer[0];

    }
}

int get_buf_num(void*pointer)
{
    for(int n=0;n<5;n++)
    {
        if(pointer == buffer[n])
        {
            return n;
        }
    }

}

//��������ĵ�ַ�Ͷ�Ӧֵ
void fun_array()
{
    int *value;

    buffer[0][0]=1;
    buffer[1][0]=2;
    buffer[2][0]=3;
    buffer[3][0]=4;
    buffer[4][0]=5;

    for(int i=0;i<5;i++)
        //printf("Hellow world");
        {
            printf("address=%x\r\n",buffer[i]);

        }
    for(int i=0;i<5;i++)
    {
        value = buffer[i];
        printf("value = %d\r\n",*value);
    }

}
