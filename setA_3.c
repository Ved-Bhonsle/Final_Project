#include <stdio.h>
#include <stdint.h>

void print_binary(uint32_t number) 
{
        
	for (uint32_t i = 0;i<4;++i) 
	{
	        printf("%u", (number>>i) & 1);
	}    
    	printf("\n");
}

uint32_t reverseBits(uint32_t source) 
{

  	uint32_t result=0;
	for (uint32_t i = 0;i<4;++i) 
	{
        uint8_t i_bit_value = (source >> i) & 1;
        result |= i_bit_value << (3-i) ;
	}    
    
	printf("Before:");
	print_binary(result);
	
	printf("After:");
  	print_binary(source);
    
    	return result;

}

int main()
{
    
    	uint32_t number = 0;
	printf("Input:");
	if (scanf("%u", &number)==1)
        	reverseBits(number);
}
