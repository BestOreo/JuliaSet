#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* ReadTxt(char* root){
    FILE *fp=fopen(root,"r");
    char *Buffer = NULL;
    int ContentLength = 0;
    if(fp==NULL)
    {
        printf("Fail to openg txt");
        return NULL;
    }
    fseek(fp, 0, SEEK_END); //move pointer to tail
    ContentLength = ftell(fp);  //get the current position of the point and get the length of content
    rewind(fp);    //reset pointer to head
    // Apply memeory to store the string note the last character is '\0'
    Buffer = (char*) malloc(sizeof(char)*ContentLength+1);
    if(Buffer == NULL)
    {
        perror("Not enough memory!\n");
        exit(0);
    }
    //Read the file
    ContentLength = fread(Buffer, sizeof(char), ContentLength, fp);
    Buffer[ContentLength] = '\0'; //add the end character
    fclose(fp);  //  close fp
    return Buffer;
}

void ReWriteScript(int argc, char *argv[]){
    char * root = argv[1];
    char txtBuffer[1000];
    memset(txtBuffer,0,1000*sizeof(char));  // clean the buffer to a series of 0
    char *p = ReadTxt(root); // read the root txt and return a string. Note
    strcpy(txtBuffer,p);
    p = txtBuffer;
    FILE *fp = fopen("julia.txt","wr");
    while(*p != '\0'){
        if(*p == '#' && *(p+1) == 'A' && *(p+2) == '#'){
            fprintf(fp,"%.6f",atof(argv[2]));
            p += 3;// '#A#'
        }
        else if(*p == '#' && *(p+1) == 'B' && *(p+2) == '#'){
            fprintf(fp,"%.6f",atof(argv[3]));
            p += 3;// '#B#'
        }
        else{
            fprintf(fp,"%c",*p);
            p++;
        }

    }
    fclose(fp);
}


int main(int argc, char *argv[]){

    if ( argc != 4){ // check the number of arguments
        printf("ERROR: Please enter exactly 3 command-line arguments.\n");
    }
    else {
        ReWriteScript(argc,argv);
        char *result = ReadTxt("julia.txt"); //for test
        printf("%s",result);
        return 0;
    }
}

