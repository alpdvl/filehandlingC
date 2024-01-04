#include <stdio.h>
#include <windows.h>
#include <conio.h>


int main() {
    printf("File handling in C\n");
    FILE* Filepointer;
    char data[50]="This is your first line";
    char data2[50]="This is your second line.";
    int lengthofdata =sizeof(data)/sizeof (data[0]);
    int lengthofdata2 =sizeof(data2)/sizeof (data2[0]);
    int counter=0;

    Filepointer=fopen("experimental.txt","w"); // this line will return the address of that file,
    // if it cant create it succ. then it will return "NULL" instead
    // it'll create it to the filehandling.exe's (your build's location)folder
    if(Filepointer==NULL)
    {
        printf("you couldn't create it!\n");
    }
    else
    {
        printf("you've created or opened the file successfully!\n");

        fclose(Filepointer); // closing the file after we're done with it
    }
    Filepointer = fopen("experimental.txt","w");// it can make it possible to only write it also deletes the old data in that file
    if(Filepointer==NULL) {
        printf("you couldn't open it!\n");
    }

    else
        {
            while (counter < lengthofdata && data[counter]!='\0') {
                printf("we're currently writing this char: %c\n", data[counter]);

                fputc(data[counter], Filepointer);
                counter++;
            }
        }


        fclose(Filepointer);

    counter=0;
    Filepointer = fopen("experimental.txt","a");// it opens the file in appending mode
    if(Filepointer==NULL) {
        printf("you couldn't open it!\n");
    }

    else
    {
        fputc('\n',Filepointer);// with this part we make sure that our code will
        // append to second line of this txt
        while (counter < lengthofdata2 && data2[counter]!='\0') {
            printf("we're currently adding this char: %c\n", data2[counter]);

            fputc(data2[counter], Filepointer);
            counter++;
        }
    }
    fputc('\n',Filepointer);
    fputc('<',Filepointer);
    fputc('E',Filepointer); // sign for the end of the file
    fputc('>',Filepointer);



    fclose(Filepointer);




    printf("press enter to continue");
    getch();//

    system("cls");

    Filepointer= fopen("experimental.txt","r");
    if(Filepointer==NULL)
    {
        printf("ERROR!\n");
    }

    else
    {

        char buffer;
        //
        // printf("Something happening\n");

        while(1)
        {
            //printf("inside while check\n");
            buffer=fgetc(Filepointer);
            if(buffer=='<')
            {
                buffer = fgetc(Filepointer);
                if(buffer=='E')
                {
                    buffer = fgetc(Filepointer);
                    if(buffer=='>')
                    {
                        break;
                    }
                }

            }

            printf("%c",buffer);
        }
    }

    fclose(Filepointer);





    return 0;
}
