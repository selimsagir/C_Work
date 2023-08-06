#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

float pi;

void printSignal(float *arr, size_t size){
        // Print the generated input signal values
    for (size_t i = 0; i < size; i++)
    {   // print signal
         printf("%f\n", arr[i]);
    }
}


void dft(float in[], float complex out[], size_t n){

    for (size_t f = 0; f < n; f++){
        out[f] = 0;
        for (size_t i = 0; i < n; i++){
            float t = (float)i/n;
            out[f] += in[i]*cexp(2*I*pi*f*t);
        }
        
    }
}

void fft(float in[], size_t stride, float complex out[], size_t n){

    if(n == 1){
        out[0] = in[0];
        return;
    } 

    fft(in,           stride*2, out,       n/2); 
    fft(in + stride , stride*2, out + n/2, n/2);

    for (size_t k = 0; k < n/2; ++k)
    {
        float t = (float)k/n;
        float complex v = cexp(-2*I*pi*t)*out[k + n/2];
        float complex e = out[k];
        out[k] = e + v;
        out[k + n/2] = e - v;
    }
    

}

int main()
{
    // Calculate the value of pi and store it in the global variable 'pi'
    pi = atan2f(1, 1) * 4;
    // Note: 'atan2f(1, 1)' calculates the arctangent of 1/1, which is equivalent to pi/4.
    // Multiplying by 4 gives the value of pi and stores it in 'pi' for later use.

    // Set the number of samples 'n' to 8
    size_t n = 64*4  ;

    // Declare two arrays to hold the input and output signals, both of size 'n'
    float in[n];
    float complex out[n];

    // Create signal
    for (size_t i = 0; i < n; i++)
    {
        // Calculate the time value 't' for the current sample
        float t = (float)i / n;
        // Generate a complex waveform by summing two sine waves of different frequencies:
        in[i] = cosf(2 * pi * t * 1) + sinf(2 * pi * t * 2);
        // The first sine wave has a frequency of 1 Hz, and the second has a frequency of 3 Hz.
    }

    // dft(in, out, n);
    fft(in,1, out, n);
    
    // Print the FFT results for each frequency bin
    for (size_t f = 0; f < n; f++)
    {
        printf("%02zu: %.2f, %.2fi\n", f, creal(out[f]), cimag(out[f]));
    }

    return 0;
}
