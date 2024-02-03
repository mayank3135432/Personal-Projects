struct tree{
  int size;
  int* arr;
  int left(int i){
    return(2*i+1);
  }
  int right(int i){
    return(2*i+2);
  }
};
