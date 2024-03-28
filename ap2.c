#include <stdio.h>
#include <stdlib.h>
void main()
{
    int list[5];                                //크기가 (20byte)인 int 형 배열 list를 선언한다.
    int *plist[5];                              //크기가 (64비트 기준 40byte)인 int 형 포인터 배열 plist를 선언한다.
    list[0] = 10;                               //list[0]에 10의 값을 저장한다.
    list[1] = 11;                               //list[1]에 11의 값을 저장한다.
    plist[0] = (int*)malloc(sizeof(int));       //plist[0]에 heap영역의 메모리 주소를 저장한다.
    printf("list[0] \t= %d\n", list[0]);        //list[0]의 값을 출력한다.
    printf("list \t\t= %p\n", list);            //list배열의 시작 주소를 출력한다.
    printf("&list[0] \t= %p\n", &list[0]);      //list배열의 시작 주소를 출력한다.
    printf("list + 0 \t= %p\n", list+0);        //list배열의 시작 주소로부터 0byte만큼 떨어진 주소를 출력한다.
    printf("list + 1 \t= %p\n", list+1);        //list배열의 시작 주소로부터 4byte만큼 떨어진 주소를 출력한다.
    printf("list + 2 \t= %p\n", list+2);        //list배열의 시작 주소로부터 8byte만큼 떨어진 주소를 출력한다.
    printf("list + 3 \t= %p\n", list+3);        //list배열의 시작 주소로부터 12byte만큼 떨어진 주소를 출력한다.
    printf("list + 4 \t= %p\n", list+4);        //list배열의 시작 주소로부터 16byte만큼 떨어진 주소를 출력한다.
    printf("&list[4] \t= %p\n", &list[4]);      //list[4]의 주소값을 출력한다.
    free(plist[0]);                             //plist[0]에 할당했던 heap영역의 메모리를 할당해제한다.
} 