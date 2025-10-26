class Bank {
public:
    unordered_map<int,long long>bank;
    Bank(vector<long long>& balance) {
        for(int i=0;i<balance.size();i++){
            bank[i+1]=balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if( !bank.count(account1) || !bank.count(account2)) return false;
        if (bank[account1] < money) return false;
        long long currMoney=bank[account1];
        bank[account1]=currMoney-money;
        bank[account2]+=money;
        return true;
        
    }
    
    bool deposit(int account, long long money) {
        if(!bank.count(account)) return false;
        bank[account]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
         if(!bank.count(account)) return false;
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