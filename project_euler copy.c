#include <stdio.h>


int three_five(){
  int sum = 0;
  //iterate through all numbers until 1000
  for(int i = 0; i < 1000; i++){
    //checks to see if it fits criteria
    if ((i%3 == 0) || (i%5 == 0)){
      sum += i;
    }
  }
  return sum;
}

long even_Fib(){
  long first = 1;
  long second = 2;
  long sum = 2;
  long temp = 0;
  while ( second < 4000000){
    //setting the new first and second
    temp = second;
    second = first + second;
    first = temp;
    //adding the second if it is an even number
    if (second % 2 == 0){
      //printf("%lu\n", second);
      sum += second;
    }
  }
  return sum;
}

long largest_prime(long num){
  int largest = 0;
  long current = num;
  //goes through all the numbers until the argument is 1
  for (int temp = 2; current != 1 ; temp++){
    //divide each number until it can no longer be divisible
    while (current % temp == 0 && current != 1){
      current = current / temp;
    }
    //printf ("%lu\n", current);
    largest = temp;
  }
  return largest;
}

//helper function
int check(int current, int ans){
  for (int i = 2; i < current; i++){
    if (ans % current != 0 && (ans * i) % current == 0){
      ans *= i;
    }
  }
  return ans;
}

int divisible(int num){
  int ans = 1;
  for (int i = 2; i < num; i++){
    if (ans % i != 0){
      ans = check(i , ans);
    }
    if (ans % i != 0){
      ans *= i;
    }
  }
  return ans;
}

int main(){
  printf("%d. %d\n", 1, three_five());
  printf("%d. %lu\n", 2, even_Fib());
  printf("%d. %lu\n", 3, largest_prime(600851475143));
  printf("%d. %d\n", 5, divisible(20));

}
