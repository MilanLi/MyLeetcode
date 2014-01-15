// Length of Last Word


int lengthOfLastWord(const char *s) {
    int ret = 0;
    const char* ptr = s;
    while(*ptr != '\0'){
        if(*ptr == ' '){
            if(ptr[1] != ' ' && ptr[1] != '\0'){
                ret = 0;
            }
        }
        else{
            ret++;
        }
        ++ptr;
    }
    return ret;
}