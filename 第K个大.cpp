#include<iostream>
#include<vector>
using namespace std;

int findkth(vector<int>::iterator A, vector<int>::iterator B, int a_num,int b_num, int k)
{
	int k1 = min(k / 2,a_num);
	int k2 = k - k1;
	if (a_num > b_num) return findkth(B, A,b_num,a_num, k);
	//if (a_num + b_num < k) return -1;
	if (a_num == 0) return *(B + k - 1);
	if (k == 1) return min(*A, *B);

	if (*(A+k1-1) == *(B+k2-1)) 
	{
		return *(A+k1-1);
	}
	else if (*(A + k1-1) > * (B + k2-1))
	{
		return findkth(A, B + k2, a_num, b_num - k2,k- k2);
	}
	else if (*(A + k1-1) < *(B + k2-1))
	{
		return findkth(A + k1, B, a_num-k1, b_num, k-k1);
	}
}



int main()
{
	vector<int> A = { 1,1,1,2,2,4,5,6,7 };
	vector<int> B = { 4,5,6,7,8,9,10,11 };
    int a[9]= { 1,1,1,2,2,4,5,6,7 };
    int b[7]= { 4,5,6,7,8,9,10 };
	cout << findkth(A.begin(),B.begin(),9,8, 2);
    //cout << Binary_find_Kth(a, 9, b, 7, 16);
}


