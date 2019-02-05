// FastFourierTransform.cpp : Defines the entry point for the console application.
//

// FFT.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14
#define length_of_signal 1024

double sum[2* length_of_signal];

double * fft(double *a, int N, int length_FFT)
{
	int k, h; 
	double e[length_of_signal/2], o[length_of_signal/2];
	double *x1, *x2; double result[2* length_of_signal], x1_real[length_of_signal], x1_imag[length_of_signal], x2_real[length_of_signal], x2_imag[length_of_signal];
	if (N == 2)
	{
		k = 0;
		for (int j = 0; j < 2 * length_FFT; j = j + 2)
		{
			sum[j] = ((*a)) + ((*(a + 1)) * cos(2 * pi * k / N)); // Real Part
			sum[j + 1] = -((*(a + 1)) * sin(2 * pi * k / N)); // Imaginary Part
			k++;
		}
		return(&sum[0]);
	}


	for (int i = 0; i < N / 2; i++)
	{
		e[i] = *(a + 2 * i);  
	}

	for (int i = 0; i < N / 2; i++)
	{
		o[i] = *(a + (2 * i + 1));
	}

	x1 = fft(&e[0], N / 2, length_FFT);
	k = 0;

	for (int j = 0; j < 2 * length_FFT; j = j + 2)
	{
		x1_real[k] = *(x1 + j); x1_imag[k] = *(x1 + 1 + j); k++;
	}

	x2 = fft(&o[0], N / 2, length_FFT);
	k = 0; h = 0;
	for (int j = 0; j < 2 * length_FFT; j = j + 2)
	{
		x2_real[k] = cos(2 * pi * k / N)* (*(x2 + j)) + sin(2 * pi * k / N) * (*(x2 + 1 + j));
		x2_imag[k] = cos(2 * pi * k / N)* (*(x2 + j + 1)) - sin(2 * pi * k / N) * (*(x2 + j));

		x2_real[k] = x1_real[k] + x2_real[k];
		x2_imag[k] = x1_imag[k] + x2_imag[k];

		result[h] = x2_real[k]; // Real part of the result
		result[h + 1] = x2_imag[k]; // Imaginary part of the result
		k++; h = h + 2;
	}
	return(&result[0]);
}

int main()
{
	double a[length_of_signal], res[2* length_of_signal], mag[length_of_signal];
	double *result; 
	int i, k, f, fs;
	int  length_FFT, N;
	FILE *fp;
	N = length_of_signal;
	f = 1000; fs = 3000;
	length_FFT = 1024;
	for (i = 0; i < N; i++)
	{
		a[i] = sin(2 * pi*f / fs * i);
	}
	result = fft(&a[0], N, length_FFT);

	fopen_s(&fp, "Result.csv", "w");

	k = 0;
	for (i = 0; i < 2 * length_FFT; i = i + 2)
	{
		mag[k] = pow(*(result + i), 2) + pow(*(result + i + 1), 2);
		fprintf(fp, "%lf\n", mag[k]);
		k++;
	}
	fclose(fp);
	printf("The result (Magnitude) of fft is saved in Result.CSV file");
	getchar();
	return 0;
}
