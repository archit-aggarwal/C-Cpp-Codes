#include <stdio.h>
int main()
{
    // FILE is a non-primitive data type in stdio.h Header file.
    FILE *fp;
    // fp is a pointer of type FILE which will point to address of a file when it is loaded in buffer.
     fp = fopen("txtfile.txt","w");
    /* fopen returns a address of type FILE. It takes two arguments
    1. name of text/binary file
    2. file opening mode ( a , w , r , a+ , w+ , r+ , ab , wb , rb , ab+ , wb+ , rb+  )
    */
    // fopen() will return NULL if FILE is not found in case of r or r+ opening mode.
    // Otherwise it will return NULL if it cannot open.
    if(fp == NULL)
    {
        printf("File cannot open or not found");
        exit(0);
    }
    // 1. fputc() => Write character by character in file.
    char str[100];
    printf("Enter String : ");
    gets(str);
    for(int i=0;i<strlen(str);i++)
        fputc(str[i],fp);
    fclose(fp); // fclose() closes opened file => remove the file from buffer in RAM. Store it only in Hard disk.

    // 2. fgetc => Read character by character from file.
    fp = fopen("txtfile.txt","r");
    char ch = fgetc(fp);
       while(!feof(fp)) // feof() returns true if end of file is reached else returns false.
       {
           printf("%c",ch);
           ch = fgetc(fp);
       }
       printf("\n");
    fclose(fp);

    // 3. fputs() => Write line by line on file.
    fp = fopen("txtfile.txt","w");
    fputs(str,fp);
    fclose(fp);

    // 4. fgets() => Read line by line ( or string by string ) from file.
    fp = fopen("txtfile.txt","r");
    char s[100];
    while(fgets(s,99,fp) != NULL) // fgets() returns false if no more string in file remains otherwise copies it in s;
    {
      printf("%s",s);
    }
    printf("\n");
    fclose(fp);

    // 5. fwrite() => Write data from variable( of any data type including UDT struct ) on file.
    //            => used for binary files.
    fp = fopen("binfile.dat","wb");
    struct person
    {
        int age;
        int rollno;
    }p1,p2;
    printf("\n Enter age and roll no : ");
    scanf("%d",&p1.age);
    scanf("%d",&p1.rollno);
    fwrite(&p1,sizeof(p1),1,fp);
    // four arguments : add(variable) , sizeof(variable) , no of records to write , file pointer
    fclose(fp);

    // 6. fread() => Read data from file using a variable.
    fp = fopen("binfile.dat","rb");
    fread(&p2,sizeof(p2),1,fp); // fread() returns false if no more record is to be read.
     printf("\n%d %d\n",p2.age,p2.rollno);
    fclose(fp);

    // 7. fprintf() => Write the output from screen to the file and dont't display on screen.
    fp = fopen("sum.txt","w");
    int a,b;
    printf("\n Enter two numbers : ");
    scanf("%d %d", &a , &b );
    fprintf(fp,"sum of %d and %d is %d ",a,b,a+b);
    // two arguments : file pointer and the statement of printf()
    fclose(fp);

    // 8. fscanf => Read from file and store it directly in variables.
    fp = fopen("sum.txt","r");
    fscanf(fp,"%d%d",&a,&b);
    printf("a= %d b = %d\n",a,b);
    fclose(fp);
    return 0;

}
