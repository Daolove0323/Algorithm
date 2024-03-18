#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(long price, long money, long count) {
    long long answer = (long long)price * count * (count + 1) / 2 - money;
    return answer > 0 ? answer : 0;
}