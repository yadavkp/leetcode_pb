class ProductOfNumbers {
    private:
     vector<int> prefixpdt;
public:
    ProductOfNumbers() {
        prefixpdt.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            prefixpdt.clear();
            prefixpdt.push_back(1);
        }else{
            prefixpdt.push_back(prefixpdt.back()*num);
        }
    }
    int getProduct(int k) {
        int n = prefixpdt.size();
        if(k>=n){
            return 0;
        }else{
            return prefixpdt[n-1] / prefixpdt[n-k-1];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */