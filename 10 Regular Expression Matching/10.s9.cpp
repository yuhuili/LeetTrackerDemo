struct Obj {
    string s;
    string p;
};

class Solution {
public:
    bool isMatch(string s, string p) {
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