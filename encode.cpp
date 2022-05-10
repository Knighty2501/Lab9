#include <iostream>
#include <list>
#include <time.h>
#include <vector>

int get_rand(){ //muh random function now limited to 0 -> 1
	int r;
	r = rand() % 2;
	return r;
}

void error_checker(int arr[]) {
	 
	int	len = sizeof(&arr);
	int c1 = 0;
	int c2 = 0;
	std::vector<int> err; 
	int count = 0;
	int r = 0;
    int col = 0;
	int k[2][8];
	for(int i = 0; i < len; ++i) {
		int temp = arr[i];
		err.push_back(temp);
	}

	for(auto it = err.begin(); it != err.end(); ++it) {
		
		c1 = 0;
		c2 = 0;
		if(r != 0) {
			c1 = ((err[r] + err[r-2]) % 2);
			c2 = ((err[r] + err[r-1] +err[r-2]) % 2);
		r++;
		}else{
		c1 = ((err[r] + 0) % 2);
		c2 = ((err[r] + err[r-1] +err[r-2]) % 2);
		}
		r++;
		
		
		if(col < 8){
//			std::cout << "k[0][col] is getting this val: " << c1 << std::endl;
			int temp = c1;
			k[0][col] = temp;
			k[1][col] = c2;
//			std::cout << k[0][col] << " is the value in said spot" << std::endl;
			col++;
		}
	}		
	r = 0;
		std::vector<int> cprime;

		for(int col = 7; col >= 0; --col){
			int row = 0;
			std::cout << k[row][col] << ' ' << k[row+1][col] << std::endl;
		}
		for(int col = 7; col >= 0; --col){
			int row = 0;

			if((k[row][col] == 0) && (k[row+1][col] == 0)){
				count = count + 0;
				if((row == 0) && (col == 7)){
					cprime.push_back(k[row][col]);
					cprime.push_back(k[row+1][col]);
				}
				if((row == 0) && (col == 0)){
					cprime.push_back(k[row][col]);
					cprime.push_back(k[row+1][col]);
				}
			}else{
				count++;
				if((k[row][col] == 0) && (k[row+1][col] == 1)){
					cprime.push_back(k[row][col] + 1);
					cprime.push_back(k[row+1][col] * 0);	
				}
				if((k[row][col] == 1) && (k[row+1][col] == 0)){
					cprime.push_back(k[row][col] * 0);
					cprime.push_back(k[row+1][col] + 1);	
				}
				if((k[row][col] == 1) && (k[row+1][col] == 1)){
					cprime.push_back(k[row][col]);
					cprime.push_back(k[row+1][col]);	
				}
			}	
		}
		std::cout<< "total amount of errors: " << count << '\n';
		std::cout<< "value of cprime: ";
		for(int i = 0; i< cprime.size(); i++){
			std::cout << cprime.at(i) << ' ';
		}
		std::cout << '\n';
}
int main() {

	int l[8] = {0};
	srand(time(0));
	int c = 0;
	for(int i = 0; i < 8; ++i){
		if(i != 0){
			int rando = get_rand();
			l[i] = rando;

		}else{
			l[i] = 0;
		}
	}
	std::cout << "array: ";
	while(c < 8){
		std::cout<< l[c] << ' ';
		c++;
	}
	std::cout<< '\n';
	error_checker(l);
	return 0;
}
