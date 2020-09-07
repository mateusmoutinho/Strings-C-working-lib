
#include <stdbool.h>
#include <stdio.h>

unsigned int String_Lenght(const char  *string_one);

int String_Index_Of_From_Point(const char *target_string, const char *string_to_find,unsigned int point);

int String_Index_Of_From_Point_In_Negative_Direction( const char *target_string, const char *string_to_find,unsigned int point);

int String_Index_Of(const char *target_string, const char *string_to_find);

bool String_Compare(const char * string,const char * string_two);

void String_Copy(char target_string[],const char * string_to_copy);

void String_Copy_From_Point_to_Point(char target_string[], const char * string_to_copy, unsigned int start_point, unsigned int end_point);

void String_Add_Space(char target_string [],char char_to_insert, unsigned int  number_of_chars,unsigned int  position);

void String_Remove_Space(char target_string[],unsigned int  number_of_chars,unsigned int  position);

void String_Substring(char target_string[], unsigned int  first_point, unsigned int  second_point);

void String_Insert_String(char target_string[], const char * string_to_insert, unsigned int  point);

void String_Unshift(char target_string[], const char * string_to_insert);

void String_Push(char target_string[], const char * string_to_insert);

void String_Replace(char target_string[], const char *string_to_find, const char *string_to_replace);

void String_Replace_All(char target_string[], const char *string_to_find, const char *string_to_replace);

void String_Remove_String(char target_string[], const char *string_to_remove);

void String_Remove_All_Strings(char target_string[], const char *string_to_remove);

void String_Get_Nex_Word(char target_string[], const char *string_to_find_word,unsigned int point);

void String_to_Uppercase(char target_string[]);

void String_to_Lowercase(char target_string[]);

void String_First_Word_to_Uppercase(char target_string[]);

void String_First_Word_to_Lowercase(char target_string[]);

//--------------------------------------------------------------------------------------------------------------------

unsigned int  String_Lenght(const char * string){

    unsigned int  i = 0;

    for(; string[i] != 0; i++){}

    return i;
}

int String_Index_Of_From_Point( const char *target_string, const char *string_to_find,unsigned int point){
      
             unsigned int target_string_size         = String_Lenght(target_string),
                          string_to_find_size        = String_Lenght(string_to_find);

             int  equal_count                = 0;
                    
                          for(int i = point; i <= target_string_size; i++){
                    
                             if(equal_count == string_to_find_size){
                                 return i - string_to_find_size;
                             }

                             if(target_string[i] == string_to_find[equal_count]){
                                ++equal_count;
                            }else{
                                  equal_count = 0;
                            }
                         }
                            
      
             return -1;
}

int String_Index_Of_From_Point_In_Negative_Direction(const  char *target_string, const char *string_to_find,unsigned int point){
      
             unsigned int target_string_size         = String_Lenght(target_string),
                          string_to_find_size        = String_Lenght(string_to_find);

                        int  equal_count  = string_to_find_size - 1;
                        
                          for(int i = point; i >= 0; i--){
                         
                              if(equal_count == -1){
                                 return i + 1;
                             }
                               
                             if(target_string[i] == string_to_find[equal_count]){
                                  --equal_count;
                                  
                            }else{
                                 equal_count = string_to_find_size - 1;
                            }
                        
                         }

             return -1;
}

int String_Index_Of(const char *target_string, const char *string_to_find){

             return String_Index_Of_From_Point(target_string,string_to_find,0);
}

bool String_Compare(const char * string_one, const char * string_two){
         unsigned int   string_one_lenght = String_Lenght(string_one),
                        string_two_lenght = String_Lenght(string_two),
                        size = string_two_lenght;

         if(string_two_lenght != string_one_lenght){
             return false;
         }
         for(unsigned int i = 0; i <= size; i++){
             if(string_one[i] != string_two[i]){
                 return false;
             }
         }
         return true;
}

void String_Copy(char target_string[], const char * string_to_copy){

                 for(unsigned int  i = 0; string_to_copy[i] != 0; i++){
                     target_string[i] = string_to_copy[i];
                 }

                 return;
}

void String_Copy_From_Point_to_Point(char target_string[], const char * string_to_copy, unsigned int start_point, unsigned int end_point){
                 
                 for(unsigned int  i = start_point, x = 0;i <= end_point; i++, x++){
                     target_string[x] = string_to_copy[i];
                 }

                 return;
}

void String_Add_Space(char target_string[],char char_to_insert,unsigned int  number_of_chars, unsigned int  position){

              unsigned int  size = String_Lenght(target_string);
        
                   for(unsigned int  i = size ; i >= position; i-- ){
                       target_string[i + number_of_chars] = target_string[i];
                       target_string[i] = char_to_insert;
                       if(i == 0){
                           break;
                       }
                     
                   }
                         
                return;

}

void String_Remove_Space(char target_string[],unsigned int  number_of_chars,unsigned int  position){

         unsigned int  size = String_Lenght(target_string); 
              
              for(unsigned int  i = position; i <= size; i++){
                  target_string[i] = target_string[i + number_of_chars];
              }
              return;
}

void String_Substring(char target_string[], unsigned int  first_point,unsigned int  second_point){

                  unsigned int  size = String_Lenght(target_string);

                   String_Remove_Space(target_string,0,first_point);

                   String_Remove_Space(target_string,first_point,second_point);
                   return;
}

void String_Insert_String(char target_string[], const char * string_to_insert, unsigned int  point){

                   unsigned int  size = String_Lenght(string_to_insert),
                          end_point = point + size;
                   
            
                      String_Add_Space(target_string,' ',size, point);
                   
                
                   for(unsigned int  i = point; i < end_point; i++){
                        target_string[i] = string_to_insert[i - point];
                       
                   }
                return;
}                

void String_Unshift(char target_string[], const char * string_to_insert){   

                   String_Insert_String(target_string,string_to_insert,0);
                  return;
}

void String_Push(char target_string[], const char * string_to_insert){
                 unsigned int  size = String_Lenght(target_string);

                 String_Insert_String(target_string,string_to_insert,size);
                 return;
}

void String_Replace(char target_string[], const char *string_to_find, const char *string_to_replace){

                    unsigned int point = String_Index_Of(target_string ,string_to_find),
                                 size_of_string_to_find =  String_Lenght(string_to_find);

                    String_Remove_Space(target_string,size_of_string_to_find,point);

                    String_Insert_String(target_string,string_to_replace,point);

      return;
}

void String_Replace_All(char target_string[], const char *string_to_find, const char *string_to_replace){
                     
                    unsigned int size_of_string_to_find =  String_Lenght(string_to_find);
                   
                    while(true){ 

                    unsigned int point = String_Index_Of(target_string ,string_to_find);
                    
                    if(point == -1){
                        break;
                    }
                    String_Remove_Space(target_string,size_of_string_to_find,point);

                    String_Insert_String(target_string,string_to_replace,point);
                    }
 return;
}

void String_Remove_String(char target_string[], const char *string_to_remove){
     unsigned int point = String_Index_Of(target_string,string_to_remove),
                  size = String_Lenght(string_to_remove);
                  String_Remove_Space(target_string,size,point);
                  return;
}

void String_Remove_All_Strings(char target_string[], const char *string_to_remove){
          while(true){  
                     unsigned int point = String_Index_Of(target_string,string_to_remove);
                     if(point == -1){
                        break;
                      }
                     unsigned int  size = String_Lenght(string_to_remove);
                     String_Remove_Space(target_string,size,point);                   
          }        
          return;       
}

void String_Get_Nex_Word(char target_string[], const char *string_to_find_word,unsigned int point){
                            
                          int  i = String_Index_Of_From_Point(string_to_find_word," ",point);
                          
                         for(;string_to_find_word[i] == ' '; ++i){}

                         unsigned int start_point = i,
                                      final_point = String_Index_Of_From_Point(string_to_find_word," ",i);
                           
                         String_Copy_From_Point_to_Point(target_string,string_to_find_word,start_point,final_point);
}

void String_Get_Last_Word(char target_string[], const char *string_to_find_word,unsigned int point){
                            
                          int  i = String_Index_Of_From_Point_In_Negative_Direction(string_to_find_word," ",point);
                         
                         for(;string_to_find_word[i] == ' '; --i){}

                          int final_point = i,
                              start_point = String_Index_Of_From_Point_In_Negative_Direction(string_to_find_word," ",i);
                           
                         String_Copy_From_Point_to_Point(target_string,string_to_find_word,start_point,final_point);
}


void String_to_Uppercase(char target_string[]){

     for(unsigned int i = 0;target_string[i]!= 0;i++){

         if(target_string[i] >= 'a' && target_string[i] <= 'z'){
            target_string[i] = target_string[i]  - 32;
         }
         
     }
     return;
}

void String_to_Lowercase(char target_string[]){

     for(unsigned int i = 0;target_string[i]!= 0;i++){

         if(target_string[i] >= 'A' && target_string[i] <= 'Z'){
            target_string[i] = target_string[i]  + 32;
         }
         
     }
     return;
}

void String_First_Word_to_Uppercase(char target_string[]){
       unsigned int i = 0;
           if(target_string[i] >= 'a' && target_string[i] <= 'z'){
             target_string[i] = target_string[i]  - 32;
         } 
        ++i;

        for(;target_string[i]!= 0;i++){
         
           if(target_string[i] >= 'a' && target_string[i] <= 'z' && target_string[i -1] == ' '){
             target_string[i] = target_string[i]  - 32;
          }
         
     }
     return;
}

void String_First_Word_to_Lowercase(char target_string[]){
       unsigned int i = 0;
           if(target_string[i] >= 'A' && target_string[i] <= 'Z'){
             target_string[i] = target_string[i]  + 32;
         } 
        ++i;

        for(;target_string[i]!= 0;i++){
         
           if(target_string[i] >= 'A' && target_string[i] <= 'Z' && target_string[i -1] == ' '){
             target_string[i] = target_string[i]  + 32;
          }
         
     }
     return;
}


int main(int argc, char const *argv[])
{
     char teste[30] = "0123    Abc456789";

     char teste2[30] = {} ;
             String_Get_Nex_Word(teste2,teste,2);
             printf("%s \n", teste2);
    return 0;
}
