char* reorganizeString(char* S){
    int l = strlen(S);
    int s[26]; 
    struct heap *h = newHeap(100);

    memset(s, 0, sizeof(int) * 26);

    for (int n = 0; n < l; n++) s[S[n]-97] += 100;   

    for (int i = 0; i < 26; ++i) s[i] += i;

    for (int i = 0; i < 26; ++i) {
        if (s[i] >= 100) insert(h, s[i]);       
    }

    int p = 0; 

    int *pq = h->A;

    for (int n = 0; p < l; n++){
        int letter = removeTop(h);
        int ct = letter / 100;
        int chr = 'a' + (letter % 100);

        int letter2 = removeTop(h);
        int ct2 = letter2 / 100;
        int chr2 = 'a' + (letter2 % 100);

        if (ct > (l+1)/2) return "";
        if (ct2 > (l+1)/2) return "";

        if (p==0 || chr != S[p-1]){
            S[p] = chr;
            letter -= 100;
            p++;

            if (p >= l) break;  

            S[p] = chr2;
            letter2 -= 100;
            p++;
        }else {
            S[p] = chr2;
            letter2 -= 100;
            p++;

            if (p >= l) break;  

            S[p] = chr;
            letter -= 100;
            p++;
        }

        if (letter >= 100) insert(h, letter); 
        if (letter2 >= 100) insert(h, letter2); 
    }

    return S;
}
