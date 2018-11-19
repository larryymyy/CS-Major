#include <locale.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// High resolution timer
// Code courtesy of: http://roxlu.com/2014/047/high-resolution-timer-function-in-c-c--
// My runs the inner procedures too quickly on smaller data sets(and I kept running out
// of memory on larger data sets), so the example of timing the execution used in class
// would keep showing zero. To combat this, I researched a method to time execution in
// nanoseconds. 
#ifdef CLOCK_MONOTONIC
#  define CLOCKID CLOCK_MONOTONIC
#else
#  define CLOCKID CLOCK_REALTIME
#endif
uint64_t ns() {
	uint64_t is_init = 0;
	struct timespec rate;
	if(is_init == 0) {
		clock_getres(CLOCKID, &rate);
		is_init = 1;
	}
	uint64_t now;
	struct timespec spec;
	clock_gettime(CLOCKID, &spec);
	now = spec.tv_sec * 1.0e9 + spec.tv_nsec;
	return now;
}




// Inner procedure (provided by assignment)
void inner(float * u, float * v, int length, float * dest) {
	int i;
	float sum = 0.0f;
	for(i = 0; i < length; ++i) {
		sum += u[i] * v[i];
	}
	*dest = sum;
}




// Inner2 procedure
void inner2(float * u, float * v, int length, float * dest) {
	int i;
	float sum = 0.0f;
	for(i = 0; i < length; i += 4) {
		float a = u[i] * v[i];
		float b = u[i + 1] * v[i + 1];
		float c = u[i + 2] * v[i + 2];
		float d = u[i + 3] * v[i + 3];
		sum = (((sum + a) + b) + c) + d;
	}
	for(; i < length; ++i) {
		sum += u[i] * v[i];
	}
	*dest = sum;
}



// Formats a timespan (given in nanoseconds) into a more readable format
void format_time(uint64_t span, char * dest) {
	if(span >= 1e9) { // Timespan >= 1 second
		sprintf(dest, "%.3f sec", (double)span / 1e9);
	}
	else if(span >= 1e6) { // Timespan >= 1 millisecond
		sprintf(dest, "%.3f ms", (double)span / 1e6);
	}
	else if(span >= 1e3) { // Timespan >= 1 microsecond
		sprintf(dest, "%.3f \u03BCs", (double)span / 1e3);
	}
	else { // Timespan < 1 microsecond => no formatting needed
		sprintf(dest, "%lu ns", span);
	}
}



// Main procedure
int main() {

	// Make big numbers readable
	setlocale(LC_NUMERIC, "");

	for(int j = 10; j <= 1000000000; j *= 10) {
		int array_size = j; // Size of the arrays to be processed

		// Report the size of the dataset being evaluated
		printf("N: %'d\n", array_size);

		// Make some space for the arrays
		float * u = malloc(array_size * sizeof(float));
		float * v = malloc(array_size * sizeof(float));

		// Variables to store the result of each inner procedure (to ensure each proc generates the same value)
		float inner_result = 0.0f, inner2_result = 0.0f;

		// Fill the arrays
		for(int i = 0; i < array_size; i++) {
			u[i] = v[i] = (float)i + 1.0;
		}

		// Variables to hold the start and end timestamps
		uint64_t inner_start, inner_end, inner2_start, inner2_end;

		// Time the given code
		inner_start = ns();
		inner(u, v, array_size, &inner_result);
		inner_end = ns();

		// Time the optimized code
		inner2_start = ns();
		inner2(u, v, array_size, &inner2_result);
		inner2_end = ns();

		// Strings that will hold the formated timespans of each loop
		char inner_time[32], inner2_time[32]; // 32 to ensure sufficiently large enough

		// Format the timespans into respective strings
		format_time(inner_end - inner_start, inner_time);
		format_time(inner2_end - inner2_start, inner2_time);

		// Report the timespans of each procedure
		printf("inner:  %s (result = %'f)\n", inner_time, inner_result);
		printf("inner2: %s (result = %'f)\n\n", inner2_time, inner2_result);
		fflush(stdout);

		// Free the space allocated for the arrays
		free(u);
		free(v);
	}
	return 0;
}
