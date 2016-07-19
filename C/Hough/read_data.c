#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hough_header.h"

int i = 0;

struct data *create_data_array(int size){
    float *data_x = malloc(sizeof(float) * size);
    float *data_y = malloc(sizeof(float) * size);

    struct data *data = malloc(sizeof(data));
    data->data_x = data_x;
    data->data_y = data_y;
    return data;
};

void destroy_data_array(struct data* data){
    free(data->data_x);
    free(data->data_y);
    free(data);
}

void read_line(char line[], struct data *data, int signal)
{
    char* tok;

    //strtok breaks up the given line based on the ',' delimeter
    for (tok = strtok(line, ","); tok!=NULL; tok = strtok(NULL, ",\n")){
        float x = convert_char_to_int(tok);
        if(signal == 0){
             store_x1_data(data, x);

        } else {
            store_x2_data(data, x);
        }
               
       
    }
}

float convert_char_to_int(char *text){
    //TODO
    return 0;    
}

void open_file_read_line_store_data(struct data *data){
       //opens file in read mode
    FILE* stream = fopen("DATA/input", "r");
    char line[1024];
     //fgets keeps going till it reads 1023 characters OR EOF OR return 
    while (fgets(line, 1024, stream)){
        char* tmp = strdup(line);
        read_line(tmp, data, 0);
        // NOTE strtok clobbers tmp
        free(tmp);
    }

    //reset counter
     i = 0;

    stream = fopen("DATA/input", "r");
    char line2[1024];
     //fgets keeps going till it reads 1023 characters OR EOF OR return 
    while (fgets(line2, 1024, stream)){
        char* tmp = strdup(line2);
        read_line(tmp, data, 1);
        // NOTE strtok clobbers tmp
        free(tmp);
    }
}

void store_x1_data(struct data *data, float x1){
    data->data_x[i] = x1;
    i++;
}

void store_x2_data(struct data *data, float x2){
    data->data_y[i] = x2;
    i++;
}

struct data *read_in_data_and_return_struct(){
    struct data *data = create_data_array(55700);
    open_file_read_line_store_data(data);
    return data;
}

int main(){
   
}