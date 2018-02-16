#include <stdio.h>

int ge(float x, float y) {
unsigned ux = *((unsigned *) &x); // convert x raw bits
unsigned uy = *((unsigned *) &y); // convert y raw bits
unsigned sx = ux >> 31; // extract sign bit of ux
unsigned sy = uy >> 31; // extract sign bit of uy
ux <<= 1; // drop sign bit of ux
uy <<= 1; // drop sign bit of uy
unsigned int k = (ux <= uy); // assigning variable k to comparator case <=
unsigned int l = (sx != sy); // assigning variable l to comparator case !=
unsigned int m = (ux >= uy); // assigning variable m to comparator case >=
unsigned int n = (sx == sy); // assigning variable n to comparator case ==
return(k && l) || (m && n);
return (ux <= uy && sx!= sy) || (ux >= uy && sx == sy); 
//return ((ux == uy) || (0) || (0) || (0));
// TODO: return using sx, sy, ux, uy
}

int main(int argc, char *argv[]){
	printf("%d\n", ge(0.0f, 0.0f)); // 1
	printf("%d\n", ge(-0.0f, 0.0f)); // 1
	printf("%d\n", ge(-1.0f, 0.0f)); //0
	printf("%d\n", ge(0.0f, 1.0f)); //0
	printf("%d\n", ge(1.0f, 0.0f)); //1
	printf("%d\n", ge(0.0f, -1.0f)); //1	
}