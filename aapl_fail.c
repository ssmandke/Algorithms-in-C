#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


int a[10][10][10][10];
///// please print output of the followings on a 32-bit Little Endian machine: /////
typedef union{
    int  i1;
    char c1;
    short s1;
    long long LL1;
}data_st;

typedef struct A_struct_t {
  char t;
  char *rt;
}A_struct;

data_st   *pd = (data_st *)0x1000;

typedef struct node_t
{
  unsigned long long  x; // 8
  int y;  // 4
  short z; // 2 + 2 padding
  char w;   // 4
}node;

typedef struct node_t_1
{
  unsigned long long  x; // 8
  int y;  // 4
  short z; // 2 + 2 padding
  //char w;   // 4
}node1;


typedef struct node_t_2
{
  short z; // 2 + 2 padding
  char w;   // 4
}node2;


typedef struct node_t_3
{
  
  char w;   // 4
  short z; // 2 + 2 padding
}node3;

typedef struct node_t_4
{
  char w;   // 4
  short z; // 2 + 2 padding
  int y;  // 4
  unsigned long long  x; // 8
  
}node4;

typedef struct structx_tag
{
   char        c;
   int      d;
   char        s;
} structx_t;

// structure C
typedef struct structb_tag
{
   char        c;
   short      d;
   char        s;
} structb_t;

// structure C
typedef struct structc_tag
{
   char        c;
   double      d;
   char        s;
} structc_t;

// structure C
typedef struct structd_tag
{
   char        c;
   char        s;
   double      d;   
} structd_t;

// structure C
typedef struct structe_tag
{
   double      d;   
   char        c;
   char        s;
} structe_t;

typedef struct structf_tag
{
   double      d;   
   double      c;
   char        s;
} structf_t;

typedef struct bad_pad_t{
    char c1;
    short s1;
    int  i1;
    long long LL1;
}bad_pad;


typedef struct good_pad_t{
    
    long long LL1;
	short s1;
	int  i1;
	char c1;
}good_pad;

structe_t myObj;
structe_t *ptrToStructE = &myObj;

int main()
{
	int x = 10;
    int *ptrX = &x;
	bad_pad obj_t;
	printf("%p\r\n", (&ptrX)); //will give you address of ptrX
	printf("%p\r\n", (&x)); //will give you address of X
    printf("%p\r\n", (void*)*(&ptrX)); //will give you address of X
    printf("%d\r\n", **(&ptrX)); //value of X
	
	
    printf("s1=%d\n", sizeof(a));         //10 * 10 * 10 * 10  * 4  
    printf("s2=%d\n", sizeof(a[0][0][0])); //10 * 4
    printf("s3=%d\n", sizeof(a[0])); // 10 * (10 * 10)* 4


    printf("size1 data_st = %d\n", sizeof(*pd));     // 8
    printf("size2 data_st ptr = %d\n", sizeof(pd));  // 4 
	printf("size1 data_st = %d\n", sizeof(data_st)); // 8
    printf("p1=0x%x\n", pd);                // 0x1000
    printf("p2=0x%x\n", &pd->c1);
	printf("p3=0x%x\n", &pd->s1);

    printf("sizeof struct node = %d\r\n",sizeof(node));
	printf("sizeof struct node = %d\r\n",sizeof(node1));
	printf("sizeof struct node = %d\r\n",sizeof(node2));
	printf("sizeof struct node = %d\r\n",sizeof(node3));	
	
	//sizeof struct should be 1 + 7 byte padding + 8 + 4 = 20 bytes but it is 24 bytes due to padding of 8 bytes for double..
	//So in memory..1 byte char is followed by 3 byte padding..then 8 byte padding and then the double (8 byte) and int (4 byte)
	printf("sizeof struct char double char = %d\r\n",sizeof(structc_t));
	printf("sizeof struct char char double = %d\r\n",sizeof(structd_t));
	printf("sizeof struct double char char = %d\r\n",sizeof(structe_t));
	printf("sizeof struct char short char  = %d\r\n",sizeof(structb_t));
	printf("sizeof struct char int char    = %d\r\n",sizeof(structx_t));
	printf("sizeof struct char and char*   = %d\r\n",sizeof(A_struct));
	
	printf("pointer to structE is pointing to 0x%p\r\n",ptrToStructE);
	printf("sizeof struct double d, char c , char s = 0x%p, 0x%p, 0x%p\r\n",&ptrToStructE->d,&ptrToStructE->c,&ptrToStructE->s);
	printf("sizeof struct double,double, char = %d\r\n",sizeof(structf_t));
	printf("sizeof bad pad = %d, good pad = %d\r\n",sizeof(bad_pad), sizeof(good_pad));
	printf("sizeof  0x%x 0x%x 0x%x 0x%x\r\n",&obj_t.c1,&obj_t.s1, &obj_t.i1,&obj_t.LL1);
	
  return 0;
}