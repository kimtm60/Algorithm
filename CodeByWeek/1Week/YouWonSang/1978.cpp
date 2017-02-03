#include <iostream>

int num = 0;
int prime_num = 0;

int main(int argc, const char * argv[]) {
	scanf("%d", &num);
	
	for(int i = 0; i < num; ++i){
		int input = 0;
		scanf("%d", &input);
		
		bool prime_flag = true;
		
		for(int i = 2; (i-1)*(i-1) < input; ++i){
			if(!(input - (input/i)*i)){
				prime_flag = false;
				break;
			};
		}
		if((input != 1 && prime_flag) || input == 2 || input == 0){
			++prime_num;
		}
	}
	
	printf("%d", prime_num);
	
    return 0;
}
