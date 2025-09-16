class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
           stack<int> s;
        
        for(auto i: arr){
            if(i=="*" || i=="+"||i=="-"||i=="/"||i=="^"){
                int last = s.top();
                s.pop();
                int secondLast = s.top();
                s.pop();
                
                
                
                
                if(i=="*")
                    {
                        s.push(last*secondLast);
                    }else if(i=="+"){
                        s.push(last+secondLast);
                    }else if(i=="^"){
                        int power = (int)pow(secondLast,last);
                        s.push(power);
                    }else if(i=="-"){
                        s.push(secondLast-last);
                    }else{
                       int division = secondLast / last;
int remainder = abs(secondLast) % abs(last);

if (remainder != 0 && (last*secondLast)<0) {
    division--;  // adjust only if signs differ and not divisible
}
s.push(division);
                    }
            }else{
                s.push(stoi(i));
            }
        }
        
        return s.top();
    }
};