struct heap {
    int *A;
    int idx;
};

struct heap* newHeap(int size){
    struct heap *h = malloc(sizeof(struct heap));
    // Index starts at 1 to make the math in helper fn's easier.. just for this problem.
    h->idx = 1; 
    h->A = malloc(sizeof(int)* size);

    return h; 
} 

void insert(struct heap* h, int num){
    int *A = h->A;
    int node = h->idx;
    int parent = node/2;
    
    A[h->idx] = num;

    h->idx++;
    
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
    int* A = h->A;
    int ret = A[1];
    int parent = 1;
    int l = parent * 2;
    int r = parent * 2 + 1;

    if (A[l] == 0 && A[r] == 0) return ret;             

    A[1] = A[h->idx-1];

    while(h->idx != 1 && parent < h->idx/2){
        l = parent *2;
        r = l + 1;

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

void printHeap(struct heap *h){
    for (int q = 0; q < 27; q++){
        printf("%d, ", h->A[q]);
    } 
}
