int remDup(int arr[], int size){

    int i = 0;
    int j = 1;

    int currSize = size
    while(j < currSize){
        if(arr[i] == arr[j]){
            while(j+1 < currSize && arr[i] == arr[j+1]){
                j++;
            }

            int    k = i+1;
            int l = j;
            while(l < currSize){
                arr[k++] = arr[l++];    
            }
    
            currSize = currSize - (j-i);
        }
         i++;j++;
    }
    return currSize;
}



int remDup(int* arr, int size){

    int i=0;
    int j=1;
    int *p1 = arr;

    int currSize = size
    while(j < currSize){
        if(*(p1+i) == *(p1+j)){
            while(j+1 < currSize && *(p1+i) == *(p1+(j+1))){
                j++;
            }

            int    k = i+1;
            int l = j;
            while(l < currSize){
                *(p1+k) = *(p1+l);
                k++;l++;    
            }
    
            currSize = currSize - (j-i);
        }
         i++;j++;
    }
    return currSize;
}