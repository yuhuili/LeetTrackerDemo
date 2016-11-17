struct Obj {
    string s;
    string p;
};

class Solution {
public:
    string optimizeRe(string s, string p) {
        // Contract
        for (int i=2, lenx=p.length()-1;i<lenx;i++) {
            if (p[i+1]=='*') {
                if (p[i-1]=='*' && p[i-2]==s[i]) {
                    string f = p.substr(0,i);
                    string b = "";
                    if (i<lenx-1) {
                        b = p.substr(i+2, lenx+1-(i+2));
                    }
                    p=f+b;
                    i--;
                }
            }
        }
        cout << p << endl;
        return p;
    }

    bool isMatch(string s, string p) {
    
        p = optimizeRe(s, p);
        
        stack<Obj> st;
        Obj initialObj = {s,p};
        st.push(initialObj);
        while (st.size()>0) {
            //cout << st.top().s << " :: " << st.top().p << endl;
            Obj o = st.top();
            st.pop();
            
            if (o.s.length()==0 && o.p.length()==0) {
                return true;
            }
            
            if (o.p.length()>=2) { // possible modifier
                if (o.p[1]=='*') { // any p[0] or none
                    if (o.s.length()==0) {
                        Obj newO = {o.s, o.p.substr(2)};
                        st.push(newO);
                    } else if (o.p[0]=='.' || o.s[0]==o.p[0]) { // any character or that character
                        Obj newO = {o.s.substr(1), o.p.substr(2)};
                        st.push(newO);
                        Obj newO2 = {o.s, o.p.substr(2)};
                        st.push(newO2);
                        if (o.s.length()!=0) {
                            Obj newO = {o.s.substr(1), o.p};
                            st.push(newO);
                        }
                    } else {
                        Obj newO = {o.s, o.p.substr(2)};
                        st.push(newO);
                    }
                } else {
                    // process individually
                    if (o.s.length()==0) continue;
                    if (o.s[0]==o.p[0]) {
                        Obj newO = {o.s.substr(1), o.p.substr(1)};
                        st.push(newO);
                    } else if (o.p[0]=='.') {
                        Obj newO = {o.s.substr(1), o.p.substr(1)};
                        st.push(newO);
                    }
                }
            } else if (o.p.length()==1) { // no modifier
                if (o.s.length()==0) continue;
                if (o.s[0]==o.p[0]) {
                    Obj newO = {o.s.substr(1), o.p.substr(1)};
                    st.push(newO);
                } else if (o.p[0]=='.') {
                    Obj newO = {o.s.substr(1), o.p.substr(1)};
                    st.push(newO);
                }
            } else {
                continue;
            }
        }
        return false;
    }
};