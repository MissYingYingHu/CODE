#include<stdio.h>
#include"convert.h"

static int status = NULSTA;

void do_NULSTA(FILE *ipf,FILE *opf)
{
	int f = fgetc(ipf);
	switch(f)
	{
	case '/':
		{
		int s = fgetc(ipf);
		switch(s)
		{
		case '/':
			fputc('/',opf);
			fputc('/',opf);
			status = CPPSTA;
			break;
		case '*':
			fputc('/',opf);
			fputc('/',opf);
			status = CSTA;
			break;
		case EOF:
			status = EOFSTA;
			break;
		default:
			ungetc(s,ipf);
			status = NULSTA;
			break;
		}
		}
		break;
	case EOF:
		status = EOFSTA;
		break;
	default:
		fputc(f,opf);
		break;
	}
}
void do_CPPSTA(FILE *ipf,FILE *opf)
{
	int t = fgetc(ipf);
		switch(t)
		{
		case '\n':
			fputc('\n',opf);
			status = NULSTA;
			break;
		case EOF:
			status = EOFSTA;
			break;
		default:
			fputc(t,opf);
			break;
		}
}
void do_CSTA(FILE *ipf,FILE *opf)
{
	int n = fgetc(ipf);
	switch(n)
	{
	case '*':
		{
			int m = fgetc(ipf);
			switch(m)
			{
			case'/':
				fputc('\n',opf);
				status = NULSTA;
				break;
			case EOF:
				status = EOFSTA;
				break;
			default:
				ungetc(m,ipf);
				status = NULSTA;
				break;
			}
		}
		break;
	case '\n':
		fputc('\n',opf);
		fputc('/',opf);
		fputc('/',opf);
		break;
	case EOF:
		status = EOFSTA;
		break;
	default:
		fputc(n,opf);
		break;
	}
}

 void convert()
{
	FILE *ipf=fopen(INPUT,"r");
	FILE *opf=fopen(OUTPUT,"w");
	if(ipf == NULL || opf == NULL)
	{
		printf("error\n");
		return;
	}
	while(status != EOFSTA)
	{
		switch(status)
		{
		case NULSTA:
			do_NULSTA(ipf,opf);
			break;
		case CPPSTA:
			do_CPPSTA(ipf,opf);
			break;
		case CSTA:
			do_CSTA(ipf,opf);
			break;
		case EOFSTA:
			break;
		default:
			break;
		}
	}
	fclose(ipf);
	fclose(opf);
}
