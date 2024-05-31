#include <stdio.h>

int get_max(const int array[], int n){
  int ret = -999999;
  for (int i = 0; i < n; i++){
    if (array[i] > ret){
     ret = array[i];
    }
  }
  return ret;

  	
}

int main(void){

  int x = 5;		
  printf("x = %d\n", x);
  int array[10] = { 1,2,-3,4,12,6,4,73,9,0};
  
  int max = get_max(array, 10);
  printf("maximum element is %d\n", max);   

}
