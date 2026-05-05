class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0 , ten = 0;
        for(int i = 0; i<bills.size(); i++){
            if(bills[i] == 5){
                five++;
            } else if(bills[i] == 10){
                ten++;
            }
            int change = bills[i] - 5;
            if(change == 5){
                if(five>=1){
                    five--;
                } else {
                    return false;
                }
            } else if(change == 15){
                if((ten>=1 && five>=1)){
                    ten--;
                    five--;
                } else if(five>=3){
                    five-=3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};