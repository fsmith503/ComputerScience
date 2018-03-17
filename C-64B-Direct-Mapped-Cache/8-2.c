//Franklin Smith CIS 314 Assignment 8
#include <string.h> //This is the header file in c that defines several functions to manipulate C strings and arrays.
#include <stdio.h> //The is the stdio.h header in c that defines three variable types, several macros, and various functions for performing input and output
#include <stdlib.h> //This is the stdlib.h header in c that defines four variable types, several macros, and various functions for performing general functions.
//Citation Source: Assistance from Josh Tanke
//Citation Source: Assistance from Miguel Hernandez
//scanf
//loop takes in unisgned
//symbol for hex
//store as unisgned int
typedef unsigned char* inputval; //declares type def for unsigned char pointer which is going to be my input value

struct cache_block { // declaring the cache_block struct
	unsigned char value[4];// 4 byte value
	unsigned char valid; // 0x00
	unsigned int Tag; // 26 bit
}; // end of the the cache block struct declaration
struct cache_block cache[16]; // initializing a cache_blockstruct of size 16

unsigned int getOffset(unsigned int address){ // declaring the get off set method which returns the offset of type unisgned int
	/*returns the byte offset of the address within its cache block */
	unsigned char mask1 = 0x00000003; // creating a mask to and the adress with to get the offset bits
	unsigned int offsetResult = mask1 & address; // anding the mask and the adress to get the offset bits
	return offsetResult; // returning the result of the offset of unsigned int
} // end of the getOffset method which returns the offset of type unsigned int

unsigned int getSet(unsigned int address){ // declaring the get set method which returns the set value of type unisgned int
	/* returns the cache set for the adress */
	//0000 0000 0000 0000 0000 0000 0000 0000
	unsigned char b = address << 26; // bitwise op shift left by 26
	unsigned int setResult = b >> 28; // bitwise op shift right by 28
	return setResult; // returning the result which is the set of type unsigned int
} // end of the getSet method which returns the set value of type unisgned int

unsigned int getTag(unsigned int address){ // declaring the getTag method which returns the tag of type unsignedint
	/* returns the cache tag for the address */
	unsigned int tagResult = address >> 6; // shifting the address by 6 which gives us the tag result that we want
	return tagResult; // returning the tag result of the address of type unsigned int
} // end of the get tag method which returns the tag of type unsignedint

void memory_show(inputval begin, int param){ // initializing function that displays the memory does not return anything void
	int var = 0; // declaring an it variable
	while(var < param){ // initializing the while loop condition less than param
		printf(" %.2x", begin[var]); // printing the bytes
		var++; //increasing while loop iterator
		} // end of the for loop
	printf("\n"); // printing a new line
} // end of the memory_show function which displays the memory does not return anything void

void printCache(){ //printcache function which prints the cache
	int count = 0; // initilizing a count integer variable for the for loop
	while(count < 16){ // initializing the while loop, runs if less than 16, if less than 16 increments by 1
		if(cache[count].valid == 1){ // if the cache spot for the location is valid
			printf("set: %d - tag: %d - valid: %d - value:", count, cache[count].Tag, 1); // print statement specification from project instructions
			memory_show((inputval) &cache[count].value, 4); // calling method which shows the memory
		} // end of the if statement which checks if the cache spot for the locaiton is valid
		count++; // incrementing the while loop counter param condition by 1
	} // end of the for loop which runs for 16 iterations
} // end of the print cache function which prints the cache

void valueWriter(){ // prints the set index, tag, and value for all valid blocks in the cache.
	unsigned int hexVal; // initializing a unsigned int variable for the hexadecimal value
	unsigned int hexPos; // initializing a unsigned int variable for the hexadecimal position in memory
	printf("Enter 32-bit unsigned hex address: "); // print statement specification from project instructions
	scanf("%x", &hexPos); //scanf reads formatted input from STDin to be stored in the hexadecimal position for the address
	printf("Enter 32-bit unsigned hex value: "); // print statement specificiation from project instructions
	scanf("%x", &hexVal); // scanf reads formatted input from STDin to be stored in hexadecimal value variable
	//printf("%d\n", index);
	//show_bytes((byte_pointer) &index, 4);
	unsigned limit = hexPos >> 6; // shifting the hexadecimal position to the right 6 bits
	unsigned temp = hexPos << 26; // shifting the hexadecmial position to the left 26 bits
	unsigned pos = temp >> 28; // shifting the hexadecimal position to the right 28 bits
	//printf("%d\n", index);
	//show_bytes((byte_pointer) &index, 4);

	if(cache[pos].valid == 0){ // if the validity of that item in the cache at that index is not valid
		cache[pos].valid = 1; // assign the validity of that item in the cache at that index to valid
		cache[pos].Tag = limit; // Assign the tag of that item in the cache at that index to that tag value
		memcpy(cache[pos].value, &hexVal, 4); // copying to memory the item in the cache at the indexes value and the pointer of the hexadecimal vlaue
		printf("wrote set: %d - tag: %d - valid: %d - value:", pos, limit, 1); // print statement specification from project instructions
		memory_show((inputval) &hexVal, 4); // calling function which prints the bytes defined above
	}else{ // else statement
		printf("evicting block - set: %d - tag: %d - valid: %d - value:", pos, cache[pos].Tag, 1); // print statement specification from project instructions
		memory_show((inputval) &cache[pos].value, 4); // calling function which prints the bytes defined above
		cache[pos].Tag = limit; // Assign the tag of that item in the cache at that index to that tag value
		cache[pos].valid = 1; // assign the validity of that item in the cache at that index to valid
		memcpy(cache[pos].value, &hexVal, 4); // copying to memory the item in the cache at the indexes value and the pointer of the hexadecimal value
		printf("wrote set: %d - tag: %d - valid: %d - value:", pos, limit, 1); // print statement specification from project instructions
		memory_show((inputval) &hexVal, 4); // calling function which prints the bytes defined above
	}// end of the else statement
} // end of the value write function which prints the set index, tag, and value for all valid blocks in the cache.

void valDisplay(){ // initializing function that prompts user for hexidecimal address does not return anything void
	unsigned int hexPos; // declaires an unsigned int for the hexidecimal adress which is to be the user input
	printf("Enter 32-bit unsigned hex address: "); // prompting the user for user input for the hexadecimal address
	scanf("%x", &hexPos); // scanf reads formatted input from STDin to be stored in the position of the hex address

	unsigned holder = hexPos << 30; // initializing unsigned holder var to be hex pos shifted left 30 bits
	unsigned displacement = holder >> 30; // offset = displacement
	unsigned bits = hexPos >> 6; // tag = bits
	unsigned temp = hexPos << 26; // initializing unsigned temp var to be hex pos shifiting left 26 bits
	unsigned position = temp >> 28; // initializing unsigned to be the hex position, shifting bits left 26 bits then right 28 bits
	printf("looking for set: %d - tag: %d\n", position, bits); // print statement specification from project instructions

	if(cache[position].valid == 0){ // if the cache position is not valid
		printf("no valid set found - miss!\n"); // print staement specification from project intructions
	}else{
		printf("found set: %d - tag: %d - offset: %d - valid: %d - value:", position, cache[position].Tag, 0, 1); // print statement specification from project instructions
		memory_show((inputval) &cache[position].value[displacement], 1); // calling method which shows displays the memory
		if(cache[position].Tag == bits){ // if statement if the tax of the position is equal to the bits
			printf("hit!\n"); // print statement specification from the project instructions
		}else{ // else statement
			printf("tags don't match - miss!\n"); // print statment specification from project instructions
		} // end of the else statement
	}// end of the else statement
} // end of the valDisplay function which prompts user for hexidecimal address does not return anything void

int main(int argc, char *argv[]){ // initializing main function
	/*
	Implement a main function that:
	o (5) Allocates enough memory to hold 16 cache blocks (1 per set). Initialize your cache such that all blocks are invalid.
	o Repeatedly prompts the user to either:
	*/
	char input[20]; // defining char value of 20 byte
	int loop = 0; // initialiizng and defining integer variable named loop
	struct cache_block* cache = (struct cache_block*) malloc (16*sizeof(struct cache_block)); //memory allocating space for the 16 cache blocks 

	while(loop < 16){ // initializing while loop to run 16 times, counter parameter is loop which is defined above at 0
			cache[loop].valid = 0; // setting the validity of the object in the cache at index position looop to 0
			loop++; // loop is incremented by 1 
	} // end of the of for loop which sets the validity of the object in the cache at index position looop to 0

	while(1){ // while true loop
		printf("enter r for read, w for write, p to pring, q to quit:"); // print statement specification from project instructions
		scanf(" %s", input); //scanf reads formatted input from STDin to be stored as input for the if statements below
		if(strcmp(input, "p") == 0){ // if the input from scanf is p
			//prints the values, set index, tag, and value for all valid blocks in the cache
			printCache();
		} // end of the if input is p statement
		if(strcmp(input, "w") == 0){ // if the input from scanf is w
			/*
			Write a value – prompt the user for a 32-bit hex address and a 32-bit hex value (as unsigned ints). 
			Writes the 4-byte value at the appropriate location in the cache for the given address, evicting 
			an existing block if necessary. You may assume that the user enters an address that is a multiple 
			of 4 so that the beginning of the value aligns with the beginning of a cache block. This is to 
			simulate moving an entire block from memory into the cache. Print the set index, tag, and value of 
			the new block being written. If a valid block is evicted, also print the set index, tag, and value 
			of the evicted block.
			*/
			valueWriter();
		} // end of the if input is w statement
		if(strcmp(input, "q") == 0){ // if the input from scanf is q
			//quits the simulation
			break; // quits the simulation
		} // end of the if input is q statement
		if(strcmp(input, "r") == 0){ // if the input from scanf is r
			/* 
			if (strcmp(word, "p") == 0) {
			printBlocks();
			20) Read a byte – prompt the user for a 32-bit hex address (as an unsigned int). 
			Prints the set index and tag corresponding to the address. Also print “hit” and the 
			hex value of the byte at that address if the cache contains a valid value corresponding 
			to the address. Otherwise, print “miss” and indicate the reason for the miss (i.e., invalid block or tag mismatch).
			*/
			valDisplay(); // reads a byte
		} // end of the if input is r statement
	} // end of the while true loop which is intended to get the input
	exit(0); // c library call to exit which exits the c program
} // end of the main method
