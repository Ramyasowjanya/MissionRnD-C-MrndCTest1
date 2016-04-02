/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int * find_sequences(int *arr, int len) {
	int arth[4];
	//int return_arr[6];
	int geo[2], index = 0, aindex = 0, gindex = 0, temp;
	if (arr != NULL)
	{
		while (index != len)
		{
			if (aindex<4 && arr[index + 1] - arr[index] == arr[index + 2] - arr[index + 1])
			{
				arth[aindex++] = index;
				temp = index;
				while (arr[temp + 1] - arr[temp] == arr[temp + 2] - arr[temp + 1])
				{
					temp++;
				}
				arth[aindex++] = temp + 1;
				index = temp;
			}
			else if (gindex<2 && (arr[index + 1] / arr[index]) != 1 && arr[index + 1] / arr[index] == arr[index + 2] / arr[index + 1])
			{
				geo[gindex++] = index;
				temp = index;
				while (arr[temp + 1] / arr[temp] == arr[temp + 2] / arr[temp + 1])
				{
					temp++;
				}
				geo[gindex++] = temp + 1;
				index = temp;
			}
			else
				index++;
		}index = 0;
		for (int i = 0; i < 4; i++)
		{
			arr[index++] = arth[i];
		}
		for (int i = 0; i < 2; i++)
		{
			arr[index++] = geo[i];
		}
		return arr;
	}
	return NULL;
}