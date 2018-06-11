#ifndef _CONVERT_H
#define _CONVERT_H
enum
{
	NULSTA,
	CSTA,
	CPPSTA,
	EOFSTA
};

void convert();
void do_NULSTA(FILE *ipf,FILE *opf);
void do_CPPSTA(FILE *ipf,FILE *opf);
void do_CSTA(FILE *ipf,FILE *opf);

#define  INPUT "input.txt"
#define  OUTPUT "output.txt"
#endif