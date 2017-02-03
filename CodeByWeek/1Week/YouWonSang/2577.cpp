#include <iostream>

int main(int argc, const char * argv[]) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	int input = a*b*c;
	
	while(input){
		auto remain = input%10;
		++count[remain];
		input/=10;
	}
	
	for(int i = 0; i < 10; ++i){
		printf("%d\n", count[i]);
	}
	
    return 0;
}
