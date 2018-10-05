Hi Sarang

static volatile unsigned * const foo = 8;

=================================================================
///// please print output of the followings on a 32-bit Little Endian machine:  /////
    int a[10][10][10][10];
    printf("s1=%d\n", sizeof(a));         40 * 40 * 40 * 40  
    printf("s2=%d\n", sizeof(a[0][0][0])); 10 * 4
    printf("s3=%d\n", sizeof(a[0]));  10 * (40 * 40)

==================================================================
///// please print output of the followings on a 32-bit Little Endian machine: /////
typedef union{
    int  i1;
    char c1;
    short s1;
    long long LL1;
}data_st;

data_st   *pd = (data_st *)0x1000;
{
    printf(“size1 = %d\n”, sizeof(*pd)); // 32
    printf(“size2 = %d\n”, sizeof(pd));  // 4 
    printf("p1=0x%x\n", pd);                // 0x1000
    printf("p2=%x\n", &pd->c1);
}

=================================================================
Please declare a smallest possible footprint C struct which contains the following:
1 int16_t, 1 char, 1 uint64_t, 1 int32_t
What is the size of this struct on a CPU which does not support unaligned memory access?
typedef struct node_t
{
  uint64_t x; // 8
  int32_t y;  // 4
  int16_t z; // 2 + 2 padding
  char w;   // 4
}node;



