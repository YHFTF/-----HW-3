#include <stdio.h>
#include <stdlib.h>

void main()
{
    int list[5];                                                //크기가 5인 (20byte) int 형 배열 list를 선언한다.
    int *plist[5] = {NULL,};                                    //크기가 5인 (64비트 기준 40byte)int 형 포인터 배열 plist를 선언한다. 초기값을 NULL로 설정한다. 
    plist[0] = (int *)malloc(sizeof(int));                      //plist[0]에 메모리에 heap 영역에 할당한 주소를 저장한다.
    list[0] = 1;                                                //list[0]에 1의 값을 저장한다.
    list[1] = 100;                                              //list[1]에 100의 값을 저장한다.
    *plist[0] = 200;                                            //plist[0]이 가르키는 주소에 200의 값을 저장한다.
    printf("list[0] = %d\n", list[0]);                          //list[0]의 값을 출력한다.
    printf("&list[0] = %p\n", &list[0]);                        //list[0]의 주소를 출력한다.
    printf("list = %p\n", list);                                //list 배열의 시작주소를 출력한다.
    printf("&list = %p\n", &list);                              //list 배열의 시작주소를 출력한다.     따라서 list와 &list는 동치라는것을 알 수 있다.
    printf("----------------------------------------\n\n");
    printf("list[1] = %d\n", list[1]);                          //list[1]에 저장된 값을 출력한다.
    printf("&list[1] = %p\n", &list[1]);                        //list[1]의 주소를 출력한다.
    printf("*(list+1) = %d\n", *(list + 1));                    //list의 시작 주소로 부터 4byte 떨어진 곳의 값(list[1])을 출력한다.
    printf("list+1 = %p\n", list+1);                            //list의 시작 주소로 부터 4byte 떨어진 곳의 주소(&list[1])을 출력한다.
    printf("----------------------------------------\n\n");
    printf("*plist[0] = %d\n", *plist[0]);                      //plist[0]의 주소가 가르키는 값을 출력한다.
    printf("&plist[0] = %p\n", &plist[0]);                      //plist[0]의 주소를 출력한다.
    printf("&plist = %p\n", &plist);                            //plist의 시작 주소를 출력한다.
    printf("plist = %p\n", plist);                              //plist의 시작 주소를 출력한다.
    printf("plist[0] = %p\n", plist[0]);                        //plist[0]에 저장된 주소(heap영역에 할당된 주소)를 출력한다.
    printf("plist[1] = %p\n", plist[1]);                        //plist[1]에 저장된 주소(초기에 null로 세팅)을 출력한다.
    printf("plist[2] = %p\n", plist[2]);                        //plist[2]에 저장된 주소(초기에 null로 세팅)을 출력한다.
    printf("plist[3] = %p\n", plist[3]);                        //plist[3]에 저장된 주소(초기에 null로 세팅)을 출력한다.
    printf("plist[4] = %p\n", plist[4]);                        //plist[4]에 저장된 주소(초기에 null로 세팅)을 출력한다.
    free(plist[0]);                                             //plist[0]에 할당했던 heap 영역의 메모리 할당을 해제한다.
}