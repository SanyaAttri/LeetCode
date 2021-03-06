bool isMatch(char* s, char* p) {
    if(*p == 0) return *s == 0;
    
    if(*(p+1) != '*'){
        if(*s && ((*s == *p) || (*p == '.'))){
            return isMatch(s+1,p+1);
        }
           return false;
    }
    else{
        while(*s && ((*s==*p) || (*p == '.'))){
            if(isMatch(s, p+2)) return true;
            s++;
        }
        return isMatch(s, p+2);
    }
}
