#include <stdio.h>
void print_one(int *ptr, int rows);
int main()
{
    int one[] = {0, 1, 2, 3, 4};
    printf("one = %p\n", one);                              //배열one의 시작주소를 출력한다.
    printf("&one = %p\n", &one);                            //배열one의 시작주소를 출력한다.
    printf("&one[0] = %p\n", &one[0]);                      //배열one의 시작주소를 출력한다.
    printf("\n");
    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("------------------------------------\n");
    print_one(&one[0], 5);                                  //print_one 함수가 배열one의 시작주소와 , 5 를 입력값으로 작동한다.
    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    print_one(one, 5);                                      //print_one 함수가 배열one의 시작주소와 , 5 를 입력값으로 작동한다.
    return 0;
}
void print_one(int *ptr, int rows)
{/* print out a one-dimensional array using a pointer */
    int i;
    printf ("Address \t Contents\n");
    for (i = 0; i < rows; i++)                          //rows값 만큼 반복한다.
    printf("%p \t %5d\n", ptr + i, *(ptr + i));         //ptr의 주소에서 (4*i)byte만큼 떨어진 곳의 주소와 그 값을 출력한다.
    printf("\n");
}