#include <time.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

bool data_sorted(int data[], int count)
{
	// Put specified count of random numbers into data array
	for (int index = 1; index < count; index++)
		if (data[index - 1] > data[index])
			return false;
	return true;
}

void create_random_data(int data[], int count, int range)
{
	// Put random data values into array
	for (int index = 0; index < count; index++)
		data[index] = rand() % range;
}

void create_mostly_sorted_data(int data[], int count, int swaps)
{
	// Put sorted data values into array
	for (int index = 0; index < count; index++)
		data[index] = index;

	// Shuffle data by swapping random pairs of values
	for (int index = 0; index < swaps; index++)
	{
		int pos1 = rand() % count;
		int pos2 = rand() % count;
		int temp = data[pos1];
		data[pos1] = data[pos2];
		data[pos2] = temp;
	}
}

void bubble_sort(int data[], int low, int high)
{
	// Bubble largest value to the right N times
	int pass = 1;
	int exchange = 1;
	int count = high - low + 1;
	while ((pass < count) && (exchange > 0))
	{
		// Scan unsorted part of data array
		exchange = 0;
		for (int index = low; index <= high - pass; index++)
		{
			// Swap two data values if out of order
			if (data[index] > data[index + 1])
			{
				int temp = data[index];
				data[index] = data[index + 1];
				data[index + 1] = temp;
				exchange++;
			}
		}
		pass++;
	}
}

void corn_sort(int data[], int low, int high)
{
	int pass = 1;
	int exchange = 1;
	int count = high - low + 1;
	while ((pass < count) && (exchange > 0))
	{
		exchange = 0;
		if (pass % 2 == 1)
		{
			for (int index = low; index <= high - pass; index++)
			{
				if (data[index] > data[index + 1])
				{
					int temp = data[index];
					data[index] = data[index + 1];
					data[index + 1] = temp;
					exchange++;
				}
			}
		}
		else if (pass % 2 == 0)
		{
			for (int index = high; index >= low + pass; index--)
			{
				if (data[index] < data[index - 1])
				{
					int temp = data[index];
					data[index] = data[index - 1];
					data[index - 1] = temp;
					exchange++;
				}
			}
		}
		pass++;
	}
}

void selection_sort(int data[], int low, int high)
{
	// Put largest unsorted value at end of sorted list
	for (int last = high; last > low; last--)
	{
		// Find index of largest value in unsorted array
		int largest = low;
		for (int index = low + 1; index <= last; index++)
			if (data[index] > data[largest])
				largest = index;

		// Swap with last element in unsorted array
		int temp = data[last];
		data[last] = data[largest];
		data[largest] = temp;
	}
}

void highlow_sort(int data[], int low, int high)
{
	for (int last = high; last > low; last--)
	{
		int first = low;
		int largest = low;
		for (int index = low + 1; index <= last; index++)
			if (data[index] > data[largest])
				largest = index;

		int smallest = low;
		for (int index = low + 1; index <= last; index++)
			if (data[index] < data[smallest])
				smallest = index;

		int temp = data[last];
		data[last] = data[largest];
		data[largest] = temp;

		int temp2 = data[first];
		data[first] = data[smallest];
		data[smallest] = temp2;
		first++;
	}
}

int main()
{

		ifstream din;
		ofstream dout;
		int sort = 0;
		int range = 0;
		int reading = 0;
		int size = 0;
		int count = 1;
		string filename = "0";
		string outputname;
		cout << "Please enter the size of your data." << endl;
		cin >> size;
		int data[10001];
		cout << "Please enter the name of the file that contains your data." << endl;
		cin >> filename;
		cin.ignore();
		din.open(filename);
		outputname = "Output.txt";
		cout << outputname << endl;
		dout.open(outputname);
		if (din.fail() == 0)
		{
			while (din >> data[count])
			{
				count++;
			}
		}
		cout << "Please select how you would like your data to be sorted." << endl;
		cout << "Selection -> 1" << endl;
		cout << "Bubble -> 2" << endl;
		cout << "High Low -> 3" << endl;
		cout << "Corn -> 4" << endl;
		cin >> sort;
		while (sort <= 0 && sort > 4)
		{
			sort = 0;
			cout << "Please enter a valid selection." << endl;
		}
		cout << "Please select the range of your data." << endl;
		cin >> range;
		while (range <= 0 && range > 100000)
		{
			range = 0;
			cout << "Please enter a valid range." << endl;
		}
		if (sort == 1)
		{
			time_t StartTime = time(NULL);
			selection_sort(data, 0, range);
			time_t EndTime = time(NULL);
			time_t TotalTime = EndTime - StartTime;
			for (int i = 0; i < count; i++)
			{
				dout << data[i] << endl;
			}
			cout << "Your sorted data has been placed into Output.txt." << endl;
			cout << "This method took " << TotalTime << " seconds." << endl;
		}
		else if (sort == 2)
		{
			time_t StartTime = time(NULL);
			bubble_sort(data, 0, range);
			time_t EndTime = time(NULL);
			time_t TotalTime = EndTime - StartTime;
			for (int i = 0; i < count; i++)
			{
				dout << data[i] << endl;
			}
			cout << "Your sorted data has been placed into Output.txt." << endl;
			cout << "This method took " << TotalTime << " seconds." << endl;
		}
		else if (sort == 3)
		{
			time_t StartTime = time(NULL);
			highlow_sort(data, 0, range);
			time_t EndTime = time(NULL);
			time_t TotalTime = EndTime - StartTime;
			for (int i = 0; i < count; i++)
			{
				dout << data[i] << endl;
			}
			cout << "Your sorted data has been placed into Output.txt." << endl;
			cout << "This method took " << TotalTime << " seconds." << endl;
		}
		else if (sort == 4)
		{
			time_t StartTime = time(NULL);
			corn_sort(data, 0, range);
			time_t EndTime = time(NULL);
			time_t TotalTime = EndTime - StartTime;
			for (int i = 0; i < count; i++)
			{
				dout << data[i] << endl;
			}
			cout << "Your sorted data has been placed into Output.txt." << endl;
			cout << "This method took " << TotalTime << " seconds." << endl;
		}
		din.close();
		dout.close();
		return 0;

}
