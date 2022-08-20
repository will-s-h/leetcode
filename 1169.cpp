class Solution {
public:
    
    struct tr{
        string name;
        int time;
        int amt;
        string city;
        int k;
        bool reported = false; //default is false
    };
    
    vector<string> naive (vector<string>& transactions) { //O(N^2), O(N log N) is possible but not necessary.
        vector<tr> trs;
        for(int k = 0; k < transactions.size(); k++){
            stringstream s_stream(transactions[k]); //create string stream from the string
            tr newtr; newtr.k = k;
            int i = 0;
            while(s_stream.good()) {
                string substr;
                getline(s_stream, substr, ','); //get first string delimited by comma
                
                if(i == 0) newtr.name = substr;
                if(i == 1) newtr.time = stoi(substr);
                if(i == 2) newtr.amt = stoi(substr);
                if(i == 3) newtr.city = substr;
                i++;
            }
            
            trs.push_back(newtr);
        }
        
        vector<string> ans;
        
        for(int i = 0; i < trs.size(); i++){
            if(trs[i].amt > 1000){
                trs[i].reported = true;
                ans.push_back(transactions[trs[i].k]);
            }
        }
        
        for(int i = 0; i < trs.size(); i++){
            for(int j = i+1; j < trs.size(); j++){
                if(trs[i].name == trs[j].name && trs[i].city != trs[j].city && abs(trs[i].time - trs[j].time) <= 60){
                    if(!trs[i].reported){
                        trs[i].reported = true;
                        ans.push_back(transactions[trs[i].k]);
                    } if(!trs[j].reported){
                        trs[j].reported = true;
                        ans.push_back(transactions[trs[j].k]);
                    }
                }
            }
        }
        
        return ans;
    }
};
