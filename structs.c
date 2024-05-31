#include <stdio.h>
typedef struct
{
  float height;
  short life;
  char * name;

} Man;

void structs(){
  Man man = {1.72,200,"Bozo the Clown"};
  Man man2;
  man2.height = 1.92;
  man2.life = 300;
  man2.name = "Jimmy the Chin";
  printf("man1's name is %s\n", man.name);
  printf("man2's name is %s\n", man2.name);
}

int main(int argc, char * argv[]){
  structs();
  return 0;

}
