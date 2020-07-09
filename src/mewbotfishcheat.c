#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int pos[100];


void print_name(){
    printf("              created by: EH \n");
    printf("-------------------------------------\n\n");
}


char* to_lower(char* st){
    char *starr = malloc(sizeof(char)*100);
    
    for (int i = 0; st[i] != '\0'; i++){
        if (st[i] >= 'A' && st[i] <= 'Z'){
            starr[i] = st[i]+32;
        
        }else{
            starr[i] = st[i];
        }
    }

  return starr;
}


int get_length_char(char* charin){
    int out = 0;
    for (char *c = charin; *c != '\0'; c++ , out++);

    return out;
}


int get_length_int_arr(){
    int out = 0;
    for (int i = 0; pos[i] != -1; i++, out++);

    return out;
}


int get_pos(char* userin){
    int len = get_length_char(userin);
    int count = 0;
    for (int i = 0; i < len; i++){
        if (isalpha(userin[i])){
            pos[count] = i;
            count++;
        }
    }

    pos[count] = -1;

    return 0;
}


int name_match(char* name, char* tomatch){
    int arr_len = get_length_int_arr();
    for (int i = 0; i < arr_len; i++){
        if (name[pos[i]] == tomatch[pos[i]]){
            continue;
        }
        return 1;
    }

    return 0;
}


int main()
{
    print_name();
    int len;
    int found = 0;
    char user_input[100];
    char filename[100] = "poke_names.txt";

    while (1){
        printf("Enter (exmaple: p_ka_hu): ");
        fgets(user_input, sizeof(user_input), stdin);
        
        if (user_input[0] == '\n' || user_input[0] == '\0' || user_input[0] == 0){
            printf("emptry string\n");
            memset(user_input, 0, sizeof(user_input));
            found = 0;
            printf("\n\n");
            continue;
        }

        len = get_length_char(user_input);
        get_pos(user_input);
        
        char *lower_userin = to_lower(user_input);
        FILE* fptr;
        
        if ((fptr = fopen(filename, "r")) == NULL){
            printf("error opening file\n");
            system("pause");
            return 1;
        }
        
        char buff[100];
        
        while (fgets(buff, 100, fptr)){
            if (name_match(to_lower(buff), lower_userin) == 0 && get_length_char(buff) == len){
                printf("%s\n", buff);
                found++;
            }
        }
        
        if (found == 0){
            printf("name not found\n");
        }
        
        memset(user_input, 0, sizeof(user_input));
        found = 0;
        
        printf("\n\n");
    }

    system("pause");
    return 0;
}
