#include <iostream>
#include <string>

template<typename T>

class AUDS {

	public:
		// Constructor
		AUDS() {
			initialSize = 100;
			currentSize = 0;
			maxSize = 100;
			ourData = new T[initialSize];
		}
		//Deep Copy Constructor
		AUDS(const AUDS &other) {
			initialSize = other.initialSize;
			currentSize = other.currentSize;
			maxSize = other.maxSize;
			ourData = other.ourData;
			
			if (other.ourData){
				for (int i=0; i <= currentSize; ++i){
					ourData[i] = other.ourData[i];	
				}
			}
			else {
				ourData = 0;
			}
		}
		//Copy Operator
		AUDS& operator=(AUDS other) {
			std::swap(initialSize, other.initialSize);
			std::swap(currentSize, other.currentSize);
			std::swap(maxSize, other.maxSize);		
		}
		// Destructor
		~AUDS() {
			delete[] ourData;
		}
		// Returns number of elements in array
		int size(){
			int sum=0;
			for (int i=0; i<=currentSize; i++){
				if(ourData[i] != NULL){
					sum++;
				}
			}
			return sum;
		}
		// Pushes a new element of any data type onto the end of the array
		void push(T x){
			for (int i=0; i <= maxSize; i++){
				if (ourData[i]== NULL){
					ourData[i] = x;
					currentSize++;
					std::cout << "OD after push:" << ourData[i] << std::endl;
					//checkSize(ourData);
					break;
				}
			//Test Print Statement
			std::cout << ourData[i] << std::endl;
			}	
		}

		// Pops random element from list
		T pop() {
			T tmp;
			for (int i=0; i < currentSize; i++){
				//Change to be a random element 
				if ( i = 3 ) {
					tmp = ourData[i];
					T z = ourData[currentSize -1];
					ourData[i] = z;
					currentSize--;
				}
			}
			return tmp;
		}
		// Checks to make sure the currentSize is less than maxSize
		// If not, increases the size of the array by 50%
		void checkSize(AUDS x) {
			if(currentSize >= maxSize){
				maxSize *= 1.5;	
			}
		}

	private:
		int initialSize;
		int currentSize;
		int maxSize;
		T* ourData;

};
