#include <iostream>
#include <stdlib.h>    
#include <time.h>
#include <chrono>
#include <algorithm>
#include <array>

using namespace std;

//int BubbleSort with double for loop
void BubbleSort_For(int A[], int size)
{

do{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (A[j] > A[j + 1])
      {
	int temp = A[j];
	A[j] = A[j + 1];
	A[j + 1] = temp;
      }
    }
  }
}while(!is_sorted(A.begin(),A.end()));
}


//int BubbleSort with a while loop and for loop.
void BubbleSort_while(int A[], int size)
{
  bool swapped = true;
  
  
  while(swapped)
  {
      int res = 0;
      swapped = false;
      for(int i = 0; i < size - 1; i++)
      {
	  if(A[i] > A[i + 1])
	  {
	    res = 0;
	    res = A[i];
	    A[i] = A[i + 1];
	    A[i + 1] = res;
	    swapped = true;
	  }
      }
  }
}

//InsertionSort implementation
void InsertionSort(int A[], int size)
{
  for (int i = 0; i < size; i++)
  {
    int j = 0;
    int val = A[i];
    for (j = i; j > 0 && A[j - 1] > val; j--)
      A[j] = A[j - 1];
    
    A[j] = val;
  }
}

//SelectionSort implementation
void SelectionSort(int A[], int size)
{
      int minindex;

    for (int i = 0; i < size; i++)
    {
        minindex = i;
        for (int j = i; j < size; j++)
            if (A[j] < A[minindex])
                minindex = j;

        int val = A[i];
        A[i] = A[minindex];
        A[minindex] = val;
    }
}

int main()
{
	int num;
	int input;
	srand(time(NULL));
	do{

	cout<< "array menu options" << endl;			//option menu to let user choose what they want to test.
	cout << "input 1 to test sorted arrays."<<endl;
	cout << "input 2 to test sorted arrays backwards." << endl;
	cout << "input 3 to test duplicate numbers in array." << endl;
	cout << "input 4 to test random arrays." << endl;
	cout << "enter 5 to end test. " << endl;
	cin >> input;

	if(input == 1)				// if user choose 1, they will test the time using a sorted array.
	{
		cout << "sorted array" << endl;
  		cout << "input a size of array: "<< endl;
		cin >> num;
  		int sortedArray[num];
		//Populating the array with sorted number sarting from 1 to the size of the array the user inputs.
   		for(int i = 0; i < num; i++)
 		 {
   			 sortedArray[i] = (i + 1);
 		 }
		
		int choice;
		do{
		cout << "what sort would you like to test? " << endl;
		cout << " 1 for Bubble sort, 2 for Selection sort, 3 for Insertion sort, and enter to end testing. " << endl;
		cin >> choice;
			
		if(choice == 1)
		{
			cout << "Bubble sort " << endl;	
			auto start = std::chrono::system_clock::now();
			BubbleSort_while(sortedArray, num); // replace with your sorting alorithm
			// SelectionSort(sortedArray, num);
			// InsertionSort(backWardsArray, num);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end-start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			std::cout << "finished at " << std::ctime(&end_time)
			<< "elapsed time: " << elapsed_seconds.count() << "s\n";
		}
		else if(choice == 2)
		{
			cout << "Selection sort " << endl;
			auto start = std::chrono::system_clock::now();
			//BubbleSort_while(sortedArray, num); // replace with your sorting alorithm
			SelectionSort(sortedArray, num);
			// InsertionSort(backWardsArray, num);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end-start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			std::cout << "finished at " << std::ctime(&end_time)
			<< "elapsed time: " << elapsed_seconds.count() << "s\n";
		}
		else if(choice == 3){
			cout << "Insertion sort " << endl;
			auto start = std::chrono::system_clock::now();
			//BubbleSort_while(sortedArray, num); // replace with your sorting alorithm
			//SelectionSort(sortedArray, num);
			InsertionSort(sortedArray, num);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end-start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			std::cout << "finished at " << std::ctime(&end_time)
			<< "elapsed time: " << elapsed_seconds.count() << "s\n";
		}
		}while(choice != 4);		
  
		 for(int i = 0; i < num; i++)
		 {
		       cout << sortedArray[i] << " ";
		 }
  
 		cout << endl;

		auto start = std::chrono::system_clock::now();
		BubbleSort_while(sortedArray, num); // replace with your sorting alorithm
		// SelectionSort(sortedArray, num);
		// InsertionSort(backWardsArray, num);
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end-start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		std::cout << "finished at " << std::ctime(&end_time)
		<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	}
	else if(input == 2)					//if user chooses2, they will test the time using the backwards array.
	{
		cout << "sorteed backwards " << endl;
		cout << "input a size of array: " << endl;
		cin >> num;
		int backWardsArray[num];
		//Populating the arrays with numbers starting with the size of the array and decreasing by 1.
		for(int i = 0; i < num; i++)
		{
			backWardsArray[i] = (num - (i + 1));
		}
			
  		int choice;
		do{
		cout << "what sort would you like to test? " << endl;
		cout << " 1 for Bubble sort, 2 for Selection sort, 3 for Insertion sort, and enter to end testing. " << endl;
		cin >> choice;
			
		if(choice == 1)
		{
			cout << "Bubble sort " << endl;	
			auto start = std::chrono::system_clock::now();
			BubbleSort_while(backWardsArray, num); // replace with your sorting alorithm
			// SelectionSort(sortedArray, num);
			// InsertionSort(backWardsArray, num);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end-start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			std::cout << "finished at " << std::ctime(&end_time)
			<< "elapsed time: " << elapsed_seconds.count() << "s\n";
		}
		else if(choice == 2)
		{
			cout << "Selection sort " << endl;
			auto start = std::chrono::system_clock::now();
			//BubbleSort_while(sortedArray, num); // replace with your sorting alorithm
			SelectionSort(backWardsArray, num);
			// InsertionSort(backWardsArray, num);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end-start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			std::cout << "finished at " << std::ctime(&end_time)
			<< "elapsed time: " << elapsed_seconds.count() << "s\n";
		}
		else if(choice == 3){
			cout << "Insertion sort " << endl;
			auto start = std::chrono::system_clock::now();
			//BubbleSort_while(sortedArray, num); // replace with your sorting alorithm
			//SelectionSort(sortedArray, num);
			InsertionSort(backWardsArray, num);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end-start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			std::cout << "finished at " << std::ctime(&end_time)
			<< "elapsed time: " << elapsed_seconds.count() << "s\n";
		}
		}while(choice != 4);		


		for(int i = 0; i < num; i++)
		{
		       cout << backWardsArray[i] << " ";
		}
  
 		 cout << endl;	
	}
	else if(input == 3)
	{
		cout << "duplicate array " << endl;
		cout << "input a size of array: " << endl;
		cin >> num;
	}
	else if(input == 4)						//If user chooses 4 you can test the random arrays times with different sorting.
	{
		cout << "random arrayys " << endl;
		cout << "input a size of array: "<< endl;	
		cin >> num;
		int randArray[num];
		//Populate the array with random numbers from 1 to 100 with the size the user inputs.
		for(int i = 0; i < num; i++)
 		 {
   			 randArray[i] = rand() % 100 + 1;
 		 }
			
		int choice;
		do{
		cout << "what sort would you like to test? " << endl;
		cout << " 1 for Bubble sort, 2 for Selection sort, 3 for Insertion sort, and enter to end testing. " << endl;
		cin >> choice;
			
		if(choice == 1)
		{
			cout << "Bubble sort " << endl;	
			auto start = std::chrono::system_clock::now();
			BubbleSort_while(randArray, num); // replace with your sorting alorithm
			// SelectionSort(sortedArray, num);
			// InsertionSort(backWardsArray, num);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end-start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			std::cout << "finished at " << std::ctime(&end_time)
			<< "elapsed time: " << elapsed_seconds.count() << "s\n";
		}
		else if(choice == 2)
		{
			cout << "Selection sort " << endl;
			auto start = std::chrono::system_clock::now();
			//BubbleSort_while(sortedArray, num); // replace with your sorting alorithm
			SelectionSort(randArray, num);
			// InsertionSort(backWardsArray, num);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end-start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			std::cout << "finished at " << std::ctime(&end_time)
			<< "elapsed time: " << elapsed_seconds.count() << "s\n";
		}
		else if(choice == 3){
			cout << "Insertion sort " << endl;
			auto start = std::chrono::system_clock::now();
			//BubbleSort_while(sortedArray, num); // replace with your sorting alorithm
			//SelectionSort(sortedArray, num);
			InsertionSort(randArray, num);
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end-start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			std::cout << "finished at " << std::ctime(&end_time)
			<< "elapsed time: " << elapsed_seconds.count() << "s\n";
		}
		}while(choice != 4);		

		 for(int i = 0; i < num; i++)
		 {
		       cout << randArray[i] << " ";
		 }
		   cout << endl;
		
		auto start = std::chrono::system_clock::now();
		BubbleSort_while(randArray, num); // replace with your sorting alorithm
		// SelectionSort(randArray, num);
		// InsertionSort(randArray, num);
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end-start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		std::cout << "finished at " << std::ctime(&end_time)
		<< "elapsed time: " << elapsed_seconds.count() << "s\n";
		
	}else{
	}

	}while(input != 5);

	cout << "Thank You for testing on my program." << endl;  

  return 0;
}

