#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>


using namespace std;




int main()
{
	const int SIZE = 20;
	char input1[SIZE];
	char input2[SIZE];
	char input3[SIZE];
	char output1[SIZE];

	ifstream in_stream1;
	ifstream in_stream2;
	ifstream in_stream3;
	ofstream out_stream;

// Open file1.txt and display
	in_stream1.open("file1.txt");
	if (in_stream1.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	in_stream1.getline(input1, SIZE);
	cout << "The contents of file1: " << input1 << endl;

	out_stream.open("file3.txt", ios::out);
	out_stream << input1 <<"";
	out_stream.close();

	

// Open file2.txt and display
	in_stream2.open("file2.txt");
	if (in_stream2.fail())
	{
		cout << "Input file opening failed. \n";
		exit(1);
	}
	in_stream2.getline(input2, SIZE);
	cout << "The contents of file2: " << input2 << endl;

	out_stream.open("file3.txt", ios::app);
	out_stream << input2;
	out_stream.close();

	
	

	
	in_stream3.open("file3.txt");
	in_stream3.getline(input3, SIZE);
	cout << "The contents of file3: " << input3 << endl;
	
	in_stream1.close();
	in_stream2.close();
	in_stream3.close();
	out_stream.close();
	
}