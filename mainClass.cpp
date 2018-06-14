#include <vector>
#include <iostream>

class mainClass {
   	std::vector< int > arr;
   public:
    void insertValue (int);
    float getMedian();
};
void mainClass::insertValue(int val){
	arr.push_back(val);
}
 

float mainClass::getMedian(){
      	if(arr.size()%2 == 1){
		return arr[arr.size()/2];
	}else{	
		return (arr[arr.size()/2] + arr[arr.size()/2]-1)/2.0;
	}
}


