// vector::pop_back
#include <iostream>
#include <vector>

#include <cstdlib>
#include <ctime>

using namespace std;

//display vector 
void display_vector(const vector<int> &v)//const means we don't want to change the value of input
{
	for (auto x : v) std::cout << x << " ";//c++11 version, auto: We are also using the keyword auto instead of specifying the data type thread, which we can do whenever the 
		                   //compiler can unambiguously guess what the correct type should be. 
	//std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " ")); //prior to c++11 version diaplay	
}

// swap elements
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//Heap Sort facility function
void sink(vector <int> &num, int k, int N)
{
	while ((2 * k + 1) <= N)//left = 2 * k + 1 child exisits
	{
		int j = 2 * k + 1; // left = 2 * k + 1
		if ((j < N) && (num[j] < num[j + 1])) j++; //This step is to find larger child. Note: j<N meaning (j+1) <=N, so (j+1) right child is in array. 
		if (num[k] >= num[j]) break;
		swap(num[k], num[j]);
		k = j; //sink down to child
	}
}

// Heap Sort Function for ascending Order, unstable, in-place, worst and average case:  O(N logN); best case: O(N).
void heapSort(vector <int> &num)
{
	int N = num.size();
	for (int k = (N - 1) / 2; k >= 0; k--)//bottom up build max heap	
		sink(num, k, N);	

	// One by one extract an element from heap
	int i = N - 1;
	while (i > 0)
	{
		// Move current root to end
		swap(num[0], num[i]);
		// call max heapify on the reduced heap
		sink(num, 0, --i);
	}
}

int main(int argc, char *argv[])
{
	vector<int> myvector;
	srand((unsigned)time(0));

	for (int i = 0; i < 20; i++)
	{
		myvector.push_back(rand());
	}
	display_vector(myvector);
	cout << endl;

	heapSort(myvector);
	
	display_vector(myvector);
	cout << endl;

	getchar();
	return 0;
}
