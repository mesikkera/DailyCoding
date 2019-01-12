#include<iostream>
using namespace std;

int main(){
	
	int size, rotate; 
	cout << "배열의 크기를 입력하세요 : ";
	cin >> size;

	cout << "왼쪽으로 회전할 수를 입력하세요 : ";
	cin >> rotate;	
	
	int array[size];
	cout << "배열의 각 요소를 입력하세요 : ";
	
	for(int i = 0; i < size; i++){
		cin >> array[i];
	}
	
	int temp=0;
	for(int i = 0; i < rotate; i++) {	
	temp = array[0];
		for(int j = 0; j < size; j++) {
			if(j == size-1) {
				array[size-1] = temp;
			}
			else {
			array[j] = array[j+1];
			}
		}
	}

	cout << "회전한 배열은 : ";
	for(int j = 0; j < size; j++){
		cout << array[j] << " ";
	}
	cout << endl;

	// getchar();
	return 0;
}
