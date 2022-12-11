//
// Created by DELL on 08/12/2022.
//
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
char arr[5000];
char findwords1[7] = {'w','i','n','h','t','u','t'};
char findwords2[17] = {'N','a','t','i','o','n','a','l','C','y','b','e','r','C','i','t','y'};

void ToFindCharArr();

int main (){

ToFindCharArr();

 }
void ToFindCharArr()
{
    int index = 0;
    char c;
    FILE *fptr;
    bool word1;
    char result1[7];
    //int count1 = 0;
    bool word2;
    char result2[17];
    //int count2 = 0;
    fptr = fopen("words.txt", "r");
    if(fptr==NULL){
        printf("[-] File cannot open!");
    }else{
        while(fscanf(fptr, "%c", &c) ==1)
        {
            if((c>= 65 and c<=90) or (c>=97 and c<=122)) {
                arr[index] = c;
                index++;
            }
        }
    }
    fclose(fptr);
    // find word for 'winhtut'
    for(int i=0; i<index;i++){
        //printf("%c\t",arr[i]);
        int temp = 0;
        word1 = true;
        while(temp < sizeof(findwords1) && word1)
        {
            if(arr[i+temp] == findwords1[temp])
            {
                word1 = true;
                result1[temp] = arr[i+temp];
                 temp++;
                 //count1++;

            }
            else
            {
                word1 = false;
            }
        }
    }
    // find word for 'NationalCyberCity'
    for(int i=0; i<index;i++){
        //printf("%c\t",arr[i]);
        int temp = 0;
        word2 = true;
        while(temp < sizeof(findwords2) && word2)
        {
            if(arr[i+temp] == findwords2[temp])
            {
                word2 = true;
                result2[temp] = arr[i+temp];
                temp++;
                //count2++;

            }
            else
            {
                word2 = false;
            }
        }
    }
    //printf("%d\n", sizeof(result1));
    printf("Result found for winhtut\n");
    for(int i = 0; i <sizeof(result1); i++)
    {
        printf("%c",result1[i]);
    }
    
    printf("\nResult found for NationalCyberCity\n");
    for(int i = 0; i <sizeof(result2); i++)
    {
        printf("%c",result2[i]);
    }
}


