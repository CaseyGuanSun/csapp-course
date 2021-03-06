/*************************************************************************
    > File Name: combine5.c
    > Author: sukong
    > Mail: sukong@outlook.com 
    > Created Time: 2016年07月08日 星期五 15时06分27秒
 ************************************************************************/

#include<stdio.h>
#include<vec.h>

/* 2 x 1 loop unrolling */
void combine5(vec_ptr v, data_t *dest){
	long i;
	long length  = vec_length(v);
	long limit = length-1;
	data_t *data = get_vec_start(v);
	data_t acc = IDENT;

	/* Combine 2 elements at a time */
	for(i = 0; i < limit; i+=2) {
		acc = (acc OP data[i]) OP data[i+1];
	}
	
	/* Finish any remaining elements */
	for(; i < length; i++) {
		acc = acc OP data[i];
	}
	*dest = acc;
}
