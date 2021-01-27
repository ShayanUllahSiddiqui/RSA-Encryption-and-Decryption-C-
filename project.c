#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <gmp.h>

int main()
{
    FILE * fptr;

    printf("***************************************************\n");
    printf("***\t\t\t\t\t\t***\n");
    printf("***\tWELCOME!'RSA ENCRPYTION & DECRYPTION' \t***\n" );
    printf("***\t\t\t\t\t\t***\n");
    printf("***************************************************\n");
    //Note: p and q are prime number
    int p,q,N,r,i,option,flag,prime,num;
    char ques;
    /* hard codding p&q p=2 and q=23 based on testing.
    now N= p*q
    & r=(p-1)*(q-1)*/

    p=3;
    q=41;



    printf("\n");
    N=p*q;
    printf("N=%d",N);
    printf("\n");
    r=(p-1)*(q-1);
    printf("\nr= %d",r);
    printf("\n");



    i=2;
    option=(r*i)+1;

    printf("\n");
    //these values provided are some of the values after many observation and testing  candidate option = 1modr
    option=161;
    printf("***************************************************\n");
    printf("***\t\t\t\t\t\t***\n");
    printf("***\t  ENCRYPTION | DECRYPTION  \t\t***\n" );
    printf("***\t\t\t\t\t\t***\n");
    printf("***************************************************\n");

    int j=1;
    for(i=2; i<=option; i++)
    {

        if(option%i==0)
        {

            prime=1;
            for(num=2; num<=i/2; num++)
            {
                if(i%num==0)
                {
                    prime=0;
                    break;

                }
            }

            if(prime==1)
            {
                printf("\nKEY %d : =%d, ",j,i);
                j++;

            }

        }
    }
    printf("\n\n");
    printf("This is a hard cooded encryptor or decriptor RSA modle, due to some calculation limitation.");
    printf("\n");

    int opt;

ask:

    printf("\n\n");
    printf("***************************************************\n");
    printf("***\t\t\t\t\t\t***\n");
    printf("***\t\tpress 1 for Encryption \t\t***\n" );
    printf("***\t\t\t\t\t\t***\n");
    printf("***\t\tpress 2 for DECRYPTION \t\t***\n");
    printf("***\t\t\t\t\t\t***\n");
    printf("***************************************************\n");
    printf("\n");
    scanf("%d",&opt);


    if(opt==1)
    {

        printf("ENCRYPTION MODE \n\n");
        double conv;

        mpz_t result, base, modu; // Sets these as GMP Integers

        unsigned long int exponent; // Set exponent as an unsigned long integer



        /* Initializes base and result */

        mpz_init(base);

        mpz_init(result);

        mpz_init(modu);
        //char name[1000];


        int sum=0, sett;  // variable initialization
        int i=0;  // variable initialization





        fflush(stdin);//buffer the whole string
        char encr[250] = {'\0'};
        char msg[250]= {'\0'};

        printf("Enter (ALPHABETICAL DATA)you want to encrypt: ");
        gets(msg);
        printf("\n ENTERED MESSAGE: ");
        puts(msg);
        printf("\n\n");



        /* Asks user for exponent and puts input into unsigned long int
        exponent */

        gmp_printf("\nPlease Enter Encryption key: ");

        gmp_scanf("%ld", &exponent);


        gmp_printf("\n\n");

        printf("ENCRYPTED MESSAGE: ");
        while(msg[i]!='\0')  // while loop
        {


            /* Asks user for base and puts input into GMP Integer base */


            sett = (int)msg[i];

            mpz_set_ui (base, sett);



            /* GMPS Power function, raises base ^ exponent and puts the answer  mpz_init (t);   mpz_init (t);
            into GMP integer result */

            mpz_pow_ui(result, base, exponent);


            mpz_mod_ui(modu,result,N);

            conv = mpz_get_d(modu);// CONV IS A DOUBLE
            encr[i] = (char)conv;
            printf("%c",encr[i]);
            i++;
        }/*
          A=65
          BASE=65
          KEY=7
          POWER=BASE^7
          MOD=POWER MOD N   (N=123)DECLARED ABOVE
          MOD=67
          CONV=MOD
          CONV 67 CHANGED TO ASCII =C
          C PRINT
        */

        int length = strlen(encr);
        printf("\n\n");
        puts(encr);

        fptr = fopen("test.txt", "w"); // "w" defines "writing mode"
        fwrite(encr,1,length, fptr);
        fclose(fptr);

        gmp_printf("\n\n");
        printf(" \ndo you want to decrypt the encrypted message \n\n press 2 for decryption\n press any key to exit. ");
        scanf("%d",&opt);


        if (opt==2)
        {
            goto decryption;
        }
    }

    else if(opt==2)
decryption:
    {


        printf("DECRYPTION MODE \n\n");
        double conv;

        mpz_t result, base, modu; // Sets these as GMP Integers

        unsigned long int exponent; // Set exponent as an unsigned long integer



        /* Initializes base and result */

        mpz_init(base);

        mpz_init(result);

        mpz_init(modu);
        //char name[1000];

        char choice;
        int sum=0, sett;  // variable initialization
        int i=0;  // variable initialization

        fflush(stdin);
        char encr[250]= {'\0'};
        char msg[250]= {'\0'};
A:
        printf("\n\n");
        printf("Do you want to decrypt an pre-exeisting file or manual enter message :\n 1 for yes or 2 for manual data entrance  ");
        scanf("%d", &choice);
        printf("\n\n");

        if(choice==1)
        {

            if(fptr==NULL)
            {
                printf("ERROR: CAN NOT OPEN FILE ");
                exit(1);
            }
            fptr = fopen("test.txt", "r");//r IS READING MODE
            fgets(encr,250,fptr);
            printf("Data from the file: (%s)", encr);
            fclose(fptr);
        }


        else if(choice==2)
        {

            printf("Enter (ALPHABETICAL or NUMERIC DATA)you want to encrypt: ");
            gets(encr);
            printf("entered cypher: ");
            puts(encr);
            printf("\n\n");

        }
        else
        {
            printf("invalid option");
            goto A;
        }


        /* Asks user for exponent and puts input into unsigned long int
        exponent */


        gmp_printf("\nPlease Enter decryption key: ");

        gmp_scanf("%ld", &exponent);

        gmp_printf("\n");

        printf("DECRYPTED MESSAGE:  ");
        while(encr[i]!='\0')  // while loop
        {

            /* Asks user for base and puts input into GMP Integer base */


            sett = (int)encr[i];

            mpz_set_ui (base, sett);



            /* GMPS Power function, raises base ^ exponent and puts the answer  mpz_init (t);   mpz_init (t);
            into GMP integer result */

            mpz_pow_ui(result, base, exponent);


            mpz_mod_ui(modu,result,N);

            conv = mpz_get_d(modu);

            msg[i] = (char)conv;
            printf("%c",msg[i]);

            i++;


        }
        gmp_printf("\n\n");
        system ("cls");
         printf("\t\t\t\t\t OUTPUT RESULT n");
        printf("\n\n");
        printf("\t\t\t***************************************************\n");
        printf("\n");
        printf(" ENTERED  MESSAGE:  %s",msg);
        printf("\n\n");
        printf("\t\t\t***************************************************\n");
        printf("\n");
        printf(" ENCRYPED CYPHER:   %s",encr);
        printf("\n\n");
        printf("\t\t\t***************************************************\n");
        printf("\n");
        printf(" DECRYPTED MESSAGE:  %s",msg);
        printf("\n\n\n");
    }
    else
    {
        printf("\n INVALID OPTION\n");
        return 0;
    }

}
