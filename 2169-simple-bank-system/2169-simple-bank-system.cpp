class Bank {
public:
    vector<long long>bank;
    int size;
    Bank(vector<long long>& balance) {
        int n=balance.size();
        this->size=n;
        bank.resize(size+1);
        for(int i=0;i<balance.size();i++){
            bank[i+1]=balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1>size || account2>size) return false;
        if (bank[account1] < money) return false;
        long long currMoney=bank[account1];
        bank[account1]=currMoney-money;
        bank[account2]+=money;
        return true;
        
    }
    
    bool deposit(int account, long long money) {
        if(account>size) return false;
        bank[account]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account>size) return false;
         if(bank[account]<money) return false;
         if(money<=bank[account]) bank[account]-=money;
         return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */