class Solution{
public:
    string countAndSay(int n){
        n = n - 1;
        string input = "1";
        for(int i = 0; i < n; i++){
            input = say(input);
        }
        string res;
        for(int j = 0; j < input.length(); j++){
            if(' ' != input[j])
                res.push_back(input[j]);
        }
        return res;
    }

    string say(string in){
        if(in.size() == 1){
            return "1 1";
        }
        else{
            string res;
            int pos = 0;
            while(pos < in.length()){
                string ns, cs;
                int count = 1;
                while(in[pos] != ' ')
                    ns.push_back(in[pos++]);
                pos++;
                while(pos < in.length() && 
                        ns.compare(in.substr(pos, ns.length())) == 0){
                    pos = pos + ns.length() + 1;
                    count++;
                }
                stringstream ss;
                ss << count;
                ss >> cs;
                res.append(cs);
                res.push_back(' ');
                res.append(ns);
                res.push_back(' ');
            }
            return res;
        }
    }
};
