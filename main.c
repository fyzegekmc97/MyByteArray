#include <stdio.h>
#include <stdlib.h>

struct MyByteArray
{
    u_int64_t array_length ;
    u_int8_t * data_begin_location ;
    u_int8_t * data_end_location ;
} ExampleByteArray ;

typedef struct MyByteArray MyByteArray ;

struct StaticByteArray
{
    u_int64_t st_array_length ;
    u_int8_t * end_location ;
    u_int8_t byte_array[] ;
} ExampleStaticByteArray ;



void Initialize_Byte_Array(MyByteArray * somebytearray, u_int64_t arr_length)
{
    somebytearray->array_length = arr_length ;
    somebytearray->data_begin_location = calloc(arr_length,sizeof(u_int8_t)) ;
    somebytearray->data_end_location = somebytearray->data_begin_location + arr_length*sizeof(u_int8_t);
}

void Initialize_Static_Byte_Array(struct StaticByteArray * somebytearray, u_int64_t arr_length)
{
    somebytearray->st_array_length = arr_length ;

    for(int k = 0 ; k < arr_length ; k++)
    {
        somebytearray->byte_array[k] = 0 ;
    }

    somebytearray->end_location = somebytearray->byte_array + arr_length ;
}

int main()
{
    Initialize_Byte_Array(&ExampleByteArray,10) ;
    printf("Byte array properties: \n");
    printf("Length: %lu \n",ExampleByteArray.array_length);
    printf("Begin address: %X \n", ExampleByteArray.data_begin_location) ;
    printf("End address: %X \n", ExampleByteArray.data_end_location) ;

    u_int8_t begin = 0 ;
    u_int8_t * begin_ptr = &begin ;

    Initialize_Static_Byte_Array(&ExampleStaticByteArray,15);

    printf("Byte array properties: \n");
    printf("Length: %lu \n", ExampleStaticByteArray.st_array_length);
    printf("Begin address: %X \n", ExampleStaticByteArray.byte_array) ;
    printf("End address: %X \n", ExampleStaticByteArray.end_location) ;



}