#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

float pi;

int main()
{
    // Calculate the value of pi and store it in the global variable 'pi'
    pi = atan2f(1, 1) * 4;
    // Note: 'atan2f(1, 1)' calculates the arctangent of 1/1, which is equivalent to pi/4.
    // Multiplying by 4 gives the value of pi and stores it in 'pi' for later use.

    // Set the number of samples 'n' to 8
    size_t n = 8;

    // Declare two arrays to hold the input and output signals, both of size 'n'
    float in[n];
    float complex out[n];

    // Create signal
    for (size_t i = 0; i < n; i++)
    {
        // Calculate the time value 't' for the current sample
        float t = (float)i / n;
        // Generate a complex waveform by summing two sine waves of different frequencies:
        in[i] = sinf(2 * pi * t * 1) + sinf(2 * pi * t * 3);
        // The first sine wave has a frequency of 1 Hz, and the second has a frequency of 3 Hz.
    }

    // Print the generated input signal values
    for (size_t i = 0; i < n; i++)
    {   // print signal
        // printf("%f\n", in[i]);
    }

    // Perform the FFT algorithm to transform the input signal to the frequency domain
    for (size_t f = 0; f < n; f++)
    {
        // Initialize the output frequency bin 'out[f]' to 0
        out[f] = 0;

        // Loop over all input samples to compute the FFT output at frequency bin 'f'
        for (size_t i = 0; i < n; i++)
        {
            // Calculate the time value 't' for the current input sample
            float t = (float)i / n;
            // Compute the contribution of the current input sample to the output bin 'out[f]'
            // out[f] += in[i] * sinf(2 * pi * f * t);
            out[f] += in[i]*cexp(2*I*pi*f*t);
            // The multiplication of 'in[i]' with 'sinf(2*pi*f*t)' represents the complex exponential term in the FFT formula.
        }
    }

    // Print the FFT results for each frequency bin
    for (size_t f = 0; f < n; f++)
    {
        printf("%02zu: %.2f, %.2f\n", f, creal(out[f]), cimag(out[f]));
    }

    return 0;
}
