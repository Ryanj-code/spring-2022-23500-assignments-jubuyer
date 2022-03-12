#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

void print_vector(std::vector<int> a){
  for (auto i : a){
    std::cout << i << ", ";
  }
  std::cout << "\n";
}


int find_min_index(std::vector<int> a,
		   int start_index,
		   int stop_index){
  int min_index = start_index;
  int i;
  for (i = start_index ; i < stop_index; i++){
    if (a[i] < a[min_index]){
      min_index = i;
    }
  }
  return min_index;
}

std::vector<int> ssort(std::vector<int> a){
  int i,min_index,j,tmp;
  int len = a.size();
  // loop through the vector from 0 to end
  for (i=0;i<len; i++){
    // find the smallest value from i to the end
    min_index = find_min_index(a,i,len);

    // swap it into position i
    tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;

  }
  return a;
}

/*
  left and right are already sorted

  merged should be a new vector with all the
  elements in left and right, and result
  should be sorted
*/
std::vector<int> merge(std::vector<int> left,
		       std::vector<int> right){
  std::vector<int> merged;

  // your code here

  // remember merged.push_back(n)
  // appends value n to the vector merged

  int l = 0;
  int r = 0;

  while(l < left.size() && r < right.size()) {
    if(left[l] < right[r]) {
      merged.push_back(left[l]);
      l++;
    } else if(right[r] < left[l]){
      merged.push_back(right[r]);
      r++;
    }
  }

  while(l < left.size()) {
    merged.push_back(left[l]);
    l++;
  }
  while(r < right.size()) {
    merged.push_back(right[r]);
    r++;
  }

  return merged;
}

std::vector<int> msort(std::vector<int> v) {
  if(v.size() < 2) {
    return v;
  }

  std::vector<int> v1;
  std::vector<int> v2;
  int size = v.size();

  for(int i = 0; i < size / 2; i++) {
    v1.push_back(v[i]);
  }

  for(int j =  size/2; j < size; j++) {
    v2.push_back(v[j]);
  }

  return merge(ssort(v1), ssort(v2));
}

int main()
{
  // int size=102000;
  // int max_val=1000;

  // srand(time(nullptr));
  // std::vector<int> a(size);
  // int i;
  // for (i=0;i<size; i++){
  //   a[i] = rand()%max_val;
  // }
  // print_vector(a);
  // std::cout << "\n";
  // a = ssort(a);
  // print_vector(a);

  std::vector<int> left = { 1, 2, 5, 6, 10, 15 };
  std::vector<int> right = { 3, 7, 8, 12, 16, 19, 20};

  // print_vector(left);
  // print_vector(right);
  //
  // print_vector(merge(left, right));

  std::vector<int> test = {1, 2, 5, 6, 3, 7, 8, 1, 16, 19, 20, 2, 10, 15};
  print_vector(test);

  print_vector(msort(test));

  return 0;
}
