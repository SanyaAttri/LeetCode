
//Accepted	8 ms	c
typedef enum State{
    UnkownState  = 0,       // 未知起始状态
    NumberState = 1,         // 数字状态
    OnlyNumberState = 2,
    OperatorState = 3,      // +,- 符号状态
    DecimalPointState = 4,  // 小数点 状态
    ScientificState = 5,    // 科学计数法
    NoscientificState = 6, //没有科学计数法
    IllegalState = 7,
    EndState,
}State;

int isNumber(char* s) {
    State state = UnkownState;
    while (*s == ' ')  s++;
    char *p = (s+strlen(s)-1);
    while (*p == ' ')  --p;
    *(p+1) = 0;


    while (*s) {
        switch (state) {
            case UnkownState:{
                state = IllegalState;
                if(*s == '+' || *s == '-') state = OperatorState;
                if(*s >= '0' && *s <= '9') state = NumberState;
                if(*s == '.') state = DecimalPointState;
                break;
            }
            case NumberState:{
                state = IllegalState;
                if(*s >= '0' && *s <= '9') state = NumberState;
                if(*s == '.') state = OnlyNumberState;
                if(*s == 'e' || *s == 'E') state = ScientificState;
                break;
            }
            case OnlyNumberState:{
                state = IllegalState;
                if(*s >= '0' && *s <= '9') state = OnlyNumberState;
                if(*s == 'e' || *s == 'E') state = ScientificState;
                break;
            }
            case OperatorState:{
                state = IllegalState;
                if(*s >= '0' && *s <= '9') state = NumberState;
                if(*s == '.' ) state = DecimalPointState;
                break;
            }
            case DecimalPointState:{
                state = IllegalState;
                if(*s >= '0' && *s <= '9') state = OnlyNumberState;
                break;
            }
            case ScientificState:{
                state = IllegalState;
                if(*s == '+' || *s == '-') state = NoscientificState;
                if(*s >= '0' && *s <= '9') state = EndState;
                break;
            }
            case NoscientificState:{
                state = IllegalState;
                if(*s >= '0' && *s <='9') state = EndState;
                break;
            }
            case EndState:{
                state = IllegalState;
                if(*s >= '0' && *s <='9') state = EndState;
                break;
            }
            case IllegalState:{
                return 0;
            }
        }
        s++;
    }


    return (state == NumberState || state == OnlyNumberState || state == EndState);

}

