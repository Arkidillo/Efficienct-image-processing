/********************************************************
 * Kernels to be optimized for the  Performance Project
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include <sys/time.h>
#include <sys/resource.h>

/* Below are statements to set up the performance measurement utilities */
/* we use rdtsc, clock, and getusage utilities to measure performance */

//#define rdtscll(val) __asm__ __volatile__("rdtsc" : "=A" (val))
#if defined(__i386__)

static __inline__ unsigned long long rdtsc(void)
{
  unsigned long long int x;
     __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
     return x;
}
#elif defined(__x86_64__)


static __inline__ unsigned long long rdtsc(void)
{
  unsigned hi, lo;
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}
#endif

/* end of definitions to set up measurement utilities */


/*
 * Please fill in the following team struct
 */
team_t team = {
    "G27845468",         /* Team Name */

    "Devin J. Kopp",     /* First member full name */
    "devinkopp@gwu.edu",  /* First member email address */


    "",                   /* Second member full name (leave blank if none) */
    ""                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* the getUserTime function is used for measurement, you should not change the code for this function */

long int getUserTime()
{
	int who= RUSAGE_SELF;
	int ret;
	struct rusage usage;
	struct rusage *p=&usage;
	//long int current_time;

	ret=getrusage(who,p);
	if(ret == -1)
	{
		printf("Could not get GETRUSAGE to work in function %s at line %d in file %s\n",
				__PRETTY_FUNCTION__, __LINE__, __FILE__);
		exit(1);
	}
	return (p->ru_utime.tv_sec * 1000000 + p->ru_utime.tv_usec);
}

/*
 * naive_rotate - The naive baseline version of rotate
 */
 /* The parameters, pointers, rusage_time, rdtsc_time, and cpu_time_used are used to measure performance and return values to caller. */
 /* You should not change the code that uses these parameters and variables. */

char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst, int *rusage_time, unsigned long long *rdtsc_time)
{
	int i, j;
	/* the variables below are used for performance measurement and not for computing the results of the algorithm */
	long int rusage_start_time, rusage_end_time = 0;
	unsigned long long rdtsc_start_time, rdtsc_end_time = 0;
	/* call system functions to start measuring performance. you should not bother to change these. */

	rusage_start_time = getUserTime();
	rdtsc_start_time = rdtsc();

/* below is the main computations for the rotate function */

	for (j = 0; j < dim; j++)
		for (i = 0; i < dim; i++)
			dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];

/* the remaining lines in this function stop the measurement and set the values before returning. */

	rusage_end_time = getUserTime();
	rdtsc_end_time = rdtsc();

	*rusage_time = rusage_end_time - rusage_start_time;
	*rdtsc_time = rdtsc_end_time - rdtsc_start_time;
}

 /* The parameters, pointers, rusage_time, rdtsc_time, and cpu_time_used are used to measure performance and return values to caller. */
 /* You should not change the code that uses these parameters and variables. */
char my_rotate_descr[] = "my_rotate: Naive baseline implementation";
void my_rotate(int dim, pixel *src, pixel *dst, int *rusage_time, unsigned long long *rdtsc_time)
{
	int i, j;
		/* the variables below are used for performance measurement and not for computing the results of the algorithm */
	long int rusage_start_time, rusage_end_time = 0;
        unsigned long long rdtsc_start_time, rdtsc_end_time = 0;
	/* call system functions to start measuring performance. you should not bother to change these. */
        rusage_start_time = getUserTime();
	rdtsc_start_time = rdtsc();

/* ANY CHANGES ARE MADE HERE */
/* below are the main computations for your implementation of the rotate. Any changes in implementation will go here or the other functions it may call */
int b, z;
int dim2 = dim << 1;
int dim3 = dim*3;
int dim4 = dim << 2;
int dim5 = dim*5;
int dim6 = dim3 << 1;
int dim7 = dim*7;
int dim8 = dim << 3;
int dim9 = dim3*3;
int dim10 = dim5 << 1;
int dim11 = dim*11;
int dim12 = dim3 << 2;
int dim13 = dim*13;
int dim14 = dim7 << 1;
int dim15 = dim5*3;
int dim16 = dim << 4;
int dim17 = dim*17;
int dim18 = dim9 << 1;
int dim19 = dim*19;
int dim20 = dim10 << 1;
int dim21 = dim7*3;
int dim22 = dim11 << 1;
int dim23 = dim*23;
int dim24 = dim3 << 3;
int dim25 = dim5*5;
int dim26 = dim13 << 1;
int dim27 = dim9*3;
int dim28 = dim14 << 1;
int dim29 = dim*29;
int dim30 = dim15 << 1;
int dim31 = dim*31;
int dim32 = dim16 << 1;
int y = dim*(dim-1);
int x = 0;
for (i = 0; i < dim; i += 32){
    //x = i*dim;
    z = y + i;

    for(j = 0; j < dim; j += 32){
      b = x + j;
{
      dst[z] = src[b];//1

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      //dst[z-dim] = src[b+1];
      dst[z] = src[b];//2

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//3

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//4

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//5

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//6

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];


      z -= dim;
      b++;

      dst[z] = src[b];//7

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];


      z -= dim;
      b++;

      dst[z] = src[b];//8

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];


      z -= dim;
      b++;

      dst[z] = src[b];//9

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];


      z -= dim;
      b++;

      dst[z] = src[b];//10

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];


      z -= dim;
      b++;

      dst[z] = src[b];//11

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//11

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//12

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];


      z -= dim;
      b++;

      dst[z] = src[b];//13

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//14

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//15

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//16

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//17

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//18

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//19

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//20

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//21

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//22

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//23

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//24

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//25

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//26

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//27

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//28

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//29

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//30

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
      b++;

      dst[z] = src[b];//31

      dst[z+1] = src[b+dim];
      dst[z+2] = src[b+dim2];
      dst[z+3] = src[b+dim3];
      dst[z+4] = src[b+dim4];
      dst[z+5] = src[b+dim5];
      dst[z+6] = src[b+dim6];
      dst[z+7] = src[b+dim7];
      dst[z+8] = src[b+dim8];
      dst[z+9] = src[b+dim9];
      dst[z+10] = src[b+dim10];
      dst[z+11] = src[b+dim11];
      dst[z+12] = src[b+dim12];
      dst[z+13] = src[b+dim13];
      dst[z+14] = src[b+dim14];
      dst[z+15] = src[b+dim15];
      dst[z+16] = src[b+dim16];
      dst[z+17] = src[b+dim17];
      dst[z+18] = src[b+dim18];
      dst[z+19] = src[b+dim19];
      dst[z+20] = src[b+dim20];
      dst[z+21] = src[b+dim21];
      dst[z+22] = src[b+dim22];
      dst[z+23] = src[b+dim23];
      dst[z+24] = src[b+dim24];
      dst[z+25] = src[b+dim25];
      dst[z+26] = src[b+dim26];
      dst[z+27] = src[b+dim27];
      dst[z+28] = src[b+dim28];
      dst[z+29] = src[b+dim29];
      dst[z+30] = src[b+dim30];
      dst[z+31] = src[b+dim31];

      z -= dim;
}

    }
    x += dim32;
  }
/* end of computation for rotate function. any changes you make should be made above this line. */
/* END OF CHANGES in this function */

/* the remaining lines in this function stop the measurement and set the values before returning. */
	rusage_end_time = getUserTime();
        rdtsc_end_time = rdtsc();

	*rusage_time = rusage_end_time - rusage_start_time;
	*rdtsc_time = rdtsc_end_time - rdtsc_start_time;
}



/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
	int red;
	int green;
	int blue;
	int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int minimum(int a, int b)
{ return (a < b ? a : b); }
static int maximum(int a, int b)
{ return (a > b ? a : b); }

/*
 * initialize_pixel_sum - Initializes all fields of sum to 0
 */
static void initialize_pixel_sum(pixel_sum *sum)
{
	sum->red = sum->green = sum->blue = 0;
	sum->num = 0;
	return;
}

/*
 * accumulate_sum - Accumulates field values of p in corresponding
 * fields of sum
 */
static void accumulate_sum(pixel_sum *sum, pixel p)
{
	sum->red += (int) p.red;
	sum->green += (int) p.green;
	sum->blue += (int) p.blue;
	sum->num++;
	return;
}

/*
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum)
{
	current_pixel->red = (unsigned short) (sum.red/sum.num);
	current_pixel->green = (unsigned short) (sum.green/sum.num);
	current_pixel->blue = (unsigned short) (sum.blue/sum.num);
	return;
}

/*
 * avg - Returns averaged pixel value at (i,j)
 */
static pixel avg(int dim, int i, int j, pixel *src)//Have a function that takes the average of 9 squares, subtracts the left 3 off, and adds the next right 3.
{
	int ii, jj, c;
	pixel_sum sum;
	pixel current_pixel;

	initialize_pixel_sum(&sum);
	for(ii = maximum(i - 1, 0); ii <= minimum(i + 1, dim - 1); ii++){
    c = ii * dim;
    //src[ii * dim + jj]
		for(jj = maximum(j - 1, 0); jj <= minimum(j + 1, dim - 1); jj++){
			accumulate_sum(&sum, src[c + jj]);
    }
  }
	assign_sum_to_pixel(&current_pixel, sum);
	return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth
 */
  /* The parameters, pointers, rusage_time, rdtsc_time, and cpu_time_used are used to measure performance and return values to caller. */
 /* You should not change the code that uses these parameters and variables. */

char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst, int *rusage_time, unsigned long long *rdtsc_time)
{
	int i, j;

	/* the variables below are used for performance measurement and not for computing the results of the algorithm */
	long int rusage_start_time, rusage_end_time = 0;
        unsigned long long rdtsc_start_time, rdtsc_end_time = 0;

	/* call system functions to start measuring performance. you should not bother to change these. */
        rusage_start_time = getUserTime();
	rdtsc_start_time = rdtsc();

/* below are the main computations for the smooth function */
	for (j = 0; j < dim; j++)
		for (i = 0; i < dim; i++)
			dst[RIDX(i, j, dim)] = avg(dim, i, j, src);

/* the remaining lines in this function stop the measurement and set the values before returning. */
	rusage_end_time = getUserTime();
        rdtsc_end_time = rdtsc();

	*rusage_time = rusage_end_time - rusage_start_time;
	*rdtsc_time = rdtsc_end_time - rdtsc_start_time;
}

 /* The parameters, pointers, rusage_time, rdtsc_time, and cpu_time_used are used to measure performance and return values to caller. */
 /* You should not change the code that uses these parameters and variables. */

char my_smooth_descr[] = "my_smooth: Naive baseline implementation";
void my_smooth(int dim, pixel *src, pixel *dst, int *rusage_time, unsigned long long *rdtsc_time)
{
	int i, j;

	/* the variables below are used for performance measurement and not for computing the results of the algorithm */
	long int rusage_start_time, rusage_end_time = 0;
        unsigned long long rdtsc_start_time, rdtsc_end_time = 0;
	/* call system functions to start measuring performance. you should not bother to change these. */
        rusage_start_time = getUserTime();
	rdtsc_start_time = rdtsc();

/* ANY CHANGES TO BE MADE SHOULD BE BELOW HERE */
/* below are the main computations for your implementation of the smooth function. Any changes in implementation will go here or the other functiosn it calls */
int c, d, k, x, y;
int ii, jj, c2;
pixel_sum sum;
pixel current_pixel;
c = 0;
d = 0;
k = dim-1;

	for (i = 0; i < dim; i++){
    c = i * dim;
    x = minimum(k, i + 1);
    y = (maximum(i - 1, 0));
		for (j = 0; j < dim; j += 32){
      d = c + j;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){//max(i-1,0), stop from going over the top. x, stop from going below the bottom
        c2 = ii * dim;
        //src[ii * dim + jj]
    		for(jj = maximum(j - 1 , 0); jj <= j + 1; jj++){//max(j-1, 0), stop from going too left. min (j+1, k) stops from going too far right.
    			accumulate_sum(&sum, src[c2 + jj]);
        }
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d] = current_pixel;

      /*initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){//max(i-1,0), stop from going over the top. x, stop from going below the bottom
        c2 = ii * dim;
        //src[ii * dim + jj]
    		for(jj = j; jj <= minimum(j + 2, k); jj++){//max(j-1, 0), stop from going too left. min (j+1, k) stops from going too far right.
    			accumulate_sum(&sum, src[c2 + jj]);
        }
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 1] = current_pixel;
*/
      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
        accumulate_sum(&sum, src[c2]);
        accumulate_sum(&sum, src[c2 + 1]);
        accumulate_sum(&sum, src[c2 + 2]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 1] = current_pixel;



      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
        accumulate_sum(&sum, src[c2 + 1]);
        accumulate_sum(&sum, src[c2 + 2]);
        accumulate_sum(&sum, src[c2 + 3]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 2] = current_pixel;


      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
        accumulate_sum(&sum, src[c2 + 2]);
        accumulate_sum(&sum, src[c2 + 3]);
        accumulate_sum(&sum, src[c2 + 4]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 3] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
        accumulate_sum(&sum, src[c2 + 3]);
        accumulate_sum(&sum, src[c2 + 4]);
        accumulate_sum(&sum, src[c2 + 5]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 4] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
        accumulate_sum(&sum, src[c2 + 4]);
        accumulate_sum(&sum, src[c2 + 5]);
        accumulate_sum(&sum, src[c2 + 6]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 5] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
        accumulate_sum(&sum, src[c2 + 5]);
        accumulate_sum(&sum, src[c2 + 6]);
        accumulate_sum(&sum, src[c2 + 7]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 6] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
        accumulate_sum(&sum, src[c2 + 6]);
        accumulate_sum(&sum, src[c2 + 7]);
        accumulate_sum(&sum, src[c2 + 8]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 7] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
        accumulate_sum(&sum, src[c2 + 7]);
        accumulate_sum(&sum, src[c2 + 8]);
        accumulate_sum(&sum, src[c2 + 9]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 8] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
        accumulate_sum(&sum, src[c2 + 8]);
        accumulate_sum(&sum, src[c2 + 9]);
        accumulate_sum(&sum, src[c2 + 10]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 9] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
        accumulate_sum(&sum, src[c2 + 9]);
        accumulate_sum(&sum, src[c2 + 10]);
        accumulate_sum(&sum, src[c2 + 11]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 10] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
        accumulate_sum(&sum, src[c2 + 10]);
        accumulate_sum(&sum, src[c2 + 11]);
        accumulate_sum(&sum, src[c2 + 12]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 11] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
        accumulate_sum(&sum, src[c2 + 11]);
        accumulate_sum(&sum, src[c2 + 12]);
        accumulate_sum(&sum, src[c2 + 13]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 12] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
        accumulate_sum(&sum, src[c2 + 12]);
        accumulate_sum(&sum, src[c2 + 13]);
        accumulate_sum(&sum, src[c2 + 14]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 13] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 13]);
        accumulate_sum(&sum, src[c2 + 14]);
        accumulate_sum(&sum, src[c2 + 15]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 14] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 14]);
        accumulate_sum(&sum, src[c2 + 15]);
        accumulate_sum(&sum, src[c2 + 16]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 15] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 15]);
        accumulate_sum(&sum, src[c2 + 16]);
        accumulate_sum(&sum, src[c2 + 17]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 16] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 16]);
        accumulate_sum(&sum, src[c2 + 17]);
        accumulate_sum(&sum, src[c2 + 18]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 17] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 17]);
        accumulate_sum(&sum, src[c2 + 18]);
        accumulate_sum(&sum, src[c2 + 19]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 18] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 18]);
        accumulate_sum(&sum, src[c2 + 19]);
        accumulate_sum(&sum, src[c2 + 20]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 19] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 19]);
        accumulate_sum(&sum, src[c2 + 20]);
        accumulate_sum(&sum, src[c2 + 21]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 20] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 20]);
        accumulate_sum(&sum, src[c2 + 21]);
        accumulate_sum(&sum, src[c2 + 22]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 21] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 21]);
        accumulate_sum(&sum, src[c2 + 22]);
        accumulate_sum(&sum, src[c2 + 23]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 22] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 22]);
        accumulate_sum(&sum, src[c2 + 23]);
        accumulate_sum(&sum, src[c2 + 24]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 23] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 23]);
        accumulate_sum(&sum, src[c2 + 24]);
        accumulate_sum(&sum, src[c2 + 25]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 24] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 24]);
        accumulate_sum(&sum, src[c2 + 25]);
        accumulate_sum(&sum, src[c2 + 26]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 25] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 25]);
        accumulate_sum(&sum, src[c2 + 26]);
        accumulate_sum(&sum, src[c2 + 27]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 26] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 26]);
        accumulate_sum(&sum, src[c2 + 27]);
        accumulate_sum(&sum, src[c2 + 28]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 27] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 27]);
        accumulate_sum(&sum, src[c2 + 28]);
        accumulate_sum(&sum, src[c2 + 29]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 28] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 28]);
        accumulate_sum(&sum, src[c2 + 29]);
        accumulate_sum(&sum, src[c2 + 30]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 29] = current_pixel;

      initialize_pixel_sum(&sum);
    	for(ii = y; ii <= x; ii++){
        c2 = ii * dim + j;
        //src[ii * dim + jj]
    		accumulate_sum(&sum, src[c2 + 29]);
        accumulate_sum(&sum, src[c2 + 30]);
        accumulate_sum(&sum, src[c2 + 31]);
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 30] = current_pixel;

      initialize_pixel_sum(&sum);
      for(ii = y; ii <= x; ii++){//max(i-1,0), stop from going over the top. x, stop from going below the bottom
        c2 = ii * dim;
        //src[ii * dim + jj]
    		for(jj = j+30; jj <= minimum(j + 32, k); jj++){//max(j-1, 0), stop from going too left. min (j+1, k) stops from going too far right.
    			accumulate_sum(&sum, src[c2 + jj]);
        }
      }
    	assign_sum_to_pixel(&current_pixel, sum);
      dst[d + 31] = current_pixel;
    }


  }
/* end of computation for smooth function. so don't change anything after this in this function. */
/* END OF CHANGES */

/* the remaining lines in this function stop the measurement and set the values before returning. */
	rusage_end_time = getUserTime();
        rdtsc_end_time = rdtsc();

	*rusage_time = rusage_end_time - rusage_start_time;
	*rdtsc_time = rdtsc_end_time - rdtsc_start_time;
}
