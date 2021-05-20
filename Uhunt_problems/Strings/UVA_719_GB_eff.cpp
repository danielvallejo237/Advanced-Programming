#include<bits/stdc++.h>


using namespace std;


#define CIRCULAR_SORTING false
#define ii pair<int, int>

const int MAXINT = 10010;
char T[MAXINT];
int N;
int SA[MAXINT], tempSA[MAXINT];
int RA[MAXINT], tempRA[MAXINT];

int c[MAXINT];
void radixSort(int k) {
	int i, maxi = max(300, N);
	memset(c, 0, sizeof c);
	for (i = 0; i < N; ++i) {
		int index = RA[(i + k) % N];
		c[index]++;
	}
	int sum = 0;
	for (i = 0; i < maxi; ++i) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for (i = 0; i < N; ++i) {
		int indexToRA = (SA[i] + k) % N;
		int indexToC = indexToRA < N ? RA[indexToRA] : 0;
		int indexToTempSA = c[indexToC]++;
		tempSA[indexToTempSA] = SA[i];
	}
	for (i = 0; i < N; ++i)
		SA[i] = tempSA[i];
}

void constructSA() {
	int i;
	for (i = 0; i < N; ++i)
		RA[i] = T[i];
	for (i = 0; i < N; ++i)
		SA[i] = i;
	for (int k = 1; k < N; k <<= 1) {
		radixSort(k); 
		radixSort(0); 
		int r = 0; 
		tempRA[SA[0]] = r;
		for (i = 1; i < N; ++i) {
			tempRA[SA[i]] =
				(RA[SA[i]] == RA[SA[i - 1]] && RA[(SA[i] +k) % N] == RA[(SA[i - 1] + k) % N]) ? r : ++r;
		}
		for (i = 0; i < N; ++i)
			RA[i] = tempRA[i];
		if (RA[SA[N - 1]] == N - 1)
			break; 
	}
}

int main() {
	int NumT;
	cin >> NumT;
	while (NumT--) {
		scanf("%s", T);
		N = strlen(T);
		constructSA();
		
		printf("%d\n", SA[0] + 1);
	}
}