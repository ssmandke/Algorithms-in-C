#include<stdio.h>

 
typedef enum
{
    brown_cow=0,
    black_cow,
    white_cow
 
 
}   cow_colour;
 
 
/******************************
 * declare "test" as a function
 * with input "cow_colour"
 * returning a pointer to
 * an array with 4 elements of
 * constant char pointers
 ******************************/
const char * (* test(cow_colour))[4];
 

unsigned long int (*function())[5]
{
	static unsigned long int arr[5] = {2, 3, 5, 7, 11};
	printf("%d", *arr);
	return &arr;
}
int main()
{
	
    int i;
 int a[4][3] = {{10,20,30},{40,50,60},{70,80,90},{91, 92, 93}};
int *p[4] = {a+0, a+1, a+2, a+3};
int *ptrTmp = p[2];
printf("%d %d %d 0x%x 0x%x 0x%x 0x%x\r\n",a[0][0],a[0][1],a[0][2],&a[0][0],&a[0][1],&a[0][2], &a[1][0]);
printf("%d, %d, %d  0x%x \r\n", *p[0], *p[1], *p[2],ptrTmp); // prints 10, 40, 70 and pointer addr...
printf("%d, %d\r\n", *(p[0]+1), *(p[2]+2));	   // prints 20, 90
printf("%d, %d\r\n", *(p[0]+1), p[0][0]);      // prints 20, 20
    unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6}, 
                           {7, 8, 9}, {10, 11, 12}};
						   
    printf("%x  %x  %x, %x, %x",&x[0][0],&x[0][3], x+3, *(x+3), *(x+2)+3);
    const char * (* array)[4] = test(brown_cow);
    //const char * (* array)[4] = test(black_cow);
    //const char * (* array)[4] = test(white_cow);
 
 
    for(i = 0; i < 4; i++)
    {
        printf("%s ", (*array)[i]);
    }
 
 
    printf("\r\n");
	
	unsigned long int (*ptr)[5];
	ptr = function();
	printf("%d", *(*ptr + 4));
	return 0;
}

const char * (* test(cow_colour cow))[4]
{
    static const char *brown_str[4] = {"How", "now", "brown", "cow"};
    static const char *black_str[4] = {"How", "now", "black", "cow"};
    static const char *white_str[4] = {"How", "now", "white", "cow"};
    static const char *unknown_str[4] = {"How", "now", "unknown coloured", "cow"};
 
 
    switch (cow)
    {
        case brown_cow:
            return &brown_str;
 
 
        case black_cow:
            return &black_str;
 
 
        case white_cow:
            return &white_str;
 
 
    }
 
 
    return &unknown_str;
}