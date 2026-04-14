class ParkingSystem {
    int big_slot,med_slot,small_slot;
public:
    ParkingSystem(int big, int medium, int small) {
        big_slot = big;
        med_slot = medium;
        small_slot = small;
    }
    
    bool addCar(int carType) {
        
        if(carType == 1 && big_slot>=1){
            big_slot--;return true;
        }else if(carType == 2 && med_slot>=1){
            med_slot--;
            return true;
        }else if(carType == 3 && small_slot>=1){
            small_slot--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */