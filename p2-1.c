#include <stdio.h>
#define MAX_SIZE 100
float sum1(float list[], int);
float sum2(float *list, int);
float sum3(int n, float *list); 
float input[MAX_SIZE], answer;
int i;
void main(void)
{
    for(i=0; i < MAX_SIZE; i++)                             
    input[i] = i;                                           //input[100] 배열에 각각 input[i] = i의 값이 저장된다.
    /* for checking call by reference */
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);                        //input배열의 시작주소가 출력된다.
    answer = sum1(input, MAX_SIZE);                         //sum1 함수가 input 배열의 시작주소와 , 100의 입력값을 가지고 실행된다. 이후 sum1 함수가 반환한 tempsum값을 answer값에 저장한다.
    printf("The sum is: %f\n\n", answer);                   //answer 값을 출력한다.
    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);                        //input배열의 시작주소가 출력된다.
    answer = sum2(input, MAX_SIZE);                         //sum2 함수가 input 배열의 시작주소와 , 100의 입력값을 가지고 실행된다. 이후 sum2 함수가 반환한 tempsum값을 answer값에 저장한다.
    printf("The sum is: %f\n\n", answer);                   //answer 값을 출력한다.
    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");                    
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);                        //input배열의 시작주소가 출력된다.
    answer = sum3(MAX_SIZE, input);                         //sum3 함수가 input 배열의 시작주소와 , 100의 입력값을 가지고 실행된다. 이후 sum2 함수가 반환한 tempsum값을 answer값에 저장한다.
    printf("The sum is: %f\n\n", answer);                   //answer 값을 출력한다.
}

float sum1(float list[], int n) {
    printf("list\t= %p\n", list);                           //list배열의 시작주소(input배열의 시작주소)가 출력된다.
    printf("&list\t= %p\n", &list);                         //list배열 포인터 자체의 주소를 출력한다.

    int i;
    float tempsum = 0;
    for (i = 0; i < n; i++)
        tempsum += list[i];                                 
    return tempsum;                                         //임시 저장소인 tempsum에 list[0]~list[99]까지의 값을 모두 더한다. 이후에 그 값인 tempsum을 반환한다.
}

float sum2(float *list, int n) {
    printf("list\t= %p\n", list);                           //list배열의 시작주소(input배열의 시작주소)가 출력된다.
    printf("&list\t= %p\n", &list);                         //list배열 포인터 자체의 주소를 출력한다.

    int i;
    float tempsum = 0;
    for (i = 0; i < n; i++)
        tempsum += *(list + i);
    return tempsum;                                         //임시 저장소인 tempsum에 list[0]~list[99]까지의 값을 모두 더한다. 이후에 그 값인 tempsum을 반환한다.
}

/* stack variable reuse test */
float sum3(int n, float *list) {
    printf("list\t= %p\n", list);                           //list배열의 시작주소(input배열의 시작주소)가 출력된다.
    printf("&list\t= %p\n", &list);                         //list배열 포인터 자체의 주소를 출력한다. 
                                                            //여기서 이전 sum2의 값과 다른 +8이 된 값이 나오게 되는데 이는 input 배열의 주소를 저장하기 위한 포인터의 공간을 그대로 사용하지 않고 다음 공간을 사용했기 때문이다.
    int i;
    float tempsum = 0;
    for (i = 0; i < n; i++)
        tempsum += *(list + i);
    return tempsum;                                         //임시 저장소인 tempsum에 list[0]~list[99]까지의 값을 모두 더한다. 이후에 그 값인 tempsum을 반환한다.
}