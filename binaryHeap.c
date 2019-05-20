struct heap {
    int *A;
    int idx;
    int size;
};

struct heap* newHeap(int size){
    struct heap *h = malloc(sizeof(struct heap));
    h->idx = 0; 
    h->size = size+1; //Add on because insert() starts at one to make math slightly easier.
    h->A = malloc(sizeof(int)* h->size);
    
    return h; 
} 

void insert(struct heap* h, int num){
    int *A = h->A;
    int node = h->idx+1;
    int parent = node/2;
    
    h->idx++; // Array starts at 1 to make math slightly easier.
    
    A[h->idx] = num;
    
    while(true){
        if (node == 1){
            A[node] = num;
            break;
        } 
        if (A[parent] >= A[node]){
            break;
        } 
        if (A[node] > A[parent]){
            int temp = A[node];
            A[node]  = A[parent];
            A[parent] = temp;

            node = parent; 
            parent = floor(node/2);                     
        }       
    }    
}

int removeTop (struct heap* h){
    if (h->idx == 0) return 0; 
    
    int* A = h->A;
    int ret = A[1];
    int parent = 1;
    int l = parent * 2;
    int r = parent * 2 + 1;
     
    if (h->idx == 1){
        A[1] = 0;
        h->idx -= 1;
        return ret; 
    }
    
    if (A[l] == 0 && A[r] == 0) return ret;             

    A[1] = A[h->idx];
    
    while(parent <= (h->idx)/2){
        l = parent *2;
        r = l+1;

        if (r < h->idx && A[l] < A[r]){
            if (A[parent] >= A[r]) break;
            int temp = A[r];
            A[r] = A[parent];
            A[parent] = temp;
            parent = r;
        } else {
            if (A[parent] >= A[l]) break;
            int temp = A[l];
            A[l] = A[parent];
            A[parent] = temp;
            parent = l; 
        }
    }

    h->idx--;
    
    return ret;
}

void printHeap(struct heap *h, int len){
    for (int q = 0; q < len; q++){
        printf("%d, ", h->A[q]);
    } 
    printf("\n");
}
