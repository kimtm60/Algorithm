#include <iostream>
#include <array>

auto num  = 1'000'000'000;
auto count = std::array<size_t, 10>();

using num_t = decltype(num);
using index_t = size_t;

inline auto bool_to_string(bool param){
	return (param)?"true":"false";
}

void counting_test(num_t param){
	for(num_t i = 1; i <= param; ++i){
		auto input = i;
		while(input){
			auto remain = input % 10;
			++count[remain];
			input/=10;
		}
	}
}

void double_digit_num_test(num_t input, size_t format = 1){
	std::fill_n(count.begin(), count.size(), 0);
	counting_test(input);
	
	bool test_print_format_flag = true;
	for(index_t i = 1; i <= 10; ++i){
		auto a1 = input/10;
		auto a2 = (i<=input%10)?1:0;
		
		auto b1 = (i<input/10)?10:0;
		auto b2 = (i==input/10)?(input%10)+1:0;
		auto result = a1 + a2 + b1 + b2;
		
		if(format == 1){
			printf("%2lu : %2d + %2d + %2d + %2d = %2u ? %2lu = %s\n"\
				   ,i%10, a1, a2 ,b1, b2, result, count[i%10]
				   ,bool_to_string(result==count[i%10]) );
		}
		if(result != count[i%10]){
			test_print_format_flag = false;
		}
	}
	if(format == 2){
		printf("%2d : %s\n",input, bool_to_string(test_print_format_flag));
	}
}

void three_digit_num_test(num_t input, size_t format = 1){
	std::fill_n(count.begin(), count.size(), 0);
	counting_test(input);
	
	bool test_print_format_flag = true;
	for(index_t i = 1; i <= 10; ++i){
		// 109, 110 차이
		
		// first digit
		auto a1 = input/10;
		auto a2 = (i<=(input%10))?1:0;
		
		// second digit
		auto b1 = (i<(input/10))?10:0;
		auto b2 = (i==(input/10))?(input%10)+1:0;
		
		// third digit
		auto c1 = (i<(input/100))?100:0;
		auto c2 = (i==(input/100))?(input%100)+1:0;
		
		// fourth digit
		auto d1 = (i<(input/1000))?1000:0;
		auto d2 = (i==(input/1000))?(input%1000)+1:0;
		
		auto result = a1 + a2 + b1 + b2 + c1 + c2 + d1 + d2;
		
		if(format == 1){
			printf("%2lu : %2d + %2d + %2d + %2d + %2d + %2d + %2d + %2d= %2u ? %2lu = %s\n"\
				   ,i%10, a1, a2 ,b1, b2, c1, c2, d1, d2, result, count[i%10]
				   ,bool_to_string(result==count[i%10]) );
		}
		if(result != count[i%10]){
			test_print_format_flag = false;
		}
	}
	
	if(format == 2){
		printf("%2d : %s\n",input, bool_to_string(test_print_format_flag));
	}

}

#define TEST 3
int main(int argc, const char * argv[]) {
	
	// initialize
	num = 0;
	
	scanf("%d", &num);

#if TEST == 0
		// actual logic
		
#elif TEST == 1
		// test logic 1
	counting_test1(num);
	for(auto&& iter : count){
		std::cout << iter << std::endl;
	}

#elif TEST == 2
	// test logic 2
	double_digit_num_test(num);
	
#elif TEST == 3
	// test logic 3
	for(int i = 0; i < num; ++i){
		int inner_num = 0;
		scanf("%d", &inner_num);
		three_digit_num_test(inner_num);
	}
	
#elif TEST == 4
	// test logic 4
	for(int i = 1; i <= num; ++i){
		three_digit_num_test(i, 2);
	}
	printf("\n");
	for(int i = 1; i <= num; ++i){
		double_digit_num_test(i, 2);
	}
#endif
	
	
    return 0;
}
