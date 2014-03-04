class Solution {
public:
    
    int char2int(char c) {
        return (int)(c-'0');
    }
    string int2str(int i) {
        return to_string(i);
    }
    string addstr(string num1, string num2) {
        if(num1.size() > num2.size()){
            string tmp = num1;
            num1 = num2;
            num2 = tmp;
        }
        //cout << "=>" << num1 << " " << num2 << "<=" << endl;
        //num1 size <= num2 size
        string ret = "";
        int delta = num2.size() - num1.size();
        int carry = 0;
        int i;
        for(i = num1.size()-1; i >= 0; --i) {
            int tmpsum = char2int(num1[i])+char2int(num2[i+delta])+carry;
            if(tmpsum > 9){
                carry = 1;
                tmpsum -= 10;
            }else {
                carry = 0;
            }
            ret = int2str(tmpsum)+ret;
        }
        for(int j = i+delta; j >= 0; --j) {
            int tmpsum = char2int(num2[j])+carry;
            if(tmpsum > 9){
                carry = 1;
                tmpsum -= 10;
            }else {
                carry = 0;
            }
            ret = int2str(tmpsum)+ret;
        }
        if(carry)
            ret = "1" +ret;
        return ret;
    }

    string multstr(string num1, char c) {
     	int carry = 0;
     	string tmp="";
        for(int j = num1.size()-1; j >= 0; --j) {
            int tmpmul = char2int(num1[j]) * char2int(c) + carry;
            if(tmpmul > 9) {
                carry = tmpmul/10;
                tmpmul = tmpmul%10;
            } else{
                carry = 0;
            }
            tmp = int2str(tmpmul)+tmp;
        }
        if(carry) {
            tmp = to_string(carry)+tmp;
        }
        return tmp;
    }
        
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        
        if(num1.size() > num2.size()) {
        	string tmp = num1;
        	num1 = num2;
        	num2 = tmp;
        }
        map<char, string> hash;
        
        string res = "0";
        string zeros = "";
        for(int i = num2.size()-1; i >= 0 ; --i) {
            string tmp = "";
            if(hash.find(num2[i]) != hash.end()) {
                tmp = hash[num2[i]];
            } else {
                tmp = multstr(num1, num2[i]);
                hash[num2[i]] = tmp;
            }

            tmp = tmp+zeros;
            zeros = zeros + "0";
            //cout << tmp << " -> ";
            res = addstr(res, tmp);
            //cout << res << endl;
        }
        return res;
    }

};