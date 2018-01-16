//Author Peter Adamson

# include <stdio.h>
# include <stdlib.h>

void set_busy(unsigned int *pattern, int i);
void set_idle(unsigned int *pattern, int i);
int count_busy(unsigned int pattern);
void set_busy_range(unsigned int *pattern, int from, int to);
int is_busy(unsigned int pattern, int i);

int main(){
	unsigned int pattern = 0xffffffff;	//initialize all units to idle
	char cmd,junk;
	int n = 0;
	int m = 0;
	while(scanf("%c",&cmd)==1){
		switch(cmd){
			case 'b':
				scanf("%d",&n);
				set_busy(&pattern, n);
				break;
			case 'i':
				scanf("%d",&n);
				set_idle(&pattern, n);
				break;
			case 'r':
				scanf("%d %d",&n,&m);
				set_busy_range(&pattern, n, m);
				break;
			case 'p':
				printf("0x%x\n",pattern);
				break;
			case 'c':
				printf("%d units are busy\n",count_busy(pattern));
				break;
			case '?':
				scanf("%d",&n);
				if(is_busy(pattern, n)==0){
					printf("unit %d is busy\n", n);
				}
				else{
					printf("unit %d is idle\n", n);
				}
				break;
			default:
				printf("invalid command %c\n",cmd);
		}
		scanf("%c",&junk); /* get rid of the \n char */
	}
	return EXIT_SUCCESS;
}

void set_busy(unsigned int *pattern, int i){
	*pattern ^= (0 ^ *pattern) & (1 << i);		
}

void set_idle(unsigned int *pattern, int i){
	*pattern ^= (-1 ^ *pattern) & (1 << i);	
}

int count_busy(unsigned int pattern){
	int bit;
	int count = 0;
	int i;
	for(i=0; i<32; i++){
		bit = (pattern >> i) & 1;
		if(bit == 0){
			count = count + 1;
		}	
	}
	return count;
}

void set_busy_range(unsigned int *pattern, int from, int to){
	int i;
	for(i=from; i<=to; i++){
		*pattern ^= (-0 ^ *pattern) & (1 << i);
	}
}

int is_busy(unsigned int pattern, int i){
	int bit = 1;
	bit = (pattern >> i) & 1;
	return bit;
}
