#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char const* const VERSIONSNR = "0.0.3";


void Triangle(FILE *fh, int cnt) {
    int i;

    for (i = 0; cnt/2 > i ; i+=2)
    {
        fprintf(fh, "%d,%d\n", i, 0);
        fprintf(fh, "%d,%d\n", i+1, 0);
        fprintf(fh, "%d,%d\n", i+1, 1);
        fprintf(fh, "%d,%d\n", i+2, 1);
    }
}




int main(int argc, char* argv[])
    int i;

{
    if (argc != 3) {
        printf("falsche Anzahl von Argumenten, erforderliches Format: %s <cnt> <output>", argv[0]);
        return 1;
    }

    while(true)
    {
        int option = getopt(argc, argv, "hvf:");
        switch(option)
        {
        case 'h':
            printf("Bitte -t nutzen um den Rechteckgenerator zu nutzen.\n");
            exit(0);

        case 'v':
            printf("Version %s\n", VERSIONSNR);
            exit(0);

        case 't':
               FILE *fp;

   	         fp = fopen(argv[2], "w+");

               Triangle(fp, atoi(argv[1]));

               fclose(fp);;
            break;

        case '?':
            fprintf(stderr, "Please try -h\n");
            exit(1);

        case -1:
            exit(0);
        }
    }

    return 0;
}