#include<stdio.h>
#include<string>
#include<iostream>

int main() {
	int j,count=0;
	for (j = 0; j < 100; j = j + 1) {
		printf("1st:%d,2nd:%d", j, j + 1);
		count += 2;
	}
	printf("�������%d��", count);
}