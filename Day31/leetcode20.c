bool isValid(char * s) {
    int len = strlen(s);
    
    // Optimization: An odd-length string can never be valid
    if (len % 2 != 0) {
        return false;
    }
    
    // Dynamically allocate a stack matching the maximum possible length
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        
        // Push opening brackets onto the stack
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } 
        // Handle closing brackets
        else {
            // If stack is empty but we have a closing bracket, it's invalid
            if (top == -1) {
                free(stack);
                return false;
            }
            
            char topChar = stack[top];
            
            // If the closing bracket matches the top of the stack, pop it
            if ((c == ')' && topChar == '(') ||
                (c == '}' && topChar == '{') ||
                (c == ']' && topChar == '[')) {
                top--;
            } 
            // Mismatch found
            else {
                free(stack);
                return false;
            }
        }
    }
    
    // If the stack is empty at the end, all parentheses were matched perfectly
    bool isValidString = (top == -1);
    
    // Always free dynamically allocated memory before returning
    free(stack);
    return isValidString;
}
