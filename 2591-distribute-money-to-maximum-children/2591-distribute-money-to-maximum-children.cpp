class Solution {
public:
    int distMoney(int money, int children) {
      if(money<children) return -1;
      if(money<8) return 0;

      int ans=0;
      vector<int>child(children,1);//giving 1 dollor to each question
      money-=children;

      for(int i=0;i<children-1;i++){
          if(money>6){ 
          ans++;
          child[i]+=7;
          money-=7;
      }
      }
      if(money==7) ans++;
      else if(money==3){
          if (child[children-2]==8) ans--;
      }
    
     return ans;
     
    }
};